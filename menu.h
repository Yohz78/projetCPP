#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

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
        //ajouter ici un appel vers la fonction recherchant un contact à partir de son nom
        cout<<"nom"<<endl;
    }

    //Effectuer une recherche a l'aide de la ville
    if(opt.compare("ville")==0){
        //ajouter ici un appel vers la fonction recherchant des contacts à partir de leur ville
        cout<<"ville"<<endl;
    }

    //Ajouter un contact
    if(opt.compare("ajout")==0){
        //ajouter ici un appel vers la fonction permettant d'ajouter des contacts
        cout<<"ajout"<<endl;
    }

    //Supprimer un contact
    if(opt.compare("supprimer")==0){
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
