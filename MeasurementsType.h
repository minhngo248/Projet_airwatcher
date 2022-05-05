/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <MeasurementsType> (fichier MeasurementsType.h) ----------------
#if ! defined ( MEASUREMENTSTYPE_H )
#define MEASUREMENTSTYPE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <MeasurementsType>
//
//
//------------------------------------------------------------------------

class MeasurementsType 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
	//

    friend ostream & operator<<(ostream & out, const MeasurementsType & unMeasurementsType);

//-------------------------------------------- Constructeurs - destructeur
    MeasurementsType ( const MeasurementsType & unMeasurementsType );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    MeasurementsType (string aID);
    // Mode d'emploi :
    //
    // Contrat :
    //

    MeasurementsType ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~MeasurementsType ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

	string attributeID;
	string unite;
	string description;

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // MEASUREMENTSTYPE_H

