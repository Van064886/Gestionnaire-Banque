/*
 --Programme de gestion d'une banque
 --Codé par Tha_Carter
 --Copyright (c) 2020-2021
*/
/*
int opt = 0;
  printf(">> Bienvenue dans ce programme de Gestion d'une banque ..\nAppuyez une touche pour continuer.\n"); alias : debut;
  espace();
  getchar();
  system ("clear");
  opt = affMenu();
  switch (opt)
   {
     case 1 :
      creerCmpte();
      break;
     default :
      printf("Cette option n'est pas disponible ..\n");
      goto debut;
      break;
   }
*/
#include "fonctions_banque.h"

int main()
{
  /*Liste l;
  int num = 1;
  insListe( l , num );
  //depCompte();*/
  consCompte();
  return 0;
}
