/*************************************************************************
                           Administrateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Administrateur> (fichier Administrateur.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <cstring>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Administrateur.h"
#include "User.h"
#include "Sensor.h"
#include "Zone.h"
#include "System.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Administrateur::verifierFiabiliteCapteur(Sensor capteurChoisi, Sensor capteurReference)
{
    Zone zone = Zone(capteurChoisi.GetLatitude(), capteurChoisi.GetLongitude(), 50); 
    System system = System();
    list<Sensor> sensorDeLaZone = system.GetListeCapteurs_zone(zone);

    for(auto& it1:sensorDeLaZone) {
        if (it1 == capteurReference){
            list<Measurements> listeMesuresReference = system.GetListeMesure(capteurReference.GetId());
            list<Measurements> listeMesuresAVerifier = system.GetListeMesure(capteurChoisi.GetId());

            for(auto& it2:listeMesuresAVerifier) {
                for (auto& it3:listeMesuresAVerifier){
                    if (it2.GetInstant() == it3.GetInstant() && it2.GetTypeMesure() == it3.GetTypeMesure()){
                        if (it2.GetMesure()<(it3.GetMesure()-0.05) || (it3.GetMesure()+0.05)<it2.GetMesure())
                        {
                            cout << "A exclure : mesures incompatibles avec celles de capteur reference " << endl;
                            return false;
                        }
                    }
                }
            }
            return true;
        }
    }
    cout << "capteur reference n'existe pas dans la meme zone que le capteur choisi " << endl;
    return false;
}
//------------------------------------------------- Surcharge d'opérateurs
ostream & operator <<(ostream& out, const Administrateur & unAdministrateur)
{
    out <<"email:"<<unAdministrateur.email;
    out <<",motDePasse:"<<unAdministrateur.motDePasse;
    out <<",nom:"<<unAdministrateur.nom <<",prenom:"<<unAdministrateur.prenom << endl;
    return out;
}

//-------------------------------------------- Constructeurs - destructeur
Administrateur::Administrateur ( const Administrateur & unAdministrateur )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Administrateur>" << endl;
#endif
} //----- Fin de Administrateur (constructeur de copie)


Administrateur::Administrateur (string unNom, string unPrenom, string unEmail, string unMdp)
:User(unNom, unPrenom, unEmail, unMdp) {

    #ifdef MAP
        cout << "Appel au constructeur de <Administrateur>" << endl;
    #endif
} //----- Fin de Administrateur

Administrateur::Administrateur ()
{
    #ifdef MAP
        cout << "Appel au constructeur de <Administrateur>" << endl;
    #endif
} //----- Fin de Administrateur

Administrateur::~Administrateur ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <Administrateur>" << endl;
    #endif
} //----- Fin de ~Administrateur


//------------------------------------------------------------------ PRIVE

