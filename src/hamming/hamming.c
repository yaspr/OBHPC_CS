/*
  
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rdtsc.h"

#define ITER 31

//
typedef unsigned u32;
typedef unsigned char byte;
typedef unsigned long long u64;

//
u64 rand_xy(u64 x, u64 y)
{
  return (rand() % (y - x + 1)) + x;
}

//
u32 pop1(u32 v)
{
  v = (v & 0x55555555) + ((v >>  1) & 0x55555555); 
  v = (v & 0x33333333) + ((v >>  2) & 0x33333333); 
  v = (v & 0x0F0F0F0F) + ((v >>  4) & 0x0F0F0F0F); 
  v = (v & 0x00FF00FF) + ((v >>  8) & 0x00FF00FF); 
  v = (v & 0x0000FFFF) + ((v >> 16) & 0x0000FFFF);
  
  return v;
}

//
u32 pop2(u32 v)
{
  u32 n;
  
  __asm__(".intel_syntax;"
	  
	  "popcnt %0,%1;"
	  
	  ".att_syntax;"
	  : "=r" (n) //output
	  : "r" (v)  //input
	  :);        //clobber
  
  return n;
}

//
void vv_xor(byte *s1, byte *s2, byte *d, u64 n)
{
  //SIMDable
#pragma  omp simd
  for (u64 i = 0; i < n; i++)
    d[i] = (s1[i] ^ s2[i]);
}

//
u64 v_popcount1(byte *s, u64 n)
{
  u64 p = 0;
  u32 *ptr = (u32 *)s;
  
  for (u64 i = 0; i < (n >> 2); i++)
    p += pop1(ptr[i]);

  return p;
}

//
u64 v_popcount2(byte *s, u64 n)
{
  u64 p = 0;
  u32 *ptr = (u32 *)s;
  
  for (u64 i = 0; i < (n >> 2); i++)
    p += pop2(ptr[i]);

  return p;
}

//
u64 vv_hamming1(byte *s1, byte *s2, byte *d, u64 n)
{
  vv_xor(s1, s2, d, n);
  
  return v_popcount1(d, n);
}

//
u64 vv_hamming2(byte *s1, byte *s2, byte *d, u64 n)
{
  vv_xor(s1, s2, d, n);
  
  return v_popcount2(d, n);
}

//
void init_rand_buffer(byte *s, u64 n)
{
  u64 *ptr = (u64 *)s;

  for (u64 i = 0; i < n; i++)
    s[i] = rand_xy(0, RAND_MAX);
}

//
void print_hex_buffer(byte *s, u64 n)
{
  for (u64 i = 0; i < n; i++)
    printf("0x%02x%c", s[i], ((i + 1) % 32) ? '\n' : ' ');
}

//
int main(int argc, char **argv)
{
  if (argc < 2)
    return printf("Usage: %s [array size in bytes]\n", argv[0]), -1;

  srand(getpid());
  
  u64 n = atoll(argv[1]);
  byte *s1 = malloc(sizeof(byte) * n);
  byte *s2 = malloc(sizeof(byte) * n);
  byte *s3 = malloc(sizeof(byte) * n);
  byte *s4 = malloc(sizeof(byte) * n);

  double a1, b1;
  double a2, b2;

  u64 dH1, dH2;
  
  init_rand_buffer(s1, n);
  init_rand_buffer(s2, n);

  u64 size = sizeof(byte) * n;
  
  printf("Memory per buffer       : %lluB; %lluKiB; %lluMiB; %lluGiB\n"   ,    size,      size >> 10 ,      size >> 20 ,      size >> 30);
  printf("Total Memory (3 buffers): %lluB; %lluKiB; %lluMiB; %lluGiB\n\n", 3 * size, 3 * (size >> 10), 3 * (size >> 20), 3 * (size >> 30));
  
  //Bitwize popcount
  
  b1 = rdtsc();
  
  for (u64 i = 0; i < ITER; i++)
    dH1 = vv_hamming1(s1, s2, s3, n);
  
  a1 = rdtsc();

  double t1 = (a1 - b1) / (double)ITER;
  
  printf("Hamming1 distance: %llu\n\n", dH1);
  printf("Cycles           : %lf\n", t1);
  printf("Bandwidth        : %lf Bytes / Cycle\n", (double)size / t1);
  //
  
  printf("\n");
  
  //Assembly popcount

  b2 = rdtsc();

  for (u64 i = 0; i < ITER; i++)
    dH2 = vv_hamming2(s1, s2, s4, n);

  a2 = rdtsc();

  double t2 = (a2 - b2) / (double)ITER;

  printf("Hamming2 distance: %llu\n\n", dH2);
  printf("Cycles           : %lf\n", t2);
  printf("Bandwidth        : %lf Bytes / Cycle\n", (double)size / t2);

  free(s1);
  free(s2);
  free(s3);
  free(s4);
  
  return 0;
}
