/*************************************************************************
                           User  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <USER> (fichier USER.h) ----------------
#if ! defined (USER_H)
#define USER_H

using namespace std;
#include <string>
#include <map>


//--------------------------------------------------- Interfaces utilisées


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

    virtual bool SeDeconnecter(bool connected);
    // Mode d'emploi :
    //  Cette méthode permet de déconnecter un User. Elle renvoie false si la déconnection s'est réalisée avec succès. True sinon.

    virtual string GetEmail();
    virtual int GetId();
    virtual void SetId(int i);
    virtual string GetMdp();
    virtual string GetNom();
    virtual string GetPrenom();

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
    int id;
    string nom;
    string prenom;
    string email;
    string motDePasse;
};


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


bool User::SeDeconnecter(bool connected)
{
    if (connected)
    {
        cout << "Vous êtes déconnecté" << endl;
        connected = false;
    }
    return connected;
} //----- Fin de seDeconnecter

int User::GetId() {
    return id;
}

void User::SetId(int i) {
    this->id = i;
}

string User::GetEmail() {
    return email;
}

string User::GetMdp() {
    return motDePasse;
}

string User::GetNom() {
    return nom;
}

string User::GetPrenom() {
    return prenom;
}

//------------------------------------------------- Surcharge d'opérateurs

ostream &operator<<(ostream &out, const User &unUser)
{
    out << unUser.id << ";" << unUser.nom << ";" << unUser.prenom << ";" <<
            unUser.email << ";" << unUser.motDePasse;
    return out;
} //----- Fin de operator << 

//-------------------------------------------- Constructeurs - destructeur
User::User(const User &unUser)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <User>" << endl;
#endif
    this->id = unUser.id;
    this->nom = unUser.nom;
    this->prenom = unUser.prenom;
    this->email = unUser.email;
    this->motDePasse = unUser.motDePasse;
} //----- Fin de User (constructeur de copie)

User::User(string unNom, string unPrenom, string unEmail, string unMdp)
{
    // type=1 --> particulier, type=2 --> fournisseur, type=3 --> admin
#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif
    this->nom = unNom;
    this->prenom = unPrenom;
    this->email = unEmail;
    this->motDePasse = unMdp;
} //----- Fin de User

User::User()
{
#ifdef MAP
    cout << "Appel au constructeur par def de <User>" << endl;
#endif
    this->id = 0;
} //----- Fin de User

User::~User()
{
#ifdef MAP
    cout << "Appel au destructeur de <User>" << endl;
#endif
} //----- Fin de ~User

#endif // USER_H