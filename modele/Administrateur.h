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
    bool verifierFiabiliteCapteur(int idSensorToCheck, double precision = 0.05);

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
bool Administrateur::verifierFiabiliteCapteur(int idSensorToCheck, double precision)
{
    string periode = "2019-01-01 12:00:00to2019-12-31 12:00:00";
    System system;
    bool capteurDeParticulier = false;
    list<pair<int, int>> sensorsIndividualUsers = system.getListeSensorsIndividualUsers();
    for (auto &i : sensorsIndividualUsers)
    {
        if (i.second == idSensorToCheck)
        {
            capteurDeParticulier = true;
            break;
        }
    }

    if (capteurDeParticulier)
    {
        Sensor capteurChoisi = system.getSensorById(idSensorToCheck);

        // Récupération mesures du capteur
        Zone zone = Zone(capteurChoisi.GetLatitude(), capteurChoisi.GetLongitude(), 50);
        list<Measurements> listeMesuresAVerifier = system.getListeMesure(capteurChoisi.GetId());

        // Récupération des mesures des autres capteurs
        list<Sensor> sensorDeLaZone = system.GetListeCapteurs_zone(zone);
        list<Measurements> listeMesuresReference;

        for (auto &it1 : sensorDeLaZone)
        {
            if (it1.GetId() != capteurChoisi.GetId())
            {
                for (auto &it2 : system.getListeMesure(it1.GetId()))
                {
                    listeMesuresReference.push_back(it2);
                }
            }
        }

        // Calcule qualité air (dans un but de performance toutes les qualités de sont pas calculées d'office)
        double qualiteO3 = system.CalculerQualiteAir(listeMesuresAVerifier, periode, "O3");
        double qualiteO3Ref = system.CalculerQualiteAir(listeMesuresReference, periode, "O3");

        cout << "Qualité du choisi : " << qualiteO3 << endl;
        cout << "Qualité des autres : " << qualiteO3Ref << endl;

        if ((abs(qualiteO3 - qualiteO3Ref) / qualiteO3Ref) <= precision)
        {
            cout << "03 PASSED" << endl;
            double qualiteNO2 = system.CalculerQualiteAir(listeMesuresAVerifier, periode, "NO2");
            double qualiteNO2Ref = system.CalculerQualiteAir(listeMesuresReference, periode, "NO2");
            if ((abs(qualiteNO2 - qualiteNO2Ref) / qualiteNO2Ref) <= precision)
            {
                cout << "NO2 PASSED" << endl;
                double qualiteSO2 = system.CalculerQualiteAir(listeMesuresAVerifier, periode, "SO2");
                double qualiteSO2Ref = system.CalculerQualiteAir(listeMesuresReference, periode, "SO2");
                if ((abs(qualiteSO2 - qualiteSO2Ref) / qualiteSO2Ref) <= precision)
                {
                    cout << "SO2 PASSED" << endl;
                    double qualitePM10 = system.CalculerQualiteAir(listeMesuresAVerifier, periode, "PM10");
                    double qualitePM10Ref = system.CalculerQualiteAir(listeMesuresReference, periode, "PM10");

                    if ((abs(qualitePM10 - qualitePM10Ref) / qualitePM10Ref) <= precision)
                    {
                        cout << "PM10 PASSED" << endl;
                        cout << "Le capteur est fiable" << endl;
                        cout << "D'après un intervalle de confiance de " << precision * 100 << "%" << endl;
                        return true;
                    }
                }
            }
        }

        cout << "A exclure : mesures incompatibles avec celles de capteur reference" << endl;
        cout << "D'après un intervalle de confiance de " << precision * 100 << "%" << endl;
        return false;
    } else {
        cout << "Ce n'est pas un capteur de particulier" << endl;
        return false;
    }

} //----- Fin de VerifierFiabiliteCapteur

//------------------------------------------------- Surcharge d'opérateurs
ostream &operator<<(ostream &out, const Administrateur &unAdministrateur)
{
    out << "email:" << unAdministrateur.email;
    out << ",motDePasse:" << unAdministrateur.motDePasse;
    out << ",nom:" << unAdministrateur.nom << ",prenom:" << unAdministrateur.prenom << endl;
    return out;
} //----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur
Administrateur::Administrateur(const Administrateur &unAdministrateur)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Administrateur>" << endl;
#endif
} //----- Fin de Administrateur (constructeur de copie)

Administrateur::Administrateur(string unNom, string unPrenom, string unEmail, string unMdp)
    : User(unNom, unPrenom, unEmail, unMdp)
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
} //----- Fin de Administrateur (par défaut)

Administrateur::~Administrateur()
{
#ifdef MAP
    cout << "Appel au destructeur de <Administrateur>" << endl;
#endif
} //----- Fin de ~Administrateur

#endif // Administrateur_H