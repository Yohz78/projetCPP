#include "private.h"
#include <string>

Private::~Private(){}

Private::Private(int id, string nom, string prenom, char sexe, Adresse adresse,int day, int month, int year)
:Contact(id, nom, prenom, sexe, adresse){
       this->dateNaissance=ddn(day, month, year);
}

string Private::Getddn(){
    ddn dateNaissance=this->dateNaissance;
    string day = to_string(dateNaissance.day);
    string month = to_string(dateNaissance.month);
    string year = to_string(dateNaissance.year);
    string ddn = day+"/"+month+"/"+year;
    return ddn;
}

string Private::affiche(){
    ostringstream oss;
    oss << Contact::affiche();
    oss <<"Date de naissance: "<< this->Getddn()<<endl;
    return oss.str();
}
