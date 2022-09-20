#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "flame.h"

#define min(a, b) (a < b) ? (a) : (b)
#define max(a, b) (a > b) ? (a) : (b)
#define abs(a)    (a > 0) ? (a) : (-(a))

#define D      2

#define BASE_X 20
#define BASE_Y 20

#define BW_THRESHOLD 128

#define ZOOM_RECT_W 400
#define ZOOM_RECT_H 200

//
typedef unsigned char byte;

//
typedef

struct ppm_s {

  int w; //Width
  int h; //Height 
  int t; //Threshold
  byte *px; }
  
  ppm_t;

//
int randxy(int a, int b)
{
  return ((rand() % b) - a + 1) % b;
}

//
void draw_frame(flame_obj_t *fo, int w, int h)
{
  flame_set_color(fo, 255, 255, 255);
  
  int bx = BASE_X;
  int by = BASE_Y;
  
  //Horizontal
  flame_draw_line(fo, bx - D, by - D, bx + w + D, by - D);      //Top line
  flame_draw_line(fo, bx - D, by + h + D, bx + w + D, by + h + D); // Bottom line

  //Vertical
  flame_draw_line(fo, bx - D, by - D, bx - D, by + h + D);          //Left line
  flame_draw_line(fo, bx + w + D, by - D, bx + w + D, by + h + D);  //Right line
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
      
      p->px = malloc(sizeof(byte) * p->w * p->h * 3);//h lines & w columns & 3 values per pixel(RGB)
      
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

//
void ppm_save(char *fname, ppm_t *p)
{
  FILE *fd = fopen(fname, "wb");
  
  fprintf(fd, "P6\n");
  fprintf(fd, "%d %d\n", p->w, p->h);
  fprintf(fd, "%d\n", 255);

  fwrite(p->px, sizeof(byte), p->w * 3 * p->h, fd);

  fclose(fd);
}

//Super vectorizable & cachable (memory pattern)
//Very naive implementation !
//A malloc with each zoom ==> not good!
void ppm_zoom_in_x2(ppm_t *p)
{
  int l = 0, m = 0;
  //Double the width, double the hight, 3 bytes per pixel 
  byte *new_px = malloc(sizeof(byte) * (p->w << 1) * (p->h << 1) * 3);

  //Pointer hacking :) (1D ==> 2D) 
  byte (*p_px)[p->w * 3] = (byte (*)[p->w * 3]) p->px;
  byte (*p_new_px)[(p->w << 1) * 3] = (byte (*)[(p->w << 1) * 3]) new_px;
  
  for (int i = 0; i < p->h && l < (p->h << 1); i++, l += 2)
    {
      m = 0;
      
      for (int j = 0, k = 0; j < p->w && m < (p-> w << 1) * 3 ; j++, k += 3, m += 6)
	{
	  byte r = p_px[i][k];
	  byte g = p_px[i][k + 1];
	  byte b = p_px[i][k + 2];
	  
	  p_new_px[l][m]     = r;
	  p_new_px[l][m + 1] = g;
	  p_new_px[l][m + 2] = b;

	  p_new_px[l][m + 3] = r;
	  p_new_px[l][m + 4] = g;
	  p_new_px[l][m + 5] = b;
	}
      
      //
      for (int j = 0; j < (p->w << 1) * 3; j++)
	p_new_px[l + 1][j] = p_new_px[l][j];
    }
  
  free(p->px);
  
  p->w  = p->w << 1;
  p->h  = p->h << 1;
  p->px = new_px;
}

//Pick one pixel out of 2 & 1 row out of two
void ppm_zoom_out_x2(ppm_t *p)
{
  int l = 0, m = 0;
  //Double the width, double the hight, 3 bytes per pixel 
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

//Converts an image to its grayscale equivalent - better color precision
void ppm_grayscale0(ppm_t *p)
{
 int newRed, newGreen, newBlue;
  
  for (int i = 0; i < p->w * p->h * 3; i += 3)
    {
      //Convert RGB color values into grayscale for each pixel using color weights
      //Other weights: 0.59, 0.30, 0.11
      //Principle: mix different quantities of R, G, B to create a variant of gray
      newRed   = (p->px[i] * 0.299) + (p->px[i + 1] * 0.587) + (p->px[i + 2] * 0.114);  
      newGreen = (p->px[i] * 0.299) + (p->px[i + 1] * 0.587) + (p->px[i + 2] * 0.114);  
      newBlue  = (p->px[i] * 0.299) + (p->px[i + 1] * 0.587) + (p->px[i + 2] * 0.114);
      
      p->px[i]     = newRed;
      p->px[i + 1] = newGreen;
      p->px[i + 2] = newBlue;
    }
}

//Converts an image to its grayscale equivalent - inaccurate color
void ppm_grayscale1(ppm_t *p)
{
  int newRed, newGreen, newBlue;
  
  for (int i = 0; i < p->w * p->h * 3; i += 3)
    {
      //Average
      byte gray = (p->px[i] + p->px[i + 1] + p->px[i + 2]) / 3;
      
      p->px[i]     = gray;
      p->px[i + 1] = gray;
      p->px[i + 2] = gray;
    }
}

//Convert an image to its grayscale equivalent - Desaturation
void ppm_grayscale2(ppm_t *p)
{
  for (int i = 0; i < p->w * p->h * 3; i += 3)
    {
      //Gray color = (max(r, g, b) + min (r, g, b)) / 2
      byte gray = (max(max(p->px[i], p->px[i + 1]), p->px[i + 2]) + min(min(p->px[i], p->px[i + 1]), p->px[i + 2]))/ 2;

      p->px[i]     = gray;
      p->px[i + 1] = gray;
      p->px[i + 2] = gray;
    }
}

//Convert an image to its grayscale equivalent.
//Minimum or maximum decomposition - max(r, g, b) [dark] or min (r, g, b) [light]
void ppm_grayscale3(ppm_t *p)
{
  for (int i = 0; i < p->w * p->h * 3; i += 3)
    {
      byte gray = max(max(p->px[i], p->px[i + 1]), p->px[i + 2]);
      //byte gray = min(min(p->px[i], p->px[i + 1]), p->px[i + 2]);

      p->px[i]     = gray;
      p->px[i + 1] = gray;
      p->px[i + 2] = gray;
    }
}

//Convert an image to its grayscale equivalent - Pick one color out of 3 (r, g, b)
//Super fast. Used in digital cameras sensors. VERY LOW ACCURACY
void ppm_grayscale(ppm_t *p)
{
  for (int i = 0; i < p->w * p->h * 3; i += 3)
    {
      //red   --> light gray image
      //green --> dark gray image (b&w photograph) 
      //blue  --> darker gray image (old b&w photograph)
      byte gray = p->px[i + 2];
      
      p->px[i]     = gray; 
      p->px[i + 1] = gray;
      p->px[i + 2] = gray;
    }
}

//
void ppm_grayscale5(ppm_t *p)
{
  const int nb_shades = randxy(2, 255);
  const int conv_fact = 255.0 / nb_shades;
  
  for (int i = 0; i < p->w * p-> h * 3; i += 3)
    {
      int avg = (p->px[i] + p->px[i + 1] + p->px[i + 2]) / 3;
      byte gray = (int)(((float)(avg / conv_fact) + 0.5) * (float)conv_fact);

      p->px[i]     = gray;
      p->px[i + 1] = gray;
      p->px[i + 2] = gray;
    }
}

//Dither an image using Floyd-Steinberg (black & white)
void ppm_dither_bw(ppm_t *p)
{
  for (int i = 1; i < p->h - 1; i++)
    {
      for (int j = 0, k = 0; j < p->w; j++, k += 3)
	{
	  byte old_r  = p->px[i * p->w * 3 + k];
	  byte old_g  = p->px[i * p->w * 3 + k + 1];
	  byte old_b  = p->px[i * p->w * 3 + k + 2];
	  
	  //Black 0 or White 255 
	  byte bw = (((old_r + old_g + old_b) / 3) > 128) ? 255 : 0;

	  p->px[i * p->w * 3 + k]     = bw;
	  p->px[i * p->w * 3 + k + 1] = bw;
	  p->px[i * p->w * 3 + k + 2] = bw;
	  
	  float quant_error = (float)(abs(old_r - bw) + abs(old_g - bw) + abs(old_b - bw)) / 3.0;
	  
	  //Stencil
	  p->px[(i + 1) * p->w * 3 + k    ] += 1.3 * quant_error * 7 / 16;
	  p->px[(i + 1) * p->w * 3 + k + 1] += 1.3 * quant_error * 7 / 16;
	  p->px[(i + 1) * p->w * 3 + k + 2] += 1.3 * quant_error * 7 / 16;
	  
	  p->px[(i - 1) * p->w * 3 + k    ] += 1.3 * quant_error * 3 / 16;
	  p->px[(i - 1) * p->w * 3 + k + 1] += 1.3 * quant_error * 3 / 16;
	  p->px[(i - 1) * p->w * 3 + k + 2] += 1.3 * quant_error * 3 / 16;
	  
	  p->px[(i    ) * p->w * 3 + k    ] += 1.3 * quant_error * 5 / 16;
	  p->px[(i    ) * p->w * 3 + k + 1] += 1.3 * quant_error * 5 / 16;
	  p->px[(i    ) * p->w * 3 + k + 2] += 1.3 * quant_error * 5 / 16;
	  
	  p->px[(i + 1) * p->w * 3 + k    ] += 1.3 * quant_error * 1 / 16;
	  p->px[(i + 1) * p->w * 3 + k + 1] += 1.3 * quant_error * 1 / 16;
	  p->px[(i + 1) * p->w * 3 + k + 2] += 1.3 * quant_error * 1 / 16;
	}
    }
}

//
void ppm_bw_filter(ppm_t *p)
{
  for (int i = 0; i < p->w * p->h * 3; i += 3)
    {
      byte avg = (p->px[i] + p->px[i + 1] + p->px[i + 2]) / 3;

      if (avg < BW_THRESHOLD)
	{
	  p->px[i]     = 20;
	  p->px[i + 1] = 20;
	  p->px[i + 2] = 20;	  
	}
      else
	{
	  p->px[i]     = 255;
	  p->px[i + 1] = 255;
	  p->px[i + 2] = 255;	  
	}
    }
}

//
void ppm_draw(flame_obj_t *fo, ppm_t *p)
{
  int k = 0;
  
  for (int h = 0; h < p->h; h++)
    for (int w = 0; w < p->w; w++, k += 3)
      {
	flame_set_color(fo, p->px[k], p->px[k + 1], p->px[k + 2]);
	flame_draw_point(fo, BASE_X + w, BASE_Y + h);
      }
}

//Transpose the matrix (swap rows with columns) - Optimize with in-place
//More a flip than a rotate 
void ppm_rotate(ppm_t *p)
{
  int tmp;
  byte *new_px = malloc(sizeof(byte) * p->w * p->h * 3);
  
  //Pointer hacking :) (1D ==> 2D) 
  byte (*p_px)[p->w * 3] = (byte (*)[p->w * 3]) p->px;        //h x w (rows x cols)
  byte (*p_new_px)[p->h * 3] = (byte (*)[p->h * 3]) new_px; //w x h (rows x cols) 
  
  for (int i = 0, m = 0; i < p->h; i++, m += 3)
    {
      for (int j = 0, l = 0; j < p->w; j++, l += 3)
	{
	  //Swap row pixel with column pixel
	  byte r = p_px[i][l];
	  byte g = p_px[i][l + 1];
	  byte b = p_px[i][l + 2];

	  p_new_px[j][m]     = r; 
	  p_new_px[j][m + 1] = g; 
	  p_new_px[j][m + 2] = b; 
	}
    }
  
  free(p->px);
  
  //Swap height with width
  tmp  = p->w;
  p->w = p->h;
  p->h = tmp;
  
  p->px = new_px;
}

//(x, y) is the center of the rectangle, d is the 
void ppm_select_region(ppm_t *p, int x, int y, int w, int h)
{
  if (p->w * p->h > w * h)
    {
      //Check if y + h is above image heigh
      //Check if x + w is above image width
      
      //Cancel to 0 if negative 
      x -= (w >> 1); x = (x < 0) ? 0 : x;
      y -= (h >> 1); y = (y < 0) ? 0 : y; 
      
      int new_h, new_w;
      int bound_h = y + h, bound_w = x + w;
      
      if (bound_h > p->h)
	{
	  new_h   = h - (bound_h - p->h);
	  bound_h = p->h;
	}
      else
	new_h = h;
      
      if (bound_w > p->w)
	{
	  new_w   = w - (bound_w - p->w);
	  bound_w = p->w;
	}
      else
	new_w = w;
      
      byte *new_px = malloc(sizeof(byte) * new_w * new_h * 3);

      //Pointer hacking :) (1D ==> 2D) 
      byte (*p_px)[p->w * 3] = (byte (*)[p->w * 3]) p->px;        //h x w (rows x cols)
      byte (*p_new_px)[new_w * 3] = (byte (*)[new_h * 3]) new_px; //w x h (rows x cols) 

      for (int i = y, k = 0; i < bound_h; i++, k++)
	{
	  for (int j = x * 3, l = 0; j < bound_w * 3; j += 3, l += 3)
	    {
	      p_new_px[k][l]     = p_px[i][j];
	      p_new_px[k][l + 1] = p_px[i][j + 1];
	      p_new_px[k][l + 2] = p_px[i][j + 2];
	    }
	}
  
      free(p->px);
  
      p->w = new_w;
      p->h = new_h;
      p->px = new_px;
    }
}

//Event triggered on mouse click on image
void ppm_zoom_on_click(ppm_t *p, int x, int y)
{
  ppm_select_region(p, x - BASE_X, y - BASE_Y, ZOOM_RECT_W, ZOOM_RECT_H);
  ppm_zoom_in_x2(p);
}

//
int main(int argc, char **argv)
{
  if (argc < 2)
    return printf("OUPS: %s [ppm file]\n", argv[0]), -1;
  
  char c, done = 0;
  int click_x, click_y;
  int x_min =    0, y_min =    0;
  int x_max = 1920, y_max = 1080;
  flame_obj_t *fo = flame_open("PPM Viewer", x_max, y_max);
  ppm_t *ppm_image = ppm_open(argv[1]);
  
  if (!ppm_image)
    return printf("OUPS: file %s not found!\n", argv[1]), -1;
  
  srand(getpid());

  printf("List of keyboard commands:\n"
	 " i: zoom in by 2\n"
	 " o: zoom out by 2\n"
	 " a: redraw\n"
	 " b: convert to black & white\n"
	 " g: convert to grayscale\n"
	 " d: apply dithering\n"
	 " r: rotate\n"
	 " s: save file (must enter file name)\n"
	 " q: quit\n\n"
	 "A left click selects a 400x200 rectangular region and zooms on it.\n\n"
	 "/!\\ Warning: zooming out below original image resolution will "
	 "down scale the image and affect its quality.\n\n");
  
 run:
  
  flame_clear_display(fo);

  printf("# %d x %d\n", ppm_image->w, ppm_image->h);
  
  draw_frame(fo, ppm_image->w, ppm_image->h);
  
  //ppm_grayscale(ppm_image);
  ppm_draw(fo, ppm_image);
  
  while (!done)
    {
      c = flame_wait(fo, &click_x, &click_y);
      
      if (c == 1)
	{
	  printf("Click real: %d, %d\n", click_x, click_y);
	  printf("Click rela: %d, %d\n", click_x - BASE_X, click_y - BASE_Y);

	  ppm_zoom_on_click(ppm_image, click_x, click_y);
	  
	  goto run;
	}
      else
	if (c == 'q')
	  done = 1;
	else
	  if (c == 'a')
	    goto run;
	  else
	    if (c == 'i')
	      {
		ppm_zoom_in_x2(ppm_image);
		goto run;
	      }
	    else
	      if (c == 'o')
		{
		  ppm_zoom_out_x2(ppm_image);
		  goto run;
		}
	      else
		if (c == 'r')
		  {
		    ppm_rotate(ppm_image);
		    goto run;
		  }
		else
		  if (c == 'd')
		    {
		      ppm_dither_bw(ppm_image);
		      goto run;
		    }
		  else
		    if (c == 'g')
		      {
			ppm_grayscale(ppm_image);
			goto run;
		      }
		    else
		      if (c == 'b')
			{
			  ppm_bw_filter(ppm_image);
			  goto run;
			}
		      else
			if (c == 's')
			  {
			    byte path[1024];
			    
			    printf("Output ppm file path: ");
			    scanf("%s", path);
			    
			    ppm_save(path, ppm_image);
			    
			    goto run;
			  }
    }
  
  flame_close(fo);
  
  return 0;
}
