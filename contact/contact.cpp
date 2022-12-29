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
    oss << "Contact: "
        << this->GetNom() << "---"
        << this->GetPrenom() << "---"
        << this->GetSexe() << "---"
        << this->adresse.affiche();
    return oss.str();
}
