#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// STRUCT ADRESSE
struct Adresse{
    string rue;
    string complement;
    int codePostal;
    string ville;

        string affiche(){
        ostringstream oss;
        oss <<    "Rue:"<< rue << "---"  <<
                  "Cplt:"<< complement << "---" <<
                  "CP:"<< codePostal << "---" <<
                  "Ville:"<< ville
                  << endl;
        return oss.str();
    }
    Adresse(){};
    Adresse(string rue,string complement,int codePostal,string ville){
        this->rue = rue;
        this->complement = complement;
        this->codePostal = codePostal;
        this->ville = ville;
    }
    void SetAdresse(string rue,string complement,int codePostal,string ville){
        this->rue = rue;
        this->complement = complement;
        this->codePostal = codePostal;
        this->ville = ville;
    }

    string GetRue() const {
        return rue;
    }

    string GetComplement() const {
        return complement;
    }

    int GetCodePostal() const {
        return codePostal;
    }

    string GetVille() const {
        return ville;
    }



};

typedef struct Adresse Adresse;

// CLASS CONTACT

class Contact {

    private:
        int identifiant;
        string nom;
        string prenom;
        string sexe;
        Adresse adresse;

    public:
        Contact(int=0,string="",string="",string="",Adresse=Adresse());
        virtual ~Contact();

        // ----------- SETTERS ---------- //
        void SetIdentifiant(int ID){ this->identifiant = ID;}
        //void SetNom(string nom){ this->nom=nom;}
        void SetNom(string);
        //void SetPrenom(string prenom){ this->prenom = prenom;}
        void SetPrenom(string);
        void SetSexe(char sexe){ this->sexe = sexe;}


        // ----------- GETTERS ---------- //
        int GetIdentifiant() const {return identifiant;}
        string GetNom() const {return nom;}
        string GetPrenom() const {return prenom;}
        string GetSexe() const {return sexe;}
        Adresse GetAdresse() const {return adresse;}

        // ----------- METHODS ---------- //

        virtual string affiche();


};


#endif // CONTACT_H_INCLUDED
