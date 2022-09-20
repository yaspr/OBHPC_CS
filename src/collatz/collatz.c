#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rdtsc.h"

//
#define META 100001

//
typedef unsigned long long u64;

//
u64 collatz1(u64 n)
{
  u64 i = 0;
  u64 m = n;
  
  while (m != 1)
    {
      if (m & 1)
	m = (3 * m) + 1;
      else
	m >>= 1;

      i++;
    }
  
  return i + 1;
}

//
u64 collatz2(u64 n)
{
  u64 i = 0;
  
  __asm__(".intel_syntax noprefix;"
	  
	  "mov rax, 1;"
	  "cmp %0, 1;"
	  "je loop_exit1;"
	  
	  "loop_entry1:;"
	  
	  "test %0, 1;"
	  "jnz odd;"
	  
	  //Even
	  "shr %0, 1;"
	  "jmp loop_exit1;"
	  
	  "odd:;"
	  
	  "imul %0, 3;"
	  "inc %0;"

	  "loop_exit1:;"

	  "inc rax;"
	  "cmp %0, 1;"
	  "jne loop_entry1;"

	  "mov [%1], rax;"
	  
	  ".att_syntax prefix;"
	  
	  : //Outputs
	    
	  : //Inputs
	    "r" (n),
	    "r" (&i)
	    
	  : //Clobber
	    "cc", "rax");
  
  return i;
}

//
u64 collatz3(u64 n)
{
  u64 i = 0;

  __asm__(
	  ".intel_syntax noprefix;"

	  "mov rax, 1;"
	  "mov rcx, %0;"
	  
	  "loop_entry2:;"
	  
	  //Copy the input rcx into rdx
	  "mov rdx, rcx;" 

	  //Odd --> 3 * n + 1
	  "imul rdx, 3;"
	  "inc rdx;"
	  
	  //Even --> n / 2
	  "shr rcx, 1;"

	  //Conditional move
	  "cmovc rcx, rdx;"
	  
	  "inc rax;" 	  
	  "cmp rcx, 1;"
	  "jne loop_entry2;"
	  
	  "mov [%1], rax;"
	  
	  ".att_syntax prefix;"
	  
	  : //Outputs

	  : //Inputs
	    "r" (n),
	    "r" (&i)
	    
	  : //Clobber
	    "cc", "rax", "rdx", "rcx"
	  );

  return i;
}

//
u64 collatz4(u64 n)
{
  u64 i = 0;

  __asm__(
	  ".intel_syntax noprefix;"

	  "mov rcx, %0;"
	  
	  "xor rax, rax;"
	  "xchg rdx, rcx;"
	  
	  "loop_entry3:;"

	  "bsf rcx, rdx;"
	  "shr rdx, cl;"
	  "add rax, rcx;"

	  "lea rdx, [rdx * 2 + rdx];"
	  "inc rax;"
	  "inc rdx;"
	  
	  "cmp rcx, 4;"
	  "jne loop_entry3;"

	  "mov [%1], rax;"
	  
	  ".att_syntax prefix;"

	  : //Outputs

	  : //Inputs
	    "r" (n),
	    "r" (&i)
	    
	  : //Clobber
	    "cc", "rax", "rcx", "rdx"
	  );

  return i;
}

//
u64 collatz5(u64 n)
{
  u64 i = 0;

  __asm__(
	  ".intel_syntax noprefix;"

	  "mov rcx, %0;"
	  
	  "xor rax, rax;"
	  "xchg rdx, rcx;"
	  
	  "loop_entry4:;"

	  "bsf rcx, rdx;"
	  "shr rdx, cl;"

	  "lea rax, [rax + rcx + 1];"
	  "lea rdx, [rdx * 2 + rdx + 1];"
	  
	  "cmp rcx, 4;"
	  "jne loop_entry4;"

	  "mov [%1], rax;"
	  
	  ".att_syntax prefix;"

	  : //Outputs

	  : //Inputs
	    "r" (n),
	    "r" (&i)
	    
	  : //Clobber
	    "cc", "rax", "rcx", "rdx"
	  );

  return i;
}

//
int main(int argc, char **argv)
{
  if (argc < 2)
    return printf("Usage: %s [n]\n", argv[0]), -1;
  
  u64 n = atoll(argv[1]);

  //
  u64 r = 0;
  double cycles[5];
  double after, before;

  //1
  before = rdtsc();

  for (u64 i = 0; i < META; i++)
    r = collatz1(n);
  
  after = rdtsc();

  cycles[0] = (after - before);

  //2
  before = rdtsc();

  for (u64 i = 0; i < META; i++)
    r = collatz1(n);
  
  after = rdtsc();

  cycles[1] = (after - before);

  //3
  before = rdtsc();

  for (u64 i = 0; i < META; i++)
    r = collatz1(n);
  
  after = rdtsc();

  cycles[2] = (after - before);

  //4
  before = rdtsc();

  for (u64 i = 0; i < META; i++)
    r = collatz1(n);
  
  after = rdtsc();

  cycles[3] = (after - before);

  //5
  before = rdtsc();

  for (u64 i = 0; i < META; i++)
    r = collatz1(n);
  
  after = rdtsc();

  cycles[4] = (after - before);

  //
  for (u64 i = 0; i < 5; i++)
    printf("Cycles %llu:\t%lf\n", i, cycles[i] / META);
  
  return 0;
}
