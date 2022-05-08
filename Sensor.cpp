/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <System> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;
//------------------------------------------------------ Include personnel

#include "Sensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

int Sensor::getId()
{
    return sensorId;
} //----- Fin getId

double Sensor::getLatitude()
{
    return latitude;
} //----- Fin getLatitude

double Sensor::getLongitude()
{
    return longitude;
} //----- Fin getLongitude

//------------------------------------------------- Surcharge d'opérateurs

ostream &operator<<(ostream &out, const Sensor &unSensor)
{
    out << unSensor.sensorId << " " << unSensor.latitude << " " << unSensor.longitude;
    return out;
} //----- Fin de operator <<

bool operator==(Sensor &unSensor1, Sensor &unSensor2)
{
    bool res = false;
    if (unSensor1.getId() == unSensor2.getId())
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
