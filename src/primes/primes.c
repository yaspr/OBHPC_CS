//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
#include "rdtsc.h"

//
#define META 101

//
typedef unsigned char byte;
typedef unsigned long long u64;

//Naive implementation
byte n_is_prime(u64 v)
{
  byte div = 0;

  if (v == 2)
    return 1;
  else
    if (v == 1)
      return 0;
  
  for (u64 i = 2; !div && i <= (u64)sqrt(v); i++)
    div = ((v % i) == 0);

  return !div;
}

//
void build_sieve1(u64 v, u64 *LUT, u64 *n)
{
  byte p = 1;
  u64 _n_ = 1;
  
  //
  LUT[0] = 2;

  //
  for (u64 i = 3; i < v; i += 2)
    {
      p = n_is_prime(i);

      LUT[_n_] = i;
      _n_ += p;
    }

  (*n) = _n_;
}

//Sieving
void build_sieve2(u64 v, u64 *LUT, u64 *n)
{
  byte div;
  u64 _n_ = 1;
  
  //First prime number
  LUT[0] = 2;
  
  //Find all prime numbers below v
  for (u64 i = 3; i < v; i += 2)
    {
      div = 1;
      
      //If the current number is divisible
      //by a previous prime ==> not prime
      //i % LUT[j] can overflow div and turn
      for (u64 j = 0; div && j < _n_; j++)
	div = !(!(i % LUT[j]));
      
      if (div)
	LUT[_n_++] = i;
    }
  
  (*n) = _n_;
}

//
void print_sieve(u64 *LUT, u64 n)
{
  for (u64 i = 0; i < n; i++)
    printf("%llu%c", LUT[i], ((i + 1) % 10) ? '\t' : '\n');

  printf("\n");
}

//
int main(int argc, char **argv)
{
  if (argc < 2)
    return printf("Usage: %s [number]\n", argv[0]), -1;

  u64 v = atoll(argv[1]);
  double a1, b1, a2, b2;
  
  u64 n1, n2;
  u64 *LUT1 = malloc(sizeof(u64) * v);
  u64 *LUT2 = malloc(sizeof(u64) * v);
  
  //Sqrare root naive
  
  //
  b1 = rdtsc();
  
  for (byte i = 0; i < META; i++)
    build_sieve1(v, LUT1, &n1);

  a1 = rdtsc();
  
  print_sieve(LUT1, n1);
  
  //
  printf("\n");

  //Sieving
  
  //
  b2 = rdtsc();
  
  for (byte i = 0; i < META; i++)
    build_sieve2(v, LUT2, &n2);

  a2 = rdtsc();
  
  print_sieve(LUT2, n2);
  
  //
  printf("\n");

  //
  double t1 = (a1 - b1) / META, t2 = (a2 - b2) / META;

  //
  printf("\n"
	 "Cycles 1        :\t%lf\n"
	 "Cycles 2        :\t%lf\n"
	 "Speed up (2 / 1):\t%lf\n", t1, t2, t2 / t1);
  
  free(LUT1);
  free(LUT2);
  
  return 0;
}
