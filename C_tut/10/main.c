//
#include <stdio.h>

//
#define SQUARE(x) ((x) * (x))

//Genère la séquence suivante: 0 3 6 9 12 ...
void seq3(int *t, int n)
{
  int m = 0;
  
  for (int i = 0; i < n; i++)
    {
      t[i] = m;
      m += 3;
    }
}

//
void seq4(int *t, int n)
{
  for (int i = 0, j = 0; i < n; i++, j += 4)
    t[i] = j;
}

//
void seq_tri(int *t, int n)
{
  int r;
  
  for (int i = 0; i < n; i++)
    {
      r = 0;
      
      for (int j = 1; j <= i; j++)
	r += j;

      t[i] = r;
    }
}

//
void seq_prec(int *t, int n)
{
  t[0] = 2;
  
  for (int i = 1; i < n; i++)
    t[i] = SQUARE(t[i - 1]); 
}

//
void print_tab(int *t, int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", t[i]);

  putchar('\n');
}

//Fonction qui écrit les données en format texte (humainement lisible)
//Cette fonction fait appel à fprintf qui comme printf elle affiche en utilisant un format
//mais dans un fichier au lieu de la sortie standard.
void write_tab_to_file(char *fname, int *t, int n)
{
  //
  FILE *fd = fopen(fname, "w");
  
  //
  if (fd)
    {
      for (int i = 0; i < n; i++)
	fprintf(fd, "%d ", t[i]);
      
      fprintf(fd, "\n");
      
      fclose(fd);
    }
}

//
int main()
{
  int t[100];
  
  //
  seq3(t, 20);
  
  printf("seq3(t, 20): ");
  print_tab(t, 20);
  write_tab_to_file("seq3.txt", t, 20);
  
  //
  seq4(t, 30);
  
  printf("seq4(t, 20): ");
  print_tab(t, 30);
  write_tab_to_file("seq4.txt", t, 30);
  
  //
  seq_tri(t, 10);
  
  printf("seq_tri(t, 20): ");
  print_tab(t, 10);
  write_tab_to_file("seq_tri.txt", t, 10);
  
  //
  seq_prec(t, 15);

  //
  printf("seq_prec(t, 20): ");
  print_tab(t, 15);
  write_tab_to_file("seq_prec.txt", t, 15);
  
  return 0;
}
