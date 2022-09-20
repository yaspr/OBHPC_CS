/*
  Cholesky decomposition of a matrix:

  A = L . L*
  
  or 
  
  A = L . transpose(L)

  This program implements the Cholesky decomposition and calculates the L matrix.x

 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
typedef unsigned u32;
typedef unsigned long long u64;

//
double **alloc_matrix(u64 m, u64 n)
{
  double **p = malloc(sizeof(double *) * m);

  for (u64 i = 0; i < m; i++)
    p[i] = malloc(sizeof(double) * n);
  
  return p;
}

//
double **load_matrix(FILE *fd, u64 *m, u64 *n)
{
  //Read the number of rows (m), then the number of columns (n)
  fscanf(fd, "%llu %llu\n", m, n);

  //Allocate m pointers for rows
  double **data = malloc(sizeof(double *) * (*m));

  //Allocate and load data into rows
  for (u64 i = 0; data && i < (*m); i++)
    {
      //Allocate memory
      data[i] = malloc(sizeof(double) * (*n));

      //Load data 
      for (u64 j = 0; j < (*m); j++)
	fscanf(fd, "%lf ", &data[i][j]);
    }
  
  return data;
}

//
void print_matrix(double **a, u64 m, u64 n)
{
  printf("%llu %llu\n", m, n);
  
  for (u64 i = 0; i < m; i++)
    {
      for (u64 j = 0; j < n; j++)
	printf("%lf ", a[i][j]);

      printf("\n");
    }
}

//
void store_matrix(FILE *fd, double **data, u64 m, u64 n)
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
void release_matrix(double **data, u64 m)
{
  if (data)
    {
      //Free rows
      for (u64 i = 1; i < m; i++)
	free(data[i]);

      //Free pointer
      free(data);
    }
}

//
double **cholesky(double **A, double **L, u64 n)
{ 
  for (u64 i = 0; i < n; i++)
    for (u64 j = 0; j < (i + 1); j++)
      {
	double s = 0;
	
	for (u64 k = 0; k < j; k++)
	  s += L[i][k] * L[j][k];
	
	L[i][j] = (i == j) ? sqrt(A[i][i] - s) : (1.0 / L[j][j] * (A[i][j] - s));
      }
  
  return L;
}

//
int main(int argc, char **argv)
{
  if (argc < 3)
    return printf("Usage: %s [input matrix] [output matrix]\n", argv[0]), -1;

  FILE *mfd = fopen(argv[1], "rb");
  FILE *lfd = fopen(argv[2], "wb");

  //
  if (!mfd)
    return printf("Error: cannot open file (%s)\n", argv[1]), -2;
  
  if (!lfd)
    return printf("Error: cannot create file (%s)\n", argv[2]), -2;

  //
  u64 A_m, A_n;
  double **A = load_matrix(mfd, &A_m, &A_n);

  if (A_m != A_n)
    return printf("Error: the number of rows and the number of columns must be identical\n"), -4;
  
  double **L = alloc_matrix(A_m, A_n);

  //
  cholesky(A, L, A_m);

  store_matrix(lfd, L, A_m, A_n);
  
  release_matrix(A, A_m);
  release_matrix(L, A_m);
  
  fclose(mfd);
  fclose(lfd);

  return 0;
}
