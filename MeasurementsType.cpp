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
#include <fstream>
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

ostream & operator<<(ostream & out, const MeasurementsType & unMeasurementsType) {
    out << unMeasurementsType.attributeID << " " << unMeasurementsType.unite << " " << unMeasurementsType.description;
    return out; 
}
//-------------------------------------------- Constructeurs - destructeur
MeasurementsType::MeasurementsType ( const MeasurementsType & unMeasurementsType )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <MeasurementsType>" << endl;
#endif

	attributeID=unMeasurementsType.attributeID;
	unite=unMeasurementsType.unite;
	description=unMeasurementsType.description;
	
} //----- Fin de MeasurementsType (constructeur de copie)


MeasurementsType::MeasurementsType (string aID)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <MeasurementsType>" << endl;
#endif

    ifstream fic;
    char lineGet[100];
    string line;
    fic.open("dataset/attributes.csv");
    fic >> line; //skip the first line
    while ( !fic.eof() ) {
        fic.getline(lineGet,100,'\n');
        line = lineGet;
        size_t pos1 = line.find(";");
        string unID = line.substr(0,pos1);
        
        if(!unID.compare(aID))
        {
            attributeID = aID;
            size_t pos2 = line.find_first_of(";", pos1+1);
            unite = line.substr(pos1+1, pos2-pos1-1);
            size_t pos3 = line.find_first_of(";", pos2+1);
            description = line.substr(pos2+1, pos3-pos2-1);
            break;
        }
    }
    fic.close();
} //----- Fin de MeasurementsType


MeasurementsType::MeasurementsType ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <MeasurementsType>" << endl;
#endif
}

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

