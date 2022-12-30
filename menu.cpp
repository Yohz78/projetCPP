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

void buildPro(sqlite3* db,std::vector<Contact>* build_db){
    cout << "BUILD PRO" << endl;
    sqlite3_stmt *stmt = NULL;
    int rc = sqlite3_prepare_v2(db,"SELECT IdContact,nom,prenom,sexe,entreprise,rue,complement,cp,ville,mail FROM contacts WHERE entreprise IS NOT NULL",-1,&stmt, NULL);
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW){

    std::string rue = (const char*)sqlite3_column_text(stmt,5);
    cout << rue << endl;
    std::string complement = "";
    if(sqlite3_column_text(stmt,6)!=NULL){complement = (const char*)sqlite3_column_text(stmt,6);}
    cout << complement << endl;
    std::string ville = (const char*)sqlite3_column_text(stmt,8);
    cout << ville << endl;
    Adresse A(rue,complement,sqlite3_column_int(stmt,7),ville);

    //int id = sqlite3_column_int(stmt,0); // ID
    std::string nom = "";
    if(sqlite3_column_text(stmt,1)!=NULL){nom = (const char*)sqlite3_column_text(stmt,1);}// NOM
    std::string prenom = "";
    if(sqlite3_column_text(stmt,2)!=NULL){prenom = (const char*)sqlite3_column_text(stmt,2);}// PRENOM
    std::string sexe = "";
    if(sqlite3_column_text(stmt,3)!=NULL){sexe = (const char*)sqlite3_column_text(stmt,3);}// SEXE
    std::string entreprise = (const char*)sqlite3_column_text(stmt,4);// ENTREPRISE
    cout << entreprise << endl;
    std::string mail = (const char*)sqlite3_column_text(stmt,9);// MAIL
    cout << mail << endl;

    Pro B(sqlite3_column_int(stmt,0), // ID
                            nom,        // NOM
                            prenom,     // PRENOM
                            sexe,       // SEXE
                            A,           // ADRESSE
                            entreprise, // ENTREPRISE
                            mail);        // MAIL
    cout << "On a cree PRO: " << B.affiche() << endl;
    build_db->push_back(B);
    }

    sqlite3_finalize(stmt);
    cout << "ON A FINI LES PROS" << endl;
}

void buildPrivate(sqlite3* db, std::vector<Contact>* build_db){
    cout << "BUILD PRIVATE" << endl;
    sqlite3_stmt *stmt2 = NULL;
    int rc2 = sqlite3_prepare_v2(db,"SELECT IdContact,nom,prenom,sexe,rue,complement,cp,ville,dtnaissance FROM contacts WHERE entreprise IS NULL",-1,&stmt2, NULL);
    while ( (rc2 = sqlite3_step(stmt2)) == SQLITE_ROW){

    std::string rue = "";
    if(sqlite3_column_text(stmt2,4)!=NULL){rue = (const char*)sqlite3_column_text(stmt2,4);};
    std::string complement = "";
    if(sqlite3_column_text(stmt2,5)!=NULL){complement = (const char*)sqlite3_column_text(stmt2,5);}
    std::string ville = "" ;
    if(sqlite3_column_text(stmt2,7) !=NULL){ville = (const char*)sqlite3_column_text(stmt2,7);}

    std::string nom = "";
    if(sqlite3_column_text(stmt2,1)!=NULL){nom = (const char*)sqlite3_column_text(stmt2,1);}// NOM
    std::string prenom = "";
    if(sqlite3_column_text(stmt2,2)!=NULL){prenom = (const char*)sqlite3_column_text(stmt2,2);}// PRENOM
    std::string sexe = "";
    if(sqlite3_column_text(stmt2,3)!=NULL){sexe = (const char*)sqlite3_column_text(stmt2,3);}// SEXE
    std::string dateNaissance = (const char*)sqlite3_column_text(stmt2,8);// DATE NAISSANCE

    Adresse A(rue,complement,sqlite3_column_int(stmt2,6),ville);
    Private C(sqlite3_column_int(stmt2,0),   // ID
                            nom,            // NOM
                            prenom,         // PRENOM
                            sexe,           // SEXE
                            A,               // ADRESSE
                            dateNaissance);// DATE NAISSANCE
    cout << "On a cree PRIVATE: " << C.affiche() << endl;
    build_db->push_back(C);
    }
    sqlite3_finalize(stmt2);
    cout << " ON A FINI LES PRIVATE" << endl;
}



void build_from_database(sqlite3* db, std::vector<Contact>* build_db){
    cout << "BUILD FROM DATABASE" << endl;
    buildPro(db,build_db);
    buildPrivate(db,build_db);
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

