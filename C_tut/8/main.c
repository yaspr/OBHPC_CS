//Ce programme permet de lire un fichier et d'en effectuer une copie
#include <stdio.h>
#include <string.h>

//File Not Found - Fichier non trouvé 
#define ERR_FNF 2

//Cannot Create File - Impossible de créer le fichier
#define ERR_CCF 3

//Wrong Destination Path - Chemin destination erroné
#define ERR_WDP 4

//
#define MAX_BUFFER 1024

//
int main(int argc, char **argv)
{
  //Cette syntaxe: return X, Y; implique que l'expression X sera exécutée et qu'ensuite, l'expression
  //Y sera exécutée et sa valeur retournée. Pour l'expression: return X, Y, Z; c'est la valeur de Z qui sera
  //retournée.
  if (argc < 3)
    return printf("Usage: %s [fichier source] [fichier destination]\n", argv[0]), 1;

  //
  int len1    = strlen(argv[1]);
  int len2    = strlen(argv[2]);

  //Vérification des noms de fichiers. Le nom du fichier source doit être différent du nom du fichier destination. 
  if ((len1 == len2) && !strncmp(argv[1], argv[2], len1))
    {
      printf("Erreur: le chemin du fichier source doit être différent de celui du fichier destination\n");
      
      return ERR_WDP;
    }
  
  //Ouverture du fichier source
  FILE *fd_in = fopen(argv[1], "rb");

  //
  if (!fd_in)
    return printf("Erreur: le fichier %s n'a pas été trouvé\n", argv[1]), ERR_FNF;

  //Ouverture d'un fichier en écriture (le fichier destination, copie)
  FILE *fd_out = fopen(argv[2], "wb");

  if (!fd_out)
    return printf("Erreur: le fichier %s n'a pas pu être créé\n", argv[2]), ERR_CCF;

  //
  char buffer[MAX_BUFFER];
  
  //
  int n;

  //
  while ((n = fread(buffer, sizeof(char), MAX_BUFFER, fd_in)))
    fwrite(buffer, sizeof(char), n, fd_out);

  //
  fclose(fd_in);
  fclose(fd_out);
  
  return 0;
}
