//gcc p2.c -o p2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//
typedef float              f32;
typedef unsigned long long u64;
typedef char               ascii;

//
void init_array_f32(f32 *restrict a, const f32 c, u64 n)
{
  for (u64 i = 0; i < n; i++)
    a[i] = c + (f32)RAND_MAX / (f32)rand();
}

//
void add_array_f32(f32 *restrict a, f32 *restrict b, f32 *restrict c, u64 n)
{
  for (u64 i = 0; i < n; i++)
    c[i] = a[i] + b[i];
}

//
void dump_array_f32(const ascii *fname, f32 *restrict a, u64 n)
{
  FILE *fp = fopen(fname, "wb");

  if (!fp)
    {
      printf("Error cannot create output file '%s'\n", fname);
      exit(5);
    }
  
  fprintf(fp, "%llu\n", n);
  
  for (u64 i = 0; i < n; i++)
    fprintf(fp, "%f ", a[i]);

  fprintf(fp, "\n");
}

//
int main(int argc, char **argv)
{
  
  if (argc < 3)
    return printf("usage: %s [s] [n]\n", argv[0]), 1;

  u64 s = atoll(argv[1]);
  u64 n = atoll(argv[2]);

  srand(s);
  
  f32 *restrict a = malloc(sizeof(f32) * n);
  f32 *restrict b = malloc(sizeof(f32) * n);
  f32 *restrict c = malloc(sizeof(f32) * n);
  
  if (!a)
    return printf("Error allocating array a\n"), 2;
  
  if (!b)
    return printf("Error allocating array b\n"), 3;
  
  if (!c)
    return printf("Error allocating array c\n"), 4;

  u64 size = sizeof(f32) * n * 3;
  
  printf("Total allocated memory: %llu B; %llu KiB; %llu MiB\n",
	 size,
	 size >> 10,
	 size >> 20);

  init_array_f32(a, 1.0, n);
  init_array_f32(b, 2.0, n);
  init_array_f32(c, 0.0, n);
  
  add_array_f32(a, b, c, n);
  
  dump_array_f32("a_f32.dat", a, n);
  dump_array_f32("b_f32.dat", b, n);
  dump_array_f32("c_f32.dat", c, n);

  free(a);
  free(b);
  free(c);
  
  return 0;
}
