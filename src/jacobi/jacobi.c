/*
  Solving a system of linear equations using the Jacobi method
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Absolute value
#define f_abs(a) (a < 0.0) ? (-(a)) : (a)

//
typedef unsigned u32;
typedef unsigned long long u64;

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
void release_matrix(double **data, u64 m)
{
  if (data)
    {
      for (u64 i = 1; i < m; i++)
	free(data[i]);
      
      free(data);
    }
}

//
double *load_vector(FILE *fd, u64 *n)
{
  fscanf(fd, "%llu\n", n);

  double *data = malloc(sizeof(double) * (*n));

  for (u64 i = 0; i < (*n); i++)
    fscanf(fd, "%lf ", &data[i]);
  
  return data;
}

//
void store_vector(FILE *fd, double *v, u64 n)
{
  fprintf(fd, "%llu\n", n);
  
  for (u64  i = 0; i < n; i++)
    fprintf(fd, "%lf ", v[i]);

  fprintf(fd, "\n"); 
}

//
void release_vector(double *v)
{
  if (v)
    free(v);
}

//A . x = b where A is a matrix, x and b vectors
double jacobi(double **restrict a, double *restrict b, double *restrict x, double *restrict x_tmp, u64 n, const double prec, const u64 iter)
{
  u64 k = 0;
  double *p = NULL;
  double r = 0.0, e = 0.0;
  
  do
    {
      r = 0.0;
      e = 0.0;
      
      for (u64 i = 0; i < n; i++)
	{
	  r = 0.0;

	  //Avoid an if inside the dotprod loop 
	  for (u64 j = 0; j < i; j++)
	    r += a[i][j] * x[j];
	  
	  for (u64 j = i + 1; j < n; j++)
	    r += a[i][j] * x[j];
	  
	  x_tmp[i] = (b[i] - r) / a[i][i];

	  //Error
	  e += f_abs(x_tmp[i] - x[i]);
	}

      //Swap the two pointers (avoid full copy)
      p = x_tmp;
      x_tmp = x;
      x = p;

      //Count solver iterations
      k++;
    }
  while (e > prec && k < iter);

  return k;
}

//
int main(int argc, char **argv)
{
  if (argc < 4)
    return printf("Usage: %s [matrix input file] [vector input file] [solution output file]\n", argv[0]), -1;

  FILE *mfd = fopen(argv[1], "rb"); //Matrix file
  FILE *vfd = fopen(argv[2], "rb"); //Vector file
  FILE *sfd = fopen(argv[3], "wb"); //Solution file

  //
  if (!mfd)
    return printf("Error: cannot read file (%s)\n", argv[1]), -3;

  if (!vfd)
    return printf("Error: cannot read file (%s)\n", argv[2]), -3;
  
  if (!sfd)
    return printf("Error: cannot create file (%s)\n", argv[3]), -3;

  u64 max_it = 10000;
  double prec = 1e-4;

  u64 A_m, A_n;
  double **A = load_matrix(mfd, &A_m, &A_n);
  
  if (A_m != A_n)
    return printf("Error: the number of rows must be equal to the number of columns\n"), -4;

  u64 b_n;
  double *b  = load_vector(vfd, &b_n);
  
  if (b_n != A_m)
    return printf("Error: the vector size must be equal to the number of rows and columns in the matrix\n"), -5;
  
  double *x     = malloc(sizeof(double) * b_n);
  double *x_tmp = malloc(sizeof(double) * b_n);

  memset(x    , 0, sizeof(double) * b_n);
  memset(x_tmp, 0, sizeof(double) * b_n);
  
  //
  u64 it = jacobi(A, b, x, x_tmp, b_n, prec, max_it);

  printf("Iterations: %llu\n", it);
  
  store_vector(sfd, x, b_n);

  //
  release_matrix(A, A_m);
  release_vector(b);

  free(x);
  free(x_tmp);
  
  //
  fclose(mfd);
  fclose(vfd);
  fclose(sfd);
  
  return 0;
}
