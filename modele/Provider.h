/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Provider> (fichier Provider.h) ----------------
#if ! defined (PROVIDER_H)
#define PROVIDER_H

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

class Provider : public User {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Cleaner ConsulterDonneesPurificateur(int idPurificateur);
    list<Cleaner> GetListePurificateurs();

    string GetEmail();
    int GetId();
    void SetId(int i); 
    string GetMdp();
    void SetListePuri(list<Cleaner> & li);

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Provider (const Provider & unProvider);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Provider(string unNom, string unPrenom, string unEmail, string unMdp);
    // Mode d'emploi :
    //
    // Contrat :
    //
    Provider();
    virtual ~Provider();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    list<Cleaner> listePurificateur;
};



//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Cleaner Provider::ConsulterDonneesPurificateur(int idPurificateur) {
    Cleaner monCleaner;
    for (auto& i:this->listePurificateur) {
        if (i.GetId() == idPurificateur)
        {
            monCleaner = i;
            break;
        }
    }
    return monCleaner;
} //----- Fin de ConsulterDonneesPurificateur

list<Cleaner> Provider::GetListePurificateurs(){
    return listePurificateur;
}

string Provider::GetEmail() {
    return User::email;
}

int Provider::GetId() {
    return User::id;
}

void Provider::SetId(int i) {
    User::SetId(i);
}

string Provider::GetMdp() {
    return User::motDePasse;
}

void Provider::SetListePuri(list<Cleaner> & li) {
    this->listePurificateur = li;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Provider::Provider ( const Provider & unProvider ) : User(unProvider)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Provider>" << endl;
#endif
    this->listePurificateur = unProvider.listePurificateur;
} //----- Fin de Provider (constructeur de copie)

Provider::Provider() {
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif  
}

Provider::Provider(string unNom, string unPrenom, string unEmail, string unMdp) : User(unNom, unPrenom, unEmail, unMdp)
{

} //----- Fin de Provider


Provider::~Provider ()
{
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif
    this->listePurificateur.clear();
} //----- Fin de ~Provider

#endif // Provider_H