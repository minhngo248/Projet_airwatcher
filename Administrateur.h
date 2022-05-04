/*************************************************************************
                           Administrateur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Administrateur> (fichier Administrateur.h) ----------------
#if ! defined ( Administrateur_H )
#define Administrateur_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <cstring>
#include<list>
#include "User.h"
#include "Sensor.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Administrateur>
//
//
//------------------------------------------------------------------------

class Administrateur : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
bool vérifierFiabilitéCapteurs(Sensor capteurChoisi, list<Sensor> capteursRéférence);

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Administrateur ( const Administrateur & unAdministrateur );

    Administrateur ( );

    virtual ~Administrateur ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Administrateur>

#endif // Administrateur_H

