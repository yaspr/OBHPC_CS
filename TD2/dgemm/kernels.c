//
#if defined(__INTEL_COMPILER)
#include <mkl.h>
#else
#include <cblas.h>
#endif

//
#include "types.h"

//Baseline - naive implementation
void dgemm_ijk(f64 *restrict a, f64 *restrict b, f64 *restrict c, u64 n)
{
  for (u64 i = 0; i < n; i++)
    for (u64 j = 0; j < n; j++)
      for (u64 k = 0; k < n; k++)
	c[i * n + j] += a[i * n + k] * b[k * n + j];
}

//First optimization (loop interchange) 
void dgemm_ikj(f64 *restrict a, f64 *restrict b, f64 *restrict c, u64 n)
{
  for (u64 i = 0; i < n; i++)
    for (u64 k = 0; k < n; k++)
      for (u64 j = 0; j < n; j++)
	c[i * n + j] += a[i * n + k] * b[k * n + j];
}

//Second optimization (loop interchange + invariant extraction) 
void dgemm_iex(f64 *restrict a, f64 *restrict b, f64 *restrict c, u64 n)
{
  for (u64 i = 0; i < n; i++)
    {
      for (u64 k = 0; k < n; k++)
	{
	  const f64 _a_ = a[i * n + k];
	  
	  for (u64 j = 0; j < n; j++)
	    c[i * n + j] +=  _a_ * b[k * n + j];
	}
    }
}

//
void dgemm_cblas(f64 *restrict a, f64 *restrict b, f64 *restrict c, u64 n)
{
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, n, n, n, 1.0, a, n, b, n, 0.0, c, n);
}
