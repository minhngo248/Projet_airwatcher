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

#include <iostream>
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


//-------------------------------------------- Constructeurs - destructeur
MeasurementsType::MeasurementsType ( const MeasurementsType & unMeasurementsType )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif

	attributeID=unMeasurementsType.attributeID;
	unite=unMeasurementsType.unite;
	description=unMeasurementsType.description;
	
} //----- Fin de MeasurementsType (constructeur de copie)


MeasurementsType::MeasurementsType (int aID, string unit, string descrip )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <MeasurementsType>" << endl;
#endif

	attributeID=aID;
	unite=unit;
	description=descrip;
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

