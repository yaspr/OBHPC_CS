#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <emmintrin.h>

#include "rdtsc.h"

#define META 11
#define ITER 10000

//
const unsigned one_as_int = 0x3F000000;

//
const float scale_up = (float)(0x00800000);

//
const float scale_down = 1 / scale_up;

//
unsigned as_int(float f)
{ return *(unsigned *)&f; }

//
float as_float(unsigned u)
{ return *(float *)&u; }

//
float _sqrt_blinn_(float x)
{ return as_float((as_int(x) >> 1) + (one_as_int >> 1)); }

//
float _sqrt_blinn_NR_(float x)
{
  float r = _sqrt_blinn_(x);
  
  r = (r * r + x) / (2 * r);
  r = (r * r + x) / (2 * r);
  r = (r * r + x) / (2 * r);
  
  return (r * r + x) / (2 * r);
}

//
float rsqrt_blinn(float x)
{
  return 1.0 / _sqrt_blinn_NR_(x);
}

//Original rsqrt found in Quake - with original magic constant
float rsqrt_00(float number)
{
  long i;
  float x2, y;
  const float threehalfs = 1.5F;
  
  x2 = number * 0.5F;
  y  = number;
  i  = * (long *) &y;                            // evil floating point bit level hacking
  i  = 0x5f3759df - (i >> 1);                    // what the fuck? 
  y  = *(float *) &i;
  y  = y * ( threehalfs - ( x2 * y * y ) );      // 1st iteration
  // y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

  return y;
}

//Chris Lomont's magic constant
float rsqrt_01(float number)
{
  long i;
  float x2, y;
  const float threehalfs = 1.5F;

  x2 = number * 0.5F;
  y  = number;
  i  = * (long *) &y;                            // evil floating point bit level hacking
  i  = 0x5f375a86 - (i >> 1);                    // what the fuck? 
  y  = *(float *) &i;
  y  = y * ( threehalfs - ( x2 * y * y ) );      // 1st iteration
  // y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

  return y;
}

//Libc sqrt 
float rsqrt_1(float number)
{ return 1 / sqrt(number); }

//sqrt instruction
float rsqrt_2(float number)
{
  __m128 xvec = _mm_set_ss(number);

  float x = 1.0 / _mm_cvtss_f32(_mm_sqrt_ss(xvec));

  return x;
}

//rsqrt instruction
float rsqrt_3(float number)
{
  __m128 xvec = _mm_set_ss(number);

  float x = _mm_cvtss_f32(_mm_rsqrt_ss(xvec));

  return x;
}

//
int main(int argc, char **argv)
{
  register float r = 0.0;
  register double start, stop;
  
  printf("RSQRT0(Blinn)\n");
  for (uint64_t m = 0; m < META; m++)
    {
      start = rdtsc();
      
      for (uint64_t i = 0; i < ITER; i++)
	r = rsqrt_blinn(4);

      stop = rdtsc();

      printf("rsqrt\t:\t%.10lf\tcycles\t:\t%lf\n", r, (double)(stop - start) / ITER);
    }
  
  printf("RSQRT0(Quake)\n");
  for (uint64_t m = 0; m < META; m++)
    {
      start = rdtsc();
      
      for (uint64_t i = 0; i < ITER; i++)
	r = rsqrt_00(4);

      stop = rdtsc();

      printf("rsqrt\t:\t%.10lf\tcycles\t:\t%lf\n", r, (double)(stop - start) / ITER);
    }
  
  printf("RSQRT0(Lomont)\n");
  for (uint64_t m = 0; m < META; m++)
    {
      start = rdtsc();
      
      for (uint64_t i = 0; i < ITER; i++)
	r = rsqrt_01(4);

      stop = rdtsc();

      printf("rsqrt\t:\t%.10lf\tcycles\t:\t%lf\n", r, (double)(stop - start) / ITER);
   }

  printf("RSQRT1(1/sqrt)\n");
  for (uint64_t m = 0; m < META; m++)
    {
      start = rdtsc();
      
      for (uint64_t i = 0; i < ITER; i++)
	r = rsqrt_1(4);

      stop = rdtsc();

      printf("rsqrt\t:\t%.10lf\tcycles\t:\t%lf\n", r, (double)(stop - start) / ITER);
    }
    
  printf("RSQRT2(sqrtss)\n");
  for (uint64_t m = 0; m < META; m++)
    {
      start = rdtsc();
      
      for (uint64_t i = 0; i < ITER; i++)
	r = rsqrt_2(4);

      stop = rdtsc();

      printf("rsqrt\t:\t%.10lf\tcycles\t:\t%lf\n", r, (double)(stop - start) / ITER);
    }

  printf("RSQRT3(rsqrtss)\n");
  for (uint64_t m = 0; m < META; m++)
    {
      start = rdtsc();
      
      for (uint64_t i = 0; i < ITER; i++)
	r = rsqrt_2(4);

      stop = rdtsc();

      printf("rsqrt\t:\t%.10lf\tcycles\t:\t%lf\n", r, (double)(stop - start) / ITER);
    }

  return 0;
}
