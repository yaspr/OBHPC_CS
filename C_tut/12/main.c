/*

  166761116717888887111761161
  
  111111111116666667777788888
  
*/
#include <stdio.h>
#include <stdlib.h>

//
typedef struct count_val_s { unsigned count; unsigned val; } count_val_t;

//
unsigned sort(unsigned *t, unsigned long long n)
{
  for (unsigned long long i = 0; i < n; i++)
    for (unsigned long long j = i + 1; j < n; j++)
      if (t[i] > t[j])
	{
	  unsigned tmp = t[i];
	  
	  t[i] = t[j];
	  t[j] = tmp;
	}
}

//Find the value ta repeats the most 
count_val_t *find_mode(unsigned *t, unsigned long long n)
{
  //
  unsigned curr_m = 0;
  unsigned curr_v = 0;
  count_val_t *cv = malloc(sizeof(count_val_t));
  
  //
  for (unsigned long long i = 0; i < n; i++)
    {
      unsigned c = 0;
      unsigned v = t[i];
      
      while (t[i] == v)
	{
	  i++;
	  c++;
	}
      
      if (c > curr_m)
	{
	  curr_v = v;
	  curr_m = c;
	}
    }

  cv->val   = curr_v;
  cv->count = curr_m;

  return cv;
}

//
void print_tab(unsigned *t, unsigned long long n)
{
  for (unsigned long long i = 0; i < n; i++)
    printf("%u, ", t[i]);

  printf("\n");
}

//
int main(int argc, char **argv)
{
  //
  unsigned long long n = 33;
  unsigned t[33] = { 8, 1, 6, 7, 1, 6, 1, 8, 6, 7, 1,
		     7, 1, 8, 8, 6, 6, 7, 1, 6, 8 ,7,
		     8, 1, 1, 6, 1, 8, 6, 6, 7, 1, 1 };

  print_tab(t, n);
  
  //
  sort(t, n);

  print_tab(t, n);
  
  count_val_t *cv = find_mode(t, n);

  printf("Mode: %u\t Count: %u\n", cv->val, cv->count);
  
  return 0;
}
