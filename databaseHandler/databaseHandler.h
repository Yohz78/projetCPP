#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <iostream>
#include <string>
#include "../contact/contact.h"
#include "../sqlite3.h"

class databaseHandler
{
    public:
        databaseHandler(char*);
        virtual ~databaseHandler();

        //sqlite3 Getdb() { return *db; }
        //void Setdb(sqlite3* val) { *db = val; }
        char GetzErrMsg() { return *zErrMsg; }
        void SetzErrMsg(char val) { *zErrMsg = val; }
        int Getrc() { return rc; }
        void Setrc(int val) { rc = val; }

        void close();
        void open();
        void liste(std::string);
        void recherche(std::string,std::string);
        void ajoutContact(int,std::string,std::string,char,Adresse,std::string, std::string);
        void ajoutContact(int,std::string,std::string,char,Adresse,std::string);

    private:
        sqlite3 *db;
        char *zErrMsg;
        int rc;
};

/*select */
    /*
    sqlite3_prepare_v2(db, ------------------------------------------------------> DATABASE
                       "select trackid, name, composer, unitprice from tracks", -> REQUETE
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



#endif // DATABASEHANDLER_H
