#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
#define MAX_GRAY_LVL 256

//
#define max(a, b) ((a) > (b)) ? (a) : (b)

//
typedef unsigned u32;
typedef unsigned char byte;
typedef unsigned long long u64;

//
typedef struct pgm_s { u64 h; u64 w; u64 t; byte *p; } pgm_t;

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
void pgm_hist(pgm_t *in, int *hist)
{
  for (u64 i = 0; i < MAX_GRAY_LVL; i++)
    hist[i] = 0;
  
  for (u64 i = 0; i < in->h * in->w; i++)
    {
      byte pixel = in->p[i];

      hist[pixel]++;
    }
}

//
int main(int argc, char **argv)
{
  //
  if (argc < 3)
    return printf("Usage: %s [input pgm] [output]\n", argv[0]), -1;

  int hist[MAX_GRAY_LVL];
  pgm_t *p_in = pgm_open(argv[1]);
  FILE *fdout = fopen(argv[2], "wb");
  
  pgm_hist(p_in, hist);

  for (u64 i = 0; i < MAX_GRAY_LVL; i++)
    fprintf(fdout, "%llu\t%d\n", i, hist[i]);
  
  pgm_close(p_in);

  fclose(fdout);
  
  return 0;
}
