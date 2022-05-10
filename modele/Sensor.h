/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------

#if !defined(SENSOR_H)
#define SENSOR_H

#include <string>
#include <iostream>

//--------------------------------------------------- Interfaces utilisées

#include "Measurements.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Srnsor>
//  La classe Sensor définit ce qu'est un capteur
//
//------------------------------------------------------------------------
class Sensor
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    int GetId();
    double GetLatitude();
    double GetLongitude();

    //-------------------------------------------- Surchage d'opérateurs
    friend ostream &operator<<(ostream &out, const Sensor &unSensor);
    bool operator==(const Sensor& unSensor);

    //-------------------------------------------- Constructeurs - destructeur
    Sensor(int unSensorId = 0, double unLat = 44.0, double unLong = -1.0);
    virtual ~Sensor();
    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
private:
    int sensorId;
    double latitude;
    double longitude;
};

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int Sensor::GetId()
{
    return sensorId;
} //----- Fin getId

double Sensor::GetLatitude()
{
    return latitude;
} //----- Fin getLatitude

double Sensor::GetLongitude()
{
    return longitude;
} //----- Fin getLongitude

//------------------------------------------------- Surcharge d'opérateurs

ostream &operator<<(ostream &out, const Sensor &unSensor)
{
    out << unSensor.sensorId << " " << unSensor.latitude << " " << unSensor.longitude;
    return out;
} //----- Fin de operator <<

bool Sensor::operator==(const Sensor& unSensor)
{
    bool res = false;
    if (this->sensorId == unSensor.sensorId)
    {
        res = true;
    }
    return res;
} //----- Fin operator ==

//-------------------------------------------- Constructeurs - destructeur

Sensor::Sensor(int unSensorId, double unLat, double unLong)
{
    this->sensorId = unSensorId;
    this->latitude = unLat;
    this->longitude = unLong;
} //----- Fin Sensor

Sensor::~Sensor()
{

} //----- Fin ~Sensor

#endif // Sensor_H
