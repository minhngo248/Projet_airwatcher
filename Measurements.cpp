/*************************************************************************
                           Measurements  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Measurements> (fichier Measurements.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Measurements.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Measurements::getTypeMesure()
{
    return typeMesure;
} //----- Fin de getTypeMesure

double Measurements::getMesure()
{
    return mesure;
} //----- Fin de getMesure

string Measurements::getInstant()
{
    return instant;
} //----- Fin de getInstanta

//-------------------------------------------- Surchage d'opérateurs
ostream &operator<<(ostream &out, const Measurements &uneMesure)
{
    out << uneMesure.instant << " " << uneMesure.typeMesure << " " << uneMesure.mesure;
    return out;
} //----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur

Measurements::Measurements(string ins, string typeMes, double mes)
{
// Algorithme :
//
#ifdef MAP
    cout << "Appel au constructeur de <Measurements>" << endl;
#endif
    this->instant = ins;
    this->mesure = mes;
    this->typeMesure = typeMes;
} //----- Fin de Measurements

Measurements::~Measurements()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Measurements>" << endl;
#endif
} //----- Fin de ~Measurements

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
