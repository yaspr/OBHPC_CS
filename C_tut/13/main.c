/*
  Exemple de tables de hachages.
  
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
#include "rdtsc.h"

//
#define MAX_RUN 100000000

//
#define MAX_STR 128

//
typedef struct hashtab_entry_s {

  //
  unsigned          eid;
  unsigned char    *str;
  unsigned          len;

  //
  unsigned long long hash;

  //
  struct hashtab_entry_s *next;
  
} hashtab_entry_t;

//
typedef struct hashtab_s {

  //
  hashtab_entry_t **entries;

  //
  unsigned long long *nb_collisions_per_entry;
  
  //
  unsigned long long size;

  //
  unsigned long long nb_entries;
  
  //
  unsigned long long nb_collisions;

  unsigned long long (*hash_fct)(char *);
  
} hashtab_t ;

//Global entry id
unsigned geid = 0;

//Dan Bernstein 
unsigned long long djb2(char *str)
{
  int c;
  unsigned long long hash = 5381;

  while (c = *str++)
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return hash;
}  

//SDBM hash functions
unsigned long long sdbm(char *str)
{
  int c;
  unsigned long hash = 0;
  
  while (c = *str++)
    hash = c + (hash << 6) + (hash << 16) - hash;
  
  return hash;
}

//Polynomial rolling hash
unsigned long long prh(char *str)
{
  char c;
  const int p = 31;
  const int m = 1e9 + 9;
  unsigned long long hash  = 0;
  unsigned long long p_pow = 1;

  while (c = *str++)
    {
      hash = (hash + (c - 'a' + 1) * p_pow) % m;
      p_pow = (p_pow * p) % m;
    }

  return hash;
}

//
hashtab_t *hashtab_init(unsigned long long hashtab_size, unsigned long long (*hash_fct)(char *))
{
  hashtab_t *ht = malloc(sizeof(hashtab_t));

  if (ht)
    {
      ht->nb_entries = 0;
      ht->hash_fct = hash_fct;
      ht->size = hashtab_size;
      
      ht->entries = malloc(sizeof(hashtab_entry_t *) * hashtab_size);

      //Set bytes to 0
      memset((void *)ht->entries, 0, sizeof(hashtab_entry_t *) * hashtab_size);
    }
  
  return ht;
}

//
void hashtab_fini(hashtab_t *ht)
{
  if (ht)
    {
      if (ht->entries)
	{
	  for (unsigned long long i = 0; i < ht->size; i++)
	    {
	      hashtab_entry_t *n = NULL;
	      hashtab_entry_t *e = ht->entries[i];
	      
	      while (e)
		{
		  n = e->next;

		  if (e->str)
		    free(e->str);

		  free(e);

		  e = n;
		}
	    }

	  free(ht->entries);
	}
      
      free(ht);
    }
}

//
hashtab_entry_t *hashtab_entry_lookup(hashtab_entry_t *l, char *str)
{
  if (l && str)
    {
      int not_found = 1;
      hashtab_entry_t *e = l;
      hashtab_entry_t *p = l;
      unsigned str_len = strlen(str);

      //
      while (not_found && e)
	{
	  if (e->len == str_len)
	    not_found = strncmp(e->str, str, str_len);

	  p = e;
	  e = e->next;
	}

      return (not_found) ? NULL : p;
    }
  else
    return NULL;
}

//
hashtab_entry_t *hashtab_entry_init(char *str)
{
  hashtab_entry_t *e = malloc(sizeof(hashtab_entry_t));

  if (e)
    {
      unsigned str_len = strlen(str);
      
      e->eid = geid++;
      e->len = str_len;
      e->str = malloc(sizeof(char) * (str_len + 1));
      
      if (e->str)
	{
	  strncpy(e->str, str, str_len);

	  str[str_len] = 0;
	}
      else
	return  NULL;
      
      e->next = NULL;
    }
  
  return e;
}

//
hashtab_entry_t *hashtab_entry_insert(hashtab_entry_t *l, hashtab_entry_t *e)
{
  if (l && e)
    {
      hashtab_entry_t *n = l;
      
      while (n->next)
	n = n->next;

      n->next = e;
    }
  else
    return NULL;
}

//
void hashtab_print(hashtab_t *ht)
{
  if (ht)
    {
      unsigned long long size = ht->size;
      
      for (unsigned long long i = 0; i < size; i++)
	{
	  hashtab_entry_t *l = ht->entries[i];

	  //
	  printf("[%10llu]\n\n", i);
	  
	  //
	  while (l)
	    {
	      printf("\t%10llu\t %50s\t %llu\n", l->eid, l->str, ht->hash_fct(l->str) % size);
	      l = l->next;
	    }

	  printf("\n");
	}
    }
}

//
hashtab_entry_t *hashtab_lookup(hashtab_t *ht, char *str)
{
  if (ht && str)
    {
      unsigned long long h = ht->hash_fct(str) % ht->size;
      
      hashtab_entry_t *e = ht->entries[h];
      
      return hashtab_entry_lookup(e, str);
    }
  else
    return NULL;
}

//
hashtab_t *hashtab_load_dictionary(char *fname, unsigned long long hashtab_size, unsigned long long (*hash_fct)(char *))
{
  hashtab_t *ht = NULL;
  FILE *fp = fopen(fname, "rb");
  
  if (fp)
    {
      //
      ht = hashtab_init(hashtab_size, hash_fct);

      if (ht)
	{
	  //
	  char entry_str[MAX_STR + 1];
	  unsigned long long nb_reads = 0;

	  ht->nb_entries = 0;
	  ht->size = hashtab_size;
	  
	  while ((nb_reads = fscanf(fp, "%s\n", entry_str)) !=  EOF)
	    {
	      //Create new node
	      hashtab_entry_t *e = hashtab_entry_init(entry_str);
	      
	      //Calculate hash
	      unsigned long long h = ht->hash_fct(entry_str) % hashtab_size;

	      hashtab_entry_t *l = ht->entries[h];

	      if (l)
		{
		  hashtab_entry_insert(l, e);
		  ht->nb_collisions++;
		}
	      else
		ht->entries[h] = e;

	      ht->nb_entries++;
	    }

	  return ht;
	}

      fclose(fp);
    }

  return NULL;
}

//
int main(int argc, char **argv)
{
  if (argc < 4)
    return printf("Usage: %s [string] [words file] [hash functions: 0, 1, 2]\n", argv[0]), 2;

  //
  unsigned long long hf_id = atoll(argv[3]);

  if (hf_id > 2)
    return printf("Error: bad hash function id (%llu)\n", hf_id), 3;
  
  //
  const char *hf_names[] = { "djb2", "sdbm", "prh" };
  unsigned long long (*hf_list[])(char *) = { djb2, sdbm, prh };

  unsigned long long hashtab_size = 10000;
  
  //djb2, sdbm, prh
  hashtab_t *ht = hashtab_load_dictionary(argv[2], hashtab_size, hf_list[hf_id]);
  
  //hashtab_print(ht);

  printf("Running with: %s\n", hf_names[hf_id]);

  unsigned long long sz_kib = sizeof(hashtab_entry_t) * ht->nb_entries / 1024;
  unsigned long long sz_mib = sz_kib / 1024;
  
  printf("Hashtab size\t\t:\t %10llu KiB %10llu MiB\n", sz_kib, sz_mib);
  
  printf("# enrties\t\t:\t %10llu\n", ht->nb_entries);
  printf("# collisions\t\t:\t %10llu\n", ht->nb_collisions);
  printf("Delta\t\t\t:\t %10llu\n", (ht->nb_entries > ht->nb_collisions) ? ht->nb_entries - ht->nb_collisions : ht->nb_collisions - ht->nb_entries);
  
  printf("Percentage of collisions:\t %10.3lf %%\n", (((double) ht->nb_collisions * 100) / ht->nb_entries));

  //
  volatile hashtab_entry_t *n = NULL;

  //Perform 1000 lookups and measures the cycles
  unsigned long long before = rdtsc();
  
  for (volatile unsigned i = 0; i < MAX_RUN; i++)
    n = hashtab_lookup(ht, argv[1]);

  unsigned long long after = rdtsc();

  //
  if (n)
    printf("\n%s FOUND at position %llu\n", n->str, n->eid);
  else
    printf("\nNOT FOUND\n");

  //
  printf("Cycles: %lf\n", (double)(after - before) / MAX_RUN);
  
  //
  hashtab_fini(ht);
  
  return 0;
}
