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
    int GetId();
    void SetId(int i);

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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


int Administrateur::GetId() {
    return User::id;
}

void Administrateur::SetId(int i) {
    User::SetId(i);
}

//------------------------------------------------- Surcharge d'opérateurs
ostream &operator<<(ostream &out, const Administrateur &unAdministrateur)
{
    out << "email:" << unAdministrateur.email;
    out << ",motDePasse:" << unAdministrateur.motDePasse;
    out << ",nom:" << unAdministrateur.nom << ",prenom:" << unAdministrateur.prenom << endl;
    return out;
} //----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur
Administrateur::Administrateur(const Administrateur &unAdministrateur) : User(unAdministrateur)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Administrateur>" << endl;
#endif
} //----- Fin de Administrateur (constructeur de copie)

Administrateur::Administrateur(string unNom, string unPrenom, string unEmail, string unMdp) :
        User(unNom, unPrenom, unEmail, unMdp)
{
#ifdef MAP
    cout << "Appel au constructeur de <Administrateur>" << endl;
#endif
} //----- Fin de Administrateur

Administrateur::Administrateur()
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Administrateur>" << endl;
#endif
} //----- Fin de Administrateur

Administrateur::~Administrateur()
{
#ifdef MAP
    cout << "Appel au destructeur de <Administrateur>" << endl;
#endif
} //----- Fin de ~Administrateur

#endif // Administrateur_H