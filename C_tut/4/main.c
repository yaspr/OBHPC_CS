#include <stdio.h>

//Nécessaire pour utiliser les fonctions d'allocation mémoire
#include <stdlib.h>

#define newline putchar('\n')

/*
  Un pointeur est une variable dont la vleur est une adresse mémoire.
  Les pointeurs sont généralement utilisés pour implémenter les tableaux, 
  les listes chaînées, ...
				
  On suppose que la variable b est initialisée à 5 et est stockée en mémoire 
  à l'adresse 0x7AFFBC60.
  
  Après avoir exécuter l'expression C suivante:
  
  p = &b;  
  
  Le pointeur p aura comme valeur: p = 0x7AFFBC60.


  L'entier b est encodé sur 4 octets et contient la valeur .
  
                        @ mémoire    Donnée (1 ligne = 1 octet)
			              ________
				 0   |________|
				 .   |________|
				 .   |________|
				 .   |________|
			         .   |________|
			         .   |________|
		p -->	0x7AFFBC60   |00000000|
			0x7AFFBC61   |00000000|
			0x7AFFBC62   |00000000|
			0x7AFFBC63   |00000101|
			         .   |________|

  Pour accéder à la valeur pointée par p (5), il faut utiliser l'expression suivante: (*p).
  
  Par exemple: c = (*p) * 3;

  Pour afficher un pointeur avec printf, le format %p est utilisé.
  
 */

//
void testp(int v)
{
  int b = v;
  int *p = &v;

  printf("%p %d\n", p, (*p));
}


//Lorsqu'un tableau static est alloué, sa variable est un pointeur.
void testt()
{
  int t[10];

  //Affectation d'une valeur en utilisant un accès indexé
  t[0] = 0;

  //Affectation de valeurs en utilisant de l'arithmétique de pointeurs.
  *(t + 1) = 1;
  *(t + 2) = 2;
  *(t + 3) = 3;

  printf("%p %d %d %d %d %d\n", t, *t, t[0], t[1], *(t + 2), *(t + 3));
}

//malloc alloue une zone mémoire spécifiée par sa taille en octets.
int testm(int n)
{
  //Si n est inférieur à 2, quitte la fonction et retourne 0
  if (n < 2)
    return 0;
  
  //Calcul de la taille en octets.
  //En C, l'opérateur sizeof retourne la taille en octet du paramètre passé.
  //Ici, in retournera la taille d'un élément de type int (4 octets).
  //En multipliant cette valeur par le nombre d'éléments, on obtient la taille
  //mémoire totale à allouer en octets.
  int s = sizeof(int) * n; 

  //La fonction malloc retourne l'adresse mémoire du début de la zone allouée.
  //Cette adresse est stockée dans un pointeur.
  int *p = malloc(s);

  p[0] = 0;
  *(p + 1) = 1;
  
  printf("%p %d %d %d\n", p, *(p + 0), p[1], p[2]); 

  free(p);		  
}

//
int main()
{
  testp(5);

  newline;

  testt();

  newline;

  testm(3);
  
  return 0;
}
  
