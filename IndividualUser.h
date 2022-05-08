/*************************************************************************
                           IndividualUser  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <IndividualUser> (fichier IndividualUser.h) ----------------
#if ! defined ( IndividualUser_H )
#define IndividualUser_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include "User.h"
#include "Sensor.h"
#include <list>
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
    User CreerCompte(int unUserID, string unNom, string unPrenom, string unEmail, string unMdp);
    int consulterScore();
    void setScore(int unScore);
    Sensor ConsulterDonneesCapteur(int idCapteur);
    Sensor CreerSensor(int unSensorID);


//------------------------------------------------- Surcharge d'opérateurs
    friend ostream & operator <<(ostream& out, const IndividualUser & unIndividualUser);

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

