#include "private.h"
#include <string>

Private::~Private(){
    cout<<"Destruction du contact privé"<<this->GetNom()<<endl;
}

Private::Private(int day, int month, int year):Contact(){
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
    Contact::affiche();
    ostringstream oss;
    oss<<"Date de naissance "<<this->Getddn()<<endl;
    return oss.str();
}
