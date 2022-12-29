#include <iostream>

#include "contact/contact.h"

using namespace std;

int main()
{

    Adresse A(50,"toto","tata",34000,"Montpellier");
    A.affiche();
    cout << "Hello world!" << endl;
    return 0;
}
