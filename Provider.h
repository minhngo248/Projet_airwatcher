/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Provider> (fichier Provider.h) ----------------
#if ! defined ( Provider_H )
#define Provider_H

//--------------------------------------------------- Interfaces utilisées

#include <cstring>
#include "User.h"
#include <iostream>
#include <fstream>
#include <list>
#include "modele/Cleaner.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Provider>
//  La classe provider définit ce que sont les fournisseurs des purificateurs d'air. Elle hérite de User
//
//------------------------------------------------------------------------

class Provider : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    User CreerCompte(int Provider_ID_in,string nom_in,string prenom_in, string email_in, string mdp_in);
    Cleaner ConsulterDonneesPurificateur();

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Provider ( const Provider & unProvider );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Provider ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Provider ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int providerID;
    list<Cleaner> listePurificateur;
    list<Cleaner>::iterator it;
};



//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Cleaner CreerCleaner(int cleanerID){
    ifstream fic;
    string line;
    string str="Cleaner";
    int idCleaner=0;
    float lat=0;
    float longi=0;
    string deb="";
    string fin="";
    string tab[5];
    int j;
    size_t pos=0;

    fic.open("dataset/cleaners.csv");
    while (getline(fic, line)) {
        //cout<<i<<": "<<line.c_str()<<endl;
        j=0;
        while ((pos = line.find(";")) != string::npos) {
            if(j==0){
                tab[j]=(line.substr(str.length(), pos-str.length()));
            }
            else{
                tab[j]=(line.substr(0, pos));
            }
            line.erase(0, pos + 1);
            j++;
        }
        if(stoi(tab[0])==cleanerID){
            idCleaner=stoi(tab[0]);
            lat= strtof(tab[1].c_str(),NULL);
            longi= strtof(tab[2].c_str(),NULL);
            deb=tab[3];
            fin=tab[4];
        }

        /*for (j=0;j<5;j++) {
            cout << tab[j] << endl;
        }*/

    }
    Cleaner cleaner=Cleaner(idCleaner,lat,longi,deb,fin);
    fic.close();
    return cleaner;
} //----- Fin de CreerCleaner

User Provider::CreerCompte(int Provider_ID_in,string nom_in,string prenom_in, string email_in, string mdp_in){
    ifstream fChargement;
    bool dejaInscrit=false;
    size_t sz;
    ifstream fic;
    string line;
    User user;
    int i=0;
    // -------------Initialisation de la ListePurificateurs ----------------------
    fic.open("dataset/providers.csv");
    while (!fic.eof()) {
        fic >> line;
        string str = "Provider";
        string str2="Cleaner";
        size_t pos1 = line.find(";");
        i++;
        int idProvider = stoi(line.substr(str.length(), pos1 - str.length()), &sz);
        int idCleaner = stoi(line.substr(pos1 +str2.length()+1, line.length()-(pos1 +str2.length()+1)));
        //cout<<i<<": "<< idProvider << " c "<<idCleaner<<endl;

        if(idProvider==Provider_ID_in){
            if(!dejaInscrit) {
                user=User (nom_in, prenom_in, email_in, mdp_in);
                dejaInscrit=true;
            }
            listePurificateur.push_back(CreerCleaner(idCleaner));
        }
    }
    fic.close();
    return user;
} //----- Fin de CreerCompte

Cleaner Provider::ConsulterDonneesPurificateur() {
    for (it = listePurificateur.begin (); it != listePurificateur.end (); ++it) {
        cout<<*it<<endl;
    }
    //cout<<listePurificateur.size()<<endl;
    return *listePurificateur.begin();
} //----- Fin de ConsulterDonneesPurificateur


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Provider::Provider ( const Provider & unProvider )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Provider>" << endl;
#endif
} //----- Fin de Provider (constructeur de copie)


Provider::Provider ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif
} //----- Fin de Provider


Provider::~Provider ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif
} //----- Fin de ~Provider

#endif // Provider_H