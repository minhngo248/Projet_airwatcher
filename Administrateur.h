/*************************************************************************
                           Administrateur  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Administrateur> (fichier Administrateur.h) ----------------
#if !defined(Administrateur_H)
#define Administrateur_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <cstring>
#include <list>
#include <iostream>
#include "User.h"
#include "Sensor.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Administrateur>
//  Cette classe définit ce qu'est un administrateur. Elle hérite de User
//
//------------------------------------------------------------------------

class Administrateur : public User
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    bool verifierFiabiliteCapteur(Sensor capteurChoisi, Sensor capteurReference);

    //------------------------------------------------- Surcharge d'opérateurs
    friend ostream &operator<<(ostream &out, const Administrateur &unAdministrateur);

    //-------------------------------------------- Constructeurs - destructeur
    Administrateur(const Administrateur &unAdministrateur);
    Administrateur(string unNom, string unPrenom, string unEmail, string unMdp);
    Administrateur();
    virtual ~Administrateur();

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Administrateur>

#endif // Administrateur_H
