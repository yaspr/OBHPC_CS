#include <math.h>
#include <stdio.h>
#include <unistd.h>

#include "flame.h"

#include "pi.h"

#define G 9.8

#define ORIG_X 400
#define ORIG_Y 200

//
typedef unsigned char byte;

//Define a double pendulum system 
typedef struct double_pend_s
{
  //First ball
  double prev_p1_x;
  double prev_p1_y;

  //Position
  double p1_x;
  double p1_y;

  //Radius in meters
  double r1;

  //Mass in grams
  double m1;

  //Cord lenth in meters
  double len1;

  //Angle
  double a1;

  //Velocity
  double vel1;

  //Acceleration
  double acc1;

  //Second ball
  double prev_p2_x;
  double prev_p2_y;
  
  double p2_x;
  double p2_y;
  double r2;
  double m2;
  double len2;
  double a2;
  
  double vel2;
  
  double acc2;
  
  double g;
  
} double_pend_t;


//Draw current ball and remove (blacken) the previous one
void draw_ball(flame_obj_t *fo, double x, double y, double px, double py, double r)
{
  flame_set_color(fo, 0, 0, 0);
  for (double a = 0.0; a < 2 * PI; a += 0.1)
    flame_draw_point(fo, px + r * cos(a), py + r * sin(a));
  
  flame_set_color(fo, 255, 255, 255);
  for (double a = 0.0; a < 2 * PI; a += 0.1)
    flame_draw_point(fo, x + r * cos(a), y + r * sin(a));
}

//Draw the first cord and blacken the previous one
void draw_cord1(flame_obj_t *fo, double_pend_t *p)
{
  //Remove previous line
  flame_set_color(fo, 0, 0, 0);
  flame_draw_line(fo, ORIG_X, ORIG_Y, p->prev_p1_x, p->prev_p1_y);
  
  flame_set_color(fo, 255, 255, 255);
  flame_draw_line(fo, ORIG_X, ORIG_Y, p->p1_x, p->p1_y);
}  

//Draw the second cord and blacken the previous one
void draw_cord2(flame_obj_t *fo, double_pend_t *p)
{
  //Remove previous line
  flame_set_color(fo, 0, 0, 0);
  flame_draw_line(fo, p->prev_p1_x, p->prev_p1_y, p->prev_p2_x, p->prev_p2_y);
  
  flame_set_color(fo, 255, 255, 255);
  flame_draw_line(fo, p->p1_x, p->p1_y, p->p2_x, p->p2_y);
}  

//Initialize the system
void init_double_pend(double_pend_t *p)
{
  p->prev_p1_x = 0;
  p->prev_p1_x = 0;

  p->prev_p2_x = 0;
  p->prev_p2_x = 0;

  //First section
  p->r1   = 10;
  p->m1   = 200; 
  p->len1 = 100;
  p->a1 = PI / 4;

  p->p1_x = ORIG_X + p->len1 * sin(p->a1);
  p->p1_y = ORIG_Y + p->len1 * cos(p->a1);

  p->vel1 = 0;

  p->acc1 = 0.1;

  //Second section
  p->r2   = 20;
  p->m2   = 100; 
  p->len2 = 200;
  p->a2 = PI / 8;
  
  p->p2_x = p->p1_x + p->len2 * sin(p->a2);
  p->p2_y = p->p1_y + p->len2 * cos(p->a2);
  
  p->vel2 = 0;

  p->acc2 = -0.001;  
}

//
void update(double_pend_t *p)
{
  p->prev_p1_x = p->p1_x;
  p->prev_p1_y = p->p1_y;

  p->prev_p2_x = p->p2_x;
  p->prev_p2_y = p->p2_y;

  //Acceleration equations to simulate a double pendulum
  
  double num1, num2, num3, num4, den;
  double a1, a2;
  
  num1 = -G * (2 * p->m1 + p->m2) * sin(p->a1);
  num2 = -p->m2 * G * sin(p->a1 - 2 * p->a2);
  num3 = -2 * sin(p->a1 - p->a2) * p->m2;
  num4 = p->vel2 * p->vel2 * p->len2 + p->vel1 * p->vel1 * p->len1 * sin(p->a1 - p->a2);
  den  = p->len1 * (2 * p->m1 + p->m2 - p->m2 * cos(2 * p->a1 - 2 * p->a2));
  
  a1   = (num1 + num2 + num3 * num4) / den;

  p->acc1 = a1;
    
  num1 = 2 * sin(p->a1 - p->a2);
  num2 = p->vel1 * p->vel1 * p->len1 * (p->m1 + p->m2);
  num3 = G * (p->m1 + p->m2) * cos(p->a1);
  num4 = p->vel2 * p->vel2 * p->len2 * cos(p->a1 - p->a2);
  den  = p->len2 * (2 * p->m1 + p->m2 - p->m2 * cos(2 * p->a1 - 2 * p->a2));

  a2   = num1 * (num2 + num3 + num4) / den;

  p->acc2 = a2;
  
  p->p1_x = ORIG_X + p->len1 * sin(p->a1);
  p->p1_y = ORIG_Y + p->len1 * cos(p->a1);
  
  p->p2_x = p->p1_x + p->len2 * sin(p->a2);
  p->p2_y = p->p1_y + p->len2 * cos(p->a2);

  p->vel1 += p->acc1;
  p->vel2 += p->acc2;
	  
  p->a1   += p->vel1;
  p->a2   += p->vel2;  
}

//
int main(int argc, char **argv)
{
  char c;
  XEvent event;
  int click_x, click_y;
  int prev_click_x, prev_click_y;
  int x_min = 50, x_max = 1900;
  int y_min = 50, y_max = 1000; 
  flame_obj_t *fo = flame_open("Pendulum", x_max, y_max);

  flame_clear_display(fo);

  double_pend_t p;

 run:
  
  init_double_pend(&p);
  
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
	      }
	}
      else
	{	  
	  draw_cord1(fo, &p);
	  draw_ball(fo, p.p1_x, p.p1_y, p.prev_p1_x, p.prev_p1_y, p.r1);
	  
	  draw_cord2(fo, &p);
	  draw_ball(fo, p.p2_x, p.p2_y, p.prev_p2_x, p.prev_p2_y, p.r2);
	  
	  update(&p);

	  //Ball1 trail
	  flame_set_color(fo, 0, 0, 255);
	  flame_draw_point(fo, p.p1_x, 50 + p.p1_y);

	  //Ball2 trail
	  flame_set_color(fo, 0, 255, 0);
	  flame_draw_point(fo, p.p2_x, 100 + p.p2_y);
	  
	  usleep(100000);
	}
    }

  flame_close(fo);

  return 0;
}
