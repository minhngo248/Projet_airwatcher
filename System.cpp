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


System::System ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <System>" << endl;
#endif
	//listeCapteurs=new Sensor [nbSensor] ;
	
	
} //----- Fin de System


System::~System ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <System>" << endl;
#endif

	delete listeCapteurs;
} //----- Fin de ~System


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

