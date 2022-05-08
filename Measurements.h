/*************************************************************************
                           Measurements  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Measurements> (fichier Measurements.h) ----------------
#if !defined(MEASUREMENTS_H)
#define MEASUREMENTS_H

#include <iostream>
#include <string>
#include <list>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Measurements>
//  Cette classe correspond aux données mesurées par les capteurs
//
//------------------------------------------------------------------------

class Measurements
{
    //----------------------------------------------------------------- PUBLIC
public:
    //----------------------------------------------------- Méthodes publiques
    string getTypeMesure();
    double getMesure();
    string getInstant();
    //-------------------------------------------- Surchage d'opérateurs
    friend ostream &operator<<(ostream &out, const Measurements &uneMesure);
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
