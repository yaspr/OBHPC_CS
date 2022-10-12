//
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//
#include "types.h"

//
#include "tools.h"

//
#include "kernels.h"

//
#define ALIGN64 64

//
#define MAX_SAMPLES 33

//
void run_benchmark(const ascii *title,
		   f64 (*kernel)(f64 *restrict, f64 *restrict, u64),
		   u64 n,
		   u64 r);

//
int main(int argc, char **argv)
{
  //
  srand(getpid());

  //
  if (argc < 3)
    return printf("usage: %s [n] [r]\n", argv[0]), 1;

  //Number of array elements
  u64 n = atoll(argv[1]);

  //Number of kernel repetitions
  u64 r = atoll(argv[2]);

  //Print header
  printf("%10s; %15s; %15s; %15s; %10s; %10s; %15s; %15s; %15s; %15s; %26s; %10s\n",
	 "title",
	 "KiB", "MiB", "GiB",
	 "n", "r", "d", "min", "max", "mean", "stddev (%)", "MiB/s");
  
  run_benchmark("BASE",   dotprod_base, n, r);
  
  //
  return 0;
}

//
void run_benchmark(const ascii *title,
		   f64 (*kernel)(f64 *restrict, f64 *restrict, u64),
		   u64 n,
		   u64 r)
{
  //Calculate the size of a single matrix
  u64 size = (sizeof(f64) * n);
  
  //
  f64 size_b = (float) size;
  f64 size_kib = size_b / (1024.0);
  f64 size_mib = size_b / (1024.0 * 1024.0);
  f64 size_gib = size_b / (1024.0 * 1024.0 * 1024.0);
  
  //
  f64 elapsed = 0.0;
  struct timespec t1, t2;
  f64 samples[MAX_SAMPLES];
  
  //
  f64 d = 0.0;
  f64 *restrict a = aligned_alloc(ALIGN64, size);
  f64 *restrict b = aligned_alloc(ALIGN64, size);
  
  //
  init_f64(a, n, 'r');
  init_f64(b, n, 'r');

  //
  for (u64 i = 0; i < MAX_SAMPLES; i++)
    {
      do
	{
	  clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
	  
	  for (u64 j = 0; j < r; j++)
	    d = kernel(a, b, n);
	  
	  clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
	  
	  elapsed = (f64)(t2.tv_nsec - t1.tv_nsec) / (f64)r;	  
	}
      while (elapsed <= 0.0);
      
      samples[i] = elapsed;
    }
  
  //
  sort_f64(samples, MAX_SAMPLES);
  
  //
  f64 min  = samples[0];
  f64 max  = samples[MAX_SAMPLES - 1];
  f64 mean = mean_f64(samples, MAX_SAMPLES);
  f64 dev  = stddev_f64(samples, MAX_SAMPLES);
  
  //Size in MiB / time in seconds
  f64 mbps = size_mib / (mean / 1e9);

  //
  printf("%10s; %15.3lf; %15.3lf; %15.3lf; %10llu; %10llu; %15.3lf; %15.3lf; %15.3lf; %15.3lf; %15.3lf (%6.3lf %%); %10.3lf\n",
	 title,
	 2 * size_kib, //2 arrays
	 2 * size_mib, //2 arrays
	 2 * size_gib, //2 arrays
	 n,
	 r,
	 d,
	 min,
	 max,
	 mean,
	 dev,
	 (dev * 100.0 / mean),
	 mbps);
  
  //
  free(a);
  free(b);
}
