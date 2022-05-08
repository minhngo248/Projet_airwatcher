/*************************************************************************
                           System  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <System> (fichier System.h) ----------------
#if ! defined (SYSTEM_H)
#define SYSTEM_H
using namespace std;
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <cmath>

//--------------------------------------------------- Interfaces utilisées
#include "../modele/Zone.h"
#include "../modele/Measurements.h"
#include "../modele/MeasurementsType.h"
#include "../modele/Sensor.h"

//------------------------------------------------------------- Constantes
const double pi = M_PI;

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <System>
//  La classe System fournie les fonctionnalités de l'application AirWatcher
//
//------------------------------------------------------------------------

class System
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    list<Measurements> getListeMesure(int sensorId_in);
	list<Sensor> GetListeCapteurs_zone(Zone& zoneGeo);
	list<pair<string, double>> CalculerQualiteAir_zone(Zone & zoneGeo);
	double CalculerQualiteAir(list<Measurements>& listeMesures, string periode,
                                 string typeMesure);
    multimap<double, int> ClassifierCapteurs(int idCapteurReference, string periode, string typeMesure);
    //float VerifierAmeliorationAir(Zone & zoneGeo); 

//-------------------------------------------- Surchage d'opérateurs
    friend ostream & operator<<(ostream & out, const System & unSystem);

//-------------------------------------------- Constructeurs - destructeur

    System( const System & unSystem );
    System();
    virtual ~System();
    // Mode d'emploi :

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
private:
    map<int, Sensor> listeCapteurs;
	map<int, list<Measurements>> listeMesures;
};


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

list<Measurements> System::getListeMesure(int sensorId_in)
{
    list<Measurements> uneListe = this->listeMesures.at(sensorId_in);
    return uneListe;
} //----- Fin getListeMesure

list<Sensor> System::GetListeCapteurs_zone(Zone &zoneGeo)
{
    const float ky = 40000.0 / 360.0;
    list<Sensor> sensorDeLaZone;
    for (auto &i : this->listeCapteurs)
    {
        float kx = cos(pi * zoneGeo.getLatitude() / 180.0) * ky;
        float dx = abs(zoneGeo.getLongitude() - i.second.getLongitude()) * kx;
        float dy = abs(zoneGeo.getLatitude() - i.second.getLatitude()) * ky;
        if (sqrt(dx * dx + dy * dy) <= zoneGeo.getRayon())
        {
            sensorDeLaZone.push_back(i.second);
        }
    }
    return sensorDeLaZone;
} //----- Fin de GetListeCapteur_zone

list<pair<string, double>> System::CalculerQualiteAir_zone(Zone &zoneGeo)
{
    // string : typeMesure (O3, PM10 ...), double : mesure
    list<pair<string, double>> qualite;
    list<Sensor> sensorsDeLaZone = GetListeCapteurs_zone(zoneGeo);
    cout << sensorsDeLaZone.size() << " capteurs sont dans cette zone" << endl;
    list<Measurements> mesuresDeLaZone;
    for (auto &i : sensorsDeLaZone)
    {
        for (auto &j : this->listeMesures.at(i.getId()))
        {
            mesuresDeLaZone.push_back(j);
        }
    }
    string periode = "2019-01-01 12:00:00to2019-12-31 12:00:00";
    double qualiteO3 = CalculerQualiteAir(mesuresDeLaZone, periode, "O3");
    qualite.push_back(pair<string, double>("O3", qualiteO3));
    double qualiteNO2 = CalculerQualiteAir(mesuresDeLaZone, periode, "NO2");
    qualite.push_back(pair<string, double>("NO2", qualiteNO2));
    double qualiteSO2 = CalculerQualiteAir(mesuresDeLaZone, periode, "SO2");
    qualite.push_back(pair<string, double>("SO2", qualiteSO2));
    double qualitePM10 = CalculerQualiteAir(mesuresDeLaZone, periode, "PM10");
    qualite.push_back(pair<string, double>("PM10", qualitePM10));
    return qualite;
} //----- Fin de CalculerQualiteAir_zone

double System::CalculerQualiteAir(list<Measurements> &listeMesures, string periode,
                                  string typeMesure)
{
    double quality = 0.0;
    list<Measurements> listeMesuresPeriode;
    for (auto &i : listeMesures)
    {
        // recuperer la listeMesure par periode
        size_t pos1 = periode.find("to");
        string tempsDeb = periode.substr(0, pos1);
        string tempsFin = periode.substr(pos1 + 2);
        if (tempsDeb <= i.getInstant() && i.getInstant() <= tempsFin)
        {
            listeMesuresPeriode.push_back(i);
        }
    }
    int j = 0;
    for (auto &i : listeMesuresPeriode)
    {
        if (i.getTypeMesure() == typeMesure)
        {
            quality += i.getMesure();
            ++j;
        }
    }
    quality /= j;
    return quality;
} //----- Fin de CalculerQualiteAir

multimap<double, int> System::ClassifierCapteurs(int idCapteurRef, string periode,
                                                 string typeMesure)
{
    multimap<double, int> listeQualiteCapteur;
    // double : similitude, int : idCapteur (idSensor)
    list<Measurements> listeMesuresRef = this->listeMesures[idCapteurRef];
    double qualiteRef = CalculerQualiteAir(listeMesuresRef, periode, typeMesure);
    for (auto &i : this->listeCapteurs)
    {
        list<Measurements> listeMesuresParCapteur = this->listeMesures.at(i.first);
        double similitude = abs(CalculerQualiteAir(listeMesuresParCapteur, periode, typeMesure) - qualiteRef);
        listeQualiteCapteur.insert(pair<double, int>(similitude, i.first));
    }
    return listeQualiteCapteur;
} //----- Fin de ClassifierCapteurs

//------------------------------------------------- Surcharge d'opérateurs
ostream &operator<<(ostream &out, const System &unSystem)
{
    out << "SensorID | Latitude | Longitude" << endl;
    for (auto &i : unSystem.listeCapteurs)
    {
        out << i.first << " " << i.second << endl;
    }
    return out;
} //----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur

System::System(const System &unMeasurements)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <System>" << endl;
#endif
} //----- Fin de System (constructeur de copie)

System::System()
{
    size_t sz;
    ifstream fic;
    ifstream fic1;
    string line;
    string line1;
    // -------------Initialisation de la ListeCapteurs ----------------------
    fic.open("dataset/sensors.csv");
    fic1.open("dataset/measurements.csv");
    while (!fic.eof())
    {
        fic >> line;
        string str = "Sensor";
        size_t pos1 = line.find(";");
        int idSensor = stoi(line.substr(str.length(), pos1 - str.length()), &sz);
        size_t pos2 = line.find_first_of(";", pos1 + 1);
        double lat = stod(line.substr(pos1 + 1, pos2 - pos1 - 1), &sz);
        double lon = stod(line.substr(pos2 + 1), &sz);
        Sensor unSensor(idSensor, lat, lon);
        this->listeCapteurs.insert(pair<int, Sensor>(idSensor, unSensor));

        list<Measurements> uneListeMesures;
        uneListeMesures.clear();
        while (!fic1.eof())
        {   
            getline(fic1, line1);
            size_t pos11 = line1.find(";");
            size_t pos12 = line1.find(";", pos11 + 1);
            size_t pos13 = line1.find(";", pos12 + 1);
            int idSensor1 = 200;
            if (pos11 != string::npos && pos12 != string::npos && pos13 != string::npos)
                idSensor1 = stoi(line1.substr(pos11 + 7, pos12 - pos11 - 7), &sz);
            if (idSensor1 != idSensor)
                break;
            
            string instant = line1.substr(0, pos11);
            double mesure = stod(line1.substr(pos13 + 1), &sz);
            string attribut = line1.substr(pos12 + 1, pos13 - pos12 - 1);
            Measurements uneMesure(instant, attribut, mesure);
            uneListeMesures.push_back(uneMesure);
        }
        this->listeMesures.insert(pair<int, list<Measurements>>(idSensor, uneListeMesures));
    }
    fic1.close();
    fic.close();
} //----- Fin de System

System::~System()
{
    this->listeCapteurs.clear();
    this->listeMesures.clear();
} //----- Fin de ~System

#endif // System_H