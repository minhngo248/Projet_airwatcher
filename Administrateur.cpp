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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Administrateur::vérifierFiabilitéCapteurs(Sensor capteurChoisi, list<Sensor> capteursRéférence)
{
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Administrateur::Administrateur ( const Administrateur & unAdministrateur )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Administrateur>" << endl;
#endif
} //----- Fin de Administrateur (constructeur de copie)


Administrateur::Administrateur ( )
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

