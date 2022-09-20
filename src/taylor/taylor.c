#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flame.h"

//
typedef unsigned long long u64;

//
double power(double x, u64 p)
{
  double _x_= x;
  
  for (u64 i = 0; p && i < p - 1; i++)
    _x_ *= x;

  return (p) ? _x_ : 1;
}

//n! = n * (n - 1) * (n - 2) * ... * 2
double fact(double n)
{
  double v = n;
  
  for (double i = n - 1; n && i >= 2; i--)
    v *= i;

  return (n) ? v : 1;
}

//
double _sin_(double x, u64 n)
{
  double v = 0.0;
  
  for (u64 i = 0; i < n; i++)
    v += (power(-1.0, i) / fact(2.0 * i + 1.0)) * power(x, 2 * i + 1); 
  
  return v;  
}

//
double _cos_(double x, u64 n)
{
  double v = 0.0;

  for (u64 i = 0; i < n; i++)
    v += (power(-1.0, i) / fact(2.0 * i)) * power(x, 2 * i);
  
  return v;
}

//
double _exp_(double x, u64 n)
{
  double v = 0.0;

  for (u64 i = 0; i < n; i++)
    v += (power(x, i) / fact(i));
  
  return v;
}

//
double _sinh_(double x, u64 n)
{
  double v = 0.0;

  for (u64 i = 0; i < n; i++)
    v += power(x, 2 * i + 1) /fact(2 * i + 1);

  return v;
}

//
void cos_draw(flame_obj_t *fo, double x, u64 scale, u64 x_max, u64 y_max, u64 n)
{  
  double y1 = cos(x);
  double y2 = _cos_(x, n);

  double d_x  = (double)100 + (x * scale);
  double d_y1 = (double)400 - (y1 * scale);
  double d_y2 = (double)400 - (y2 * scale);

  if (d_x < x_max && d_y1 > 0 && d_y1 < y_max)
    {
      flame_set_color(fo, 255, 255, 255);
      flame_draw_point(fo, d_x, d_y1);
    }

  if (d_x < x_max && d_y2 > 0 && d_y2 < y_max)
    {
      flame_set_color(fo, 0, 0, 255);
      flame_draw_point(fo, d_x, d_y2);
    }
}

//
void sin_draw(flame_obj_t *fo, double x, u64 scale, u64 x_max, u64 y_max, u64 n)
{
  double y1 = sin(x);
  double y2 = _sin_(x, n);

  double d_x  = (double)300 + (x * scale);
  double d_y1 = (double)400 - (y1 * scale);
  double d_y2 = (double)400 - (y2 * scale);

  if (d_x < x_max && d_y1 > 0 && d_y1 < y_max)
    {
      flame_set_color(fo, 255, 255, 255);
      flame_draw_point(fo, d_x, d_y1);
    }

  if (d_x < x_max && d_y2 > 0 && d_y2 < y_max)
    {
      flame_set_color(fo, 0, 255, 0);
      flame_draw_point(fo, d_x, d_y2);
    }
}

//
void exp_draw(flame_obj_t *fo, double x, u64 scale, u64 x_max, u64 y_max, u64 n)
{
  double y1 = exp(x);
  double y2 = _exp_(x, n);

  double d_x  = (double)500 + (x * scale);
  double d_y1 = (double)400 - (y1 * scale);
  double d_y2 = (double)400 - (y2 * scale);

  if (d_x < x_max && d_y1 > 0 && d_y1 < y_max)
    {
      flame_set_color(fo, 255, 255, 255);
      flame_draw_point(fo, d_x, d_y1);
    }

  if (d_x < x_max && d_y2 > 0 && d_y2 < y_max)
    {
      flame_set_color(fo, 255, 0, 0);
      flame_draw_point(fo, d_x, d_y2);
    }
}

//
void sinh_draw(flame_obj_t *fo, double x, u64 scale, u64 x_max, u64 y_max, u64 n)
{
  double y1 = sinh(x);
  double y2 = _sinh_(x, n);

  double d_x  = (double)700 + (x * scale);
  double d_y1 = (double)400 - (y1 * scale);
  double d_y2 = (double)400 - (y2 * scale);

  if (d_x < x_max && d_y1 > 0 && d_y1 < y_max)
    {
      flame_set_color(fo, 255, 255, 255);
      flame_draw_point(fo, d_x, d_y1);
    }

  if (d_x < x_max && d_y2 > 0 && d_y2 < y_max)
    {
      flame_set_color(fo, 255, 255, 0);
      flame_draw_point(fo, d_x, d_y2);
    }
}

//
int main(int argc, char **argv)
{
  char c;

  //Event for keyboard & mouse interruptions
  XEvent event;
  
  //Set display size
  int x_max = 1920, y_max = 1080;

  //Initialize display
  flame_obj_t *fo = flame_open("Taylor series", x_max, y_max);

  //
  int scale = 10;
  int bx = x_max >> 1, by = y_max >> 1; //Start in the middle of the screen

  u64 n;
  
 lbl_init:
  
  n = 0;

  flame_clear_display(fo);
  
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
		  goto lbl_init;
		  
	    }
	  else //Mouse input
	    if (event.type == ButtonPress)
	      {
	      }
	}
      else
	{

	  for (double x = -2 * 3.14; x < 2 * 3.14; x += 0.001)
	    {
	      cos_draw(fo, x, scale, x_max, y_max, n);
	      sin_draw(fo, x, scale, x_max, y_max, n);
	      exp_draw(fo, x, scale, x_max, y_max, n);
	      sinh_draw(fo, x, scale, x_max, y_max, n);
	      
	      usleep(100);
	    }

	  printf("Iterations: %llu\n", n);
	  
	  n++;
	}
    }

  flame_close(fo);
  
  return 0;
}
