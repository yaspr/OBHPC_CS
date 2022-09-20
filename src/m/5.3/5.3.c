#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rdtsc.h"

//
typedef unsigned char byte;
typedef unsigned long long u64;

//
void init_matrix(double *data, double c, u64 m, u64 n)
{
  for (u64 i = 0; i < m * n; i++)
    data[i] = c;
}

//
double *load_matrix(FILE *fd, u64 *m, u64 *n)
{
  fscanf(fd, "%llu %llu\n", m, n);
  
  double *data = malloc(sizeof(double) * (*m) * (*n));
  
  for (u64 i = 0; data && i < (*m); i++)
    for (u64 j = 0; j < (*n); j++)
      fscanf(fd, "%lf ", &data[i * (*n) + j]);
  
  return data;
}

//
void store_matrix(FILE *fd, double *data, u64 m, u64 n)
{
  fprintf(fd, "%llu %llu\n", m, n);

  for (u64 i = 0; i < m; i++)
    {
      for (u64 j = 0; j < n; j++)
	fprintf(fd, "%lf ", data[i * n + j]);
      
      fprintf(fd, "\n");
    }
}

//
void release_matrix(double *data)
{
  if (data)
    free(data);
}

//
void mm_mul1(double *a, double *b, double *c, u64 n)
{
  for (u64 i = 0; i < n; i++)
    for (u64 j = 0; j < n; j++)
      for (u64 k = 0; k < n; k++)
	c[i * n + j] += a[i * n + k] * b[k * n + j];
}

//
void mm_mul2(double *a, double *b, double *c, u64 n)
{
  for (u64 i = 0; i < n; i++)
    for (u64 k = 0; k < n; k++)
      for (u64 j = 0; j < n; j++)
	c[i * n + j] += a[i * n + k] * b[k * n + j];
}

//
byte mm_compare(double *A, double *B, u64 m, u64 n, int *r, int *c)
{
  byte cmp = 1;
  int row = -1, col = -1;
  
  for (u64 i = 0; cmp && i < m; i++)
    for (u64 j = 0; cmp && j < n; j++)
      {
	cmp = (A[i * n + j] == B[i * n + j]);
	row = (cmp) ? -1 : i;
	col = (cmp) ? -1 : j;
      }

  (*r) = row;
  (*c) = col;
  
  return cmp;
}

//
int main(int argc, char **argv)
{
  if (argc < 4)
    return printf("Usage: [input matrix] [input matrix] [output matrix]\n", argv[0]), -1;

  //
  FILE *m1fd = fopen(argv[1], "rb");
  FILE *m2fd = fopen(argv[2], "rb");
  FILE *mofd = fopen(argv[3], "wb");

  //
  if (!m1fd)
    return printf("Error: cannot open file (%s)\n", argv[1]), -2;
  
  if (!m2fd)
    return printf("Error: cannot open file (%s)\n", argv[2]), -2;

  if (!mofd)
    return printf("Error: cannot create file (%s)\n", argv[3]), -2;

  //
  u64 rep = 1;
  double before1, after1;
  double before2, after2;

  u64 A_m, A_n;
  double *A = load_matrix(m1fd, &A_m, &A_n);
  
  u64 B_m, B_n;
  double *B = load_matrix(m2fd, &B_m, &B_n);

  u64 C_m = A_m, C_n = A_n;
  double *C = malloc(sizeof(double) * C_m * C_n);

  u64 D_m = A_m, D_n = A_n;
  double *D = malloc(sizeof(double) * D_m * D_n);

  if (A_m != A_n)
    return printf("Error: the matrix must be square"), -3;

  //Repeat if size dimension isn't heavy enough
  if (A_m < 1000)
    rep = 31;
  
  //
  init_matrix(C, 0.0, C_m, C_n);
  
  //
  before1 = rdtsc();

  for (u64 r = 0; r < rep; r++)
    mm_mul1(A, B, C, A_n);
  
  after1 = rdtsc();

  double t1 = (after1 - before1) / rep;
  
  //
  init_matrix(D, 0.0, D_m, D_n);

  //
  before2 = rdtsc();
  
  for (u64 r = 0; r < rep; r++)
    mm_mul2(A, B, D, A_n);

  after2 = rdtsc();

  double t2 = (after2 - before2) / rep;
  
  //Checking the output of both algorithms  
  int r, c;

  if (mm_compare(C, D, C_m, C_n, &r, &c))    
    store_matrix(mofd, C, C_m, C_n);
  else
    return printf("Error: the algorithms do not return the same result, mismatch at (%d, %d)\n", r, c), -4;

  //Total memory size in bytes: size of an element * Number of elements * Number of matrices (in, in, out) 
  u64 memsize = sizeof(double) * A_m * A_n * 3;
  
  //
  printf("Cycles mul1             : %lf\n"  , t1);
  printf("Cycles mul2             : %lf\n\n", t2);

  double i1 = t1 / (A_m * A_n * A_n);
  double i2 = t2 / (A_m * A_n * A_n);
  
  //
  printf("Cycles per iteration 1  : %lf\n"  , i1);
  printf("Cycles per iteration 2  : %lf\n\n", i2);
  
  printf("Speedup                 : %lf\n\n", t1 / t2);

  printf("Memory size             : %llu B, %llu KiB, %llu MiB, %llu GiB\n\n",
	 memsize,
	 memsize >> 10,
	 memsize >> 20,
	 memsize >> 30);
  
  printf("Bytes per cycle 1       : %lf\n"  , (double)memsize / t1);
  printf("Bytes per cycle 2       : %lf\n\n", (double)memsize / t2);

  char metric1, metric2;

  if(memsize >= (1 << 10) && memsize < (1 << 20))
    {
      memsize >>= 10;
      metric1 = 'K';
      metric2 = 'i';
    }
  else //Between 1M & 1G
    if (memsize >= (1 << 20) && memsize < (1 << 30))
      {
	memsize >>= 20;
	metric1 = 'M';
	metric2 = 'i';
   }
    else //Above 1G
      if (memsize >= (1 << 30))
	{
	  memsize >>= 30;
	  metric1 = 'G';
	  metric2 = 'i';
	}
  
  printf("%c%cBytes per iteration 1 : %lf\n", metric1, metric2, (double)(memsize) / i1);
  printf("%c%cBytes per iteration 2 : %lf\n", metric1, metric2, (double)(memsize) / i2);

  //
  release_matrix(A);
  release_matrix(B);
  release_matrix(C);
  release_matrix(D);
  
  //
  fclose(m1fd);
  fclose(m2fd);
  fclose(mofd);
  
  return 0;
}
