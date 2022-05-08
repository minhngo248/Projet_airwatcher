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
#include "Cleaner.h"
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

//-------------------------------- Autres définitions dépendantes de <Provider>

#endif // Provider_H

