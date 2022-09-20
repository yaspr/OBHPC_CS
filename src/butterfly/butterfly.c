/*
  Butterfly transcendental plane curve
  
  x = sin(t) * (e^cos(t) - (2 * cos(4 * t)) - sin(t / 12)^5)
  y = cos(t) * (e^cos(t) - (2 * cos(4 * t)) - sin(t / 12)^5)

  with  0 <= t <= 12 * Pi
  
 */

#include <math.h>
#include <stdio.h>
#include <unistd.h>

#include "flame.h"

#include "pi.h"

#define max(a, b) ((a) > (b)) ? (a) : (b)

//
typedef unsigned char byte;

//
static inline unsigned randxy(unsigned x, unsigned y)
{ return (rand() % (y - x + 1)) + x; }

//
void draw_butterfly(flame_obj_t *fo, int bx, int by, int scale, byte r, byte g, byte b)
{
  float x, y;
  
  for (float t = 0.0; t <= 12 * PI; t += 0.01)
    {
      float c = exp(cos(t)) - (2 * cos(4 * t)) - pow(sin(t / 12), 5);

      x = sin(t) * c;
      y = cos(t) * c;

      //Set the pixel color
      flame_set_color(fo, r, g, b);

      //Draw the pixel
      flame_draw_point(fo, bx + (x * scale), by - (y * scale));
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
  flame_obj_t *fo = flame_open("Butterfly", x_max, y_max);

  //
  int scale = 1;
  int bx = x_max >> 1, by = y_max >> 1; //Start in the middle of the screen

  byte r = 0, g = 0, b = 0;
  
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
	  //Random colors
	  r = randxy(50, 255);
	  g = randxy(50, 255);
	  b = randxy(50, 255);

	  //
	  draw_butterfly(fo, bx, by, scale++, r, g, b);

	  usleep(10000);
	}
    }
  
  flame_close(fo);

  return 0;
}
