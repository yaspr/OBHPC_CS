//Argument, paramètre, option, flag veulent dire la même chose.
#include <stdio.h>

//Nécessaire pour invoquer atoi.
#include <stdlib.h>

//Nécessaire pour strlen, strcpy, strncpy, strcmp, strncmp, ...
#include <string.h>

#define newline putchar('\n')

//La fonction main peut prendre des paramètres.
//Ces paramètres proviennent de la ligne de commandes.
int main(int argc, char **argv)
{
  //La variable argc est déterminée par le terminal.
  //Elle contient le nombre de paramètres passés au programme.
  //La variable argv contient les paramètres en chaînes de caractères.
  
  //Exemple: ./programme Hello 12 Arg3 Arg4
  //Après l'exécution du programme:
  
  //argc: 5
  //argv[0]: "programme"
  //argv[1]: "Hello"
  //argv[2]: "12"
  //argv[3]: "Arg3"
  //argv[4]: "Arg4"

  
  //On vérifie si le programme a le bon nombre de paramètres.
  if (argc < 5)
    {
      printf("Attention! Usage: %s Paramètre1 Paramètre2 Argument3 Nombre\n", argv[0]);

      return 1;
    }
  else
    {
      printf("argc: %d\n", argc);
      printf("argv[0]: %s\n", argv[0]);
      printf("argv[1]: %s\n", argv[1]);
      printf("argv[2]: %s\n", argv[2]);
      printf("argv[3]: %s\n", argv[3]);
      printf("argv[4]: %s\n", argv[4]);

      newline;
      
      //Il est possible de convertir une chaîne de caractère représentant un nombre en un nombre.
      int n = atoi(argv[4]);

      printf("%s * 3 = %d\n", argv[4], n * 3);

      newline;
      
      //Certaines opérations sur les chaînes de caractères peuvent être effectuée avec des fonctions
      //fournies par la librairie du language.

      //strlen : retourne la longueure d'une chaîne (le nombre de caractères).
      //strcpy : copie une chaîne source dans une chaîne destination. (ne jamais l'utiliser, source de bugs)
      //strncpy: copie les 'n' premiers caractères depuis une chaine source vers une chaîne destination.
      //strcmp : compare deux chaînes de caractères et retourne 0 si elles sont similaires. (ne jamais l'utiliser, source de bugs)
      //strncmp: compare les 'n' premiers caractères de deux chaînes de caractères.

      //Longueure du nom nu programme
      int len0 = strlen(argv[0]);
      int len1 = strlen(argv[1]);
      int len2 = strlen(argv[2]);
      int len3 = strlen(argv[3]);

      printf("len0:\t%d\nlen1:\t%d\nlen2:\t%d\nlen3:\t%d\n", len0, len1, len2, len3);
      
      //Allocation mémoire pour y copier le premier paramètre.  
      //Ne pas oublier le caractère de fin de chaîne, d'où le (len1 + 1) et pas len1.
      /*
	p: CCCCCCCCCCCCCCCCCCC0 <- caractère de fin de chaîne
	   -------------------  
	            |
		    v
	     len1 caractères
	 
        Nombre total de caractères: len1 + 1
	
      */
      char *p1 = malloc((len1 + 1) * sizeof(char));
      char *p2 = malloc((len2 + 1) * sizeof(char));
      char *p3 = malloc((len3 + 1) * sizeof(char));

      strncpy(p1, argv[1], len1);
      strncpy(p2, argv[2], len2);
      strncpy(p3, argv[3], len3);
      
      printf("p1: %s\n", p1);
      printf("p2: %s\n", p2);
      printf("p3: %s\n", p3);

      //Compare les deux chaînes argv[1] & p.
      int cmp1 = strncmp(argv[1], p1, len1);

      //On compare selon laplus petite longueure.
      /*
	    s1: Hello0.....
	    s2: HelloAgain0

	    On ne peut pas comparer ces deux chaînes au delà du dernier charactère de la plus courte. 
      */
      int cmp2 = strncmp(p2, p1, (len1 < len2) ? len1 : len2); 

      //
      int cmp3 = strncmp(p2, p3, (len2 < len3) ? len2 : len3);

      //
      printf("Les chaînes %s et %s sont: ", p1, argv[1]);
      
      if (cmp1 == 0)
	printf("similaires\n");
      else
	printf("différentes\n");

      //
      printf("Les chaînes %s et %s sont: %s\n", p1, p2, (cmp2) ? "différentes" : "similaires");
      printf("Les chaînes %s et %s sont: %s\n", p2, p3, (cmp3) ? "différentes" : "similaires");
      
      free(p1);
      free(p2);
      free(p3);
      
      return 0;
    }
}
