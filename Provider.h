/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
//
//
//------------------------------------------------------------------------

class Provider : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    User creerCompte(int Provider_ID_in,string nom_in,string prenom_in, string email_in, string mdp_in);
    Cleaner consulterDonneesPurificateur();


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

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int providerID;
    list<Cleaner> listePurificateur;
    list<Cleaner>::iterator it;
};

//-------------------------------- Autres définitions dépendantes de <Provider>

#endif // Provider_H

