/*
  Matrix generator

  Identity
                     1 0 0 0 0 0 0 0 0
		     0 1 0 0 0 0 0 0 0
		     0 0 1 0 0 0 0 0 0
		     0 0 0 1 0 0 0 0 0
		     0 0 0 0 1 0 0 0 0
		     0 0 0 0 0 1 0 0 0
		     0 0 0 0 0 0 1 0 0
		     0 0 0 0 0 0 0 1 0
		     0 0 0 0 0 0 0 0 1
     
  Diagonal 
                     x 0 0 0 0 0 0 0 0
		     0 x 0 0 0 0 0 0 0
		     0 0 x 0 0 0 0 0 0
		     0 0 0 x 0 0 0 0 0
		     0 0 0 0 x 0 0 0 0
		     0 0 0 0 0 x 0 0 0
		     0 0 0 0 0 0 x 0 0
		     0 0 0 0 0 0 0 x 0
		     0 0 0 0 0 0 0 0 x
  

  Dense (filled with random values)
  
  Upper triangular
  
                     x x x x x x x x
		     0 x x x x x x x
		     0 0 x x x x x x
		     0 0 0 x x x x x
		     0 0 0 0 x x x x
		     0 0 0 0 0 x x x
		     0 0 0 0 0 0 x x
		     0 0 0 0 0 0 0 x
  Lower triangular

                     x 0 0 0 0 0 0 0
		     x x 0 0 0 0 0 0
		     x x x 0 0 0 0 0
		     x x x x 0 0 0 0
		     x x x x x 0 0 0
		     x x x x x x 0 0
		     x x x x x x x 0
		     x x x x x x x x

  Sparse matrix in dense format

                     0 0 0 0 0 0 0 0 0
		     0 x 0 0 0 0 x 0 0
		     0 x x 0 0 0 0 0 0
		     0 0 0 x x x 0 0 0
		     0 0 0 0 x 0 0 0 0
		     0 0 0 0 0 1 0 0 0
		     0 x 0 0 0 0 1 0 0
		     0 0 x 0 0 0 0 1 0
		     0 0 0 0 x 0 0 0 1
  		
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
typedef unsigned u32;
typedef unsigned long long u64;

//Generate a 4 bytes pseudo-random number between x & y
//!\\This is not a cryptographically secure PRNG
u32 rand_xy(u32 x, u32 y)
{
  return (rand() % (y - x + 1)) + x;
}

//
double rand_real()
{
  u32 s = (rand_xy(0, 1)) ? -1 : 1, n = rand_xy(0, RAND_MAX);
  double d = (rand_xy(0, 1)) ? (double)RAND_MAX / (double)n : (double)n / (double)RAND_MAX;

  return s * d;
}

//
void gen_identity(FILE *fd, u64 m, u64 n)
{
  double v;
  
  fprintf(fd, "%llu %llu\n", m, n);
  
  for (u64 i = 0; i < m; i++)
    {
      for (u64 j = 0; j < n; j++)
	{
	  v = (i == j) ? 1.0 : 0.0;
	  
	  fprintf(fd, "%lf ", v);
	}
      
      fprintf(fd, "\n");
    }
} 

//
void gen_diagonal(FILE *fd, u64 m, u64 n)
{
  double v;
  
  fprintf(fd, "%llu %llu\n", m, n);

  for (u64 i = 0; i < m; i++)
    {
      for (u64 j = 0; j < n; j++)
	{
	  if (i == j)
	    v = rand_real();
	  else
	    v = 0.0;
	  
	  fprintf(fd, "%lf ", v);
	}

      fprintf(fd,"\n"); 
    }
}

//
void gen_dense(FILE *fd, u64 m, u64 n)
{
  fprintf(fd, "%llu %llu\n", m, n);

  for (u64 i = 0; i < m; i++)
    {
      for (u64 j = 0; j < n; j++)
	fprintf(fd, "%lf ", rand_real());
      
      fprintf(fd, "\n");
    }
}

//
void gen_upper_triangular(FILE *fd, u64 m, u64 n)
{
  fprintf(fd, "%llu %llu\n", m, n);

  for (u64 i = 0; i < m; i++)
    {
      for (u64 j = 0; j < i; j++)
	fprintf(fd, "%lf ", 0.0);
      
      for (u64 j = i; j < n; j++)
	fprintf(fd, "%lf ", rand_real());

      fprintf(fd, "\n");
    }
}

//
void gen_lower_triangular(FILE *fd, u64 m, u64 n)
{
  fprintf(fd, "%llu %llu\n", m, n);

  for (u64 i = 0; i < m; i++)
    {
      for (u64 j = 0; j <= i; j++)
	fprintf(fd, "%lf ", rand_real());
      
      for (u64 j = i + 1; j < n; j++)
	fprintf(fd, "%lf ", 0.0);

      fprintf(fd, "\n");
    }
}

//
void gen_sparse(FILE *fd, u64 m, u64 n, u64 *nz, u64 *nnz)
{
  u64 _nz_ = 0, _nnz_ = 0;
  
  fprintf(fd, "%llu %llu\n", m, n);

  double threshold = rand_real();
  
  for (u64 i = 0; i < m; i++)
    {
      for (u64 j = 0; j < n; j++)
	{
	  if (rand_real() < threshold)
	    {
	      fprintf(fd, "%lf ", 0.0);
	      _nz_++;
	    }
	  else
	    {
	      fprintf(fd, "%lf ", rand_real());
	      _nnz_++;
	    }
	}

      fprintf(fd, "\n");
    }

  *nz  = _nz_;
  *nnz = _nnz_;
}

//
int main(int argc, char **argv)
{
  if (argc < 5)
    return printf("Usage      : %s [matrix type] [output file] [number of rows] [number of columns]\n"
		  "Matrix type:\n"
		  "\tIdentity          : -i\n"
		  "\tDiagonal          : -d\n"
		  "\tUpper triangular  : -u\n"
		  "\tLower triangular  : -l\n"
		  "\tDense/Full        : -f\n"
		  "\tSparse            : -s\n\n", argv[0]), -1;

  u32 mode;
  
  //Check arguments
  if (argv[1][0] == '-')
    {
      switch (argv[1][1])
	{
	case 'i':
	  mode = 'i'; break;
	  
	case 'd':
	  mode = 'd'; break;

	case 'u':
	  mode = 'u'; break;

	case 'l':
	  mode = 'l'; break;

	case 'f':
	  mode = 'f'; break;

	case 's':
	  mode = 's'; break;

	default:
	  return printf("Error: unknow matrix type\n"), -2;
	}
    }

  u64 nz, nnz;
  u64 m = atoll(argv[3]);
  u64 n = atoll(argv[4]);
  
  //
  srand(time(NULL));

  //
  FILE *fd = fopen(argv[2], "wb");

  if (!fd)
    return printf("Error: cannot create file (%s)\n", argv[2]), -2;

  switch (mode)
    {
    case 'i':
      gen_identity(fd, m, n); break;
      
    case 'd':
      gen_diagonal(fd, m, n); break;

    case 'u':
      gen_upper_triangular(fd, m, n); break;
      
    case 'l':
      gen_lower_triangular(fd, m, n); break;

    case 'f':
      gen_dense(fd, m, n); break;
      
    case 's':
      gen_sparse(fd, m, n, &nz, &nnz);

      printf("Zero elements count    : %llu\n", nz);
      printf("Non zero elements count: %llu\n", nnz);
      
      break;
    }
  
  fclose(fd);
  
  return 0;
}
