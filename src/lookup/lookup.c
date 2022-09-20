#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

//
#include "rdtsc.h"

//
#define MAX_SYMBOLS  256

//
#define META 131

//
#define max(a, b) ((a) > (b)) ? (a) : (b)

//
typedef long long int i64;
typedef unsigned char byte;
typedef unsigned long long u64;

//
u64 bm_count = 0;

//
void bm_init_LUT(byte *p, u64 plen, u64 *LUT)
{
  for (u64 i = 0; i < MAX_SYMBOLS; i++)
    LUT[i] = plen;
  
  for (u64 i = 0; i < plen; i++)
    LUT[p[i]] = max(1, plen - i - 1);
}

//Boyer-Moore algorithm for finding a pattern within a stream of symbols
i64 bm_lookup(byte *p, u64 plen, byte *s, u64 slen, u64 *LUT)
{
  byte v = 0;
  i64 i = 0, j = 0;
  
  for (i = 0; !v && i < slen - plen; )
    {
      v = 1;

      for (j = plen - 1; v && j >= 0 ; j--)
	v = !(p[j] ^ s[i + j]);
      
      if (!v)
	{
	  i += LUT[s[i + j + 1]];
	  bm_count++;
	}
    }
  
  return (v) ? i : -1;
}

//
i64 n_lookup(byte *p, u64 plen, byte *s, u64 slen)
{
  i64 i = 0;
  byte v = 0;
  
  for (i = 0; !v && i < slen - plen; i++)
    {
      v = 1;
      
      for (u64 j = 0; v && j < plen; j++)
	v = !(p[j] ^ s[i + j]);
    }

  //A little trick to avoid a branch
  return (i * v) - 1;
}

//
int main(int argc, char **argv)
{
  if (argc < 3)
    return printf("Usage: %s [word] [target file]\n", argv[0]), -1;

  FILE *fd = fopen(argv[2], "rb");

  if (fd)
    {
      //Getting the file size
      struct stat sb;
      
      if (lstat(argv[2], &sb) < 0)
	return printf("Error: cannot lstat file (%s)\n", argv[2]), -3;

      u64 fsize = sb.st_size;
      
      //Allocating memory 
      byte *fbuffer = malloc(sizeof(byte) * fsize + sizeof(byte));

      //Reading file into memory
      fread(fbuffer, sizeof(byte), fsize, fd);

      //File's not needed anymore
      fclose(fd);

      //
      i64 pos = 0;
      double bm_a, bm_b;
      double nv_a, nv_b;
      u64 LUT[MAX_SYMBOLS];
      u64 plen = strlen(argv[1]);
      
      //Boyer-Moore lookup
      bm_init_LUT(argv[1], plen, LUT);

      bm_b = rdtsc();

      for (u64 i = 0; i < META; i++)
	pos = bm_lookup(argv[1], plen, fbuffer, fsize, LUT);
      
      bm_a = rdtsc();
      
      bm_count /= META;
      
      printf("Boyer-Moore:\n%s ", argv[1]);
      
      if (pos >= 0)
	printf("found at %lld (shifts: %llu)\n", pos, bm_count);
      else
	printf("not found!\n");
      
      //Naive
      
      nv_b = rdtsc();
      
      for (u64 i = 0; i < META; i++)
	pos = n_lookup(argv[1], plen, fbuffer, fsize);

      nv_a = rdtsc();

      printf("\nNaive:\n%s ", argv[1]);
      
      if (pos >= 0)
	printf("found at %lld (shifts: %llu)\n", pos, pos);
      else
	printf("not found!\n");

      printf("\n");
      
      //
      double bm_t = (bm_a - bm_b) / (double)META;
      printf("Cycles Boyer-Moore:\t%lf\n", bm_t);

      double nv_t = (nv_a - nv_b) / (double)META;
      printf("Cycles Naive      :\t%lf\n\n", nv_t);
      
      printf("Cycles speedup  (Boyer-Moore over Naive) = %lf\n", (nv_t) / (bm_t)); 
      printf("Shifts speedup  (Boyer-Moore over Naive) = %lf\n\n", (double)pos / (double)bm_count); 
      
      free(fbuffer);

    }
  else
    return printf("Error: cannot open file (%s)\n", argv[2]), -2;
  
  return 0;
}
