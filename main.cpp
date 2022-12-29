#include <iostream>

#include "contact/contact.h"
#include "Private/private.h"
#include "Pro/pro.h"


using namespace std;

int main()
{
    string nom1 = "Blalalala";
    string nom2 = "Blalalala2";
    string nom3 = "Blalalala3";
    string prenom1 = "Lucas";
    string prenom2 = "Lucas2";
    string prenom3 = "Lucas3";

    string entreprise = "APPLE";
    string mail = "totolucas@hotmail.com";

    ddn date(10,10,10);
    Adresse A(50,"toto","tata",34000,"Montpellier");
    //A.affiche();

    cout << "--------------------------------" << endl;
    Contact Lucas(10,nom1,prenom1,'M',A);
    cout << Lucas.affiche();
    cout << "--------------------------------" << endl;

    cout << "--------------------------------" << endl;
    Pro totoLucas(10,nom2,prenom2,'M',A,entreprise,mail);
    cout << totoLucas.affiche();
    cout << "--------------------------------" << endl;

    cout << "--------------------------------" << endl;
    Private totoLucas2(10,nom2,prenom2,'M',A,10,10,10);
    cout << totoLucas2.affiche();
    cout << "--------------------------------" << endl;

    //cout << "Hello world!" << endl;
    return 0;
}


void test1(){
    string nom1 = "Blalalala";
    string nom2 = "Blalalala2";
    string nom3 = "Blalalala3";
    string prenom1 = "Lucas";
    string prenom2 = "Lucas2";
    string prenom3 = "Lucas3";

    string entreprise = "APPLE";
    string mail = "totolucas@hotmail.com";

    ddn date(10,10,10);
    Adresse A(50,"toto","tata",34000,"Montpellier");
    //A.affiche();

    cout << "--------------------------------" << endl;
    Contact Lucas(10,nom1,prenom1,'M',A);
    cout << Lucas.affiche();
    cout << "--------------------------------" << endl;

    cout << "--------------------------------" << endl;
    Pro totoLucas(10,nom2,prenom2,'M',A,entreprise,mail);
    cout << totoLucas.affiche();
    cout << "--------------------------------" << endl;

    cout << "--------------------------------" << endl;
    Private totoLucas2(10,nom2,prenom2,'M',A,10,10,10);
    cout << totoLucas2.affiche();
    cout << "--------------------------------" << endl;
}
