
/*************************************************************************
                           System  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <System> (fichier System.h) ----------------
#if ! defined ( SYSTEM_H )
#define SYSTEM_H
using namespace std;
#include <iostream>
#include <fstream>
#include <map>
#include <list>

#include "Zone.h"
#include "Measurements.h"
#include "MeasurementsType.h"
#include "Sensor.h"




//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <System>
//
//
//------------------------------------------------------------------------

class System
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    //list<Measurements> GetListeMesureParType(int sensorId_in, MeasurementsType type);
    list<Measurements> GetListeMesure(int sensorId_in);

	list<Sensor> GetListeCapteurs_zone(Zone& zoneGeo);
	map<string, double> CalculerQualiteAir_zone(Zone & zoneGeo);
	double CalculerQualiteAir(list<Measurements>& listeMesures, string periode,
                                 string typeMesure);
    multimap<double, int> ClassifierCapteurs(int idCapteurReference, string periode, string typeMesure);
    //float VerifierAmeliorationAir(Zone & zoneGeo); 
    
    friend ostream & operator<<(ostream & out, const System & unSystem);
//-------------------------------------------- Constructeurs - destructeur

    System ( const System & unSystem );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    System ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~System ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE


//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
private:
    map<int, Sensor> listeCapteurs;
	map<int, list<Measurements>> listeMesures;
};

//-------------------------------- Autres définitions dépendantes de <Measurements>

#endif // MEASUREMENTS_H

