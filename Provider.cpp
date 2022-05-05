/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <cstring>
#include <iostream>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Provider.h"
#include "User.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Cleaner creerCleaner(int cleanerID){
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
    // -------------Initialisation de la ListeCapteurs ----------------------
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
}
User Provider::creerCompte(int Provider_ID_in,string nom_in,string prenom_in, string email_in, string mdp_in){
    ifstream fChargement;
    bool dejaInscrit=false;
    size_t sz;
    ifstream fic;
    string line;
    User user;
    int i=0;
    // -------------Initialisation de la ListeCapteurs ----------------------
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
            listePurificateur.push_back(creerCleaner(idCleaner));
        }
    }
    fic.close();
    return user;
}

Cleaner Provider::consulterDonneesPurificateur() {
    for (it = listePurificateur.begin (); it != listePurificateur.end (); ++it) {
        cout<<*it<<endl;
    }
    //cout<<listePurificateur.size()<<endl;
    return *listePurificateur.begin();
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Provider::Provider ( const Provider & unProvider )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Provider>" << endl;
#endif
} //----- Fin de Provider (constructeur de copie)


Provider::Provider ( )
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif
} //----- Fin de Provider


Provider::~Provider ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif
} //----- Fin de ~Provider


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

