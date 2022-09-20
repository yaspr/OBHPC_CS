//Nécessaire pour utiliser la fonction time pour initialiser
//la graine du générateur aléatoire.
#include <time.h>

//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Intervalle de génération du nombre mystère
#define MIN_VAL  1

//
#define MAX_VAL1 10
#define MAX_VAL2 100
#define MAX_VAL3 1000

//Nombre maximal de tentatives
#define MAX_ATTEMPT 10

//
unsigned randxy(unsigned x, unsigned y)
{
  return (rand() % (y - x + 1)) + x;
}

//
int main(int argc, char **argv)
{
  if (argc < 2)
    return printf("Usage: %s [niveau de difficulté]\n\n"
		  "\t1: niveau facile\t\t(1, 10)\n"
		  "\t2: niveau moyen\t\t\t(1, 100)\n"
		  "\t3: niveau difficile\t\t(1, 1000)\n\n", argv[0]), -1;
  
  //Si à 1 ==> mode test/debug/développeur/tricheur :)
  //Si à 0 ==> mode joueur
  int c0d3r_mode = (!strncmp(argv[1], "0xc0d3r", 6));

  //Niveau de difficulté: 1 2 3 4
  //Si le programme est en mode test, le niveau 1 est appliqué
  int diff = (c0d3r_mode) ? 1 : atoi(argv[1]);

  //
  int min = MIN_VAL, max;
  
  switch (diff)
    {
      
    case 1:

      max = MAX_VAL1;
      break;
      
    case 2:

      max = MAX_VAL2;
      break;

    case 3:
      
      max = MAX_VAL3;
      break;

    default:

      printf("Erreur: mauvais niveau de difficulté. Valeurs autorisées: 1 2 3\n");
      return 1;
    }
  
  //Initialisation du générateur aléatoire
  srand(time(NULL));

  //
  unsigned m; //Nombre mystère
  unsigned n; //Nombre tentative
  unsigned nb_entries = 0; //Nombre de tentatives

  //Pour gérer les touches Entrée (retour chariot)
  char garbage;

  //
  int same = 0;
  int new_game = 0;

  //Pour gérer les 
  char answer;
  int answer_ok;
  
  do {
    
    //
    unsigned m = randxy(min, max);
    
    //Mode debug/developpeur/test
    if (c0d3r_mode)
      printf("==> m : %u\n", m);
    
    //Tant que n est différent de m,  
    while (!same && nb_entries < MAX_ATTEMPT)
      {
	//
	printf("%3d\tEntrer une valeur entre %d & %d: ", nb_entries + 1, min, max);
      
	//La fonction scanf permet de lire une valeur depuis le clavier.
	//Le format à spécifier pour la lecture est similaire au format utilisé pour afficher avec printf.
	scanf("%u", &n);
	scanf("%c", &garbage); //
	
	same = (n == m);
      
	if (!same)
	  if (n > m)
	    printf("\n\tTrop haut\n\n");
	  else
	    printf("\n\tTrop bas\n\n");
      
	nb_entries++;
      }
  
    //
    if (same)
      printf("\nBravo: le nombre mystère a été trouvé après %u tentatives\n", nb_entries);
    else
      {
	printf("\nPerdu :( ... Le nombre était: %u\n", m);

	//
	do
	  {
	    printf("\nNouvelle partie? (O/o ou N/n)? ");
	    scanf("%c", &answer);
	    scanf("%c", &garbage);
	    
	    //
	    switch (answer)
	      {

	      case 'O':
	      case 'o':

		same = 0;
		nb_entries = 0;
		
		new_game = 1;
		answer_ok = 1;
		break;
	      
	      case 'N':
	      case 'n':

		new_game = 0;
		answer_ok = 1;
		break;
	      
	      default:
		printf("\n\t## Erreur: réponse non valide!\n");
		answer_ok = 0;

	      }
	  }
	while (!answer_ok);
      }
  }
  while (new_game);

  printf("Merci, au revoir :)\n");
  
  return 0;
}
