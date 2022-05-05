
/*************************************************************************
                           Measurements  -  description
                             -------------------
    début                : 05/2022
    copyright            : (C) 2022 par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <System> (fichier System.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include <cmath>
using namespace std;

//------------------------------------------------------ Include personnel
#include "System.h"

//------------------------------------------------------------- Constantes
const double pi = M_PI;
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// type System::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

/*list<Measurements> Sensor::GetListeMesureParType(int sensorId_in, MeasurementsType type) {

} */

list<Measurements> System::GetListeMesure(int sensorId_in) {
    cout << "Instant | " << "type | " << "mesure" << endl;
    list<Measurements> uneListe = this->listeMesures.at(sensorId_in);
    for(auto& i:uneListe) {
        cout << i << endl;
    } 
    cout << uneListe.size() << endl;
    return uneListe;
}

list<Sensor> System::GetListeCapteurs_zone(Zone& zoneGeo, const string temps) {
    const float ky = 40000.0 / 360.0;
    list<Sensor> sensorDeLaZone;
    for(auto& i:this->listeCapteurs) {
        float kx = cos(pi * zoneGeo.GetLatitude() / 180.0) * ky;
        float dx = abs(zoneGeo.GetLongitude() - i.second.GetLongitude()) * kx;
        float dy = abs(zoneGeo.GetLatitude() - i.second.GetLatitude()) * ky;
        if(sqrt(dx * dx + dy * dy) <= zoneGeo.GetRayon()) {
            sensorDeLaZone.push_back(i.second); 
        }
    }
    return sensorDeLaZone;
    
}

//-------------------------------------------- Constructeurs - destructeur
ostream & operator << (ostream & out, const System & unSystem) {
    out << "SensorID | Latitude | Longitude"<<endl;
    for(auto& i : unSystem.listeCapteurs) {
        out << i.first << " " << i.second << endl;
    }
    return out; 
}


System::System ( const System & unMeasurements )
//Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <System>" << endl;
#endif
} //----- Fin de System (constructeur de copie)


System::System() {
    size_t sz;
    ifstream fic;
    ifstream fic1;
    string line;
    string line1;
    // -------------Initialisation de la ListeCapteurs ----------------------
    fic.open("dataset/sensors.csv");
    fic1.open("dataset/measurements.csv");
    while ( !fic.eof() ) {
        fic >> line;
        string str = "Sensor";
        size_t pos1 = line.find(";");
        int idSensor = stoi(line.substr(str.length(), pos1-str.length()), &sz);
        size_t pos2 = line.find_first_of(";", pos1+1);
        double lat = stod(line.substr(pos1+1, pos2-pos1-1), &sz);
        double lon = stod(line.substr(pos2 + 1), &sz);
        Sensor unSensor(idSensor, lat, lon);
        this->listeCapteurs.insert(pair<int, Sensor>(idSensor, unSensor));

        list<Measurements> uneListeMesures;
        uneListeMesures.clear();
        while( !fic1.eof() ) {
            getline(fic1, line1);
            size_t pos11;
            size_t pos12;
            size_t pos13;
            int idSensor1;
            if (line1.length() > 0) {
                pos11 = line1.find(";");
                pos12 = line1.find(";", pos11+1);
                pos13 = line1.find(";", pos12+1);
                idSensor1 = stoi(line1.substr(pos11+7, pos12-pos11-7), &sz);
            } else break;
            
            if (idSensor != idSensor1) {        
                break;
            }
            string instant = line1.substr(0, pos11);
            double mesure = stod(line1.substr(pos13+1), &sz);
            string attribut = line1.substr(pos12+1, pos13-pos12-1); 
            Measurements uneMesure(instant, attribut, mesure);
            uneListeMesures.push_back(uneMesure);
        }
        this->listeMesures.insert(pair<int, list<Measurements>>(idSensor, uneListeMesures));
    }
    fic1.close();
    fic.close();
    // ----------------------------------------------------------------------
}

System::~System() {
    this->listeCapteurs.clear();
    this->listeMesures.clear();
}




