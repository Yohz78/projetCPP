#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "sqlite3.h"
#include "contact/contact.h"
#include "Private/private.h"
#include "Pro/pro.h"

// FAIRE DES FONCTIONS POUR MANIPULER LA BDD

// PENSER AU TYPE DE RETOUR
// LISTE DES FONCTIONS
// MANIPULATIONS DES REQUETES

typedef std::basic_string <unsigned char> ustring;

void select_db(char* requete,sqlite3 *db){

    sqlite3_stmt *stmt = NULL;
    int rc = sqlite3_prepare_v2(db,requete,-1,&stmt, NULL);
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW){

    printf("ID: %d", sqlite3_column_int(stmt,0));
    printf("\nNom: %s %s", sqlite3_column_text(stmt,1), sqlite3_column_text(stmt,2));
    printf("\nSexe: %s", sqlite3_column_text(stmt,3));
    printf("\nEntreprise: %s", sqlite3_column_text(stmt,4));
    printf("\nRue: %d %s", sqlite3_column_int(stmt,5), sqlite3_column_text(stmt,6));
    printf("\nCP: %d ville: %s", sqlite3_column_int(stmt,7), sqlite3_column_text(stmt,8));
    printf("\nDate de naissance %d", sqlite3_column_int(stmt,9));
    printf("\n--------------------------------------\n");
    }
    sqlite3_finalize(stmt);} // PENSEZ A VERIFIER QUE SI LE CHAMP EST NULL ON NE L AFFICHE PAS

/*vector<std::string> select_to_string(std::string requete){ // PENSEZ A VERIFIER QUE SI LE CHAMP EST NULL ON NE L AFFICHE PAS

    vector<std::string> to_string;
    std::ostringstream oss;
    sqlite3_stmt *stmt = NULL;
    sqlite3_prepare_v2(db,requete,-1,&stmt, NULL);

    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW){

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

    return to_string;
}*/


std::vector<Contact> build_from_database(sqlite3* db){
    std::vector<Contact> build_db;
    sqlite3_stmt *stmt = NULL;
    int rc = sqlite3_prepare_v2(db,"SELECT id,nom,prenom,sexe,entreprise,rue,complement,cp,ville,mail WHERE entreprise IS NOT NULL",-1,&stmt, NULL);
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW){

    std::string rue = (const char*)sqlite3_column_text(stmt,5);
    std::string complement = (const char*)sqlite3_column_text(stmt,6);
    std::string ville = (const char*)sqlite3_column_text(stmt,8);
    Adresse A(rue,complement,sqlite3_column_int(stmt,7),ville);

    //int id = sqlite3_column_int(stmt,0); // ID
    std::string nom = (const char*)sqlite3_column_text(stmt,1);// NOM
    std::string prenom = (const char*)sqlite3_column_text(stmt,2);// PRENOM
    std::string sexe = (const char*)sqlite3_column_text(stmt,3);// SEXE
    std::string entreprise = (const char*)sqlite3_column_text(stmt,4);// ENTREPRISE
    std::string mail = (const char*)sqlite3_column_text(stmt,9);// MAIL

    Pro B(sqlite3_column_int(stmt,0), // ID
                            nom,        // NOM
                            prenom,     // PRENOM
                            sexe,       // SEXE
                            A,           // ADRESSE
                            entreprise, // ENTREPRISE
                            mail);        // MAIL

    build_db.push_back(B);
    }

    sqlite3_finalize(stmt);

    rc = sqlite3_prepare_v2(db,"SELECT id,nom,prenom,sexe,rue,complement,cp,ville,dtnaissance WHERE entreprise IS NULL",-1,&stmt, NULL);
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW){

    std::string rue = (const char*)sqlite3_column_text(stmt,4);
    std::string complement = (const char*)sqlite3_column_text(stmt,5);
    std::string ville = (const char*)sqlite3_column_text(stmt,7);

    std::string nom = (const char*)sqlite3_column_text(stmt,1);// NOM
    std::string prenom = (const char*)sqlite3_column_text(stmt,2);// PRENOM
    std::string sexe = (const char*)sqlite3_column_text(stmt,3);// SEXE
    std::string dateNaissance = (const char*)sqlite3_column_text(stmt,8);// DATE NAISSANCE

    Adresse A(rue,complement,sqlite3_column_int(stmt,6),ville);
    Private C(sqlite3_column_int(stmt,0),   // ID
                            nom,            // NOM
                            prenom,         // PRENOM
                            sexe,           // SEXE
                            A,               // ADRESSE
                            dateNaissance);// DATE NAISSANCE
    uild_db.push_back(C);
    }
    sqlite3_finalize(stmt);

    return build_db;
}
/*
IdContact        integer primary key autoincrement not null,
        Nom                        varchar(30) NOT NULL,
        Prenom                varchar(30) ,
        Sexe                char(1) ,
        Entreprise        varchar(50) ,
        rue                        varchar(250) ,
        Complement        varchar(250) ,
        cp                        char(5),
        Ville                varchar(100) ,
        mail                varchar(250) ,
        dtNaissance        date
*/


void insert_database(Contact *p){
}

void delete_database(int id){
}

