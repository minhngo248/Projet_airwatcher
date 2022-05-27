/*************************************************************************
                           IndividualUser  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <IndividualUser> (fichier IndividualUser.h) ----------------
#if ! defined (IndividualUser_H)
#define IndividualUser_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include "User.h"
#include "Sensor.h"
#include <list>
#include <iostream>
#include <fstream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <IndividualUser>
//
//
//------------------------------------------------------------------------

class IndividualUser : public User {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int consulterScore();
    void setScore(int unScore);
    Sensor ConsulterDonneesCapteur(int idCapteur);
    void SetListeCapteurs(list<Sensor> & uneListe);
    int GetSizeListeCapteurs();

    string GetEmail();
    int GetId();
    void SetId(int i);
    string GetMdp();

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    IndividualUser ( const IndividualUser & unIndividualUser );
    IndividualUser(string unNom, string unPrenom, string unEmail, string unMdp);
    IndividualUser();
    ~IndividualUser();
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int score;
    list<Sensor> mesCapteurs;
};



//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Sensor IndividualUser::ConsulterDonneesCapteur(int idCapteur)
{
    list<Sensor>::iterator it;
    Sensor monCapteur;

    for (it = mesCapteurs.begin(); it != mesCapteurs.end(); ++it)
    {   
        if (it->GetId() == idCapteur)
        {
            monCapteur = *it;
            break;
        }
    }
    return monCapteur;
}

void IndividualUser::SetListeCapteurs(list<Sensor> & uneListe) {
    this->mesCapteurs = uneListe;
}

int IndividualUser::consulterScore()
{
    return score;
}

void IndividualUser::setScore(int unScore)
{
    score = unScore;
}

int IndividualUser::GetSizeListeCapteurs() {
    return mesCapteurs.size();
}

string IndividualUser::GetEmail() {
    return User::GetEmail();
}

int IndividualUser::GetId() {
    return User::GetId();
}

void IndividualUser::SetId(int i) {
    User::SetId(i);
}

string IndividualUser::GetMdp() {
    return User::motDePasse;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
IndividualUser::IndividualUser(const IndividualUser &unIndividualUser) : User(unIndividualUser)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <IndividualUser>" << endl;
#endif
    this->score = unIndividualUser.score;
    this->mesCapteurs = unIndividualUser.mesCapteurs;
} //----- Fin de IndividualUser (constructeur de copie)

IndividualUser::IndividualUser() {
#ifdef MAP
    cout << "Appel au constructeur de <IndividualUser>" << endl;
#endif    
}

IndividualUser::IndividualUser(string unNom, string unPrenom, string unEmail, string unMdp) :
        User(unNom, unPrenom, unEmail, unMdp)
{
#ifdef MAP
    cout << "Appel au constructeur de <IndividualUser>" << endl;
#endif
} //----- Fin de IndividualUser

IndividualUser::~IndividualUser()
{
#ifdef MAP
    cout << "Appel au destructeur de <IndividualUser>" << endl;
#endif
} //----- Fin de ~IndividualUser

#endif // IndividualUser_H