#include <stdio.h>
#include <stdlib.h>

#define ERR_ZERO   0
#define ERR_NULL  -1

#define newline putchar('\n')

//
int func(int a, int b, int **t)
{
  int i;

  if ((*t) != NULL)
    return ERR_NULL;

  //Si a ou b est égal à 0. Une autre syntaxe: if (!a || !b). Si inverse de a ou in verse de b.
  //L'opérateur || symbolise le ou logique (booléen).
  //L'opérateur !, inverse une valeur: si valeur == 0, alors l'inverse sera 1; si la valeur est != 0,
  //alors l'inverse sera 0.
  if (a == 0 || b == 0)
    return ERR_ZERO;
  
  if (a < b)
    {
      //Allocation mémoire et stockage dans un pointeur passé en paramètre
      (*t) = malloc(sizeof(int) * b);

      for (i = 0; i < b; i++)
	(*t)[i] = a;

      return b;
    }
  else
    if (a > b)
      {
	(*t) = malloc(sizeof(int) * a);

	for (i = 0; i < a; i++)
	  (*t)[i] = b; 

	return a;
      }
    else //a == b
      {
	(*t) = malloc(sizeof(int) * a * b);
	
	for (i = 0; i < a * b; i++)
	  (*t)[i] = 0;
	
	return (a * b);
      }
}

//
void cnuf(int **t)
{
  //En C, tout ce qui n'est pas égal à zero est vrai.
  //Si le pointeur vers le pointeur n'est pas NULL, donc il contient une adresse,
  if (t)
    if (*t) //Si pointée par le pointeur n'est pas NULL
      free(*t);
}

//
void call_func(int a, int b)
{
  int *t = NULL;

  //Ici, le troisième paramètre est un pointeur vers un pointeur
  int n = func(a, b, &t);
  
  if (n == ERR_NULL)
    printf("Erreur: le pointeur doit être initialisé à NULL\n");
  
  if (n == ERR_ZERO)
    printf("Erreur: A et B doivent être non nuls\n");

  printf("Valeurs du tableau pour a = %d et b = %d:\t\t", a, b);
  
  for (int i = 0; i < n; i++)
    printf("%d ", t[i]);
  
  cnuf(&t);
}

//
int main()
{
  //
  call_func(1, 2);

  newline;

  //
  call_func(4, 3);

  newline;

  //
  call_func(5, 5);

  newline;

  return 0;
}
