#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rdtsc.h"

#define ITER 31

//
typedef unsigned long long u64;

//
double **load_matrix2D(char *fname, u64 *m, u64 *n)
{
  FILE *fd = fopen(fname, "rb");

  if (!fd)
    return printf("Error: cannot open file (%s)\n", fname), NULL;
  
  fscanf(fd, "%llu %llu\n", m, n);
  
  double **data = malloc(sizeof(double *) * (*m));
  
  for (u64 i = 0; data && i < (*m); i++)
    {
      data[i] = malloc(sizeof(double) * (*n));

      for (u64 j = 0; j < (*n); j++)
	fscanf(fd, "%lf ", &data[i][j]);
    }

  fclose(fd);
  
  return data;
}

//
void store_matrix2D(FILE *fd, double **data, u64 m, u64 n)
{
  fprintf(fd, "%llu %llu\n", m, n);

  for (u64 i = 0; i < m; i++)
    {
      for (u64 j = 0; j < n; j++)
	fprintf(fd, "%lf ", data[i][j]);

      fprintf(fd, "\n");
    }
}

//
void release_matrix2D(double **data, u64 m)
{
  if (data)
    {
      for (u64 i = 1; i < m; i++)
	free(data[i]);
      
      free(data);
    }
}

//
double *load_matrix1D(char *fname, u64 *m, u64 *n)
{
  FILE *fd = fopen(fname, "rb");

  if (!fd)
    return printf("Error: cannot open file (%s)\n", fname), NULL;
  
  fscanf(fd, "%llu %llu\n", m, n);
  
  double *data = malloc(sizeof(double *) * (*m) * (*n));
  
  for (u64 i = 0; data && i < (*m); i++)
    for (u64 j = 0; j < (*n); j++)
      fscanf(fd, "%lf ", &data[i * (*n) + j]);

  fclose(fd);
  
  return data;
}

//
void store_matrix1D(FILE *fd, double *data, u64 m, u64 n)
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
void release_matrix1D(double *data)
{
  if (data)
    free(data);
}

//
void transpose_matrix2D(double **data, u64 m, u64 n)
{
  double t = 0.0;

  for (u64 i = 0; i < m; i++)
    for (u64 j = i + 1; j < n; j++)
      {
	t          = data[i][j];
	data[i][j] = data[j][i];
	data[j][i] = t; 
      }
}

//
void transpose_matrix1D(double *data, u64 m, u64 n)
{
  double t = 0.0;

  for (u64 i = 0; i < m; i++)
    for (u64 j = i + 1; j < n; j++)
      {
	t               = data[i * n + j];
	data[i * n + j] = data[j * n + i];
	data[j * n + i] = t; 
      }
}

//
int main(int argc, char **argv)
{
  if (argc < 3)
    return printf("Usage: %s [input matrix] [output matrix]\n", argv[0]), -1;

  FILE *fdout = fopen(argv[2], "wb");

  if (!fdout)
    return printf("Error: cannot create file (%s)\n", argv[2]), -2;
  
  //
  u64 m2D, n2D;
  double **data2D = load_matrix2D(argv[1], &m2D, &n2D);

  if (!data2D)
    return printf("Error: cannot allocate 2D matrix\n"), -3;
  
  u64 m1D, n1D;
  double *data1D  = load_matrix1D(argv[1], &m1D, &n1D);

  if (!data1D)
    return printf("Error: cannot allocate 1D matrox\n"), -4;
  
  u64 size = sizeof(double) * m2D * n2D;
  
  //
  double after1, before1; 
  double after2, before2; 
  
  //
  before1 = rdtsc();

  for (u64 i = 0; i < ITER; i++)
    transpose_matrix1D(data1D, m1D, n1D);

  after1 = rdtsc();

  double t1  = (after1 - before1) / ITER; //Cycles per run
  double bw1 = size / t1;                 //Bytes per cycle (bandwidth)
  
  //
  before2 = rdtsc();

  for (u64 i = 0; i < ITER; i++)
    transpose_matrix2D(data2D, m2D, n2D);

  after2 = rdtsc();

  double t2  = (after2 - before2) / ITER; //Cycles per run
  double bw2 = size / t2;                 //Bytes per cycle (bandwidth)
  
  //
  printf("Cycles 1D    : %lf\n", t1);
  printf("Cycles 2D    : %lf\n\n", t2);
  
  printf("Bandwidth 1D : %lf\n", bw1);
  printf("Bandwidth 2D : %lf\n", bw2);

  //
  store_matrix2D(fdout, data2D, m2D, n2D);
  fclose(fdout);
  
  //
  release_matrix2D(data2D, m2D);
  release_matrix1D(data1D);  
  
  return 0;
}

