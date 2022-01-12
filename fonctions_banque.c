/*
 --Fichiers contenant tout les programmes qui seront chargés dans le
 main pour utilisation
 --Codé par Tha_Carter
 --Copyright (c) 2020-2021
*/

#include "fonctions_banque.h"

 void espace ()
   {
      for ( int i = 0 ; i <= 2 ; i++ )
      printf("\n");
   }

  // Fonction pour l'affichage du menu
  int affMenu()
   {
    int rep = 0;

    printf("********************PROGRAMME DE GESTION DE BANQUE*********************\n");
    for ( int i = 0 ; i <= 5 ; i++ )
     printf("\n");
    printf("_________________MENU___________________\n");
    printf("1- Creer un compte client ---> Tapez 1 \n");
    printf("\n");
    printf("2- Rechercher un compte ---> Tapez 2 \n");
    printf("\n");
    printf("3- Consulter un compte ---> Tapez 3 \n");
    printf("\n");
    printf("4- Faire un dépot sur un compte ---> Tapez 4 \n");
    printf("\n");
    printf("5- Faire un retrait d'un compte ---> Tapez 5 \n");
    printf("\n");
    printf("6- Faire un transfert entre deux comptes ---> Tapez 6 \n");
    printf("\n");
    printf("7- Consulter l'historique des actions sur un compte ---> Tapez 7 \n");
    printf("\n");
    printf("Saisissez votre réponse : \n > ");
    scanf("%d", &rep);
    return rep;
   }

    // Gestion des erreurs liés a l'ouverture de fichiers
  void fileError ( FILE * a )
   {
     if ( a == NULL )
      {
        printf("Impossible d'accéder au fichier\n");
        exit(-1);
      }
   }

  // Fonction Creer un compte
  int countLine ( FILE * a )
   {
     int compteur = 0, c;
     fileError( a );
     while ( ( c = getc( a )) != EOF )
      {
        if ( c == '\n')
         compteur ++;
      }
      return compteur;
   }


  void creerCmpte ()
   {
     Compte c;
     int d;
     FILE * user;
     printf("****************CREATION D'UN COMPTE *********************\n");
     espace();

       // Gestion automatique numero de compte lors de la creation
     FILE * fichier_num;
     fichier_num = fopen("numero.txt" , "r");
     d = countLine( fichier_num );
     fclose( fichier_num );

      // Remplissage des champs du compte
    printf("Votre numéro de compte sera : %d\n",d);

        // Sauvegarde de l'indice numéro dans un fichier
    fichier_num = fopen("numero.txt" , "a");
    fileError( fichier_num );
    fprintf(fichier_num , "%d\n" , d );

    printf("Saisir la date : jj-mm-aaaa \n > ");
    scanf("%s", c.date);
    printf("Saisir votre nom : \n > ");
    scanf("%s", c.prop.nomProp);
    printf("Saisir votre prénom : \n > ");
    scanf("%s", c.prop.prenomProp);
    printf("Saisir votre email : \n > ");
    scanf("%s", c.prop.emailProp);
    printf("Saisir votre contact téléphonique : \n > ");
    scanf("%s" , c.prop.telProp);
    printf("Saisir le montant :\n > ");
    scanf("%d", &c.montant);
    strcpy( c.etat , "actif");
    printf("L'etat du compte est : %s\n", c.etat);
    printf("Saisir votre code Pin : \n > ");
    scanf("%d", & c.codePin);

     // Enregistrement des infos dans un fichier
    user = fopen( "users.txt" , "a" );
    fileError( user );
    fprintf( user , "%d %s %s %s %s %s %d %s %d\n", d, c.date , c.prop.nomProp , c.prop.prenomProp , c.prop.emailProp ,
     c.prop.telProp , c.montant , c.etat  , c.codePin );
    fclose( user );
   }

   // Fonctions de recherche de compte
  int rechCompteNum ( int numCompte )
   {
     int fdata , c , cVal = -1;
     FILE * fichierNum;

      // Ouverture du fichier pour la recherche par numero
     fichierNum = fopen( "numero.txt" , "r" );
     fileError( fichierNum );
     while ( ! feof( fichierNum ) )
      {
        fscanf( fichierNum , "%d\n" , &fdata );
        if ( fdata == numCompte )
         {
           printf("Ce compte existe dans la base de données...\nPour y accéder , utilisez l'option consulter un compte \n");
           cVal = 1;
         }
        else
         {
           printf("Ce compte n'existe pas ..\n");
         }
      }
      fclose( fichierNum );
      return cVal;
   }

  void rechCompteNom ()
   {
     char nom [50];
     FILE * fichier;
     int num = 0 , montant = 0 , codePin = 0;
     char date [11] , nomProp [50] , prenomProp [50] , emailProp [100] , telProp [9] , etat [7] ;

     printf("Saisissez le nom :\n > ");
     scanf("%s" , nom);

      // Recherche du nom dans le fichier pour trouver une correspondance
     fichier = fopen( "users.txt" , "r" );
     fileError( fichier );
     while ( ! feof( fichier ) )
      {
         fscanf( fichier , "%d %s %s %s %s %s %d %s %d\n", &num , date , nomProp , prenomProp , emailProp ,
         telProp , &montant , etat  , &codePin );
         if ( strcmp( nom , nomProp ) == 0 )
          {
            printf("Ce nom de compte existe dans la base de données ..\n");
            break;
          }
      }
     fclose( fichier );
   }

  void rechCompte ()
   {
     char choix ;
     int numCompte;
     printf("****************CREATION D'UN COMPTE *********************\n");
     espace();
     printf("Vous pouvez effectuer vos recherches par compte ou par numéro..\n");
     printf("Recherche par numero  ---> Saisir n \n");
     printf("Recherche par nom de famille  ---> Saisir f \n > ");
     scanf("%c", &choix );

     switch ( choix )
      {
        case 'n' :
         printf("Saisir le numero du compte : \n > ");
         scanf("%d", &numCompte );
         rechCompteNum ( numCompte );
         break;
        case 'f' :
         rechCompteNom ();
         break;
        default :
         printf("Cette option n'existe pas ..\n");
         break;
      }
   }

   // Fonctions pour consulter un compte
  void consCompte ()
   {
     printf("****************CONSULTER UN COMPTE *********************\n");
     int num_saisi = 0 , pin = 0 , test = 0 , num = 0 , montant = 0 , codePin = 0 , i = 0;
     char date [11] , nomProp [50] , prenomProp [50] , emailProp [100] , telProp [9] , etat [7] ;
     FILE * fuser;
     /* Nous ferons appel à notre fonction rechCompteNum pour vérifier si le numéro de compte saisi par l'utilisateur existe.
         Ainsi nous ferons appel au fichier users.txt que nous parcourerons ligne par ligne en verifiant les correspondances
         entre le pin saisi et le pin lié au numero fourni par l'utilisateur.
         Au cas ou ce compte n'existerait pas , ce programmme prendra fin.
      */
     printf("Saisir le numéro du compte :\n >");
     scanf("%d", &num_saisi );
     test = rechCompteNum ( num_saisi );
      // Verification
     if ( test == 1 )
      {

        fuser = fopen( "users.txt" , "r" );
        while ( ! feof( fuser ) )
         {
           fscanf( fuser , "%d %s %s %s %s %s %d %s %d\n", &num , date , nomProp , prenomProp , emailProp ,
           telProp , &montant , etat  , &codePin );
            if ( ( num_saisi == num ) )
             {
                do
                {
                   printf("Entrez le code PIN du compte :\n > ");
                   scanf("%d", &pin);
                   if ( codePin ==  pin )
                    {
                       printf("*******DONNEES DU COMPTE*******\n");
                       printf(" Numéro du compte : %d \n Date de création : %d \n Nom du propriétaire : %s \n" ,num , date , nomProp);
                       printf(" Prénom du propriétaire : %s\n Email de propriétaire : %s \n Téléphone du propriétaire : %s \n" ,prenomProp ,
                       emailProp , telProp);
                       printf(" Etat du compte : %s \n   Montant : %d \n Code Pin : %d \n", etat , montant , codePin );
                       //break;
                    }
                    i++;
                } while ( i < 3 );
             }
         }
      }
    else
      {
        printf("Vous ne pouvez pas consulter un compte inexistant..\n");
      }
   }

     // Fonctions liées à la gestion d'une liste
   void initListe ( Liste * L )
    {
       L -> premier = NULL;
    }

   void creerElt ( Element * e )
    {
      printf("Saisir le montant à ajouter \n > ");
      scanf("%d" , &e -> montant );
    }

   void ajoutElt ( Liste * L , Element e )
    {
       Element * e1 = malloc ( sizeof ( Element ) );
       e1 -> montant = e.montant;
       e1 -> suivant = NULL;
       if ( L -> premier == NULL )
        {
          L -> premier == e1;
        }
        else
        {
          e1 -> suivant = L -> premier;
          L -> premier = e1;
        }
   }

 void insListe ( Liste L , int num_saisi )
   {
      FILE * modUser ;
      int pin = 0 ,test = 0 , num = 0 , montant = 0 , codePin = 0 , somme = 0 , pos = 0;
      char date [11] , nomProp [50] , prenomProp [50] , emailProp [100] , telProp [9] , etat [7] ;

        // Parours de la liste

      modUser  = fopen( "users.txt" , "a" );
      fileError( modUser  );
      while ( ! feof( modUser ) )
       {
         fscanf( modUser , "%d %s %s %s %s %s %d %s %d\n", &num , date , nomProp , prenomProp , emailProp ,
         telProp , &montant , etat  , &codePin );
         if ( num_saisi == num )
          {

          }
       }
     fclose( modUser );
   }

     // Fonctions liés a la gestioln des dépots sur les comptes
  void depCompte ()
   {
     int num = 0 , etCompte = 0;
     Liste L;
     Element e;
     char reponse;

     printf("****************DEPOT SUR UN COMPTE *********************\n");
     printf("Saisir le numéro du compte : \n > ");
     scanf("%d" , &num );
     etCompte = rechCompteNum( num );
     if ( etCompte == 1 )
      {
        while ( reponse == 'o' )
         {
            initListe( &L );
            creerElt( &e );
            ajoutElt( &L , e );
            printf("Voulez vous ajouter encore : \n > ");
            scanf("%c" , &reponse );
         }
      }
    else
      {
        printf("Impossible d'effectuer un dépot sur un compte inexistant ...\n");
      }
   }

    // Fonctions liées a la mise en place de l'historique

    void affhistorique ( )
     {
       int a = 0;
     }
