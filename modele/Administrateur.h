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
#include "../modele/Sensor.h"
#include "../modele/Zone.h"
#include "../service/System.h"
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
    bool verifierFiabiliteCapteur(Sensor capteurChoisi, Sensor capteurReference, double precision = 0.05);

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
bool Administrateur::verifierFiabiliteCapteur(Sensor capteurChoisi, Sensor capteurReference, double precision)
{
    Zone zone = Zone(capteurChoisi.GetLatitude(), capteurChoisi.GetLongitude(), 50); 
    System system = System();
    list<Sensor> sensorDeLaZone = system.GetListeCapteurs_zone(zone);
    for(auto& it1:sensorDeLaZone) {
        if (it1 == capteurReference){
            list<Measurements> listeMesuresReference = system.getListeMesure(capteurReference.GetId());
            list<Measurements> listeMesuresAVerifier = system.getListeMesure(capteurChoisi.GetId());

            for(auto& it2:listeMesuresAVerifier) {
                for (auto& it3:listeMesuresAVerifier){
                    if (it2.getInstant() == it3.getInstant() && it2.getTypeMesure() == it3.getTypeMesure()){
                        if (it2.getMesure()<(it3.getMesure()-precision) || (it3.getMesure()+precision)<it2.getMesure())
                        {
                            cout << "A exclure : mesures incompatibles avec celles de capteur reference" << endl;
                            cout << "D'après un intervalle de confiance de " << precision*100 <<"%"<<endl;
                            return false;
                        }
                    }
                }
            }
            cout << "Le capteur est fiable" << endl;
            cout << "D'après un intervalle de confiance de " << precision*100 <<"%"<<endl;
            return true;
        }
    }
    cout << "capteur reference n'existe pas dans la meme zone que le capteur choisi " << endl;
    return false;
} //----- Fin de VerifierFiabiliteCapteur

//------------------------------------------------- Surcharge d'opérateurs
ostream & operator <<(ostream& out, const Administrateur & unAdministrateur)
{
    out <<"email:"<<unAdministrateur.email;
    out <<",motDePasse:"<<unAdministrateur.motDePasse;
    out <<",nom:"<<unAdministrateur.nom <<",prenom:"<<unAdministrateur.prenom << endl;
    return out;
} //----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur
Administrateur::Administrateur ( const Administrateur & unAdministrateur )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Administrateur>" << endl;
#endif
} //----- Fin de Administrateur (constructeur de copie)


Administrateur::Administrateur (string unNom, string unPrenom, string unEmail, string unMdp)
:User(unNom, unPrenom, unEmail, unMdp) {

    #ifdef MAP
        cout << "Appel au constructeur de <Administrateur>" << endl;
    #endif
} //----- Fin de Administrateur

Administrateur::Administrateur ()
{
    #ifdef MAP
        cout << "Appel au constructeur par défaut de <Administrateur>" << endl;
    #endif
} //----- Fin de Administrateur (par défaut)

Administrateur::~Administrateur ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <Administrateur>" << endl;
    #endif
} //----- Fin de ~Administrateur

#endif // Administrateur_H