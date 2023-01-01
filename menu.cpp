#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

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

void insert_contact_pro(sqlite3 *db, Pro *p){
    sqlite3_stmt *stmt;
    int rc;

    /* Create the SQL statement */
    const char *sql = "INSERT INTO contacts (IdContact,nom,prenom,sexe,entreprise,rue,complement,cp,ville,mail) VALUES (?,?,?,?,?,?,?,?,?,?)";

    /* Prepare the statement */
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        exit(0);
    }

    int IdContact = p->GetIdentifiant();
    const char* nom = p->GetNom().c_str();
    const char* prenom = p->GetPrenom().c_str();
    const char* sexe = p->GetSexe().c_str();
    const char* entreprise =p->GetnomEntreprise().c_str();
    const char* rue = p->GetAdresse().GetRue().c_str();
    const char* complement = p->GetAdresse().GetComplement().c_str();
    int cp = p->GetAdresse().GetCodePostal();
    const char* ville = p->GetAdresse().GetVille().c_str();
    const char* mail = p->Getaddmail().c_str();

    /* Bind the values to the placeholders */
    sqlite3_bind_int(stmt, 1, IdContact);
    sqlite3_bind_text(stmt, 2,nom , -1, NULL);
    sqlite3_bind_text(stmt, 3,prenom , -1, NULL);
    sqlite3_bind_text(stmt, 4,sexe , -1, NULL);
    sqlite3_bind_text(stmt, 5,entreprise , -1, NULL);
    sqlite3_bind_text(stmt, 6,rue , -1, NULL);
    sqlite3_bind_text(stmt, 7,complement , -1, NULL);
    sqlite3_bind_int(stmt, 8,cp );
    sqlite3_bind_text(stmt, 9,ville , -1, NULL);
    sqlite3_bind_text(stmt, 10,mail , -1, NULL);


    /* Execute the statement */
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Failed to insert object: %s\n", sqlite3_errmsg(db));
        exit(0);
    }

    /* Clean up */
    sqlite3_finalize(stmt);
}

void insert_contact_private(sqlite3 *db, Private *p){
    sqlite3_stmt *stmt;
    int rc;

    /* Create the SQL statement */
    const char *sql = "INSERT INTO contacts (IdContact,nom,prenom,sexe,rue,complement,cp,ville,dtnaissance) VALUES (?,?,?,?,?,?,?,?,?)";

    /* Prepare the statement */
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
        exit(0);
    }

    int IdContact = p->GetIdentifiant();
    const char* nom = p->GetNom().c_str();
    const char* prenom = p->GetPrenom().c_str();
    const char* sexe = p->GetSexe().c_str();
    const char* rue = p->GetAdresse().GetRue().c_str();
    const char* complement = p->GetAdresse().GetComplement().c_str();
    int cp = p->GetAdresse().GetCodePostal();
    const char* ville = p->GetAdresse().GetVille().c_str();
    const char* ddn = p->Getddn().c_str();

    /* Bind the values to the placeholders */
    sqlite3_bind_int(stmt, 1, IdContact);
    sqlite3_bind_text(stmt, 2,nom , -1, NULL);
    sqlite3_bind_text(stmt, 3,prenom , -1, NULL);
    sqlite3_bind_text(stmt, 4,sexe , -1, NULL);
    sqlite3_bind_text(stmt, 5,rue , -1, NULL);
    sqlite3_bind_text(stmt, 6,complement , -1, NULL);
    sqlite3_bind_int(stmt, 7,cp );
    sqlite3_bind_text(stmt, 8,ville , -1, NULL);
    sqlite3_bind_text(stmt, 9,ddn , -1, NULL);


    /* Execute the statement */
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Failed to insert object: %s\n", sqlite3_errmsg(db));
        exit(0);
    }

    /* Clean up */
    sqlite3_finalize(stmt);

}

void delete_from_database(int id) {
    sqlite3 *db;
    int rc;

    rc = sqlite3_open("database.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(0);
    }

    char *sql = "DELETE FROM contacts WHERE id = ?";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(0);
    }

    rc = sqlite3_bind_int(stmt, 1, id);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(0);
    }

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(0);
    }

    sqlite3_finalize(stmt);
}


void search_by_city(const char *city) {
    sqlite3 *db;
    int rc;

    rc = sqlite3_open("database.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(0);
    }

    char *sql = "SELECT * FROM contacts WHERE city = ?";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(0);
    }

    rc = sqlite3_bind_text(stmt, 1, city, -1, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(0);
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *name = (const char *)sqlite3_column_text(stmt, 1);
        const char *city = (const char *)sqlite3_column_text(stmt, 4);

        printf("ID: %d, Name: %s, City: %s\n", id, name, city);
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(0);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

void search_by_name(const char *nom) {
    sqlite3 *db;
    int rc;

    rc = sqlite3_open("database.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(0);
    }

    char *sql = "SELECT * FROM contacts WHERE nom = ?";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(0);
    }

    rc = sqlite3_bind_text(stmt, 1, nom, -1, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(0);
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char *name = (const char *)sqlite3_column_text(stmt, 1);
        const char *city = (const char *)sqlite3_column_text(stmt, 4);

        printf("ID: %d, Name: %s, City: %s\n", id, name, city);
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(0);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

