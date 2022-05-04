/*************************************************************************
                           Measurements  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Measurements> (fichier Measurements.h) ----------------
#if ! defined ( MEASUREMENTS_H )
#define MEASUREMENTS_H
#include <chrono>
using namespace std;
#include <iostream>



//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Measurements>
//
//
//------------------------------------------------------------------------

class Measurements
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


//-------------------------------------------- Constructeurs - destructeur
    Measurements ( const Measurements & unMeasurements );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Measurements (string periode, float mesure, MeasurementsType typeMesure );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Measurements ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    string periode;
    float mesure;
    MeasurementsType typeMesure;
};

//-------------------------------- Autres définitions dépendantes de <Measurements>

#endif // MEASUREMENTS_H

