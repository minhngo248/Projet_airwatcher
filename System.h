/*************************************************************************
                           System  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <System> (fichier System.h) ----------------
#if ! defined ( SYSTEM_H )
#define SYSTEM_H
using namespace std;
#include <iostream>
#include <fstream>
#include <map>
#include <list>

//--------------------------------------------------- Interfaces utilisées
#include "Zone.h"
#include "Measurements.h"
#include "MeasurementsType.h"
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <System>
//  La classe System fournie les fonctionnalités de l'application AirWatcher
//
//------------------------------------------------------------------------

class System
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    //list<Measurements> GetListeMesureParType(int sensorId_in, MeasurementsType type);
    list<Measurements> getListeMesure(int sensorId_in);
	list<Sensor> GetListeCapteurs_zone(Zone& zoneGeo);
	map<string, double> CalculerQualiteAir_zone(Zone & zoneGeo);
	double CalculerQualiteAir(list<Measurements>& listeMesures, string periode,
                                 string typeMesure);
    multimap<double, int> ClassifierCapteurs(int idCapteurReference, string periode, string typeMesure);
    //float VerifierAmeliorationAir(Zone & zoneGeo); 

//-------------------------------------------- Surchage d'opérateurs
    friend ostream & operator<<(ostream & out, const System & unSystem);

//-------------------------------------------- Constructeurs - destructeur

    System ( const System & unSystem );
    System ( );
    virtual ~System ( );
    // Mode d'emploi :

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
private:
    map<int, Sensor> listeCapteurs;
	map<int, list<Measurements>> listeMesures;
};

//-------------------------------- Autres définitions dépendantes de <System>

#endif // System_H