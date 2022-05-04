
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
#include <chrono>
using namespace std;
#include <iostream>

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
	Sensor * GetListeCapteurs_zone(Zone zoneGeo, string temps);
	float CalculerQualitéMoyenne(Zone zoneGeo);
	float CalculerQualitéAir_zone(list <Measurements> listeMesures);
	float CalculerQualitéAir_point(list <Measurements> listeMesures, string temps) ;
	float CalculerQualitéAir_point(list <Measurements> listeMesures, string temps,MeasurementsType type) ;
    Sensor * ClassifierCapteurs( string idCapteurRéférence, string temps, list <MeasurementsType>  donnees);
    float VérifierAméliorationAir(Zone zoneGeo);

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
	map<int, Sensor> listeCapteurs;
};

//-------------------------------- Autres définitions dépendantes de <Measurements>

#endif // MEASUREMENTS_H

