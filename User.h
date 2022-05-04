/*************************************************************************
                           USER  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <USER> (fichier USER.h) ----------------
#if ! defined ( USER_H )
#define USER_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <USER>
//
//
//------------------------------------------------------------------------

class User 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual bool seConnecter(string email_in, string mdp);

    virtual bool seDeconnecter(bool connected);

//------------------------------------------------- Surcharge d'opérateurs
    
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend ostream & operator <<(ostream& out, const User & unUser);

//-------------------------------------------- Constructeurs - destructeur
    User ( const User & unUser );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    User (string unNom, string unPrenom, string unEmail, string unMdp);
    // Mode d'emploi :
    //
    // Contrat :
    //

    User ();

    virtual ~User ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string nom;
string prenom;
string email;
string motDePasse;
};

//-------------------------------- Autres définitions dépendantes de <USER>

#endif // USER_H
