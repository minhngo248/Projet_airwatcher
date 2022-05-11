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
    fSauvegarde.open("dataset/login.csv", ios::app);
    if (fSauvegarde)
    {

        fSauvegarde << nom << ";" << prenom << ";" << email << ";" << motDePasse <<";\n";
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

#endif // USER_H