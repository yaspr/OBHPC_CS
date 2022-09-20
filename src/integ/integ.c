/*
  Integration using the Trapezoidal rule
         __
       /   b
      /      f(x) dx = (b - a) * (f(a) + f(b)) / 2 
   __/ a

   The purpose is to approximate the function's surface using
   multiple trapezoids.
   
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "flame.h"

//Function to integrate
float f(float x)
{
  return (x) ? sin(x) / x : 1;
}

//
int main(int argc, char **argv)
{
  char c;
  int click_x, click_y;
  int x_max = 1920, y_max = 1080;
  flame_obj_t *fo = flame_open("Integration", x_max, y_max);

  int y_max_2 = y_max >> 1;

  //Number of iterations
  int n = 10;
  float x, y, x1, y1, delx, a, b, s;

  printf("\n\t'u' to increment the number iterations\n\t'd' to decrement the number iterations\n\n");
  
 lbl1:

  flame_clear_display(fo);
  
  a = 0;
  b = 20;
  s = 0;
  
  //
  flame_set_color(fo, 255, 255, 255);
  
  //Draw plane
  flame_draw_line(fo, 0, 0, 0, y_max); 
  flame_draw_line(fo, 0, y_max_2, x_max, y_max_2); 

  //Drawing the function
  for (int i = 0; i < x_max; i++)
    {
      x = i * b / x_max;
      y = f(x);

      flame_draw_line(fo, i, (-y_max_2) * y + y_max_2, i, y_max_2);
    }

  delx = (b - a) / n;
  y = f(a);

  //
  flame_set_color(fo, 0, 128, 0);
  
  for (int i = 0; i < n;)
    {
      s += delx * y / 2;

      flame_draw_line(fo, i * x_max / n, (-y_max_2) * y + y_max_2, i * x_max / n, y_max_2);
      i++;

      x1 = a + i * delx;
      y1 = f(x1);

      s += delx * y1 / 2;
      flame_draw_line(fo, i * x_max / n, (-y_max_2) * y1 + y_max_2, i * x_max / n, y_max_2);

      //
      if (signbit(y) == signbit(y1))
	{
	  flame_draw_line(fo, (i - 1) * x_max / n, (-y_max_2) * y + y_max_2, i * x_max / n, (-y_max_2) * y1 + y_max_2);
	  flame_draw_line(fo, (i - 1) * x_max / n, y_max_2, i * x_max / n, y_max_2);
	}
      else
	{
	  flame_draw_line(fo, (i - 1) * x_max / n, (-y_max_2) * y + y_max_2, i * x_max / n, y_max_2);
	  flame_draw_line(fo, (i - 1) * x_max / n, y_max_2, i * x_max / n,  (-y_max_2) * y1 + y_max_2);
	}
      
      //
      y = y1;
    }

  printf("Iterations: %d\tApproximated surface: %lf\n", n, s);
  
  c = flame_wait(fo, &click_x, &click_y);

  if (c == 'q')
    ;
  else
    {
      if (c == 'u')
	n++;
      if
	(c == 'd')
	n -= (n) ? 1 : 0; 
      
      goto lbl1;
    }
  
  flame_close(fo);

  return 0;
}
