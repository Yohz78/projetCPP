#include "databaseHandler.h"
#include "../sqlite3.h"

#include <string>
#include <iostream>

databaseHandler::databaseHandler(sqlite3* db)
{
    this->db = db;
    this->SetzErrMsg('0');
    this->rc = (sqlite3_open("test.db",&db));
    if(rc){
        fprintf(stderr , "Can't open database : %s n", sqlite3_errmsg(db));
        exit(0);
    }
    else
    {
        fprintf(stderr , "Opened database successfully n");
    }
    sqlite3_close(db);
}

databaseHandler::~databaseHandler()
{
    //dtor
}
void databaseHandler::close()
{

}

void databaseHandler::open()
{

}

void databaseHandler::liste(string requete)
{
    sqlite3_stmt *stmt = NULL;

    if(requete.empty()){
            this->rc = sqlite3_prepare_v2( this->db,"SELECT * FROM contacts",-1,&stmt,NULL);
    }
    if(requete == "Pro"){
            this->rc = sqlite3_prepare_v2( this->db,"SELECT * FROM contacts WHERE Entreprise is NOT NULL",-1,&stmt,NULL);
    }
    if(requete == "Private"){
            this->rc = sqlite3_prepare_v2( this->db,"SELECT * FROM contacts WHERE Entreprise is NULL ",-1,&stmt,NULL);
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        printf("ID: %d", sqlite3_column_int(stmt,0));
        printf("Nom: %s", sqlite3_column_name(stmt,1));
        printf("Prenom: %s", sqlite3_column_name(stmt,2));
        printf("Sexe: %c", sqlite3_column_name(stmt,3));
        printf("Entreprise: %s", sqlite3_column_name(stmt,4));
        /*printf("Rue: %s", sqlite3_column(stmt,5));
        printf("Rue: %s", sqlite3_column(stmt,6));
        printf("Rue: %s", sqlite3_column(stmt,7));
        printf("Rue: %s", sqlite3_column(stmt,8));
        printf("Rue: %s", sqlite3_column(stmt,9));*/
    }

    sqlite3_finalize(stmt);

}

void databaseHandler::recherche(string, string)
{
    sqlite3_stmt *stmt = NULL;
    sqlite3_finalize(stmt);
}

void databaseHandler::ajoutContact(int, string, string, char, Adresse, string, string)
{
    sqlite3_stmt *stmt = NULL;
    sqlite3_finalize(stmt);
}

void databaseHandler::ajoutContact(int, string, string, char, Adresse, string)
{
    sqlite3_stmt *stmt = NULL;
    sqlite3_finalize(stmt);
}


/*SELECT */
    /*
    sqlite3_prepare_v2(db, ------------------------------------------------------> DATABASE
                       "SELECT trackid, name, composer, unitprice from tracks", -> REQUETE
                       -1, ------------------------------------------------------>nb caractere
                       &stmt,----------------------------------------------------> Statement (resultat)
                        NULL); --------------------------------------------------> Laisser a NULL

    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        printf("Piste %d : %s", sqlite3_column_int(stmt, 0),sqlite3_column_text(stmt, 1));
        printf("\nCompositeur : %s",  sqlite3_column_text(stmt, 2));
        printf("\nPrix Unitaire en : %lf",  sqlite3_column_double(stmt, 3));
        printf("\n--------------------------------------\n");
    }

    */

