/*
  Silly example of ppm steganography.
  
  Each 2 bits from the input byte stream are spread over 4 bytes of the image.

   b0 b1 b2 b3 b4 b5 b6 b7   ... Input byte stream in 2 bit packs
   |__|  |__|  |__|  |__|
    ||    ||    ||    ||
    \/    \/    \/    \/
    B0    B1    B2    B3     ... Image bytes

  The least significant bits of an image byte are updated with the 2 bits from the input byte stream.
  This alters the colors but not enough to be observed with the naked eye. The generated image should 
  look similar to the original one and have both should have the same size.
  
  This program requires the user to provide the size (in bytes) of the hidden
  file for extraction to occur. This can be used as a measure of security, but
  it is no reliable.
  Another - unreliable - way is to store the size as 4, or 8, a bytes value in the
  first 16, or 32, bytes of the image: BYTE_STREAM_SIZE + BYTE_STREAM [+ REST_OF_IMAGE | eps]
   
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
#define BUFFER_SIZE 16

//
typedef unsigned u32;
typedef unsigned char byte;
typedef unsigned long long u64;

//
typedef struct ppm_s {
  
  u64 w;
  u64 h;
  u64 size;   //Size in bytes: w x h x 3
  byte *data;
  
} ppm_t;

//Open and load a ppm file in binary format (P6)
ppm_t *load_ppm(FILE *fd)
{
  u32 n = 0;
  byte c1, c2;
  u64 w = 0, h = 0;
  ppm_t *p = malloc(sizeof(ppm_t));

  fscanf(fd, "%c%c\n", &c1, &c2);

  printf("%c%c\n", c1, c2);
  
  if (c1 == 'P' && c2 == '6')
    {
      fscanf(fd, "%llu %llu\n", &w, &h);

      printf("%llu %llu\n", w, h);
      
      p->w = w;
      p->h = h;
      p->size = w * h * 3;
      p->data = malloc(sizeof(byte) * p->size);

      fscanf(fd, "%u\n", &n);

      printf("%u\n", n);
      
      printf("%llu\n", p->size);
      
      fread(p->data, sizeof(byte), p->size, fd);
    }
  else
    return printf("Error: unrecognized format\n"), NULL;
  
  return p;
}

//Write a ppm structure into a ppm file in binary format (P6)
void store_ppm(FILE *fd, ppm_t *p)
{
  fprintf(fd, "P6\n");
  fprintf(fd, "%lu %lu\n", p->w, p->h);
  fprintf(fd, "255\n");
  
  fwrite(p->data, sizeof(byte), p->size, fd);
}

//Clear all memory 
void release_ppm(ppm_t *p)
{
  if (p)
    if (p->data)
      {
	free(p->data); //RGB array
	free(p);       //Pointer
      }
}

//
u64 load_buffer(FILE *fd, byte *buffer, u64 size)
{
  return fread(buffer, sizeof(byte), size, fd);
}

//
u64 store_buffer(FILE *fd, byte *buffer, u64 size)
{
  return fwrite(buffer, sizeof(byte), size, fd);
}

//Hide buff1 in buff2
void hide(byte *buff1, byte *buff2, u64 size)
{
  const byte _s_[4] = {    0,    2,    4,    6 };
  const byte _m_[4] = { 0x03, 0x0C, 0x30, 0xC0 };
  
  for (u64 i = 0, j = 0; i < size; i++, j += 4)
    {
      byte c = buff1[i];

      byte b0 = (c & 0x03); 
      byte b1 = (c & 0x0C) >> 2; 
      byte b2 = (c & 0x30) >> 4; 
      byte b3 = (c & 0xC0) >> 6;

      buff2[j]     = (buff2[j]     & 0xFC) | b0;
      buff2[j + 1] = (buff2[j + 1] & 0xFC) | b1;
      buff2[j + 2] = (buff2[j + 2] & 0xFC) | b2;
      buff2[j + 3] = (buff2[j + 3] & 0xFC) | b3;
    }
}

//Extract buff1 in buff2
void extract(byte *buff1, byte *buff2, u64 size)
{
  for (u64 i = 0, j = 0; i < size; i++, j += 4)
    {
      byte b0 = (buff1[j]     & 0x03);
      byte b1 = (buff1[j + 1] & 0x03);
      byte b2 = (buff1[j + 2] & 0x03);
      byte b3 = (buff1[j + 3] & 0x03);
      
      buff2[i] = b0 | (b1 << 2) | (b2 << 4) | (b3 << 6);
    }
}

//Hiding process
u64 h_process(FILE *tfd, FILE *pfd, FILE *ofd)
{
  u64 i = 0;
  u64 size = 0, tsize = 0;
  byte tbuff[BUFFER_SIZE];
  ppm_t *p = load_ppm(pfd);

  //Read byte stream buffer and hide
  while ((size = load_buffer(tfd, tbuff, BUFFER_SIZE)))
    {
      hide(tbuff, p->data + (BUFFER_SIZE << 2) * i, size);

      tsize += size;
      
      i++;
    }

  //Write ppm file
  store_ppm(ofd, p);

  //Free allocated memory
  release_ppm(p);

  return tsize;
}

//Extraction process
void e_process(FILE *pfd, FILE *ofd, u64 size)
{
  u64 i;
  byte tbuff[BUFFER_SIZE];
  ppm_t *p = load_ppm(pfd);
  u64 q = size / BUFFER_SIZE, r = size % BUFFER_SIZE;
  
  for (i = 0; i < q; i++)
    {
      extract(p->data + (BUFFER_SIZE << 2) * i, tbuff, BUFFER_SIZE);
      store_buffer(ofd, tbuff, BUFFER_SIZE);
    }
  
  extract(p->data + (BUFFER_SIZE << 2) * (i + 1), tbuff, r);

  store_buffer(ofd, tbuff, r);
  
  release_ppm(p);
}

//
int main(int argc, char **argv)
{
  if (argc < 5)
    return printf("Usage: %s [-h (hide)] [file to hide] [input ppm file] [output ppm file]\n"
		  "                 [-e (extract)] [input ppm file] [output file] [file size in bytes]\n", argv[0]), -1;

  byte mode;

  if (argv[1][0] == '-')
    if (argv[1][1] == 'h')
      mode = 'h';
    else
      if (argv[1][1] == 'e')
	mode = 'e';
      else
	return printf("Error: unknown mode, only -h or -e\n"), -3;

  if (mode == 'h')
    {
      FILE *tfd = fopen(argv[2], "rb");
      FILE *pfd = fopen(argv[3], "rb");
      FILE *ofd = fopen(argv[4], "wb");

      if (!tfd)
	return printf("Error: cannot open file (%s)\n", argv[2]), -2;
      
      if (!pfd)
	return printf("Error: cannot open file (%s)\n", argv[3]), -2;

      if (!ofd)
	return printf("Error: cannot create file (%s)\n", argv[4]), -2;

      u64 size = h_process(tfd, pfd, ofd);

      printf("Size: %llu\n", size);
      
      fclose(tfd);
      fclose(pfd);
      fclose(ofd);
      
    }
  else
    if (mode == 'e')
      {
	FILE *pfd = fopen(argv[2], "rb");
	FILE *ofd = fopen(argv[3], "wb");
	u64 size = atoll(argv[4]);

	e_process(pfd, ofd, size);

	fclose(pfd);
	fclose(ofd);
      }
  
  return 0;
}

