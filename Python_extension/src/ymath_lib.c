/*

  This file contains the code for the ymath library.
  
  yaspr - 2022
  
*/

//
#include "ymath_lib.h"

//
void ymath_vadd_f32(f32 *a, f32 *b, f32 *c, u64 n)
{
  for (u64 i = 0; i < n; i++)
    c[i] = a[i] + b[i];
}

//1 cache line
void ymath_vadd_f32_AVX(f32 *a, f32 *b, f32 *c, u64 n)
{
  //
  u64 _n_ = n - (n & 15);
  u64 s = sizeof(f32) * _n_;

  __asm__ volatile (
		    //Zero up the loop counter
		    "xor %%rcx, %%rcx;\n"

		    "1:;\n"

		    //Load values from memory (a and b)
		    "vmovups (%[_a], %%rcx), %%ymm1;\n"
		    "vmovups (%[_b], %%rcx), %%ymm2;\n"

		    //Add values
		    "vaddps %%ymm2, %%ymm1, %%ymm0;\n"

		    //Store values into memory (c)
		    "vmovups %%ymm0, (%[_c], %%rcx);\n"

		    //Next
		    "add $64, %%rcx;\n"
		    "cmp %[_s], %%rcx;\n"
		    "jl 1b;\n"
		    
		    : //output
		    : //input
		      [_a] "r" (a),
		      [_b] "r" (b),
		      [_c] "r" (c),
		      [_s] "r" (s)		    
		    : //clobber
		      "cc", "memory", "rcx",
		      "ymm0", "ymm1", "ymm2"
		    );

  //
  for (u64 i = _n_; i < n; i++)
    c[i] = a[i] + b[i];
}

//
f32 ymath_reduc_f32(f32 *a, u64 n)
{
  f32 r = 0.0;

  for (u64 i = 0; i < n; i++)
    r += a[i];

  return r;
}

//1 cache line
f32 ymath_reduc_f32_AVX(f32 *a, u64 n)
{
  //
  u64 _n_ = n - (n & 15);
  f32 r[8] __attribute__((aligned(YMATH_ALIGN)));
  u64 s = sizeof(f32) * _n_;
  
  //
  __asm__ volatile(
		   //Zero up the loop counter
		   "xor %%rcx, %%rcx;\n"

		   //Zero up the partial accumulation registers
		   "vxorpd %%ymm0, %%ymm0, %%ymm0;\n"
		   "vxorpd %%ymm1, %%ymm1, %%ymm1;\n"

		   //Loop entry
		   "1:;\n"

		   //Load and accumulate
		   "vaddps   (%[_a_], %%rcx), %%ymm0, %%ymm0;\n"
		   "vaddps 32(%[_a_], %%rcx), %%ymm1, %%ymm1;\n"

		   //Next 
		   "add $64, %%rcx;\n"
		   "cmp %[_s_], %%rcx;\n"
		   "jl 1b;\n"
		   
		   //Sum up the partial accumulation register
		   "vaddps %%ymm1, %%ymm0, %%ymm0;\n"
		   
		   //Store result
		   "vmovaps %%ymm0, (%[_r_]);\n"
		   
		   : //output
		   : //input
		     [_a_] "r" (a),
		     [_s_] "r" (s),
		     [_r_] "r" (r)
		   : //clobber
		     "cc", "memory", "rcx",
		     "ymm0", "ymm1"
		   );

  //
  for (u64 i = _n_; i < n; i++)
    r[0] += a[i];
  
  //
  return (r[0] + r[1] + r[2] + r[3] + r[4] + r[5] + r[6] + r[7]);
}

//
f32 ymath_dotprod_f32(f32 *a, f32 *b, u64 n)
{
  f32 r = 0.0;

  for (u64 i = 0; i < n; i++)
    r += a[i] * b[i];

  return r;
}

//1 cache line
f32 ymath_dotprod_f32_AVX(f32 *a,
		      f32 *b,
		      u64 n)
{
  //
  u64 _n_ = n - (n & 15);
  f32 r[8] __attribute__((aligned(YMATH_ALIGN)));
  u64 s = sizeof(f32) * _n_;
  
  //
  __asm__ volatile(
		   "xor %%rcx, %%rcx;\n"
		   
		   "vxorpd %%ymm0, %%ymm0, %%ymm0;\n"
		   "vxorpd %%ymm1, %%ymm1, %%ymm1;\n"
		   
		   "1:;\n"
		   
		   "vmovups   (%[_a_], %%rcx), %%ymm2;\n"
		   "vmovups 32(%[_a_], %%rcx), %%ymm3;\n"
		   
		   "vfmadd231ps   (%[_b_], %%rcx), %%ymm2, %%ymm0;\n"
		   "vfmadd231ps 32(%[_b_], %%rcx), %%ymm3, %%ymm1;\n"
		   
		   "add $64, %%rcx;\n"
		   "cmp %[_s_], %%rcx;\n"
		   "jl 1b;\n"
		   
		   "vaddps %%ymm1, %%ymm0, %%ymm0;\n"
		   
		   "vmovaps %%ymm0, (%[_r_]);\n"
		   
		   : //output
		   : //input
		     [_a_] "r" (a),
		     [_b_] "r" (b),
		     [_s_] "r" (s),
		     [_r_] "r" (r)
		   : //clobber
		     "cc", "memory", "rcx",
		     "ymm0", "ymm1", "ymm2", "ymm3"
		   );

  for (u64 i = _n_; i < n; i++)
    r[0] += a[i];
  
  //
  return (r[0] + r[1] + r[2] + r[3] + r[4] + r[5] + r[6] + r[7]);
}
