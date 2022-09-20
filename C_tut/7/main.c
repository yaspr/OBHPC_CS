/*
  Ce programme permet de lire et d'afficher le contenu d'un fichier
  donné en paramètre.
  
  La lecture s'effectue par blocks de MAX_BUFFER caractères (lecture temporisée).
  
  Buffer en anglais ==> tampon en Français.
  
*/

#include <stdio.h>

//File Not Found
#define ERR_FNF 2

//
#define MAX_BUFFER 1024

//
int main(int argc, char **argv)
{
  if (argc < 2)
    {
      printf("Attention! Usage: %s [fichier d'entrée]\n", argv[0]);

      return 1;
    }

  //Un fichier est identifié par un descripteur (fd: file descriptor).
  //La fonction fopen permet d'ouvrir un fichier situé à l'emplacement spécifié dans
  //le chemin contenu dans la chaîne en paramètre.
  //Ouverture d'un fichier en mode lecture binaire (r: read, b: binary).
  FILE *fd = fopen(argv[1], "rb");

  //Si le fihcier n'existe pas.
  if (!fd)
    {
      printf("Erreur: le fihcier %s n'a pas ét trouvé\n", argv[1]);

      return ERR_FNF;
    }
  
  //
  int n;
  char buffer[MAX_BUFFER];

  //La fonction fread permet de remplir un tableau de caractères lus depuis un fichier.
  //Cette fonction retourne le nombre de caractères réellement lu. Par exemple, on peut
  //demander à la fonction de lire 1000 caractères, mais si le fichier en contient moins,
  //elle lira tous les caractères jusqu'à atteindre la fin du fichier, puis elle retournera 0.
  while ((n = fread(buffer, sizeof(char), MAX_BUFFER, fd)))
    {
      for (int i = 0; i < n; i++)
	putchar(buffer[i]);
    }
    
  //Après ouverture, un fichier doit être fermé.
  fclose(fd);
  
  return 0;
}
