#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>


// OPERATOR << OVERLOAD
/*
std::ostream& operator<<(ostream& sortie, Contact& contact){

} */


// STRUCT ADRESSE
typedef struct {
    int numero;
    std::string rue;
    std::string complement;
    int codePostal;
    std::string ville;

    void affiche(){
        std::cout << "L'adresse est la suivante: " <<
                  "Num:"<< numero << "---" <<
                  "Rue:"<< rue << "---"  <<
                  "Cplt:"<< complement << "---" <<
                  "CP:"<< codePostal << "---" <<
                  "Ville:"<< ville << "---"
                  << std::endl;
    }
    //Adresse(){};
    Adresse(int numero,std::string rue,std::string complement,int codePostal,std::string ville){
        this->numero = numero;
        this->rue = rue;
        this->complement = complement;
        this->codePostal = codePostal;
        this->ville = ville;
    }

}Adresse;

// CLASS CONTACT

class Contact {

    private:
        int identifiant;
        std::string nom;
        std::string prenom;
        char sexe;
        Adresse adresse;

    public:
        Contact(int=0,std::string="",std::string="",char=' ',Adresse=Adresse());
        virtual ~Contact();

        // ----------- SETTERS ---------- //
        void SetIdentifiant(int ID){ this->identifiant = ID;}
        void SetNom(std::string nom){ this->nom=nom;} // FAIRE FULL MAJUSCULE
        void SetPrenom(std::string prenom){ this->prenom = prenom;} // FAIRE FIRST MAJUSCULE
        void SetSexe(char sexe){ this->sexe = sexe;}

        // ----------- GETTERS ---------- //
        int GetIdentifiant(){return this->identifiant;}
        std::string GetNom(){return this->nom;}
        std::string GetPrenom(){return this->prenom;}
        char GetSexe(){return this->sexe;}
        Adresse GetAdresse(){return this->adresse;}

        // ----------- METHODS ---------- //

        std::string affiche();
};




#endif // CONTACT_H_INCLUDED
