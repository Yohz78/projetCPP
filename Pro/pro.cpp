#include "pro.h"
#include <iostream>
#include <string>

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

void Pro::affiche()
{
    Contact::affiche();

}
