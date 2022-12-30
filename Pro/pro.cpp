#include "pro.h"
#include "../contact/contact.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


Pro::Pro(int id, string nom, string prenom, string sexe, Adresse adresse, string nomEntreprise, string addmail)
  :Contact(id, nom, prenom, sexe, adresse)
{
    this->Setaddmail(addmail);
    this->SetnomEntreprise(nomEntreprise);
}

Pro::~Pro(){}

string Pro::affiche()
{
    ostringstream oss;
    oss << Contact::affiche();
    oss  << "Entreprise: " << this->GetnomEntreprise() <<endl;
    oss << "Mail: " << this->Getaddmail() <<endl;

    return oss.str();

}
