/*
  
  Welcome to the bitwise wonderland, says the white rabbit :)
  If you can't understand any of this, go flip burgers at McDonald's. 
  
 */

#include <stdio.h>
#include <stdlib.h>
#include <emmintrin.h>

#include "rdtsc.h"

#define MAX_REP_ITER 10000

#define MAX_POP_LUT 256

//Look up table
unsigned char LUT[MAX_POP_LUT];

/*
  Definition of RDTSC & measurement method

  RDTSC : ReaD TimeStamp Counter

  The rdtsc instruction returns the value in the cycles counter after the last CPU reset.
  The returned values will be used to evaluate the performance of functions.
  The returned values are considered stable only if the measured target object exhibits 
  a CPU life span of at least 1000 cycles. Given that none of the functions present in this code
  last for that long, they'll be put inside a repetition loop to expand their life span and the 
  probes will be inserted around the repetition loop. The obtained results will be divided by the number of 
  iterations of the repetition loop : MAX_REP_ITER
  
 */

//Measurement macro
#define MEASURE(s, f, v, probe)						\
  {									\
    									\
    int ret;								\
    double a, b;							\
    									\
    b = probe();							\
    									\
    for (unsigned i = 0; i < MAX_REP_ITER; i++)				\
      ret = f(v);							\
									\
    a = probe();							\
    									\
    printf("%s(0x%08x)\tret:\t%d\tcycles:\t%lf\n", s, v, ret, (a - b) / MAX_REP_ITER); \
                                                                                 \
}						                                 \

//popcount on a 32 bits long value using log2(32)=5 steps
unsigned pop1(unsigned v)
{
  v = (v & 0x55555555) + ((v >>  1) & 0x55555555); 
  v = (v & 0x33333333) + ((v >>  2) & 0x33333333); 
  v = (v & 0x0F0F0F0F) + ((v >>  4) & 0x0F0F0F0F); 
  v = (v & 0x00FF00FF) + ((v >>  8) & 0x00FF00FF); 
  v = (v & 0x0000FFFF) + ((v >> 16) & 0x0000FFFF);
  
  return v;
}

//Another variant of the popcount
unsigned pop2(unsigned v)
{
  v = v - ((v >> 1) & 0x55555555);
  v = (v & 0x33333333) + ((v >> 2) & 0x33333333);
  v = (v + (v >> 4)) & 0x0F0F0F0F;
  v += (v >> 8);
  v += (v >> 16);
  
  return v & 0x0000003F;
}

//For the Lulz: n++ = -(~n), also n-- = ~(-n)
unsigned pop3(unsigned v)
{
  unsigned n = 0;
  
  while (v)
    v &= (v - 1), n = -(~n);
  
  return n;
}

//For the Lulz: n++ = -(~n), also n-- = ~(-n)
unsigned pop3_plus(unsigned v)
{
  unsigned n = 0;
  
  while (v)
    v &= (v - 1), n++;
  
  return n;
}

//Another variant, again.
unsigned pop4(unsigned v)
{
  unsigned n;
  
  n = (v >> 1) & 0x77777777;
  v = v - n;
  n = (n >> 1) & 0x77777777;
  v = v - n;
  n = (n >> 1) & 0x77777777;
  v = v - n;
  
  v = (v + (v >> 4)) & 0x0F0F0F0F;
  v *= 0x01010101;
  
  return v >> 24;
}

//Assembly version with the popcnt instruction.
//Works only on Intel processors.
unsigned pop5(unsigned v)
{
  unsigned n;
  
  __asm__(".intel_syntax;"
	  
	  "popcnt %0,%1;"
	  
	  ".att_syntax;"
	  : "=r" (n) //output
	  : "r" (v)  //input
	  :);        //clobber
  
  return n;
}

//
void init()
{
  for (unsigned i = 0; i < MAX_POP_LUT; i++)
    LUT[i] = pop1(i);
}

//
unsigned pop6(unsigned x)
{
  return LUT[x & 0xFF] + LUT[(x >> 8) & 0xFF] + LUT[(x >> 16) & 0xFF] + LUT[x >> 24];
}

//Find the position of the left-most-bit.
//Returns -1 if not found.
int lmb1(unsigned v)
{
  int pos = -1;

  while (v)
    v >>= 1, pos++;
  
  return pos;
}

//Returns 32 if not found.
int lmb2(unsigned v)
{
  unsigned pos = 32, ret = 1;
  const unsigned M = 0x80000000;
  
  while (v && (ret = ((v & M) != M)))
      v <<= 1, pos--;
  
  return pos - !ret; //This replaces an if (recycling) 
}

//Dichotomy using mask & shift tables. 
int lmb3(unsigned v)
{
  unsigned pos = 0;
  const unsigned M[] = { 0xFFFF0000, 0xFF00, 0xF0, 0b1100, 0b10 };
  const unsigned S[] = { 16        ,      8,    4,      2,    1 }; 

  for (unsigned i = 0; v && i <= 4; i++)
    if (v & M[i])
      {
	v >>= S[i];
	pos += S[i]; 
      }
  
  return pos - !v ; //if v is 0 return error code -1
}

//Dichotomy using masks only.
int lmb4(unsigned v)
{
  unsigned pos = 0, scale = 16;
  const unsigned M[] = { 0xFFFF0000, 0xFF00, 0xF0, 0b1100, 0b10 };
  
  for (unsigned i = 0; v && i <= 4; i++)
    if (v & M[i])
      {
	v >>= (scale >> i);
	pos += (scale >> i); 
      }
  
  return pos - !v ; //if v is 0 return error code -1
}

//Dichotomy using masks and a scale to compute shift values.
int lmb5(unsigned v)
{
  unsigned flipflop;
  unsigned pos = 0, scale = 16;
  const unsigned M[] = { 0xFFFF0000, 0xFF00, 0xF0, 0b1100, 0b10 };
  
  for (unsigned i = 0; v && i <= 4; i++)
    {
      flipflop = ((v & M[i]) != 0) | 0xFFFFFFFF;
             
      v  >>= ((scale >> i) & flipflop);
      pos += ((scale >> i) & flipflop); 
    }
  
  return pos - !v ; //if v is 0 return error code -1
}

//
int lmb6(unsigned v)                                                                                               
{                                                                                                                                                     
  unsigned pos = 0;
  
  __asm__("bsrl %1,%0\n\t"                                                                                                                            
	  : "=r" (pos)        
	  : "r" (v));
  
  return (pos < (sizeof(unsigned) * 8)) ? pos : -1;                                   
}

// 32 iterations max, variable
char pos_bit(int M){
  
  if(!M) exit(1);	
  
  char position = 31;
  
  while(-~position)
    {
      if(M & (1u << position))
	break;

      position = ~-position;
    }
  
  return position;
}

/* These two functions were proposed by a student */

//5 iterations, constant
char pos_bit_opti(int M){
  
  if(!M) exit(1);
	
  //lm correspond à la "largeur" du masque
  int lm = 0x0000FFFF;
  int mask = 0xFFFF0000;
  int Mg = M;
  
  char pos = 0;
  int shift = 1u << 4;
  
  while(shift)
    {
      Mg = M & mask;
      
      if(Mg) pos += shift;
      
      //on "divise" le decalage par 2
      shift = shift >> 1;		
      //on reajuste la largeur du masque
      lm = lm >> shift;
      //on repositionne le masque
      mask = lm << (pos+shift);
    }
  
  return pos;
  
}

//
char pos_bit_best(int M){

  if (!M) exit(1);

  char pos = 0;
  
  pos  = ((M &  0xFFFF0000 )        != 0) << 4;
  pos += ((M & (0x0000FF00 << pos)) != 0) << 3;
  pos += ((M & (0x000000F0 << pos)) != 0) << 2;
  pos += ((M & (0x0000000C << pos)) != 0) << 1;
  pos += ((M & (0x00000002 << pos)) != 0);

  return pos;
}


//Reverse bits of a byte in 3 swaps
unsigned char reverse(unsigned char b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}

//
int main(int arc, char **argv)
{
  //val1 : 5 bits up,
  unsigned val1 = ~0, val2 = 0x0F008000;//0x0F0F0110;

  init();
  printf("LUT init done ...\n");
  
  printf("POPCOUNT:\n");
  MEASURE(" pop1", pop1, val2, rdtsc);
  MEASURE(" pop2", pop2, val2, rdtsc);
  MEASURE(" pop3", pop3, val2, rdtsc);
  MEASURE(" pop3+", pop3_plus, val2, rdtsc);
  MEASURE(" pop4", pop4, val2, rdtsc);
  MEASURE(" pop5", pop5, val2, rdtsc);
  MEASURE(" pop6", pop6, val2, rdtsc);
  
  printf("\nLEFT-MOST-BIT:\n");
  MEASURE(" lmb1", lmb1, val2, rdtsc);
  MEASURE(" lmb2", lmb2, val2, rdtsc);
  MEASURE(" lmb3", lmb3, val2, rdtsc);
  MEASURE(" lmb4", lmb4, val2, rdtsc);
  MEASURE(" lmb5", lmb5, val2, rdtsc);
  MEASURE(" lmb6", lmb6, val2, rdtsc);

  printf("\nPOS-BIT:\n");
  MEASURE(" POS-0", pos_bit, val2, rdtsc);
  MEASURE(" POS-1", pos_bit_opti, val2, rdtsc);
  MEASURE(" POS-2", pos_bit_best, val2, rdtsc);
  
  return 0;
}
