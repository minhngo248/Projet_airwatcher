/*************************************************************************
                           User  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
// type User::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool User::seConnecter(string email_in, string mdp)
{
    ifstream fChargement;
    char emailTmp[50] ;
    char mdpTmp[50];

    fChargement.open("users.txt");
    if(fChargement)
    {

        while (!fChargement.eof())
        {

            fChargement.getline(emailTmp,200,':');
            
            fChargement.getline(emailTmp,200,',');
            if(emailTmp==email_in)
            {

                fChargement.getline(mdpTmp,200,':');
                fChargement.getline(mdpTmp,200,',');
                if(mdpTmp==mdp)
                {
                    return true;
                }
            }else{
                fChargement.getline(emailTmp,1000,'\n');
            }
        }
    }
    return false;
}

bool User::seDeconnecter(bool connected)
{
    if(connected)
    {
        cout<<"Vous êtes déconnecté"<<endl;
        return false;
    }

}

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator<<(ostream& out, const User & unUser)
{
    out<<"email:"<<unUser.email<<",motDePasse:"<<unUser.motDePasse<<",nom:"<<unUser.nom<<",prenom:"<<unUser.prenom<<endl;
    return out;
}

//-------------------------------------------- Constructeurs - destructeur
User::User ( const User & unUser )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <User>" << endl;
#endif
} //----- Fin de User (constructeur de copie)


User::User (string unNom, string unPrenom, string unEmail, string unMdp)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif


nom=unNom;
prenom = unPrenom;
email = unEmail;
motDePasse = unMdp;

ofstream fSauvegarde;
fSauvegarde.open("users.txt", ios::app);
if(fSauvegarde)
{
    
    fSauvegarde << *this <<endl;
}

fSauvegarde.close();

} //----- Fin de User


User::User ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur par def de <User>" << endl;
#endif
} //----- Fin de ~User

User::~User ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <User>" << endl;
#endif
} //----- Fin de ~User


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
