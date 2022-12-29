#include <iostream>
#include <string>


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

}Adresse;

class Contact {

    private:
        int identifiant;
        std::string nom;
        std::string prenom;
        char sexe;
        Adresse adresse;

    public:
        Contact(int=0,std::string="",std::string="",int=0,char=' ');
        virtual ~Contact();
        void SetIdentifiant(int ID){ this->identifiant = ID;}
        void SetNom(std::string nom){ this->nom=nom;}
        void SetPrenom(std::string prenom){ this->identifiant = prenom;}
        void SetSexe(char sexe){ this->identifiant = sexe;}

        int GetIdentifiant(){return this->identifiant;}
        std::string GetNom(){return this->nom;}
        std::string GetPrenom(){return this->prenom;}
        char GetSexe(){return this->sexe;}
};
