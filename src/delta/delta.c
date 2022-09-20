/*
  
 */

#include <math.h>
#include <stdio.h>
#include <unistd.h>

#include "flame.h"

#include "pi.h"

#define max(a, b) ((a) > (b)) ? (a) : (b)

#define COLOR_WHITE 0xFF
#define COLOR_BLACK 0x00

#define MAX_STARS 300
#define MAX_BOMBS 300
#define MAX_LIVES 20

#define MIN_X 10
#define MAX_X 1850

#define MIN_Y 10
#define MAX_Y 1080

//
typedef unsigned char byte;

//
typedef struct vehicle_s {

  float x;
  float y;

  float r;
  float a;

  float dx;
  float dy;
  
  float vx;
  float vy;

  float ax;
  float ay;

  float max_velocity;
  
} vehicle_t;

//
typedef struct particle_s {

  float x;
  float y;

  float r;

  float vx;
  float vy;

  float ax;
  float ay;

  //Color
  byte r_;
  byte g_;
  byte b_;

  //Alive or taken
  byte state;
  
  float max_velocity;
  
} particle_t;

//
static inline unsigned randxy(unsigned x, unsigned y)
{ return (rand() % (y - x + 1)) + x; }

//Distance between two points (Pythagoras)
static inline float dist(float x1, float y1, float x2, float y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

//
static inline void norm(float *x, float *y)
{
  float d = sqrt((*x) * (*x) + (*y) * (*y));

  (*x) /= d;
  (*y) /= d;
}

//
static inline void scale(float *x, float *y, float s)
{
  *x *= s;
  *y *= s;
}

//
static inline void limit(float *x, float *y, float s)
{
  norm(x, y);
  scale(x, y, s);
}

//
void draw_vehicle(flame_obj_t *fo, vehicle_t *v, byte r, byte g, byte b)
{
  //
  flame_set_color(fo, r, g, b);

  flame_draw_point(fo, v->x, v->y);

  //Triangle direction
  flame_draw_line(fo, v->x, v->y, v->x + v->r * cos(v->a), v->y + v->r * sin(v->a));
  
  //Delta vehicle (Triangle)
  flame_draw_line(fo,
		  v->x + v->r * cos(v->a),
		  v->y + v->r * sin(v->a),
		  v->x + v->r * cos(PI_2 + PI_3 + v->a),
		  v->y + v->r * sin(PI_2 + PI_3 + v->a));

  flame_draw_line(fo,
		  v->x + v->r * cos(v->a),
		  v->y + v->r * sin(v->a),
		  v->x + v->r * cos(PI + PI_6 + v->a),
		  v->y + v->r * sin(PI + PI_6 + v->a));

  flame_draw_line(fo,
		  v->x + v->r * cos(PI_2 + PI_3 + v->a),
		  v->y + v->r * sin(PI_2 + PI_3 + v->a),
		  v->x + v->r * cos(PI + PI_6 + v->a),
		  v->y + v->r * sin(PI + PI_6 + v->a));
}

//
void update_vehicle(vehicle_t *v)
{
  if (v->x > MIN_X && v->x < MAX_X && v->y > MIN_X && v->y < MAX_Y)
    {
      v->x += v->vx; 
      v->y += v->vy;
    }
}

//
void draw_particle(flame_obj_t *fo, particle_t *p, byte r, byte g, byte b)
{
  //
  flame_set_color(fo, r, g, b);
  
  for (float a = 0.0; a < 2 * PI; a += 0.1)
    flame_draw_point(fo, p->x + p->r * cos(a), p->y + p->r * sin(a));
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
  flame_obj_t *fo = flame_open("Delta", x_max, y_max);

  //
  int scale = 1;
  int bx = x_max >> 1, by = y_max >> 1; //Start in the middle of the screen

  //
  srand(getpid());

  //
  vehicle_t v;
  particle_t p;
  int shot = 0;
  int shot_dist = 0;

  printf("Rules\n"
	 "\t1. Get all the blue circles by putting the center point of the delta ship inside the circle.\n"
	 "\t2. Avoid putting the center point inside a white circle\n\n");
  
  printf("Controls\n"
	 "\tLeft  arrow - rotate left\n"
	 "\tRight arrow - rotate right\n"
	 "\tUp    arrow - move up\n"
	 "\tDown  arrow - move down\n"
	 "\ta           - accelerate down\n"
	 "\ts           - accelerate up\n"
	 "\tr           - restar the game\n"
	 "\tq           - quit\n"
	 );
  
 lbl_start:

  //
  flame_clear_display(fo);
  
  //
  v.x = v.y = randxy(100, 1500);
  v.r = 40;
  v.a = 0.0;

  v.vx = 0.003;
  v.vy = 0.003;

  //
  p.x = v.x + v.r * cos(v.a);
  p.y = v.y + v.r * sin(v.a);
  
  p.r = 2;
  
  p.vx = 0.1;
  p.vy = 0.1;
    
  //
  float stars_x[MAX_STARS];
  float stars_y[MAX_STARS];
  
  for (unsigned i = 0; i < MAX_STARS; i++)
    {
      stars_x[i] = randxy(20, 1900);
      stars_y[i] = randxy(20, 1000);
    }

  //
  particle_t bombs[MAX_BOMBS];

  int remain_lives = MAX_LIVES;
  particle_t lives[MAX_LIVES];

  //Init bombs
  for (unsigned i = 0; i < MAX_BOMBS; i++)
    {
      bombs[i].x = randxy(20, 1800);
      bombs[i].y = randxy(20, 1000);
      bombs[i].r = randxy(5, 30);
      
      bombs[i].r_ = 0xFF;
      bombs[i].g_ = 0xFF;
      bombs[i].b_ = 0xFF;
    }
  
  //Init lives
  for (unsigned i = 0; i < MAX_LIVES; i++)
    {
      lives[i].x = randxy(20, 1800);
      lives[i].y = randxy(20, 1000);
      lives[i].r = randxy(5, 30);

      lives[i].state = 1; //Alive
      
      lives[i].r_ = 0x00;
      lives[i].g_ = 0x00;
      lives[i].b_ = 0xFF;
    }

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
		  {
		    flame_clear_display(fo);
		    goto lbl_start;
		  }
		else
		  {
		    switch (c)
		      {
			//Left
		      case 81:
			draw_vehicle(fo, &v, 0x00, 0x00, 0x00);
			v.a -= 0.05;
			draw_vehicle(fo, &v, 0xFF, 0xFF, 0xFF);
			break;

			//Right
		      case 83:
			draw_vehicle(fo, &v, 0x00, 0x00, 0x00);
			v.a += 0.05;
			draw_vehicle(fo, &v, 0xFF, 0xFF, 0xFF);
			break;

			//Up
		      case 82:
			draw_vehicle(fo, &v, 0x00, 0x00, 0x00);

			if (v.x > MIN_X && v.x < MAX_X && v.y > MIN_Y && v.y < MAX_Y)
			  {
			    v.x += (v.r * cos(v.a)) / 10;
			    v.y += (v.r * sin(v.a)) / 10;
			  }
			else
			  {
			    v.x -= (v.r * cos(v.a)) / 10;
			    v.y -= (v.r * sin(v.a)) / 10;
			  }
			
			draw_vehicle(fo, &v, 0xFF, 0xFF, 0xFF);
			break;

			//Down
		      case 84:
			draw_vehicle(fo, &v, 0x00, 0x00, 0x00);

			if (v.x > MIN_X && v.x < MAX_X && v.y > MIN_Y && v.y < MAX_Y)
			  {
			    v.x -= (v.r * cos(v.a)) / 10;
			    v.y -= (v.r * sin(v.a)) / 10;
			  }
			else
			  {
			    v.x += (v.r * cos(v.a)) / 10;
			    v.y += (v.r * sin(v.a)) / 10;
			  }

			draw_vehicle(fo, &v, 0xFF, 0xFF, 0xFF);
			break;

		      case 'a':
			v.vx += 0.001;
			v.vy += 0.001;
			break;

		      case 's':
			v.vx -= 0.001;
			v.vy -= 0.001;
			break;
		      }
		  }
	    }
	  else //Mouse input
	    if (event.type == ButtonPress)
	      {
	      }
	}
      else
	{
	  //Draw the starry background
	  for (unsigned i = 0; i < MAX_STARS; i++)
	    flame_draw_point(fo, stars_x[i], stars_y[i]);

	  //Draw & place the bombs
	  for (unsigned i = 0; i < MAX_BOMBS; i++)
	    draw_particle(fo, &bombs[i], bombs[i].r_, bombs[i].g_, bombs[i].b_);
	  
	  //Draw & place the bombs
	  for (unsigned i = 0; i < MAX_LIVES; i++)
	    draw_particle(fo, &lives[i], lives[i].r_, lives[i].g_, lives[i].b_);

	  float d;
	  
	  //Check collision with bombs
	  for (unsigned i = 0; i < MAX_BOMBS; i++)
	    {	      
	      if ((d = dist(v.x, v.y, bombs[i].x, bombs[i].y)) <= bombs[i].r)
		{
		  bombs[i].r_ = 0xFF;
		  bombs[i].g_ = bombs[i].b_ = 0x00;
		}
	    }
	  
	  //Check collision with bombs
	  for (unsigned i = 0; i < MAX_LIVES; i++)
	    {	      
	      if (lives[i].state && (d = dist(v.x, v.y, lives[i].x, lives[i].y)) <= lives[i].r)
		{
		  lives[i].r_ = 0x00;
		  lives[i].g_ = 0x00;
		  lives[i].b_ = 0x00;

		  lives[i].state = 0; //Taken
		  
		  remain_lives--;

		  if (!remain_lives)
		    goto lbl_start;
		}
	    }

	  //Draw delta spacecraft
	  draw_vehicle(fo, &v, 0x00, 0x00, 0x00);
	  update_vehicle(&v);
	  draw_vehicle(fo, &v, 0xFF, 0xFF, 0xFF);

	  //usleep(100);
	}
    }
  
  flame_close(fo);
  
  return 0;
}
