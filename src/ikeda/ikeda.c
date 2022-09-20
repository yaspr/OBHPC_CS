/*
  Ikeda Map
  
  x_(n+1) = 1 + u * (x_n * cos(t_n) - y_n * sin(t_n))
  y_(n+1) = u * (x_n * sin(t_n) + y_n * cos(t_n))

  t_n = 0.4 - (6 / (1 + x_n^2 + y_n^2))
  
 */

#include <math.h>
#include <stdio.h>
#include <unistd.h>

#include "flame.h"

//
typedef unsigned char byte;
typedef unsigned long long u64;

//
u64 randxy(u64 x, u64 y)
{ return (rand() % (y - x + 1)) + x; }

//
void draw_ikeda(flame_obj_t *fo, u64 bx, u64 by, u64 scale, u64 n)
{
  double t, u = 0.918;
  double x0 = (double)RAND_MAX / randxy(0, RAND_MAX), x1 = (double)RAND_MAX / randxy(0, RAND_MAX);
  double y0 = (double)RAND_MAX / randxy(0, RAND_MAX), y1 = (double)RAND_MAX / randxy(0, RAND_MAX);

  for (u64 i = 0; i < n; i++)
    {
      t = 0.4 - (6.0 / (1 + (x0 * x0) + (y0 * y0)));
      
      x1 = 1 + u * (x0 * cos(t) - y0 * sin(t));
      y1 = u * (x0 * sin(t) + y0 * cos(t));

      byte r = randxy(0, 255);
      byte g = randxy(0, 255);
      byte b = randxy(0, 255);
      
      flame_set_color(fo, r, g, b);
      flame_draw_point(fo, bx + (x1 * scale), by - (y1 * scale));
      	  
      x0 = x1;
      y0 = y1;
    }  
}

//
int main(int argc, char **argv)
{
  char c;

  //Event for keyboard & mouse interruptions
  XEvent event;

  //Set display size
  int x_min = 0, x_max = 1920;
  int y_min = 0, y_max = 1080;

  //Initialize display
  flame_obj_t *fo = flame_open("Ikeda Map", x_max, y_max);

  //
  int scale = 20;
  int bx = x_max >> 1, by = y_max >> 1; //Start in the middle of the screen

  srand(getpid());
  
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
	      else
		if (c == 'r')
		  flame_clear_display(fo);
	    }
	  else //Mouse input
	    if (event.type == ButtonPress)
	      {
	      }
	}
      else
	{
	  draw_ikeda(fo, bx, by, scale, 2000);
	  
	  //
	  //usleep(10000);
	}
    }

  flame_close(fo);

  return 0;
}
