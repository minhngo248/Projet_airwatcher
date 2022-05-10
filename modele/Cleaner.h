/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Cleaner> (fichier Cleaner.h) ----------------
#if ! defined (CLEANER_H)
#define CLEANER_H
using namespace std;
#include <iostream>
#include <string>

//--------------------------------------------------- Interfaces utilisées
//#include "Provider.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cleaner>
//  Cette classe définit ce qu'est un purificateur d'air
//
//------------------------------------------------------------------------

class Cleaner
{
    //----------------------------------------------------------------- PUBLIC
public:
    //----------------------------------------------------- Méthodes publiques

    //-------------------------------------------- Surchage d'opérateurs
    friend ostream &operator<<(ostream &out, const Cleaner &unCleaner) {
        out << "CleanerID:" << unCleaner.cleanerID << ",Lattitude:" << unCleaner.Lattitude << ",Longitude:" << unCleaner.Longitude << ",debut:" << unCleaner.debut << ",fin:" << unCleaner.fin << endl;
        return out;
    } //----- Fin de operator <<

    //-------------------------------------------- Constructeurs - destructeur
    Cleaner(int CleanerID, float lattitude, float longitude, string Debut, string Fin) {
    #ifdef MAP
        cout << "Appel au constructeur de <Measurements>" << endl;
    #endif
        cleanerID = CleanerID;
        Lattitude = lattitude;
        Longitude = longitude;
        debut = Debut;
        fin = Fin;
    } //----- Fin de Cleaner
    
    ~Cleaner()
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Cleaner>" << endl;
    #endif
    } //----- Fin de ~Cleaner

    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    int cleanerID;
    float Lattitude;
    float Longitude;
    string debut;
    string fin;
};

#endif // CLEANER_H

