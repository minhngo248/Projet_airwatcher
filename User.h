/*************************************************************************
                           User  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <USER> (fichier USER.h) ----------------
#if !defined(USER_H)
#define USER_H

using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <USER>
// La classe User définit un utilisateur lambda de l'application
//
//------------------------------------------------------------------------

class User
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    virtual bool seConnecter(string email_in, string mdp);
    // Mode d'emploi :
    //  Cette méthode permet de connecter un User grâce à son email et mot de passe. Elle renvoie true si l'authentification s'est réalisée avec succès. Faux sinon.

    virtual bool seDeconnecter(bool connected);
    // Mode d'emploi :
    //  Cette méthode permet de déconnecter un User. Elle renvoie false si la déconnection s'est réalisée avec succès. True sinon.

    //------------------------------------------------- Surcharge d'opérateurs

    friend ostream &operator<<(ostream &out, const User &unUser);
    // Mode d'emploi :
    //  Cette méthode permet de d'afficher unUser sur le flux de sortie out.

    //-------------------------------------------- Constructeurs - destructeur
    User(const User &unUser);
    // Mode d'emploi (constructeur de copie) :
    //

    User(string unNom, string unPrenom, string unEmail, string unMdp);
    // Mode d'emploi :
    //  Cette méthode permet créer un nouvel User.

    User();
    // Mode d'emploi :
    //  Constructeur par défaut, ne fait rien.

    virtual ~User();
    // Mode d'emploi :
    //  Le destructeur ne fait rien

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
