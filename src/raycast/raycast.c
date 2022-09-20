//
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//
#include "rdtsc.h"
#include "flame.h"
#include "pi.h"

//Controls the number of rays (lower ==> more rays)
#define ANGLE_STEP 0.05

//Controls the ray's range (higher ==> more range)
#define R 500

//4 x 8B = 32B
typedef struct bound_s { double x1; double y1; double x2; double y2; } bound_t;

//4 x 8B = 32B
typedef struct ray_s { double x1; double y1; double x2; double y2; } ray_t;

//3 x 8B + 8B (padding) = 32B 
typedef struct particle_s { double x; double y; double r; double pad; } particle_t;

//
static inline unsigned randxy(unsigned x, unsigned y)
{ return (rand() % (y - x + 1)) + x; }

//Generates the rays positions from a center
void get_rays(double x, double y, ray_t *rays, unsigned n)
{
  register unsigned i = 0;
  
  for (double a = 0.0; a < 2 * PI && i < n; a += ANGLE_STEP, i++)
    {
      rays[i].x1 = x;
      rays[i].y1 = y;

      rays[i].x2 = x + R * cos(a);
      rays[i].y2 = y + R * sin(a);      
    }
}

//
void draw_rays(flame_obj_t *fo, const ray_t *rays, unsigned n)
{  
  for (unsigned i = 0; i < n; i++)
    flame_draw_line(fo, rays[i].x1, rays[i].y1, rays[i].x2, rays[i].y2);
}

//A wall is a series of bounds/segments
void build_wall(bound_t *bounds, unsigned nb)
{
  register double px, py;

  bounds[0].x1 = randxy(10, 1900);
  bounds[0].y1 = randxy(10, 1000);

  px = bounds[0].x2 = randxy(10, 1000);
  py = bounds[0].y2 = randxy(10, 1000); 

  //
  for (unsigned i = 1; i < nb; i++)
    {
      //Bad code pattern: dependence between iterations.
      /* bounds[i].x1 = bounds[i - 1].x2; */
      /* bounds[i].y1 = bounds[i - 1].y2; */
      
      bounds[i].x1 = px;
      bounds[i].y1 = py;

      px = bounds[i].x2 = randxy(10, 1000);
      py = bounds[i].y2 = randxy(10, 1000); 
    }
}

//
void draw_wall(flame_obj_t *fo, const bound_t *bounds, unsigned nb)
{
  flame_set_color(fo, 0, 0, 255);
  
  for (unsigned i = 0; i < nb; i++)
    flame_draw_line(fo, bounds[i].x1, bounds[i].y1, bounds[i].x2, bounds[i].y2);

  flame_set_color(fo, 255, 255, 255);
}

//
void draw_particle(flame_obj_t *fo, particle_t *p)
{
  for (double a = 0.0; a < 2 * PI; a += ANGLE_STEP)
    flame_draw_point(fo, p->x + p->r * cos(a), p->y + p->r * sin(a));
}

//Line (ray) to line (bound) intersection
static inline int rb_intersect(const ray_t *r, const bound_t *b, double *x, double *y)
{
  double den =   (r->x1 - r->x2) * (b->y1 - b->y2) - (r->y1 - r->y2) * (b->x1 - b->x2);
  double t  =   ((r->x1 - b->x1) * (b->y1 - b->y2) - (r->y1 - b->y1) * (b->x1 - b->x2)) / den;
  double u  = - ((r->x1 - r->x2) * (r->y1 - b->y1) - (r->y1 - r->y2) * (r->x1 - b->x1)) / den;

  //Using t
  (*x) = r->x1 + t * (r->x2 - r->x1);
  (*y) = r->y1 + t * (r->y2 - r->y1);
  
  return (t >= 0.0 && t <= 1.0) && (u >= 0.0 && u <= 1.0);
}

//
void cast(ray_t *rays, unsigned nr, bound_t *bounds, unsigned nb)
{
  double x, y;
  
  for (unsigned i = 0; i < nr; i++)
    {
      /*
	

                                                     \ L1	
                                                  /   \
	                                      P0 /     \ P1
	          O ----------------------------/-------\------
		                               /         \
                                              /L0
					      
	   The ray being cast from O intersects the two lines (L0 & L1).
	   In this case, closest intersection point is chosen: P0.
	   
	   The current implementation avoids that issue. A ray will always intersect 
	   with the closest line first. Once that intersection is detected, the ray's 
	   (x2, y2) coordinates are updated with the coordinates of the intersection point.
	   Therefore, the new ray doesn't stretch beyond the intersection point and it cannot
	   intersect with any other line. 

                                                     \ L1	
                                                  /   \
	                                      P0 /     \ P1
	          O ----------------------------/       \
		                               /         \
                                              /L0
	   
      */
      for (unsigned j = 0; j < nb; j++)
	if (rb_intersect(&rays[i], &bounds[j], &x, &y))
	  {
	    rays[i].x2 = x;
	    rays[i].y2 = y;
	  }
    }
}

//
int main(int argc, char **argv)
{
  char c;
  int x_max = 1920, y_max = 1080;
  int click_x = randxy(10, x_max - 10), click_y = randxy(10, y_max - 10);
  flame_obj_t *fo = flame_open("Raycasting", x_max, y_max);

  //Number of rays
  unsigned nr = (unsigned)ceil(2 * PI / ANGLE_STEP);
  ray_t *rays   = malloc(sizeof(ray_t) * nr);

  //Number of bounds
  unsigned nb = 3;
  bound_t *bounds = malloc(sizeof(bound_t) * nb);
  
  //
  srand(time(NULL));

 lbl_init:
  
  build_wall(bounds, nb);
  
 lbl_entry:

  flame_clear_display(fo);
  flame_set_color(fo, 255, 255, 255);

  draw_wall(fo, bounds, nb);
  
  get_rays(click_x, click_y, rays, nr);

  cast(rays, nr, bounds, nb);

  draw_rays(fo, rays, nr);
  
  while (1)
    {
      c = flame_wait(fo, &click_x, &click_y);
            
      if (c == 1)
	{
	  printf("X: %d, Y: %d\n", click_x, click_y);

	  goto lbl_entry;
	}
      else
	if (c == 'q')
	  break;
	else
	  if (c == 'r')
	    goto lbl_init;
    }

  free(rays);
  free(bounds);
  flame_close(fo);
  
  return 0;
}

