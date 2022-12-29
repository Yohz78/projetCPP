#include "private.h"

Private::~Private(){
    cout<<"Destruction du contact privé"<<this->GetNom()<<endl;
}

void Private::Setddn(int day, int month, int year){
    ddn Datenaissance(day, month, year);
    this->dateNaissance=Datenaissance;
}
