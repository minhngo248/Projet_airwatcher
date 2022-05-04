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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
User IndividualUser::creerCompte(int userID_in, User unUser)
{
    size_t sz;
    ifstream fic;
    string line;
    
    fic.open("dataset/users.csv");

    while ( !fic.eof() ) {
        fic >> line;
        string str = "Sensor";
        // size_t pos1 = line.find(";");
        // int idSensor = stoi(line.substr(str.length(), pos1-str.length()), &sz);
        // size_t pos2 = line.find_first_of(";", pos1+1);
        // double lat = stod(line.substr(pos1+1, pos2-pos1-1), &sz);
        // double lon = stod(line.substr(pos2 + 1), &sz);
        
        // Sensor unSensor(idSensor, lat, lon);
        // this->listeCapteurs.insert(pair<int, Sensor>(idSensor, unSensor));
    }
    fic.close();

}

int IndividualUser::consulterScore()
{
    return score;
}

Sensor IndividualUser::consulterDonneesCapteur(int idCapteur)
{
    std::list<Sensor>::iterator it;
    Sensor monCapteur;

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

