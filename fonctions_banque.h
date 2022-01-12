/*
 --Fichiers contenant le header de tout les programmes qui seront chargés dans le
 main pour utilisation
 --Codé par Tha_Carter
 --Copyright (c) 2020-2021
*/

#ifndef FONCTIONS_BANQUE_H_INCLUDED
#define FONCTIONS_BANQUE_H_INCLUDED

 // Insertion des includes necessaires au fonctionement des programmes
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #include <string.h>
  #include "fonctions_banque.h"

 // Déclaration des structures nécessaires a la gestion du programme
   typedef struct Proprietaire Proprietaire;
   struct Proprietaire
    {
      char nomProp [50];
      char prenomProp [50];
      int telProp [9];
      char emailProp [100];
    };
   typedef struct Compte Compte;
   struct Compte
    {
      int numero;
      char date [11];
      Proprietaire prop;
      int montant;
      char etat [7];
      int codePin;
    };
      // Listes chainées utilisées pour la réalisation des depots et retraits
   typedef struct Element Element;
   struct Element
    {
      int montant;
      Element * suivant;
    };

    typedef struct Liste Liste;
    struct Liste
     {
       Element * premier;
     };

  // Insertion des headers des fonctions
   int affMenu();
   void espace ();
   void fileError ( FILE * a );
   int countLine ( FILE * a );
   void creerCmpte ();
   int rechCompteNum ( int numCompte );
   void rechCompteNom ();
   void rechCompte ();
   void consCompte ();
   void initListe ( Liste * L );
   void creerElt ( Element * e );
   void ajoutElt ( Liste * L , Element e );
   void insListe ( Liste L , int num_saisi );
   void depCompte ();

#endif // FONCTIONS_BANQUE_H_INCLUDED
