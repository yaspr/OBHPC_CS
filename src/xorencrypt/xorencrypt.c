#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xorencrypt.h"

//Generate a 4 bytes pseudo-random number between x & y
//!\\This is not a cryptographically secure PRNG
u32 rand_xy(u32 x, u32 y)
{
  return (rand() % (y - x + 1)) + x;
}

//Read BUFFER_SIZE elements from the fd file pointer
u64 load_buffer(FILE *fd, byte *buff)
{
  //Size in bytes = sizeof(byte) * BUFFER_SIZE
  return fread(buff, sizeof(byte), BUFFER_SIZE, fd);
}

//Write size elements into the fd file pointer
u64 store_buffer(FILE *fd, byte *buff, u64 size)
{
  return fwrite(buff, sizeof(byte), size, fd);
}

//Buffer3(0 to size - 1) = Buffer1(0 to size - 1) xor Buffer2(0 to size - 1)
void xor_buff(byte *buff1, byte *buff2, byte *buff3, u64 size)
{
  //
  for (u64 i = 0; i < size && i < BUFFER_SIZE; i++)
    buff3[i] = (buff1[i] ^ buff2[i]);
}

/*
 * This function generates a random key for each loaded buffer.
 * It starts by generating a 4 bytes random value and picks a byte
 * randomly to be used in the key. 
 */
void generate_key(byte *buff)
{
  u32 _s_[4] = { 24, 16, 8, 0 };
  u32 _m_[4] = { 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF };
  
  //
  for (u64 i = 0; i < BUFFER_SIZE; i++)
    {
      u32 x = rand_xy(1000, 123456), y = rand_xy(123457, 1234570);
      u32 p = rand_xy(0, 4);
      u32 n = rand_xy(x, y);

      buff[i] = ((n & _m_[p]) >> _s_[p]); 
    }
}

//
void encrypt(FILE *ifd, FILE *kfd, FILE *ofd)
{
  u64 size = 0;
  byte ibuff[BUFFER_SIZE];
  byte kbuff[BUFFER_SIZE];
  byte obuff[BUFFER_SIZE];

  //
  while ((size = load_buffer(ifd, ibuff)))
    {
      generate_key(kbuff);
      
      xor_buff(ibuff, kbuff, obuff, size);
      
      store_buffer(kfd, kbuff, size);
      store_buffer(ofd, obuff, size);
    }
}

//
void decrypt(FILE *ifd, FILE *kfd, FILE *ofd)
{
  u64 size = 0;
  byte ibuff[BUFFER_SIZE];
  byte kbuff[BUFFER_SIZE];
  byte obuff[BUFFER_SIZE];

  //
  while ((size = load_buffer(ifd, ibuff)))
    {
      load_buffer(kfd, kbuff);
      
      xor_buff(ibuff, kbuff, obuff, size);

      store_buffer(ofd, obuff, size);
    }
}

//
int main(int argc, char **argv)
{
  //Handling parameters
  if (argc < 4)
    return printf("Usage: %s [-e (encrypt) | -d (decrypt)] [input file] [key file (generated)] [output file]\n", argv[0]), -1;

  byte mode = 0;
  
  if (argv[1][0] == '-')
    if (argv[1][1] == 'e')
      mode = 'e';
    else
      if (argv[1][1] == 'd')
	mode = 'd';
      else
	return printf("Error: unknown mode, only -e or -d\n"), -3;
  
  //Not cryptographically secure
  srand(time(NULL));
  
  //Opening files with proper modes
  FILE *ifd = fopen(argv[2], "rb"); //Input clear file 
  FILE *ofd = fopen(argv[4], "wb"); //Output encrypted file
  FILE *kfd = fopen(argv[3], ((mode == 'e') ? "wb" : "rb")); //Read or generated key file
  
  //Verifying file states
  if (!ifd)
    return printf("Error: cannot read input file (%s)\n", argv[1]), -2;
  
  if (!kfd)
    return printf("Error: cannot create key file (%s)\n", argv[2]), -2;
  
  if (!ofd)
    return printf("Error: cannot create output file (%s)\n", argv[3]), -2;

  //
  if (mode == 'e')
    encrypt(ifd, kfd, ofd);
  else
    {
      //Check ifd and kfd sizes
      decrypt(ifd, kfd, ofd);
    }
  
  //Close files
  fclose(ifd);
  fclose(kfd);
  fclose(ofd);
  
  return 0;
}
