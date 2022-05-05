/*************************************************************************
                           IndividualUser  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <IndividualUser> (fichier IndividualUser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "IndividualUser.h"
#include "User.h"
#include "Sensor.h"
#include "Measurements.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
User IndividualUser::creerCompte(int userID_in, string unNom, string unPrenom, string unEmail, string unMdp)
{
    User *u;
    size_t sz;
    ifstream fic;
    string line;
    bool existe = false;
    
    fic.open("dataset/users.csv");

    while ( !fic.eof() ) {
        fic >> line;
        string str = "User";
        size_t pos1 = line.find(";");
        int idUser = stoi(line.substr(str.length(), pos1-str.length()), &sz);
        cout << idUser << endl;
        if (idUser == userID_in) {
            existe = true;
            break;
        }
    }
    fic.close();

       if (existe) {
        u = new User(unNom, unPrenom, unEmail, unMdp);
       } else {
           u = new User();
       }
    return *u;
}

int IndividualUser::consulterScore()
{
    return score;
}

Sensor IndividualUser::consulterDonneesCapteur(int idCapteur)
{
    list<Sensor>::iterator it;
    Sensor monCapteur ;

    for (it = mesCapteurs.begin(); it != mesCapteurs.end(); ++it) {
        if (it->getSensorID() == idCapteur){
            monCapteur = *it;
        }
    }

    return monCapteur;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
IndividualUser::IndividualUser ( const IndividualUser & unIndividualUser )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <IndividualUser>" << endl;
#endif
} //----- Fin de IndividualUser (constructeur de copie)


IndividualUser::IndividualUser ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <IndividualUser>" << endl;
#endif
} //----- Fin de IndividualUser


IndividualUser::~IndividualUser ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <IndividualUser>" << endl;
#endif
} //----- Fin de ~IndividualUser


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

