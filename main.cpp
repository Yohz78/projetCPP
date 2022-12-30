#include <iostream>
#include <cstring>

#include "contact/contact.h"
#include "Private/private.h"
#include "Pro/pro.h"
#include "menu.h"
#include "menu.cpp"
#include "databaseHandler/databaseHandler.h"


using namespace std;

int main()
{

    sqlite3 *db = NULL;
    char zErrMsg='0';
    int rc = (sqlite3_open("dbContacts.db",&db));
    if(rc != SQLITE_OK){
        fprintf(stderr , "Can't open database : %s \n", sqlite3_errmsg(db));
        return 0;
    }
    else
    {
        fprintf(stderr , "Opened database successfully \n");
    }

    char requete[100+1] = "SELECT * FROM contacts";
    char requetePro[200+1] = "SELECT IdContact,nom,prenom,sexe,entreprise,rue,complement,cp,ville,mail FROM contacts WHERE entreprise IS NOT NULL";
    char requetePrivate[200+1] = "SELECT IdContact,nom,prenom,sexe,rue,complement,cp,ville,mail FROM contacts WHERE entreprise IS NULL";
    select_db(requete,db);

    vector<Contact> build_db;
    build_from_database(db,&build_db);

    cout << "on affiche build_db" << endl;
    cout << "on affiche build_db.size():" << build_db.size()  << endl;


    for(int i = 0; i<build_db.size();i++){
        cout << build_db[i].affiche() << endl;
    }

    sqlite3_close(db);

    //menu();

    //databaseHandler bdd("dbContacts.db");
    //bdd.liste("Pro");

 /*sqlite3 *db = NULL;
    char zErrMsg='0';
    int rc = (sqlite3_open("dbContacts.db",&db));
    if(rc != SQLITE_OK){
        fprintf(stderr , "Can't open database : %s \n", sqlite3_errmsg(db));
        return 0;
    }
    else
    {
        fprintf(stderr , "Opened database successfully \n");
    }
    sqlite3_stmt *stmt = NULL;
    rc = sqlite3_prepare_v2( db,"SELECT * FROM contacts",-1,&stmt,NULL);
    sqlite3_step(stmt);
    int colCount = sqlite3_column_count(stmt);
    cout << "ColCount: " << colCount << endl;
    for(int i=0;i<sqlite3_column_count(stmt);i++){ //
        cout << "i= " << i << endl;
        cout << "typeCol:" << sqlite3_column_type(stmt,i) << endl;
        for(int i=0;i<sqlite3_column_count(stmt);i++){
            if(sqlite3_column_type(stmt,i) == 1){
                printf("ID: %d \n",sqlite3_column_int(stmt, i));
            }
        }
        for(int i=0;i<sqlite3_column_count(stmt);i++){
            if(sqlite3_column_type(stmt,i) == 3){
                printf("Type 3: %s\n",sqlite3_column_text(stmt, i));
            }
        }
        for(int i=0;i<sqlite3_column_count(stmt);i++){
            if(sqlite3_column_type(stmt,i) == 5){
                printf("NULL \n");
            }
        }
        sqlite3_step(stmt);
        //cout << rc << endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db); */

    //cout << "Hello world!" << endl;

    return 0;
}




void test1(){
    string nom1 = "Blalalala";
    string nom2 = "Blalalala2";
    string nom3 = "Blalalala3";
    string prenom1 = "Lucas";
    string prenom2 = "Lucas2";
    string prenom3 = "Lucas3";

    string entreprise = "APPLE";
    string mail = "totolucas@hotmail.com";

    //ddn date(10,10,10);
    Adresse A("50, toto","tata",34000,"Montpellier");
    //A.affiche();

    cout << "--------------------------------" << endl;
    Contact Lucas(10,nom1,prenom1,"M",A);
    cout << Lucas.affiche();
    cout << "--------------------------------" << endl;

    cout << "--------------------------------" << endl;
    Pro totoLucas(10,nom2,prenom2,"M",A,entreprise,mail);
    cout << totoLucas.affiche();
    cout << "--------------------------------" << endl;

    cout << "--------------------------------" << endl;
    Private totoLucas2(10,nom2,prenom2,"M",A,"10,10,10");
    cout << totoLucas2.affiche();
    cout << "--------------------------------" << endl;
}
