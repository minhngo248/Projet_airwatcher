/*************************************************************************
                           Measurements  -  description
                             -------------------
    début                : 05/2022
    copyright            : (C) 2022 par $AUTHOR$
    e-mail               : $EMAIL$
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

// type Measurements::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Measurements::GetTypeMesure() {
    return typeMesure;
}

double Measurements::GetMesure() {
    return mesure;
}

string Measurements::GetInstant() {
    return instant;
}

ostream & operator<<(ostream & out, const Measurements& uneMesure) {
    out << uneMesure.instant << " " << uneMesure.typeMesure << " " << uneMesure.mesure;
    return out;
}

//-------------------------------------------- Constructeurs - destructeur


Measurements::Measurements(string ins, string typeMes, double mes) {
// Algorithme :
//
#ifdef MAP
    cout << "Appel au constructeur de <Measurements>" << endl;
#endif
	this->instant = ins;
	this->mesure = mes;
	this->typeMesure = typeMes;
} //----- Fin de Measurements


Measurements::~Measurements ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Measurements>" << endl;
#endif
} //----- Fin de ~Measurements


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

