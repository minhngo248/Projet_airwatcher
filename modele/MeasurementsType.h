/*************************************************************************
                           Measurements  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <MeasurementsType> (fichier MeasurementsType.h) ----------------
#if !defined(MEASUREMENTSTYPE_H)
#define MEASUREMENTSTYPE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <MeasurementsType>
//  Cette classe définit les différents types de mesures récoltés par les capteurs.
//
//------------------------------------------------------------------------

class MeasurementsType
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    string getId();
    //-------------------------------------------- Constructeurs - destructeur

    MeasurementsType(const MeasurementsType &unMeasurementsType);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    MeasurementsType(string aID = "", string unit = "", string descrip = "");
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~MeasurementsType();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

private:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés

    string attributeID;
    string unite;
    string description;
};



//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string MeasurementsType::getId()
{
    return attributeID;
} //----- Fin de getId

//-------------------------------------------- Constructeurs - destructeur

MeasurementsType::MeasurementsType(const MeasurementsType &unMeasurementsType)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif

    attributeID = unMeasurementsType.attributeID;
    unite = unMeasurementsType.unite;
    description = unMeasurementsType.description;

} //----- Fin de MeasurementsType (constructeur de copie)

MeasurementsType::MeasurementsType(string aID, string unit, string descrip)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <MeasurementsType>" << endl;
#endif

    this->attributeID = aID;
    this->unite = unit;
    this->description = descrip;
} //----- Fin de MeasurementsType

MeasurementsType::~MeasurementsType()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <MeasurementsType>" << endl;
#endif
} //----- Fin de ~MeasurementsType

#endif // MEASUREMENTSTYPE_H