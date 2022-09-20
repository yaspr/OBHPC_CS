/*
  Craig Reynold's steering algorithm
  
*/

#include <math.h>
#include <stdio.h>
#include <unistd.h>

#include "flame.h"

#include "pi.h"

#define MAX_PLANETS  100

#define MAX_DISTANCE 900

//
typedef unsigned char byte;

//
typedef struct xy_s { double x; double y; } xy_t;

//
typedef struct ppm_s {

  int w; //Width
  int h; //Height 
  int t; //Threshold
  byte *px; } ppm_t;

//
typedef struct planet_s {

  double x;
  double y;

  ppm_t *image; } planet_t;
  
//
typedef struct vehicle_s {

  int state;
  
  //Vehicle shape (Triangle, p1, p2, p3)
  double p1_x;
  double p1_y;
  double p2_x;
  double p2_y;
  double p3_x;
  double p3_y;

  //Centroid of the triangle
  double c_x; //(p1_x + p2_x + p3_x) / 3
  double c_y; //(p1_y + p2_y + p3_y) / 3


  //Previous position
  double prev_p1_x;
  double prev_p1_y;
  double prev_p2_x;
  double prev_p2_y;
  double prev_p3_x;
  double prev_p3_y;

  //Previous centroid
  double prev_c_x; //(p1_x + p2_x + p3_x) / 3
  double prev_c_y; //(p1_y + p2_y + p3_y) / 3

  //Acceleration
  double acc_x;
  double acc_y;

  //Velocity
  double vel_x;
  double vel_y;

  double max_speed;
  double max_force;

  ppm_t *image;
  
} vehicle_t;

//
static inline int randxy(int a, int b)
{ return (rand() % (b - a + 1)) + a; }

//
static inline double dist(double x1, double y1, double x2, double y2)
{
  double x = x1 - x2;
  double y = y1 - y2;
  
  return sqrt(x * x + y * y);
}

//
static inline void norm(double *x, double *y)
{
  double d = dist(*x, *y, 0, 0);
  
  *x /= d;
  *y /= d;
}

//
static inline void scale(double *x, double *y, double s)
{
  *x *= s;
  *y *= s;
}

//
static inline void limit(double *x, double *y, double s)
{
  norm(x, y);
  scale(x, y, s);
}

//
static inline void rotate(double *x, double *y, double angle)
{
  double xx = *x, yy = *y;

  *x = cos(angle * xx) - sin(angle * yy);
  *y = cos(angle * yy) + sin(angle * xx);
}

//
ppm_t *ppm_open(char *fname)
{
  char c0, c1, c;
  FILE *fd = fopen(fname, "rb");

  if (fd)
    {
      ppm_t *p = malloc(sizeof(ppm_t));
      
      fscanf(fd, "%c%c\n", &c0, &c1);

      c = fgetc(fd);

      if (c == '#')
	{
	  //Handle comment
	  while (c != '\n')
	    c = fgetc(fd);
	}
      else
	fseek(fd, -1, SEEK_CUR);
      
      fscanf(fd, "%d %d\n", &p->w, &p->h);
      fscanf(fd, "%d\n", &p->t);
            
      p->px = malloc(sizeof(byte) * p->w * p->h * 3);
      
      if (c0 == 'P')
	if (c1 == '6') //Binary mode
	  {
	    fread(p->px, sizeof(byte), p->w * p->h * 3, fd);
	  }
	else
	  if (c1 == '3') //ASCII mode
	    {
	    }
      
      fclose(fd);

      return p;
    }
  else
    return NULL;
}

//Pick one pixel out of 2 & 1 row out of two
void ppm_zoom_out_x2(ppm_t *p)
{
  int l = 0, m = 0;
  //Half the width, half the hight, 3 bytes per pixel 
  byte *new_px = malloc(sizeof(byte) * (p->w >> 1) * (p->h >> 1) * 3);

  //Pointer hacking :) (1D ==> 2D) 
  byte (*p_px)[p->w * 3] = (byte (*)[p->w * 3]) p->px;
  byte (*p_new_px)[(p->w >> 1) * 3] = (byte (*)[(p->w >> 1) * 3]) new_px;
  
  for (int i = 0; i < p->h && l < (p->h >> 1); i += 2, l++)
    {
      m = 0;
      
      for (int j = 0, k = 0; j < p->w; j += 2, k += 6, m += 3)
	{
	  byte r = p_px[i][k];
	  byte g = p_px[i][k + 1];
	  byte b = p_px[i][k + 2];

	  p_new_px[l][m]     = r;
	  p_new_px[l][m + 1] = g;
	  p_new_px[l][m + 2] = b;
	}
    }
  
  free(p->px);
  
  p->w  = p->w >> 1;
  p->h  = p->h >> 1;
  p->px = new_px;
}

//Draws only active pixels 
void ppm_draw(flame_obj_t *fo, double x, double y, ppm_t *p)
{
  int k = 0;
  
  for (int h = 0; h < p->h; h++)
    for (int w = 0; w < p->w; w++, k += 3)
      {
	if (p->px[k] || p->px[k + 1] || p->px[k + 2])
	  {
	    flame_set_color(fo, p->px[k], p->px[k + 1], p->px[k + 2]);
	    flame_draw_point(fo, x + w, y + h);
	  }
      }
}

//Clears active pixels
void ppm_clear(flame_obj_t *fo, double x, double y, ppm_t *p)
{
  int k = 0;
  
  for (int h = 0; h < p->h; h++)
    for (int w = 0; w < p->w; w++, k += 3)
      {
	if (p->px[k] || p->px[k + 1] || p->px[k + 2])
	  {
	    flame_set_color(fo, 0, 0, 0);
	    flame_draw_point(fo, x + w, y + h);
	  }
      }
}

//
void update_vehicle(vehicle_t *v)
{
  v->vel_x += v->acc_x;
  v->vel_y += v->acc_y;
  
  limit(&v->vel_x, &v->vel_y, v->max_speed);
  
  v->prev_c_x = v->c_x;
  v->prev_c_y = v->c_y;

  v->prev_p1_x = v->p1_x;
  v->prev_p1_y = v->p1_y;

  v->prev_p2_x = v->p2_x;
  v->prev_p2_y = v->p2_y;
  
  v->prev_p3_x = v->p3_x;
  v->prev_p3_y = v->p3_y;
  
  v->p1_x += v->vel_x;
  v->p1_y += v->vel_y;
  
  v->p2_x += v->vel_x;
  v->p2_y += v->vel_y;

  v->p3_x += v->vel_x;
  v->p3_y += v->vel_y;

  v->c_x = (v->p1_x + v->p2_x + v->p3_x) / 3;
  v->c_y = (v->p1_y + v->p2_y + v->p3_y) / 3;
  
  v->acc_x = 0;
  v->acc_y = 0;
}

//
void apply_force_vehicle(vehicle_t *v, double f_x, double f_y)
{
  v->acc_x += f_x;
  v->acc_y += f_y;
}

//Steer towards t (target)
void seek_vehicle(vehicle_t *v, double t_x, double t_y)
{
  double des_x = t_x - v->c_x;
  double des_y = t_y - v->c_y;

  limit(&des_x, &des_y, v->max_speed);

  double steer_x = des_x - v->vel_x;
  double steer_y = des_y - v->vel_y;

  limit(&steer_x, &steer_y, v->max_force);

  apply_force_vehicle(v, steer_x, steer_y);
}

//
void init_vehicle(vehicle_t *v, ppm_t *ufo_image)
{  
  //Vehicle image
  v->image = ufo_image;
  
  if (!v->image)
    {
      printf("OUPS! No UFO.\n");
      exit(-1);
    }
  
  double UFO_SIZE = v->image->w * v->image->h / 4;
  
  //
  v->prev_p1_x = 0; v->prev_p1_y = 0;
  v->prev_p2_x = 0; v->prev_p2_y = 0;
  v->prev_p3_x = 0; v->prev_p3_y = 0;
  
  v->prev_c_x = 0; 
  v->prev_c_y = 0;

  int off = randxy(1, 800);

  //Triangle
  v->p1_x = off +  0      ; v->p1_y = off +  0;
  v->p2_x = off +  0      ; v->p2_y = off + UFO_SIZE;
  v->p3_x = off + UFO_SIZE; v->p3_y = off +  0;
  
  v->c_x = (v->p1_x + v->p2_x + v->p3_x) / 3;
  v->c_y = (v->p1_y + v->p2_y + v->p3_y) / 3;

  v->acc_x = 0; v->acc_y =  0;
  v->vel_x = 0; v->vel_y = -2;

  v->max_speed = 0.9; //randxy(1, 2);
  v->max_force = 0.1;
}

//
void draw_vehicle(flame_obj_t *fo, xy_t *base, vehicle_t *v)
{
  //Draw ppm vehicle (preferably B&W)
  //Remove previous
  ppm_clear(fo, v->prev_c_x - v->image->w / 2, v->prev_c_y - v->image->h / 2, v->image);

  //Draw current
  ppm_draw(fo, v->c_x - v->image->w / 2, v->c_y - v->image->h / 2, v->image);
}

//
int main(int argc, char **argv)
{
  char c;
  int click_x, click_y;
  int prev_click_x, prev_click_y;
  int x_min = 50, x_max = 1900;
  int y_min = 50, y_max = 1000; 
  flame_obj_t *fo = flame_open("Steer", x_max, y_max);
  
  srand(getpid());
  
  XEvent event;

  xy_t base;
  int nb_vehicles = 50;
  vehicle_t v[nb_vehicles];

  base.x = base.y = 0;
  
  int nb_planets = 0;
  planet_t planets[MAX_PLANETS];
  
  //
  const int nb_ufo_images = 3;
  ppm_t *ufo_images[nb_ufo_images];
  
  ufo_images[0] = ppm_open("pix/ufo.ppm");
  ufo_images[1] = ppm_open("pix/ufo2.ppm");
  ufo_images[2] = ppm_open("pix/ufo3.ppm");
  
  ppm_zoom_out_x2(ufo_images[0]);
  ppm_zoom_out_x2(ufo_images[0]);
  ppm_zoom_out_x2(ufo_images[0]);
  
  ppm_zoom_out_x2(ufo_images[1]);
  ppm_zoom_out_x2(ufo_images[1]);
  
  ppm_zoom_out_x2(ufo_images[2]);
  ppm_zoom_out_x2(ufo_images[2]);
  ppm_zoom_out_x2(ufo_images[2]);
  ppm_zoom_out_x2(ufo_images[2]);
  
  //
  const int nb_planet_images = 6;
  ppm_t *planet_images[nb_planet_images];
  
  planet_images[0] = ppm_open("pix/home.ppm");
  planet_images[1] = ppm_open("pix/planet.ppm");
  planet_images[2] = ppm_open("pix/moon.ppm");
  planet_images[3] = ppm_open("pix/belt1.ppm");
  planet_images[4] = ppm_open("pix/belt2.ppm");
  planet_images[5] = ppm_open("pix/belt3.ppm");

  //Scaling down
  ppm_zoom_out_x2(planet_images[0]);
  ppm_zoom_out_x2(planet_images[0]);
  ppm_zoom_out_x2(planet_images[0]);

  ppm_zoom_out_x2(planet_images[1]);
  ppm_zoom_out_x2(planet_images[1]);

  ppm_zoom_out_x2(planet_images[2]);
  ppm_zoom_out_x2(planet_images[2]);

  ppm_zoom_out_x2(planet_images[3]);
  ppm_zoom_out_x2(planet_images[3]);
  
  ppm_zoom_out_x2(planet_images[4]);
  ppm_zoom_out_x2(planet_images[4]);
  
  ppm_zoom_out_x2(planet_images[5]);

  //
  for (int i = 0; i < nb_vehicles; i++)
    {
      //Assign a UFO image
      int pos = randxy(0, nb_ufo_images - 1);
      init_vehicle(&v[i], ufo_images[pos]);
    }

  printf("\n Click to place a random object on the screen.\n");
  printf("\n Objects and vehicles are picked randomly.\n");
  
  flame_clear_display(fo);
  
  //
  while (1)
    {
      if (XPending(fo->display) > 0)
	{
	  XNextEvent(fo->display, &event);
	  
	  if (event.type == KeyPress)
	    {
	      c = XLookupKeysym(&event.xkey, 0);
	      
	      if (c == 'q')
		break;
	    }
	  else
	    if (event.type == ButtonPress)
	      {
		prev_click_x = click_x;
		prev_click_y = click_y;

		click_x = event.xkey.x;
		click_y = event.xkey.y;		  

		//Create a planet

		planets[nb_planets].x = click_x;
		planets[nb_planets].y = click_y;

		//Assign a planet image
		planets[nb_planets].image = planet_images[randxy(0, nb_planet_images - 1)];
		
		nb_planets++;
	      }
	}
      else
	{
	  for (int i = 0; i < nb_planets; i++)
	    ppm_draw(fo, planets[i].x -  planets[i].image->w / 2, planets[i].y -  planets[i].image->h / 2, planets[i].image);
	  
	  for (int i = 0; i < nb_vehicles; i++)
	    for (int j = 0; j < nb_planets; j++)
	      {
		{
		  //Go to the closest planet
		  if (dist(v[i].c_x, v[i].c_y, planets[j].x, planets[j].y) < MAX_DISTANCE)
		    { 
		      seek_vehicle(&v[i], planets[j].x, planets[j].y);
		      update_vehicle(&v[i]);
		      draw_vehicle(fo, &base, &v[i]);
		    }
		}
	      }
	}
    }

  flame_close(fo);

  return 0;
}
