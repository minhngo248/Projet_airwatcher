/*************************************************************************
                           Measurements  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Measurements> (fichier Measurements.h) ----------------
#if ! defined (MEASUREMENTS_H)
#define MEASUREMENTS_H

#include <iostream>
#include <string>
#include <list>



//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Measurements>
//
//
//------------------------------------------------------------------------

class Measurements {
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    string GetTypeMesure();
    double GetMesure();
    string GetInstant();
    friend ostream & operator<<(ostream & out, const Measurements& uneMesure);
//-------------------------------------------- Constructeurs - destructeur

    Measurements(string ins = "", string typeMes = "", double mes = 0.0);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Measurements();
    // Mode d'emploi :
    //
    // Contrat :
    //

private:
    string instant;
    string typeMesure;
    double mesure;
};

//-------------------------------- Autres définitions dépendantes de <Measurements>

#endif // MEASUREMENTS_H

