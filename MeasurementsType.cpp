/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <MeasurementsType> (fichier MeasurementsType.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;

//------------------------------------------------------ Include personnel
#include "MeasurementsType.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string MeasurementsType::GetId() {
    return attributeID;
}

//-------------------------------------------- Constructeurs - destructeur

MeasurementsType::MeasurementsType ( const MeasurementsType & unMeasurementsType ) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif

	attributeID=unMeasurementsType.attributeID;
	unite=unMeasurementsType.unite;
	description=unMeasurementsType.description;
	
} //----- Fin de MeasurementsType (constructeur de copie)


MeasurementsType::MeasurementsType (string aID, string unit, string descrip )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <MeasurementsType>" << endl;
#endif

	this->attributeID=aID;
	this->unite=unit;
	this->description=descrip;
} //----- Fin de MeasurementsType


MeasurementsType::~MeasurementsType ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <MeasurementsType>" << endl;
#endif
} //----- Fin de ~MeasurementsType


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

