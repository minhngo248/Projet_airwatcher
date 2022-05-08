/*************************************************************************
                           User  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <User> (fichier User.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool User::seConnecter(string email_in, string mdp)
{
    ifstream fChargement;
    char emailTmp[50];
    char mdpTmp[50];

    fChargement.open("users.txt");
    if (fChargement)
    {

        while (!fChargement.eof())
        {

            fChargement.getline(emailTmp, 200, ':');

            fChargement.getline(emailTmp, 200, ',');
            if (emailTmp == email_in)
            {

                fChargement.getline(mdpTmp, 200, ':');
                fChargement.getline(mdpTmp, 200, ',');
                if (mdpTmp == mdp)
                {
                    return true;
                }
            }
            else
            {
                fChargement.getline(emailTmp, 1000, '\n');
            }
        }
    }
    return false;
} //----- Fin de seConnecter

bool User::seDeconnecter(bool connected)
{
    if (connected)
    {
        cout << "Vous êtes déconnecté" << endl;
        connected = false;
    }
    return connected;
} //----- Fin de seDeconnecter

//------------------------------------------------- Surcharge d'opérateurs

ostream &operator<<(ostream &out, const User &unUser)
{
    out << "email:" << unUser.email << ",motDePasse:" << unUser.motDePasse << ",nom:" << unUser.nom << ",prenom:" << unUser.prenom << endl;
    return out;
} //----- Fin de operator << 

//-------------------------------------------- Constructeurs - destructeur
User::User(const User &unUser)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <User>" << endl;
#endif
} //----- Fin de User (constructeur de copie)

User::User(string unNom, string unPrenom, string unEmail, string unMdp)
{
#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif

    nom = unNom;
    prenom = unPrenom;
    email = unEmail;
    motDePasse = unMdp;

    ofstream fSauvegarde;
    fSauvegarde.open("users.txt", ios::app);
    if (fSauvegarde)
    {

        fSauvegarde << *this;
    }
    fSauvegarde.close();

} //----- Fin de User

User::User()
{
#ifdef MAP
    cout << "Appel au constructeur par def de <User>" << endl;
#endif
} //----- Fin de User

User::~User()
{
#ifdef MAP
    cout << "Appel au destructeur de <User>" << endl;
#endif
} //----- Fin de ~User

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
