/*************************************************************************
                           Zone  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ZONE (fichier Zone.h) ----------------
#if !defined(ZONE_H)
#define ZONE_H
//--------------------------------------------------- Interfaces utilisées
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types
//------------------------------------------------------------------------
// Rôle de la classe <ZONE>
// La classe ZONE définit ce qu'est une zone géographique
//
//------------------------------------------------------------------------
class Zone
{
    //----------------------------------------------------------------- PUBLIC
public:
    //----------------------------------------------------- Méthodes publiques
    double getLatitude();
    double getLongitude();
    double getRayon();

    //-------------------------------------------- Constructeurs - destructeur
    Zone();
    Zone(double unLat, double unLong, double unRayon);
    ~Zone();

    //------------------------------------------------------------------ PRIVE
private:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
    double latitude;
    double longitude;
    double rayon;
};



//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

double Zone::getLatitude()
{
    return latitude;
} //----- Fin de getLatitude

double Zone::getLongitude()
{
    return longitude;
} //----- Fin de getLongitude

double Zone::getRayon()
{
    return rayon;
} //----- Fin de getRayon

Zone::Zone(double unLat, double unLong, double unRayon)
{
    this->latitude = unLat;
    this->longitude = unLong;
    this->rayon = unRayon;
} //----- Fin de Zone

Zone::~Zone()
{

} //----- Fin de ~Zone

#endif // ZONE_H