#ifndef PRIVATE_H_INCLUDED
#define PRIVATE_H_INCLUDED

#include "../contact/contact.h"

using namespace std;

class Private : public Contact
{
    public:
        virtual ~Private();
        Private(int,string,string,string,Adresse,string);

        string Getddn(){return dateNaissance;}
        string affiche();

    private:
        string dateNaissance;
};


#endif // PRIVATE_H_INCLUDED
