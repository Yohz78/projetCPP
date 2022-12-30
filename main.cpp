#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "contact/contact.h"
#include "Private/private.h"
#include "Pro/pro.h"
#include "menu.h"
#include "databaseHandler/databaseHandler.h"
#include "sqlite3.h"

using namespace std;

int insert_database();

int test2();
void test3();

int main()
{
    //menu();

    // databaseHandler bdd("dbContacts.db");
    //bdd.liste("liste");

//test2();

insert_database();

    return 0;
}

/*
void test1(){
    string nom1 = "Blalalala";
    string nom2 = "Blalalala2";
    string nom3 = "Blalalala3";
    string prenom1 = "Lucas";
    string prenom2 = "Lucas2";
    string prenom3 = "Lucas3";

    string entreprise = "APPLE";
    string mail = "totolucas@hotmail.com";

    ddn date(10,10,10);
    Adresse A(50,"toto","tata",34000,"Montpellier");
    //A.affiche();

    cout << "--------------------------------" << endl;
    Contact Lucas(10,nom1,prenom1,'M',A);
    cout << Lucas.affiche();
    cout << "--------------------------------" << endl;

    cout << "--------------------------------" << endl;
    Pro totoLucas(10,nom2,prenom2,'M',A,entreprise,mail);
    cout << totoLucas.affiche();
    cout << "--------------------------------" << endl;

    cout << "--------------------------------" << endl;
    Private totoLucas2(10,nom2,prenom2,'M',A,10,10,10);
    cout << totoLucas2.affiche();
    cout << "--------------------------------" << endl;
}
*/

/*

int test2()
{

    sqlite3 *db=NULL;        // connection Base
    int rc;             // code retour
    char *errmsg=NULL;       // pointeur vers err

    sqlite3_stmt *stmt=NULL;


    rc = sqlite3_open("dbContacts.db", &db);
    if (rc != SQLITE_OK) {
        printf("ERREUR Open : %s\n", sqlite3_errmsg(db));
       return 1;
    }
    printf("Base ouverte avec succès.\n");


    ///select

    sqlite3_prepare_v2(db,
                       "select * from CONTACTS where Entreprise is NULL;",
                       -1,
                       &stmt, NULL);

    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {

        printf("ID: %d", sqlite3_column_int(stmt,0));
        printf("\nNom: %s %s", sqlite3_column_text(stmt,1), sqlite3_column_text(stmt,2));
        printf("\nSexe: %s", sqlite3_column_text(stmt,3));
        printf("\nEntreprise: %s", sqlite3_column_text(stmt,4));
        printf("\nRue: %d %s", sqlite3_column_int(stmt,5), sqlite3_column_text(stmt,6));
        printf("\nCP: %d ville: %s", sqlite3_column_int(stmt,7), sqlite3_column_text(stmt,8));
        printf("\nDate de naissance %d", sqlite3_column_int(stmt,9));
        printf("\n--------------------------------------\n");
    }

    sqlite3_finalize(stmt);


    rc = sqlite3_close(db);
    if (rc != SQLITE_OK) {
        printf("ERREUR Open : %s\n", sqlite3_errmsg(db));
       return 1;
    }




}

*/


int insert_database(){


    sqlite3 *db=NULL;        // connection Base
    int rc;             // code retour
    char *errmsg=NULL;       // pointeur vers err
    sqlite3_stmt *stmt=NULL;
    rc = sqlite3_open("dbContacts.db", &db);
    if (rc != SQLITE_OK)
        {
        printf("ERREUR Open : %s\n", sqlite3_errmsg(db));
        return 1;
        }
        printf("Base ouverte avec succès.\n");



    char Pro[40];
    char Prive[40];
    char rep;
    printf("\nVous souhaitez ajouter un contact(o/n)? ");
    rep = getchar();
    if (rep=='o')
    {
        printf("Il s'agit d'un contact Pro ou prive (Pro/Prive)?");
        scanf("%s", Pro);

        if ( strcmp( Pro, "Pro" ) == 0 )
            {

        //char* requete2 = "INSERT INTO CONTACTS (Nom, Prenom, Sexe, Entreprise, rue, Complement, cp, Ville) values (?, ?, ?, ?, ?, ?, ?, ?);";

         //char* requete2 = "INSERT INTO CONTACTS values(Null, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);";

         char* requete2 = "INSERT INTO CONTACTS values(Null, ?, ?);";
        //char* requete2 = "SELECT *FROM CONTACTS;";

        if (sqlite3_prepare_v2(db, requete2 , 50, &stmt, NULL) != SQLITE_OK)
        {
            printf ("Dommage :\n");
        }

        char nom[10+1], prenom[10+1], nomEntreprise[10+1], sexe[1+1], ville[10+1], nomrue[10+1];

        int contactid, numrue, cp;

	   // printf("Saisir l'ID: ");
        //scanf("%d", &contactid);

        printf("\nSaisir le Nom: ");
        scanf("%s", nom);
        printf("\nSaisir le Prenom: ");
        scanf("%s", prenom);

        printf("\nle sexe(M/F)? ");
        scanf("%c", sexe);

        printf("\nSaisir le nom de l'entreprise: ");
        scanf("%s", nomEntreprise);

        printf("\nNumero de rue? ");
        scanf("%s", &numrue);

        printf("\nNom de rue? ");
        scanf("%s", nomrue);

        printf("\nCP? ");
        scanf("%s", &cp);

        printf("\nVille? ");
        scanf("%s", ville);
        //printf("\nDate de naissance %d", sqlite3_column_int(stmt,9));
        printf("\n--------------------------------------\n");

        //sqlite3_bind_int(stmt, 0, contactid);
        sqlite3_bind_text(stmt, 1, nom, strlen(nom), NULL);
        sqlite3_bind_text(stmt, 2, prenom, strlen(prenom), NULL);
        sqlite3_bind_text(stmt, 3, sexe, strlen(sexe), NULL);
        sqlite3_bind_text(stmt, 4, nomEntreprise, strlen(nomEntreprise), NULL);
        sqlite3_bind_int(stmt, 5, numrue);
        sqlite3_bind_text(stmt, 6, nomrue, strlen(nomrue), NULL);
        sqlite3_bind_int(stmt, 7, cp);
        sqlite3_bind_text(stmt, 8, ville, strlen(ville), NULL);

        rc = sqlite3_step(stmt);
        printf("rc : %d", rc);


    sqlite3_finalize(stmt);


    rc = sqlite3_close(db);
    if (rc != SQLITE_OK) {
        printf("ERREUR Open : %s\n", sqlite3_errmsg(db));
       return 1;
    }


            }

       ////////////////////////////////////



    }

   else
    {
     insert_database();
    }

   /*

    sqlite3 *db=NULL;        // connection Base
    int rc;             // code retour
    char *errmsg=NULL;       // pointeur vers err

    sqlite3_stmt *stmt=NULL;


    rc = sqlite3_open("dbContacts.db", &db);
    if (rc != SQLITE_OK) {
        printf("ERREUR Open : %s\n", sqlite3_errmsg(db));
       return 1;
    }
    printf("Base ouverte avec succès.\n");


    char* requete2 = "INSERT INTO CONTACTS values(NULL, ?, ?);";

    if (sqlite3_prepare_v2(db, requete2, 50, &stmt, NULL) != SQLITE_OK)
    {
		printf ("Dommage :(\n");
	}

	char nomAlb[10+1];
	int artistid;

	    printf("ID: %d", sqlite3_column_int(stmt,0));
        printf("\nNom: %s %s", sqlite3_column_text(stmt,1), sqlite3_column_text(stmt,2));
        printf("\nSexe: %s", sqlite3_column_text(stmt,3));
        printf("\nEntreprise: %s", sqlite3_column_text(stmt,4));
        printf("\nRue: %d %s", sqlite3_column_int(stmt,5), sqlite3_column_text(stmt,6));
        printf("\nCP: %d ville: %s", sqlite3_column_int(stmt,7), sqlite3_column_text(stmt,8));
        printf("\nDate de naissance %d", sqlite3_column_int(stmt,9));
        printf("\n--------------------------------------\n");







        printf("Saisir le nom  : ");
        scanf("%s", nomAlb);

        printf("Saisir le num de l'artiste");
        scanf("%d", &artistid);

        sqlite3_bind_text(stmt, 1, nomAlb, strlen(nomAlb), NULL);
        sqlite3_bind_int (stmt, 2, artistid);


        rc = sqlite3_step(stmt);
        printf("rc : %d", rc);


    sqlite3_finalize(stmt);


    rc = sqlite3_close(db);
    if (rc != SQLITE_OK) {
        printf("ERREUR Open : %s\n", sqlite3_errmsg(db));
       return 1;
    }

*/


}














//IdContact, Nom, Prenom, Sexe, Entreprise, rue, Complement, cp, ville dtNaissance





