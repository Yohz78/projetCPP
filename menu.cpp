#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// FAIRE DES FONCTIONS POUR MANIPULER LA BDD

// PENSER AU TYPE DE RETOUR
// LISTE DES FONCTIONS
// MANIPULATIONS DES REQUETES
/*
void select(string requete){ // PENSEZ A VERIFIER QUE SI LE CHAMP EST NULL ON NE L AFFICHE PAS
=======
/*
void liste(string requete){ // PENSEZ A VERIFIER QUE SI LE CHAMP EST NULL ON NE L AFFICHE PAS
>>>>>>> 3c9744296cd8b987ee4b0111189902f9573723f4

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
}
<<<<<<< HEAD

vector<std::string> select_to_string(string requete){ // PENSEZ A VERIFIER QUE SI LE CHAMP EST NULL ON NE L AFFICHE PAS

    vector<std::string> to_string;
    std::ostringstream oss;
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
}


std::vector<Contact> build_from_database(){
    std::vector<Contact> build_db;

    sqlite3_prepare_v2(db,"SELECT id,nom,prenom,sexe,entreprise,rue,complement,cp,ville,mail WHERE entreprise IS NOT NULL", ,-1,&stmt, NULL);
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW){

    printf("ID: %d", sqlite3_column_int(stmt,0));

    printf("\nNom: %s %s", sqlite3_column_text(stmt,1));
    printf("\nPrenom: %s", sqlite3_column_text(stmt,2));

    printf("\nSexe: %s", sqlite3_column_text(stmt,3));

    printf("\nEntreprise: %s", sqlite3_column_text(stmt,4));

    printf("\nRue: %d %s", sqlite3_column_int(stmt,5)); // Contient le numero
    printf("\nComplement: %s", sqlite3_column_text(stmt,6));
    printf("\nCP: %d ", sqlite3_column_int(stmt,7));
    printf("\nville: %s",sqlite3_column_text(stmt,8));

    printf("\nDate de naissance %d", sqlite3_column_int(stmt,9));


    }

    sqlite3_finalize(stmt);

    sqlite3_prepare_v2(db,"SELECT id,nom,prenom,sexe,rue,complement,cp,ville,dtnaissance WHERE entreprise IS NULL", ,-1,&stmt, NULL);
    while ( (rc = sqlite3_step(stmt)) == SQLITE_ROW){

    }
    sqlite3_finalize(stmt);


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



void insert_database(Contact *p){
}

void delete_database(int id){
}
*/
