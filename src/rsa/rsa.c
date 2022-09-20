/*

  Concept code for RSA encryption

  Reimplement using big numbers (RSA-2048, RSA-4096, ...)

*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
#define MIN_PRIME 1009
#define MAX_PRIME 104729

//
#define MAX_BUFFER 4096

//
#define max(a, b) ((a) > (b)) ? (a) : (b)

//
typedef long long int i64;
typedef unsigned char byte;
typedef long long unsigned u64;

//
u64 randxy(u64 x, u64 y)
{ return (rand() % (y - x + 1)) + x; }

//Find the gcd of two numbers
u64 gcd(u64 v1, u64 v2)
{
  while (v1 && v2)
    {
      if (v1 > v2)
	v1 %= v2;
      else
	v2 %= v1;
    }

  return max(v1, v2);
}

//Modular exponentiation
u64 modular_pow(u64 n, u64 e, u64 m)
{
  u64 r = 1;
  
  n = n % m;
  
  while (e > 0)
    {
      if ((e & 1) == 1)
	r = (r * n) % m;

      e >>= 1;

      n = (n * n) % m;
    }
  
  return r;
}

//Find a coprime to x, with 2 < cop < x
u64 get_coprime(u64 x)
{  
  u64 cop = randxy(3, x - 1);

  //Keep going until a coprime is found
  while (gcd(cop, x) != 1)
    cop = randxy(3, x - 1);
  
  return cop;
}

//Private and public keys generation
void gen_keys(u64 p, u64 q, u64 *_e_, u64 *_d_)
{
  i64 t[3][2];
  u64 n = p * q;
  u64 phi_n = (p - 1) * (q - 1);
  
  //Find e - choose a prime number p, so that 2 < p < phi_n
  u64 e = get_coprime(phi_n);
  
  //Find d - so that d . e = 1 mod phi_n
  t[0][0] = (i64)phi_n;
  t[0][1] = (i64)phi_n;

  t[1][0] = (i64)e;
  t[1][1] = 1;

  t[2][0] = t[2][1] = 0;

  //
  do
    {      
      i64 v = (t[0][0] / t[1][0]);

      t[2][0] = t[0][0] - (t[1][0] * v); 
      t[2][1] = t[0][1] - (t[1][1] * v);

      if (t[2][1] < 0)
	t[2][1] = (t[2][1] % (i64)phi_n + (i64)phi_n) % (i64)phi_n;
      
      t[0][0] = t[1][0];
      t[0][1] = t[1][1];
      t[1][0] = t[2][0];
      t[1][1] = t[2][1];
    }
  while (t[1][0] != 1);
  
  //
  u64 d = (u64)t[1][1];
  
  //
  *_e_ = e; //Public key
  *_d_ = d; //Private key
}

//
void encrypt_buffer(byte *ibuff, u64 len, u64 *_obuff_, u64 k, u64 n)
{  
  for (u64 i = 0; i < len; i++)
    _obuff_[i] = (u64)(modular_pow((u64)ibuff[i], k, n));
}

//
void decrypt_buffer(u64 *ibuff, u64 len, byte *_obuff_, u64 k, u64 n)
{ 
  for (u64 i = 0; i < len; i++)
      _obuff_[i] = (byte)(modular_pow(ibuff[i], k, n));
}

//
void encrypt_file(FILE *ifd, FILE *ofd, u64 k, u64 n)
{
  u64 len = 0;
  byte ibuffer[MAX_BUFFER];
  u64  obuffer[MAX_BUFFER];
  
  while ((len = fread(ibuffer, sizeof(byte), MAX_BUFFER, ifd)))
    {
      encrypt_buffer(ibuffer, len, obuffer, k, n);
      
      fwrite(obuffer, sizeof(u64), len, ofd);
    }
}

//
void decrypt_file(FILE *ifd, FILE *ofd, u64 k, u64 n)
{
  u64 len = 0;
  u64  ibuffer[MAX_BUFFER];
  byte obuffer[MAX_BUFFER];

  while ((len = fread(ibuffer, sizeof(u64), MAX_BUFFER, ifd)))
    {
      decrypt_buffer(ibuffer, len, obuffer, k, n);
      
      fwrite(obuffer, sizeof(byte), len, ofd);
    }
}

//
int main(int argc, char **argv)
{  
  if (argc < 6 && argc < 4)
    return printf("Usage: %s -g [p] [q]\n"
		  "             -e or -d [k] [n] [input file] [output file]\n"
		  "\n\t-g: generate the private and public keys using the given primes (p, q)\n"
		  "\t-e: encrypt the given file using the key (k) and the modulo (n)\n"
		  "\t-d: decrypt the given file using the key (k) and the modulo (n)\n\n", argv[0]), -1;

  byte mode;
  
  if (argv[1][0] == '-')
    if (argv[1][1] == 'g')
      mode = 'g';  
    else
      if (argv[1][1] == 'e')
	mode = 'e';
      else
	if (argv[1][1] == 'd')
	  mode = 'd';
  
  if (mode == 'g')
    {
      //
      srand(getpid());
      
      //
      u64 p = atoll(argv[2]);
      u64 q = atoll(argv[3]);
      
      if (p < MIN_PRIME || p >= MAX_PRIME)
	return printf("Error: p value must be between %d and %d\n", MIN_PRIME, MAX_PRIME), -3;
      
      if (q < MIN_PRIME || q >= MAX_PRIME)
	return printf("Error: q value must be between %d and %d\n", MIN_PRIME, MAX_PRIME), -4;
      
      //
      u64 n = p * q, e, d;
      
      gen_keys(p, q, &e, &d);
      
      printf("\nprivate key\t: (%llu %llu)\npublic key\t: (%llu %llu)\n\n", d, n, e, n);
    }
  else
      {
	u64 k = atoll(argv[2]);
	u64 n = atoll(argv[3]);

	FILE *ifd = fopen(argv[4], "rb");
	FILE *ofd = fopen(argv[5], "wb");
	
	if (!ifd)
	  return printf("Error: cannot open file (%s)\n", argv[4]), -4;
	
	if (!ofd)
	  return printf("Error: cannot create file (%s)\n", argv[5]), -5;

	//
	if (mode == 'e')
	  encrypt_file(ifd, ofd, k, n);
	else
	  if (mode == 'd')
	    decrypt_file(ifd, ofd, k, n);
	
	fclose(ifd);
	fclose(ofd);
      }
  
  return 0;
}
