#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <string>
#include <cstring>
#include<regex>
#include<stdio.h>
#include "contact/contact.h"
#include "Private/private.h"
#include "Pro/pro.h"

using namespace std;

bool Email_check(string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email,pattern);
}


void menu(){
    cout<<"***********************************\n"<<endl;
    cout<<"Bienvenu dans cette application de gestion de vos contacts \n\n"<< endl;
    cout<<"Que souhaitez vous faire ?\n"<< endl;
    cout<<"- Pour afficher la liste des contacts, tapez liste \n"<< endl;
    cout<<"- Pour afficher la liste des contacts professionnels, tapez pro\n"<< endl;
    cout<<"- Pour afficher la liste des contacts privés, tapez private\n"<< endl;
    cout<<"- Pour effectuer une recherche à l'aide du nom d'un contact, tapez nom\n"<< endl;
    cout<<"- Pour effectuer une recherche à l'aide de la ville d'un contact, tapez ville\n"<< endl;
    cout<<"- Pour ajouter un contact, tapez ajout \n"<< endl;
    cout<<"- Pour supprimer un contact, tapez supprimer \n"<< endl;
    cout<<"- Pour quitter, tapez q \n"<< endl;
    cout<<"- Entrez votre choix : "<<endl;

    string opt;
    cin >> opt;


    //Afficher la liste des contacts
    if(opt.compare("liste")==0){
        //Ajouter ici un appel vers la fonction listant tout les contacts à partir de la base sqlite
        cout<<"liste"<<endl;
    }

    //Afficher la liste des contacts pro
    if(opt.compare("pro")==0){
        //Ajouter ici un appel vers la fonction listant tout les contacts pro  à partir de la base sqlite
        cout<<"pro"<<endl;
    }

    //Afficher la liste des contacts privés
    if(opt.compare("private")==0){
        //Ajouter ici un appel vers la fonction listant tout les contacts privés  à partir de la base sqlite
        cout<<"private"<<endl;
    }

    //Effectuer une recherche a l'aide du nom
    if(opt.compare("nom")==0){
        string nom;
        cout<<"\nMerci de saisir le nom du contact recherché : "<<endl;
        cin>>nom;
        //ajouter ici un appel vers la fonction recherchant un contact à partir de son nom
    }

    //Effectuer une recherche a l'aide de la ville
    if(opt.compare("ville")==0){
        //ajouter ici un appel vers la fonction recherchant des contacts à partir de leur ville
        string ville;
        cout<<"\nMerci de saisir la ville recherchée : "<<endl;
        cin>>ville;
        cout<<ville<<endl;
    }

    //Ajouter un contact
    if(opt.compare("ajout")==0){


        cout<<"S'agit-il d'un contact professionnel ou privé ?"<<endl;
        cout<<"Tapez 'pro' pour un professionnel, 'private' pour un contact privé"<<endl;
        string choix;
        cin>>choix;

        //Saisie si le contact est un professionnel
        if(choix.compare("pro")==0){
            int id, codepostal;
            string nom, prenom, nomEntreprise, rue, email, complement, ville;
            string sexe;

            cout<<"Quel est l'id du contact ? \n"<<endl;
            cin>>id;
            cout<<"\n Quel est le nom du contact ? \n"<<endl;
            cin>>nom;
            while(nom.length()>30){
                cout<<"Merci de saisir un nom de moins de 30 caractères"<<endl;
                cin>>nom;
            }

            cout<<"\n Quel est le prenom du contact ? \n"<<endl;
            cin>>prenom;
            while(prenom.length()>30){
                cout<<"Merci de saisir un prenom de moins de 30 caractères"<<endl;
                cin>>prenom;
            }
            cout<<"\n Quelle est l'entreprise du contact ? \n"<<endl;
            cin>>nomEntreprise;
              while(nomEntreprise.length()>50){
                cout<<"Merci de saisir un nom d'entreprise de moins de 50 caractères"<<endl;
                cin>>nom;
            }
            cout<<"\n Quel est l'email du contact ? \n"<<endl;
            cin>>email;
            while(Email_check(email)==false){
                cout<<"Email invalide. Merci de saisir une adresse email correcte :";
                cin>>email;
            }

            cout<<"\n Quel est le sexe du contact ? H/F ? \n"<<endl;
            cin>>sexe;
            cout<<"\n Quel est le numero et la rue du contact (format: numero, rue) ? H/F ? \n"<<endl;
            cin>>rue;
            cout<<"\n Quel est le complèment de l'adresse du contact ? indiquez na si non applicable. \n"<<endl;
            cin>>complement;
            cout<<"\n Quel est le code postal du contact ? \n"<<endl;
            cin>>codepostal;
            cout<<"\n Quelle est la ville du contact ? \n"<<endl;
            cin>>ville;
            Adresse adresse(rue,complement,codepostal,ville);
            Pro newPro(id,nom,prenom,sexe,adresse, nomEntreprise, email);


        //Saisie pour un contact privé
        }else if(choix.compare("private")==0){
            int year, codepostal;
            string nom, prenom, rue, complement, ville, datenaissance;
            string sexe;

            cout<<"Quel est l'id du contact ? \n"<<endl;
            cin>>id;

            cout<<"\n Quel est le nom du contact ? \n"<<endl;
            cin>>nom;
            while(nom.length()>30){
                cout<<"Merci de saisir un nom de moins de 30 caractères"<<endl;
                cin>>nom;
            }

            cout<<"\n Quel est le prenom du contact ? \n"<<endl;
            cin>>prenom;
            while(prenom.length()>30){
                cout<<"Merci de saisir un prenom de moins de 30 caractères"<<endl;
                cin>>prenom;
            }

            cout<<"\n Merci de saisir la date de naissance du contact \n"<<endl;
            cin>>datenaissance;


            while(sexe.compare("H")!=0||sexe.compare("H")!=0){
                cout<<"\n Quel est le sexe du contact ? H/F ? \n"<<endl;
                cin>>sexe;
            }
            cout<<"\n Quel est le numero et la rue du contact (format: numero, rue) ? H/F ? \n"<<endl;
            cin>>rue;
            cout<<"\n Quel est le complèment de l'adresse du contact ? indiquez na si non applicable. \n"<<endl;
            cin>>complement;
            cout<<"\n Quel est le code postal du contact ? \n"<<endl;
            cin>>codepostal;
            cout<<"\n Quelle est la ville du contact ? \n"<<endl;
            cin>>ville;

            Adresse adresse(rue,complement,codepostal,ville);
            Private newPrivate(id,nom,prenom,sexe,adresse,datenaissance);

        }else{
            cout<<"Saisie incorrecte. Retour au menu.\n"<<endl;
            menu();
        }
        //ajouter ici un appel vers la fonction permettant d'ajouter des contacts
        cout<<"ajout"<<endl;
    }

    //Supprimer un contact
    if(opt.compare("supprimer")==0){
        string nom;
        cout<<"\nMerci de saisir le nom du contact à supprimer : "<<endl;
        cin>>nom;

        //ajouter ici un appel vers la fonction permettant de supprimer un contact à partir de son nom
        cout<<"supprimer"<<endl;
    }

    //Quitter
    if(opt.compare("q")==0){
        exit(0);
    }

    menu();

}


#endif // MENU_H_INCLUDED
