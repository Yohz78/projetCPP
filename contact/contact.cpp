#include "contact.h"
#include <iostream>
#include <string>
#include <sstream>

Contact::Contact(int identifiant,std::string nom,std::string prenom,char sexe, Adresse adresse){
    this->identifiant = identifiant;
    this->SetNom(nom) ;
    this->SetPrenom(prenom);
    this->sexe = sexe;
    this->adresse = adresse;
}

Contact::~Contact(){
}


std::string Contact::affiche()
{
    std::ostringstream oss;
    fflush(stdout);
    oss << "Contact: "
        <<"ID: " << this->GetIdentifiant()  << std::endl
        <<"Nom: "<< this->GetNom()  << std::endl
        <<"Prenom: "<< this->GetPrenom()  << std::endl
        <<"Sexe: "<< this->GetSexe()  << std::endl
        <<"Adresse: "<< this->adresse.affiche();
    return oss.str();
}

ostream& operator<<(ostream& sortie, Adresse& adresse){
    sortie << adresse.affiche();
    return sortie;
}

ostream& operator<<(ostream& sortie, Contact& contact){
        sortie << contact.affiche();
        return sortie;
}
