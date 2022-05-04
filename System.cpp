
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
using namespace std;

//------------------------------------------------------ Include personnel
#include "System.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// type System::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur

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
    string line;
    // -------------Initialisation de la ListeCapteurs ----------------------
    fic.open("dataset/sensors.csv");
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
    }
    fic.close();
    // ----------------------------------------------------------------------
}

System::~System() {
    this->listeCapteurs.empty();
}




