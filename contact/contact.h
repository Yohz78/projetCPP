#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// STRUCT ADRESSE
struct Adresse{
    int numero;
    string rue;
    string complement;
    int codePostal;
    string ville;

        string affiche(){
        ostringstream oss;
        oss <<    "Num:"<< numero << "---" <<
                  "Rue:"<< rue << "---"  <<
                  "Cplt:"<< complement << "---" <<
                  "CP:"<< codePostal << "---" <<
                  "Ville:"<< ville
                  << endl;
        return oss.str();
    }
    Adresse(){};
    Adresse(int numero,string rue,string complement,int codePostal,string ville){
        this->numero = numero;
        this->rue = rue;
        this->complement = complement;
        this->codePostal = codePostal;
        this->ville = ville;
    }
    void SetAdresse(int numero,string rue,string complement,int codePostal,string ville){
        this->numero = numero;
        this->rue = rue;
        this->complement = complement;
        this->codePostal = codePostal;
        this->ville = ville;
    }



};

typedef struct Adresse Adresse;

// CLASS CONTACT

class Contact {

    private:
        int identifiant;
        string nom;
        string prenom;
        char sexe;
        Adresse adresse;

    public:
        Contact(int=0,string="",string="",char=' ',Adresse=Adresse());
        virtual ~Contact();

        // ----------- SETTERS ---------- //
        void SetIdentifiant(int ID){ this->identifiant = ID;}
        void SetNom(string nom){ this->nom=nom;} // FAIRE FULL MAJUSCULE
        void SetPrenom(string prenom){ this->prenom = prenom;} // FAIRE FIRST MAJUSCULE
        void SetSexe(char sexe){ this->sexe = sexe;}


        // ----------- GETTERS ---------- //
        int GetIdentifiant(){return this->identifiant;}
        string GetNom(){return this->nom;}
        string GetPrenom(){return this->prenom;}
        char GetSexe(){return this->sexe;}

        // ----------- METHODS ---------- //

        virtual string affiche();


};


#endif // CONTACT_H_INCLUDED
