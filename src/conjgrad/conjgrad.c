/*
  Conjugate Gradient method for solving systems of linear equations
  
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
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
      for (u64 j = 0; j < (*n); j++)
	fscanf(fd, "%lf ", &data[i][j]);
    }
  
  return data;
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
double *load_vector(FILE *fd, u64 *n)
{
  fscanf(fd, "%llu\n", n);

  double *v = malloc(sizeof(double) * (*n));
  
  for (u64 i = 0; i < (*n); i++)
    fscanf(fd, "%lf ", &v[i]);

  return v;
}

//
void store_vector(FILE *fd, double *v, u64 n)
{
  fprintf(fd, "%llu\n", n);

  for (u64 i = 0; i < n; i++)
    fprintf(fd, "%lf ", v[i]);

  fprintf(fd, "\n");
}

//
void release_vector(double *v)
{
  if (v)
    free(v);
}

//
void v_scale(double *v, double c, double *o, u64 n)
{
  for (u64 i = 0; i < n; i++)
    o[i] = c * v[i];
}

//vector * vector = scalar
double vv_dotprod(double *u, double *v, u64 n)
{
  double r = 0.0;

  for (u64 i = 0; i < n; i++)
    r += u[i] * v[i];

  return r;
}

//
void vv_add(double *u, double *v, double *o, u64 n)
{
  for (u64 i = 0; i < n; i++)
    o[i] = u[i] + v[i];
}

//
void vv_sub(double *u, double *v, double *o, u64 n)
{
  for (u64 i = 0; i < n; i++)
    o[i] = u[i] - v[i];
}

//
void vv_copy(double *d, double *s, u64 n)
{
  for (u64 i = 0; i < n; i++)
    d[i] = s[i];
}

//matrix * vector = vector
void mv_prod(double **a, double *v, double *o, u64 n)
{
  for (u64 i = 0; i < n; i++)
    {
      o[i] = 0.0;

      for (u64 j = 0; j < n; j++)
	o[i] += a[i][j] * v[j];
    }
}

//
void conjgrad(double **A, double *b, double *x, u64 n, double prec)
{
  double rsold, rsnew, alpha;
  double *o = malloc(sizeof(double) * n);
  double *p = malloc(sizeof(double) * n);
  double *r = malloc(sizeof(double) * n);
  double *Ap = malloc(sizeof(double) * n);
  
  mv_prod(A, x, o, n);
  vv_sub(b, o, r, n);
  //r = b - (A * x);

  //Copy
  vv_copy(p, r, n);
  //p = r;

  rsold = vv_dotprod(r, r, n);
  //rsold = r * r;

  //
  for (u64 i = 0; i < n; i++)
    {
      mv_prod(A, p, Ap, n);
      //Ap = A * p;

      alpha = rsold / vv_dotprod(p, Ap, n);
      //alpha = rsold / (p * Ap);

      v_scale(p, alpha, o, n);
      vv_add(x, o, x, n);
      //x = x + (alpha * p);

      v_scale(Ap, alpha, o, n);
      vv_sub(r, o, r, n);
      //r = r - (alpha * Ap);

      //Dotprod
      rsnew = vv_dotprod(r, r, n);
      //rsnew = r * r;

      //
      if (sqrt(rsnew) < prec)
	break;

      v_scale(p, (rsnew / rsold), o, n);
      vv_add(r, o, p, n);
      //p = r + (rsnew / rsold) * p;
      
      rsold = rsnew;
    }
}
//
int main(int argc, char **argv)
{
  if (argc < 4)
    return printf("Usage: %s [input matrix] [input vector] [output vector]\n", argv[0]), -1;

  //
  FILE *mfd = fopen(argv[1], "rb");
  FILE *vfd = fopen(argv[2], "rb");
  FILE *ofd = fopen(argv[3], "wb");

  //
  if (!mfd)
    return printf("Error: cannot open file (%s)", argv[1]), -2;
  
  if (!vfd)
    return printf("Error: cannot open file (%s)", argv[2]), -2;

  if (!ofd)
    return printf("Error: cannot create file (%s)", argv[3]), -2;

  //
  double prec = 1e-4;
  
  u64 A_m, A_n;
  double **A = load_matrix(mfd, &A_m, &A_n);

  if (A_m != A_n)
    return printf("Error: the number of rows must be identical to the number of columns\n"), -3;
  
  u64 b_n;
  double *b = load_vector(vfd, &b_n);

  if (A_n != b_n)
    return printf("Error: vector size must be equal to the number of rows and columns\n"), -3;
  
  double *x = malloc(sizeof(double) * b_n);

  //
  conjgrad(A, b, x, b_n, prec);
  
  store_vector(ofd, x, b_n);
  
  //
  release_vector(b);
  release_vector(x);
  
  release_matrix(A, A_m);
  
  //
  fclose(mfd);
  fclose(vfd);
  fclose(ofd);
  
  return 0;
}
