#include "pro.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


Pro::Pro(int id , string rue, string comp, int cp, string addmail, string nomEntreprise)
  :Contact(id, rue, comp, cp)
{
    this->Setaddmail(addmail);
    this->SetnomEntreprise(nomEntreprise);
}

Pro::~Pro()
{
    cout << "Destruction du contact"
         << this->GetnomEntreprise()<<endl;
}

string Pro::affiche()
{
    ostringstream oss;
    oss << Contact::affiche();
    oss  << "Entreprise: " << this->GetnomEntreprise() <<endl;
    oss << "Mail: " << this->Getaddmail() <<endl;

    return oss.str();

}
