#include "private.h"
#include <string>

Private::~Private(){}

Private::Private(int id, string nom, string prenom, string sexe, Adresse adresse,string dateNaissance)
:Contact(id, nom, prenom, sexe, adresse){
       this->dateNaissance=dateNaissance;
}


string Private::affiche(){
    ostringstream oss;
    oss << Contact::affiche();
    oss <<"Date de naissance: "<< this->dateNaissance<<endl;
    return oss.str();
}
