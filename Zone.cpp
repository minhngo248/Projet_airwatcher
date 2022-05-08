/*************************************************************************
                           Zone  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Zone> (fichier Zone.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Zone.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

double Zone::getLatitude()
{
    return latitude;
} //----- Fin de getLatitude

double Zone::getLongitude()
{
    return longitude;
} //----- Fin de getLongitude

double Zone::getRayon()
{
    return rayon;
} //----- Fin de getRayon

Zone::Zone(double unLat, double unLong, double unRayon)
{
    this->latitude = unLat;
    this->longitude = unLong;
    this->rayon = unRayon;
} //----- Fin de Zone

Zone::~Zone()
{

} //----- Fin de ~Zone

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées