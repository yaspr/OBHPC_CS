#include <stdio.h>

/*
  Il existe deux types de blocks de code en C: les fonctions et les procédures.
  
  On appel fonction tout block retournant une valeur après exécution.
  On appel procédure tout block ne retournant aucune valeur après exécution.
  
 */

//Fonction qui prend deux paramètres en entrée et qui retourne leur somme
int _add_(int a, int b)
{
  return a + b;
}

//Procédure invoquant la fonction _add_ et ayant comme tâche d'afficher le résultat
//retourné.
void print_add(int a, int b)
{
  printf("%d + %d = %d\n", a, b, _add_(a, b));
}

//Autre syntaxe
void print_add2(int a, int b)
{
  int r = _add_(a, b);
  
  printf("%d + %d = %d\n", a, b, r);
}

//
double _mul_(double a, double b)
{
  return (a + b);
}

//
void print_mul(double a, double b)
{
  printf("%lf * %lf = %lf\n", a, b, _mul_(a, b));
}

//
void print_mul2(double a, double b)
{
  printf("%.5lf * %.5lf = %.5lf\n", a, b, _mul_(a, b));
}

//
void print_mul3(double a, double b)
{
  printf("%.10lf * %.10lf = %.10lf\n", a, b, _mul_(a, b));
}

//
int main()
{
  print_add(2, 5);
  print_add2(10, 15);

  print_mul(3.142672576, 934.162781);
  print_mul2(3.142672576, 934.162781);
  print_mul3(3.142672576, 934.162781);
  
  return 0;
}
  
