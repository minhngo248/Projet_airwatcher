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

using namespace std;
#include <iostream>

#include "MeasurementsType.h"



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

    friend ostream & operator<<(ostream & out, const Measurements& uneMesure);
//-------------------------------------------- Constructeurs - destructeur
    Measurements ( const Measurements & unMeasurements );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Measurements(string ins, string typeMes, double mes);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Measurements ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

private:
    string instant;
    double mesure;
    string typeMesure;
};

//-------------------------------- Autres définitions dépendantes de <Measurements>

#endif // MEASUREMENTS_H

