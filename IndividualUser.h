/*************************************************************************
                           IndividualUser  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <IndividualUser> (fichier IndividualUser.h) ----------------
#if ! defined ( IndividualUser_H )
#define IndividualUser_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include "User.h"
#include "Sensor.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <IndividualUser>
//
//
//------------------------------------------------------------------------

class IndividualUser : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    User creerCompte(int userID_in, User unUser);
    int consulterScore();
    Sensor consulterDonneesCapteur(int idCapteur);


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    IndividualUser ( const IndividualUser & unIndividualUser );

    IndividualUser ();

    virtual ~IndividualUser ( );
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int userID;
    int score;
    list <Sensor> mesCapteurs;

};

//-------------------------------- Autres définitions dépendantes de <IndividualUser>

#endif // IndividualUser_H

