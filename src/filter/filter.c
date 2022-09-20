#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILTER_W 3
#define FILTER_H 3

#define max(a, b) ((a) > (b)) ? (a) : (b)

//2D access in a 1D array
#define INDEX(x, y, w) (((x) * (w)) + (y))

#define max(a, b) ((a) > (b)) ? (a) : (b)

//
typedef unsigned u32;
typedef unsigned char byte;
typedef unsigned long long u64;

//
typedef struct pgm_s { u64 h; u64 w; u64 t; byte *p; } pgm_t;

//
int filter_edge1[FILTER_H * FILTER_W] = { 1, 0, -1,
					  0, 0,  0,
					 -1, 0,  1    };

int filter_edge2[FILTER_H * FILTER_H] = { 0,  1, 0,
					  1, -4, 1,
					  0,  1, 0    };

int filter_edge3[FILTER_H * FILTER_H] = { -1, -1, -1,
					  -1,  8, -1,
					  -1, -1, -1  };

//
int filter_sharp[FILTER_H * FILTER_W] = {  0, -1,  0,
					  -1,  5, -1,
					   0, -1,  0  };

//
int filter_box_blur_sum = 9;
int filter_box_blur[FILTER_H * FILTER_W] = {  1, 1, 1,
					      1, 1, 1,
					      1, 1, 1  };

//
int filter_gauss_blur_sum = 16;
int filter_gauss_blur[FILTER_H * FILTER_W] = {  1, 2, 1,
						2, 4, 2,
						1, 2, 1  };

//Convolution of two matrices (dotprod/FMA)
int convolve(byte *m, u64 mh, u64 mw, int *f, u64 fh, u64 fw)
{
  int r = 0;
  
  for (u64 i = 0; i < fh; i++)
    for (u64 j = 0; j < fw; j++)
      r += m[INDEX(i, j, mw)] * f[INDEX(i, j, fw)];
  
  return r;
}

//
pgm_t *pgm_open(char *fname)
{
  char c1, c2;
  pgm_t *p = NULL;
  FILE *fd = fopen(fname, "rb");

  if (fd)
    {
      p = malloc(sizeof(pgm_t));
      
      //P5
      fscanf(fd, "%c%c", &c1, &c2);
      
      fscanf(fd, "%llu %llu\n", &p->w, &p->h);
      
      fscanf(fd, "%llu\n", &p->t);
  
      p->p = malloc(sizeof(byte) * p->h * p->w);
  
      fread(p->p, sizeof(byte), p->h * p->w, fd);
  
      fclose(fd);
    }
  
  return p;
}

//
void pgm_save(char *fname, pgm_t *p)
{
  FILE *fd = fopen(fname, "wb");

  if (fd)
    {
      fprintf(fd, "P5\n");
      
      fprintf(fd, "%llu %llu\n", p->w, p->h);
      
      fprintf(fd, "%llu\n", p->t);
      
      fwrite(p->p, sizeof(byte), p->h * p->w, fd);
      
      fclose(fd);
    }
}

//
pgm_t *pgm_create(u64 h, u64 w, u64 t)
{
  pgm_t *p = malloc(sizeof(pgm_t));

  p->h = h;
  p->w = w;
  p->t = t;

  p->p = malloc(sizeof(byte) * w * h);
  
  return p;
}

//
void pgm_close(pgm_t *p)
{
  if (p)
    {
      if (p->p)
	free(p->p);

      free(p);
    }
}

//
void pgm_apply_filter(byte *img_in, u64 h, u64 w, int *f, u64 fh, u64 fw, byte *img_out, int sum)
{
  for (u64 i = 0; i < h - fh; i++)
    for (u64 j = 0; j < w - fw; j++)
      img_out[INDEX(i, j, w)] = (convolve(&img_in[INDEX(i, j, w)], h, w, f, fh, fw) / sum);
}

//
void pgm_apply_sobel_filter(byte *img_in, byte *img_out, u64 h, u64 w, float threshold)
{
  int gx, gy;
  int f1[9] = { -1, 0, 1,
		-2, 0, 2,
		-1, 0, 1 }; //3x3 matrix
  int f2[9] = { -1, -2, -1,
		0, 0, 0,
		1, 2, 1 }; //3x3 matrix
  
  for (u64 i = 0; i < h - 3; i++)
    for (u64 j = 0; j < w - 3; j++)
      {
	gx = convolve(&img_in[INDEX(i, j, w)], h, w, f1, 3, 3);
	gy = convolve(&img_in[INDEX(i, j, w)], h, w, f2, 3, 3);
	
	double mag = sqrt((gx * gx) + (gy * gy));
	
	img_out[INDEX(i, j, w)] = (mag > threshold) ? 255 : mag;
      }
}

//
void pgm_apply_prewitt_filter(byte *img_in, byte *img_out, u64 h, u64 w, float threshold)
{
  int gx, gy;
  int f1[9] = { 1, 0, -1, 1, 0, -1,  1,  0, -1 }; //3x3 matrix
  int f2[9] = { 1, 1,  1, 0, 0,  0, -1, -1, -1 }; //3x3 matrix
  
  for (u64 i = 0; i < h - 3; i++)
    for (u64 j = 0; j < w - 3; j++)
      {
	gx = convolve(&img_in[INDEX(i, j, w)], h, w, f1, 3, 3);
	gy = convolve(&img_in[INDEX(i, j, w)], h, w, f2, 3, 3);
	
	double mag = sqrt((gx * gx) + (gy * gy));
	
	img_out[INDEX(i, j, w)] = (mag > threshold) ? 255 : mag;
      }
}

//Rotate the initial matrix by 45° (8 entries)
void pgm_apply_kirsch_filter(byte *img_in, byte *img_out, u64 h, u64 w)
{
  int max_g;
  int g[8] = { 0 };
  int f[8][9] = {
		 {   5,  5,  5,
		    -3,  0, -3,
		    -3, -3, -3 },
  
		 {   5,  5, -3,
		     5,  0, -3,
		    -3, -3, -3 },
  
		 {   5, -3, -3,
		     5,  0, -3,
		     5, -3, -3 },
  
		 {  -3, -3, -3,
		     5,  0, -3,
		     5,  5, -3 },
	       
		 {  -3, -3, -3,
		    -3,  0, -3,
		     5,  5,  5 },

		 {  -3, -3, -3,
		    -3,  0,  5,
		    -3,  5,  5 },
  
		 {  -3, -3, 5,
		    -3,  0, 5,
		    -3, -3, 5 },
  
		 {  -3,  5,  5,
		    -3,  0,  5,
		    -3, -3, -3 } }; 

  for (u64 i = 0; i < h - 3; i++)
    for (u64 j = 0; j < w - 3; j++)
      {
	for (u64 k = 0; k < 8; k++)
	  g[k] = convolve(&img_in[INDEX(i, j, w)], h, w, f[k], 3, 3);

	max_g = g[0];
	
	for (u64 k = 1; k < 8; k++)
	  max_g = max(max_g, g[k]);
	
	img_out[INDEX(i, j, w)] = max_g >> 2;
      }
}

//
int main(int argc, char **argv)
{
  if (argc < 4)
    return printf("Usage: [mode] [input pgm] [output pgm]\n"
		  "\nmodes   :\n"
		  "\t-sobel  : apply Sobel filter\n"
		  "\t-edge1  : apply first edge filter\n"
		  "\t-edge2  : apply second edge filter\n"
		  "\t-edge3  : apply third edge filter\n"
		  "\t-sharp  : apply sharpening filter\n"
		  "\t-bblur  : apply box blur\n"
		  "\t-gblur  : apply Gaussian blur\n"
		  "\t-kirsch : apply Kirsch filter\n"
		  "\t-prewitt: apply Prewitt filter\n", argv[0]), -1;

  pgm_t *p_in  = pgm_open(argv[2]);

  if (!p_in)
    return printf("Error: cannot open pgm file (%s)\n", argv[2]), -2;
  
  pgm_t *p_out = pgm_create(p_in->h, p_in->w, p_in->t);

  printf("Resolution: %llu Pixels, %llu MPixels\n", (p_in->h * p_in->w), (p_in->h * p_in->w) / 1000000);
  
  if (!strncmp(argv[1], "-sobel", 6))
    pgm_apply_sobel_filter(p_in->p, p_out->p, p_in->h, p_in->w, 100);
  else
    if (!strncmp(argv[1], "-edge1", 6))
      pgm_apply_filter(p_in->p, p_in->h, p_in->w, filter_edge1, FILTER_H, FILTER_W, p_out->p, 30);
    else
      if (!strncmp(argv[1], "-edge2", 6))
	pgm_apply_filter(p_in->p, p_in->h, p_in->w, filter_edge2, FILTER_H, FILTER_W, p_out->p, 30);
      else
	if (!strncmp(argv[1], "-edge3", 6))
	  pgm_apply_filter(p_in->p, p_in->h, p_in->w, filter_edge3, FILTER_H, FILTER_W, p_out->p, 30);
	else
	  if (!strncmp(argv[1], "-sharp", 6))
	    pgm_apply_filter(p_in->p, p_in->h, p_in->w, filter_sharp, FILTER_H, FILTER_W, p_out->p, 1);
	  else
	    if (!strncmp(argv[1], "-bblur", 6))
	      pgm_apply_filter(p_in->p, p_in->h, p_in->w, filter_box_blur, FILTER_H, FILTER_W, p_out->p, filter_box_blur_sum);
	    else
	      if (!strncmp(argv[1], "-gblur", 6))
		pgm_apply_filter(p_in->p, p_in->h, p_in->w, filter_gauss_blur, FILTER_H, FILTER_W, p_out->p, filter_gauss_blur_sum);
	      else
		if (!strncmp(argv[1], "-kirsch", 7))
		  pgm_apply_kirsch_filter(p_in->p, p_out->p, p_in->h, p_in->w);
		else
		  if (!strncmp(argv[1], "-prewitt", 8))
		    pgm_apply_prewitt_filter(p_in->p, p_out->p, p_in->h, p_in->w, 100);
		  else
		    return printf("Usage: [mode] [input pgm] [output pgm]\n"
				  "\nmodes:\n"
				  "\t-sobel  : apply Sobel filter\n"
				  "\t-edge1  : apply first edge filter\n"
				  "\t-edge2  : apply second edge filter\n"
				  "\t-edge3  : apply third edge filter\n"
				  "\t-sharp  : apply sharpening filter\n"
				  "\t-bblur  : apply box blur\n"
				  "\t-gblur  : apply Gaussian blur\n"
				  "\t-kirsch : apply Kirsch filter\n"
				  "\t-prewitt: apply Prewitt filter\n", argv[0]), -1;
  //
  pgm_save(argv[3], p_out);

  //
  pgm_close(p_in);
  pgm_close(p_out);
  
  return 0;
}
