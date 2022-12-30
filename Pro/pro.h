#ifndef PRO_H_INCLUDED
#define PRO_H_INCLUDED
#include "../contact/contact.h"
using namespace std;


class Pro: public Contact
{

    public:

    Pro(int,string,string,string,Adresse,string, string);
    virtual~Pro();

    void SetnomEntreprise(string n){this->nomEntreprise=n;}
    string GetnomEntreprise(){return this->nomEntreprise;}

    void Setaddmail(string ad){this->addmail=ad;}
    string Getaddmail(){return this->addmail;}

    string affiche() override;

    private:
        string nomEntreprise;
        string addmail;



};

#endif // PRO_H_INCLUDED
