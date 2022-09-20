/*
  Gray Scott Algorithm for fluid diffusion simulation

  Wikipedia: Reaction diffusion system

*/

#include <math.h>
#include <stdio.h>
#include <unistd.h>

#include "flame.h"

#include "rdtsc.h"

#define max(a, b) ((a) > (b)) ? (a) : (b)

#define GRID_H 401   //Y axis
#define GRID_W 401   //X axis
#define GRID_C 2     //Chemicals: A & B

//
typedef unsigned char byte;

//Stencil
static inline float laplace(float g[GRID_H][GRID_W][GRID_C], int i, int j, int c)
{
  float sum = 0.0;

  sum += g[i][j][c]         * (-1.0);
  
  sum += g[i - 1][j][c]     *   0.2;
  sum += g[i + 1][j][c]     *   0.2;
  sum += g[i][j - 1][c]     *   0.2;
  sum += g[i][j + 1][c]     *   0.2;
  sum += g[i - 1][j - 1][c] *   0.05;
  sum += g[i - 1][j + 1][c] *   0.05;
  sum += g[i + 1][j - 1][c] *   0.05;
  sum += g[i + 1][j + 1][c] *   0.05;

  return sum;
}

//
static inline void init(float G1[GRID_H][GRID_W][GRID_C])
{
  //Initialize grid with chemical A only
  for (int i = 1; i < GRID_H - 1; i++)
    for (int j = 1; j < GRID_W - 1; j++)
      {
	G1[i][j][0] = 1.0; //Chemical A
	G1[i][j][1] = 0.0;
      }
  
  unsigned long long n = (GRID_H >> 1);
  
  //Add some of chemical B
  for (int i = n - 5; i < n + 5; i++)
    for (int j = n - 5; j < n + 5; j++)
      G1[i][j][1] = 1.0; //Chemical B
}

//
static inline void diffuse(flame_obj_t *fo, int bx, int by,
			   float G[GRID_H][GRID_W][GRID_C],
			   float G1[GRID_H][GRID_W][GRID_C],
			   unsigned frame[GRID_H][GRID_W],
			   int s)
{
  int color;
  float ta, tb;
  const float diff_rate_A = 1.0, diff_rate_B = 0.5;
  
  //Coral Growth, f = 0.0545
  //Mitosis, f= 0.0545
  const float f = 0.0321, k = 0.062, dt = 1.1; //f: feed, k: kill, dt: delta time 
  
  //Copy and set frame
  for (int i = 1; i < GRID_H - 1; i++)
    {
      for (int j = 1; j < GRID_W - 1; j++)
	{
	  G[i][j][0] = G1[i][j][0];
	  G[i][j][1] = G1[i][j][1];
	  
	  if ((s % 50) == 0)
	    {
	      ta = G[i][j][0] - G1[i][j][1];
	      
	      //Set r, g, b according to temp
	      if (ta > 0.8)
		color = 0xFFFFFF00; //White
	      else
		if (ta > 0.5)
		  color = 0xBEBEBE00; //Gray
		else
		  if (ta > 0.1)
		    color = 0xA9A9A900; //Dark Gray
		  else
		    color = 0; //Black
	      
	      frame[i][j] = color; 
	    }
	}
    }

  //Update
  for (int i = 1; i < GRID_H - 1; i++)
    for (int j = 1; j < GRID_W - 1; j++)
      {
	ta = G[i][j][0];
	tb = G[i][j][1];
	
	G1[i][j][0] = ta + (diff_rate_A * laplace(G, i, j, 0) - (ta * tb * tb) + (f * (1 - ta))) * dt;
	G1[i][j][1] = tb + (diff_rate_B * laplace(G, i, j, 1) + (ta * tb * tb) - ((k + f) * tb)) * dt;
      }
}

//
static inline int randxy(int a, int b)
{ return (rand() % (b - a + 1)) + a; }

//
int main(int argc, char **argv)
{
  char c;
  int x_min = 50, x_max = 1900;
  int y_min = 50, y_max = 1000; 
  flame_obj_t *fo = flame_open("Diffusion", x_max, y_max);

  double after, before;
  
  int bx = 5, by = y_max >> 1;
  
  srand(getpid());
  
  XEvent event;

  //
  unsigned frame[GRID_H][GRID_W];
  float G[GRID_H][GRID_W][GRID_C], G1[GRID_H][GRID_W][GRID_C];

  //Memory sizes
  unsigned s = GRID_H * GRID_W * GRID_C;
  unsigned sG = (sizeof(float) * s) >> 10;
  unsigned sG1 = (sizeof(float) * s) >> 10;
  unsigned sframe = (sizeof(unsigned) * s) >> 10;

  unsigned stotal_k = (sG + sG1 + sframe);
  unsigned stotal_m = (sG + sG1 + sframe) >> 10;
  
  fprintf(stderr,
	  "Size G     : %ukiB\n"
	  "Size G1    : %ukiB\n"
	  "Size frame : %ukiB\n"
	  "Total size : %ukiB ~ %uMiB\n",
	  sG, sG1, sframe, stotal_k, stotal_m);
  
  //
  while (1)
    {
      //Handle input
      if (XPending(fo->display) > 0)
	{
	  XNextEvent(fo->display, &event);

	  //Keyboard input
	  if (event.type == KeyPress)
	    {
	      c = XLookupKeysym(&event.xkey, 0);
	      
	      if (c == 'q')
		break;
	    }
	  else //Mouse input
	    if (event.type == ButtonPress)
	      {
	      }
	}
      else
	{
	  //Magic starts here
	  flame_clear_display(fo);
      
	  init(G1);

	  for (int s = 0;; s++)
	    {
	      before = rdtsc();
	  
	      diffuse(fo, bx, by, G, G1, frame, s);
	  
	      after = rdtsc();

	      printf("%d\t\t%lf\n", s, (double)(after - before));
	  
	      //Draw frame
	      for (int i = 1; i < GRID_H; i++)
		for (int j = 1; j < GRID_W; j++)
		  {
		    byte r = (frame[i][j] >> 24) & 0x000000FF;
		    byte g = (frame[i][j] >> 16) & 0x000000FF;
		    byte b = (frame[i][j] >>  8) & 0x000000FF;
		
		    flame_set_color(fo, r, g, b);
		    flame_draw_point(fo, bx + (i * 1), by - (j * 1));
		  }
	    }      
	}
    }
  
  flame_close(fo);

  return 0;
}
