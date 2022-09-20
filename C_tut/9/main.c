/*
  Ce programme est un exmeple d'usages des opérations sur les bits.
  
  Attention, ne pas confondre avec les opérateurs logiques: && et || qui évaluent
  une condition non des valeurs booléennes (0 --> Faux, 1 --> Vrai).

  Les opérateurs binaires sont les suivants:

  ## Le NON, inverse, negation (NOT, symbole ~). Table de vérité:
  
  A  | 0 | 1 |
  -----------|
     | 1 | 0 |

  ## Le ET (AND, symbole &). Table de vérité:
        
  A &
  A \ B | 0 | 1 |
  --------------|
  0     | 0 | 0 |
  ------|-------|   ==> 0 & 0 = 0; 0 & 1 = 0; 1 & 0 = 0; 1 & 1 = 1;  
  1     | 0 | 1 |

  Cette opération ne retourne 1 (Vrai) que lorsque les deux opérandes sont à 1 (Vraies).
  
  ## Le OU (OR, symbole |). Table de vérité:
        
  A \ B | 0 | 1 |
  --------------|
  0     | 0 | 1 |
  ------|-------|   ==> 0 | 0 = 0; 0 | 1 = 1; 1 | 0 = 1; 1 | 1 = 1;  
  1     | 1 | 1 |
  
  Cette opération retourne 1 (Vrai) lorsque l'un des deux opérandes est à 1 (Vrai).

  ## Le OU exclusif (XOR, symbole ^). Table de vérité:
        
  A \ B | 0 | 1 |
  --------------|
  0     | 0 | 1 |
  ------|-------|   ==> 0 ^ 0 = 0; 0 ^ 1 = 1; 1 ^ 0 = 1; 1 ^ 1 = 0;  
  1     | 1 | 0 |
  
  Cette opération retourne 1 (Vrai) lorsque l'un des deux opérandes est à 1 (Vrai) et l'autre à 0 (Faux).

*/

#include <stdio.h>

//
#define newline putchar('\n')

//Un byte ou octet est un block de 8 bits.
typedef unsigned char byte;

//Cette fonction affiche la représentation binaire d'un nombre dans l'ordre inverse.
//Exemple: 5 sur 8 bits = 00000101, la fonction affichera 10100000.
//Elle affiche nbits bits.
void ibin(unsigned v, byte nbits)
{
  unsigned w = v;
  
  //
  for (byte i = 0; i < nbits; i++)
    {
      printf("%d", w & 1);
      w >>= 1;
    }

  putchar('\n');
}

//Fonction qui inverse 8 bits en log2(8) = 3 lignes.
byte reverse8(byte b)
{
  b = (b >>  1) & 0x55 | (b << 1) & 0xAA;
  b = (b >>  2) & 0x33 | (b << 2) & 0xCC;
  b = (b >>  4) & 0x0F | (b << 4) & 0xF0;

  return b;
}


//Fonction qui inverse 8 bits en log2(8) = 3 lignes.
unsigned reverse32(unsigned v)
{
  v = (v >>  1) & 0x55555555  | (v <<  1) & 0xAAAAAAAA;
  v = (v >>  2) & 0x33333333  | (v <<  2) & 0xCCCCCCCC;
  v = (v >>  4) & 0x0F0F0F0F  | (v <<  4) & 0xF0F0F0F0;
  v = (v >>  8) & 0x00FF00FF  | (v <<  8) & 0xFF00FF00;
  v = (v >> 16) & 0x0000FFFF  | (v << 16) & 0xFFFF0000;
  
  return v;
}

//
void bin(unsigned v, byte nbits)
{
  unsigned w = (nbits > 8) ? reverse32(v) : reverse8(v);
  
  //
  for (byte i = 0; i < nbits; i++)
    {
      printf("%d", w & 1);
      w >>= 1;
    }

  putchar('\n');
}

//
int main()
{
  //Affectation d'une valeur encodée en hexadécimal en utilisant le préfixe 0x.
  unsigned a = 0x7FFE7FFF;

  //Affectation d'une valeur encodée en binaire à travers le préfixe 0b.
  byte b = 0b00000100;
  
  //
  printf("inverse(%u)\t:", b);
  ibin(b, 8);
  
  printf("%u\t\t:", b);
  bin(b, 8);  

  newline;

  //
  printf("inverse(0x%08x)\t:", a);
  ibin(a, 32);
  
  printf("0x%08x\t\t:", a);
  bin(a, 32);  

  newline;
  
  //
  byte c = 0xF0;
  byte d = 0x0F;

  //
  printf("0x%02x xor 0x%02x = 0x%02x\n", c, d, c ^ d);
  
  return 0;
}
