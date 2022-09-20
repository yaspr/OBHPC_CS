/*
  Fichier d'entête contenant les références
  vers les fonctions d'entrées/sorties standard.
*/

//Standard Input Output
#include <stdio.h>

/*
  En C, une chaîne de caractère se termine toujours par le caractère de code ASCII 0 ou '\0'.

 */

//Fonction principale
int main()
{
  //Invocation de printf avec une chaîne de caractères en paramètre.
  //Le caractère \n est un caractère spécial représentant un retour à la ligne.
  printf("Hello, World!\n");

  //Le symbole %s est utilisé pour afficher les chaînes de caractères.
  //Une chaîne de caractères constante doit être placée entre quotes.
  printf("%s\n", "Hello, World!");
  
  //Le caractère \t représente une tabulation.
  printf("\tHow are things going?\n");

  //Les caractères constants doivent être entre deux apostrophes et sont
  //représentés par %c dans la chaîne de format.  
  printf("This is a character: %c\n", 'k');
  
  //Pour affichier des valeures entières relatives, le symbol %d est utilisé
  //afin de signaler le format à la fonction printf.
  printf("%d + %d = %d\n", 5, 6, 11);
  
  //Le symbol %f est utilisé pour les valeures flottante simple précision.
  //Le symbol %lf est utilisé pour les valeures flottante double précision.
  printf("%d %f %lf\n", 1.3, 1.3, 1.3); 

  //The symbole %u est utilisé pour signaler un entier non signé, donc positif.
  printf("%u %u\n", -1, 1);
  
  return 0;
}
