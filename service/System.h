/*************************************************************************
                           System  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <System> (fichier System.h) ----------------
#if ! defined (SYSTEM_H)
#define SYSTEM_H

using namespace std;
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <cmath>

//--------------------------------------------------- Interfaces utilisées
#include "../modele/Zone.h"
#include "../modele/Measurements.h"
#include "../modele/Sensor.h"
#include "../modele/User.h"
#include "../modele/Provider.h"
#include "../modele/IndividualUser.h"
#include "../modele/Administrateur.h"

//------------------------------------------------------------- Constantes
const double pi = M_PI;
double getDistanceFromLatLonInKm(double lat1, double lon1, double lat2, double lon2);
double deg2rad(double deg);
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <System>
//  La classe System fournie les fonctionnalités de l'application AirWatcher
//
//------------------------------------------------------------------------

class System
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

    void CreerCompte(string unNom, string unPrenom, string unEmail, string unMdp, int type);
    IndividualUser SeConnecterIUser(string unEmail, string unMdp);
    Provider SeConnecterProvider(string unEmail, string unMdp);
    Administrateur SeConnecterAdmin(string unEmail, string unMdp);
    

    list<Measurements> getListeMesure(int sensorId_in);
    list<Sensor> GetListeCapteurs_zone(Zone &zoneGeo);
    list<pair<string, double>> CalculerQualiteAir_zone(Zone &zoneGeo, string periode = "2019-01-01 12:00:00to2019-12-31 12:00:00");
    double CalculerQualiteAir(list<Measurements> &listeMesures, string periode, string typeMesure);
    multimap<double, int> ClassifierCapteurs(int idCapteurReference, string periode, string typeMesure);
    map<int, list<int>> getListeSensorsIndividualUsers();
    list<Sensor> getListeSensorsIndividualUser(int idIndividualUser_check);

    void ConsulterScore(IndividualUser & particulierConnecte);
    void ConsulterDonneesCapteur(IndividualUser &particulierConnecte, int idCapteur);

    list<Cleaner> GetListePurificateurByProvider(int idProvider);
    void ConsulterDonneesPurificateur(Provider &fournisseurConnecte, int idPurificateur);
    bool VerifierFiabiliteCapteur(Administrateur & admin, int idSensorToCheck, double precision = 0.05);

    //-------------------------------------------- Surchage d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    System(const System &unSystem);
    System();
    virtual ~System();
    // Mode d'emploi :

    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
private:
    map<int, Sensor> listeCapteurs;
    map<int, Sensor> listeCapteurs_exclu;
    map<int, list<Measurements>> listeMesures;
    map<int, User> listeUsers;
    map<int, IndividualUser> listeIUser;
    map<int, Provider> listeProvider;
    map<int, Administrateur> listeAdmin;
    map<int, Cleaner> listeCleaners;
    void write_file(User & unUser, int type) const;
    void read_file_login();
};

double getDistanceFromLatLonInKm(double lat1, double lon1, double lat2, double lon2)
{
    double R = 6371.0;                  // Radius of the earth in km
    double dLat = deg2rad(lat2 - lat1); // deg2rad below
    double dLon = deg2rad(lon2 - lon1);
    double a =
        sin(dLat / 2) * sin(dLat / 2) +
        cos(deg2rad(lat1)) * cos(deg2rad(lat2)) *
            sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = R * c; // Distance in km
    return d;
}

double deg2rad(double deg)
{
    return deg * (pi / 180);
}
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void System::write_file(User & unUser, int type) const {
    ofstream fic("dataset/login.csv", ios::app);
    fic << unUser << ";" << type << endl;
    fic.close();    
}

void System::read_file_login() {
    ifstream fic("dataset/login.csv");
    string line;

    while (!fic.eof()) {
        getline(fic, line);
        if (line.length() == 0) break;
        size_t pos1 = line.find(";");
        size_t pos2 = line.find(";", pos1+1);
        size_t pos3 = line.find(";", pos2+1);
        size_t pos4 = line.find(";", pos3+1);
        size_t pos5 = line.find(";", pos4+1);
        int idUser = stoi(line.substr(0, pos1));
        string nom = line.substr(pos1+1, pos2-pos1-1);
        string prenom = line.substr(pos2+1, pos3-pos2-1);
        string mail = line.substr(pos3+1, pos4-pos3-1);
        string mdp = line.substr(pos4+1, pos5-pos4-1);
        int type = stoi(line.substr(pos5+1));

        if (type == 1) {
            IndividualUser iUser(nom, prenom, mail, mdp);
            iUser.SetId(idUser);
            this->listeIUser.insert(pair<int, IndividualUser>(idUser, iUser));
            this->listeUsers.insert(pair<int, User>(idUser, iUser));
        } else if (type == 2) {
            Provider pro(nom, prenom, mail, mdp);
            pro.SetId(idUser);
            this->listeProvider.insert(pair<int, Provider>(idUser, pro));
            this->listeUsers.insert(pair<int, User>(idUser, pro));
        } else if (type == 3) {
            Administrateur admin(nom,prenom,mail,mdp);
            admin.SetId(idUser);
            this->listeAdmin.insert(pair<int, Administrateur>(idUser, admin));
            this->listeUsers.insert(pair<int, User>(idUser, admin));
        }
    }
    fic.close();
}

void System::CreerCompte(string unNom, string unPrenom, string unEmail, string unMdp, int type) {
    for (auto& i:this->listeUsers) {
        if (unEmail == i.second.GetEmail()) {
            cout << "Email existe, inscription échouée." << endl;
            return;
        }
    }
    //int key = this->listeUsers.size();
    int key;
    srand(time(0));
    while (true) {
        key = rand()%1000 + 1;
        try {
            User aUser = this->listeUsers.at(key);    
        } catch (const std::out_of_range& oor) {
            break;
        }
    }
    if (type == 1) {    
        // 1 : individual user
        IndividualUser iUser(unNom, unPrenom, unEmail, unMdp);
        iUser.SetId(key);
        this->listeUsers.insert(pair<int, User>(key, iUser));
        this->listeIUser.insert(pair<int, IndividualUser>(key, iUser));
        this->write_file(iUser, type);
    } else if (type == 2) {
        Provider provider(unNom, unPrenom, unEmail, unMdp);
        provider.SetId(key);
        this->listeUsers.insert(pair<int, User>(key, provider));
        this->listeProvider.insert(pair<int, Provider>(key, provider));
        this->write_file(provider, type);
    }
    cout << "Inscription réussie." << endl;
}

IndividualUser System::SeConnecterIUser(string unEmail, string unMdp) {
    IndividualUser iu;
    for(auto& i : this->listeIUser) {
        if (i.second.GetEmail() == unEmail && i.second.GetMdp() == unMdp) {
            cout << "Connexion réussie" << endl;
            return i.second;
        }
    }
    iu.SetId(-1);
    cout << "Email ou mot de passe incorrect" << endl;
    return iu;
}

Provider System::SeConnecterProvider(string unEmail, string unMdp) {
    Provider pro;
    for(auto& i : this->listeProvider) {
        if (i.second.GetEmail() == unEmail && i.second.GetMdp() == unMdp) {
            cout << "Connexion réussie" << endl;
            return i.second;
        }
    }
    pro.SetId(-1);
    cout << "Email ou mot de passe incorrect" << endl; 
    return pro;
}

Administrateur System::SeConnecterAdmin(string unEmail, string unMdp) {
    Administrateur admin;
    for(auto& i : this->listeAdmin) {
        if (i.second.GetEmail() == unEmail && i.second.GetMdp() == unMdp) {
            cout << "Connexion réussie" << endl;
            return i.second;
        }
    }
    admin.SetId(-1);
    cout << "Email ou mot de passe incorrect" << endl; 
    return admin;
}

list<Measurements> System::getListeMesure(int sensorId_in)
{
    list<Measurements> uneListe = this->listeMesures.at(sensorId_in);
    return uneListe;
} //----- Fin getListeMesure

list<Sensor> System::GetListeCapteurs_zone(Zone &zoneGeo)
{
    list<Sensor> sensorDeLaZone;
    for (auto &i : this->listeCapteurs)
    {
        float distance = getDistanceFromLatLonInKm(zoneGeo.getLatitude(), zoneGeo.getLongitude(), i.second.GetLatitude(), i.second.GetLongitude());
        if (distance <= zoneGeo.getRayon())
        {
            sensorDeLaZone.push_back(i.second);
        }
    }
    return sensorDeLaZone;
} //----- Fin de GetListeCapteur_zone

list<pair<string, double>> System::CalculerQualiteAir_zone(Zone &zoneGeo, string periode)
{
    // string : typeMesure (O3, PM10 ...), double : mesure
    list<pair<string, double>> qualite;
    list<Sensor> sensorsDeLaZone = GetListeCapteurs_zone(zoneGeo);
    cout << sensorsDeLaZone.size() << " capteurs sont dans cette zone" << endl;
    list<Measurements> mesuresDeLaZone;
    for (auto &i : sensorsDeLaZone)
    {
        for (auto &j : this->listeMesures.at(i.GetId()))
        {
            mesuresDeLaZone.push_back(j);
        }
    }
    double qualiteO3 = CalculerQualiteAir(mesuresDeLaZone, periode, "O3");
    qualite.push_back(pair<string, double>("O3", qualiteO3));
    double qualiteNO2 = CalculerQualiteAir(mesuresDeLaZone, periode, "NO2");
    qualite.push_back(pair<string, double>("NO2", qualiteNO2));
    double qualiteSO2 = CalculerQualiteAir(mesuresDeLaZone, periode, "SO2");
    qualite.push_back(pair<string, double>("SO2", qualiteSO2));
    double qualitePM10 = CalculerQualiteAir(mesuresDeLaZone, periode, "PM10");
    qualite.push_back(pair<string, double>("PM10", qualitePM10));

    cout << "Attribut |" << " Mesure" << endl;
    for (auto& i:qualite) {
        cout << i.first << "   " << i.second << endl;
    }
    
    return qualite;
} //----- Fin de CalculerQualiteAir_zone

double System::CalculerQualiteAir(list<Measurements> & listeMesures, string periode, string typeMesure)
{
    double quality = 0.0;
    list<Measurements> listeMesuresPeriode;
    for (auto &i : listeMesures)
    {
        // recuperer la listeMesure par periode
        size_t pos1 = periode.find("to");
        string tempsDeb = periode.substr(0, pos1);
        string tempsFin = periode.substr(pos1 + 2);
        if (tempsDeb <= i.getInstant() && i.getInstant() <= tempsFin)
        {
            listeMesuresPeriode.push_back(i);
        }
    }
    int j = 0;
    for (auto &i : listeMesuresPeriode)
    {
        if (i.getTypeMesure() == typeMesure)
        {
            quality += i.getMesure();
            ++j;
        }
    }
    quality /= j;
    return quality;
} //----- Fin de CalculerQualiteAir

multimap<double, int> System::ClassifierCapteurs(int idCapteurRef, string periode, string typeMesure)
{   
    // double : similitude, int : idCapteur (idSensor)
    multimap<double, int> listeQualiteCapteur;
    try {
        Sensor unSensor = this->listeCapteurs_exclu.at(idCapteurRef);
        cout << "Capteur id " << idCapteurRef << " a été exclu." << endl;
        return listeQualiteCapteur;
    } catch (const std::out_of_range & oor) {

    }
    if (periode == "-1")
        periode = "2019-01-01 12:00:00to2019-02-02 12:00:00";
    
    list<Measurements> listeMesuresRef = this->listeMesures[idCapteurRef];
    double qualiteRef = CalculerQualiteAir(listeMesuresRef, periode, typeMesure);
    for (auto &i : this->listeCapteurs)
    {
        list<Measurements> listeMesuresParCapteur = this->listeMesures.at(i.first);
        double similitude = abs(CalculerQualiteAir(listeMesuresParCapteur, periode, typeMesure) - qualiteRef);
        listeQualiteCapteur.insert(pair<double, int>(similitude, i.first));
    }
    cout << "IdCap   |   " << "similitude" << endl;
    for(auto& i:listeQualiteCapteur) {
        cout << i.second << "        " << i.first << endl;
    }
    return listeQualiteCapteur;
} //----- Fin de ClassifierCapteurs

map<int, list<int>> System::getListeSensorsIndividualUsers() {
    // User 1 <--> n Sensors
    ifstream fChargement;
    fChargement.open("dataset/users.csv");
    string line;
    int idIndividualUser;
    int idSensor;
    size_t sz;
    string str = "User";
    string str2 = "Sensor";
    map<int, list<int>> mapSensors;
    
    while (!fChargement.eof())
    {
        getline(fChargement, line);
        if (line.length() == 0) break;
        size_t pos1 = line.find(";");
        idIndividualUser =  stoi(line.substr(str.length(), pos1 - str.length()), &sz);
        idSensor =  stoi(line.substr(pos1 +str2.length()+1, line.length()-(pos1 +str2.length()+1)));
        try {
            list<int> listeSensor = mapSensors.at(idIndividualUser);
            listeSensor.push_back(idSensor);
            mapSensors[idIndividualUser] = listeSensor;
        } catch (const std::out_of_range& oor) {
            list<int> listeSensors;
            listeSensors.push_back(idSensor);
            mapSensors.insert(pair<int, list<int>>(idIndividualUser, listeSensors));
        }
    } 
    fChargement.close();
    return mapSensors;
} //----- Fin de getListeSensorsIndividualUsers

list<Sensor> System::getListeSensorsIndividualUser(int idIndividualUser_check) {
    list<Sensor> listeSensors;
    list<int> liste = this->getListeSensorsIndividualUsers().at(idIndividualUser_check);
    for (int& i : liste) {
        try {
            Sensor sensor = this->listeCapteurs.at(i);
            listeSensors.push_back(sensor);
        } catch (const std::out_of_range& oor) {
            Sensor sensor = this->listeCapteurs_exclu.at(i);
            listeSensors.push_back(sensor);
        }
    }
    return listeSensors;
} //----- Fin de getListeSensorsIndividualUsers

void System::ConsulterScore(IndividualUser & particulierConnecte) {
    cout << "--> Votre score est : "<< particulierConnecte.consulterScore() << endl;
}

void System::ConsulterDonneesCapteur(IndividualUser &particulierConnecte, int idCapteur) {
    Sensor capt = particulierConnecte.ConsulterDonneesCapteur(idCapteur);
    if (capt.GetId()!=-1 && capt.GetLatitude()!=0.0 && capt.GetLongitude()!=0.0){
        cout << "--> "<< capt << endl;
    } else if (capt.GetId()==-1 && capt.GetLatitude()==0.0 && capt.GetLongitude()==0.0){
        cout << "--> Vous n'avez pas un capteur d'id " << idCapteur << "." << endl;
    }
}

list<Cleaner> System::GetListePurificateurByProvider(int idProvider) {
    ifstream fic("dataset/providers.csv");
    list<Cleaner> list;
 
    while (!fic.eof()) {
        string line;
        getline(fic, line);
        if (line.length() == 0) break;
        string str = "Provider";
        size_t pos1 = line.find(";");
        int idProvider_t = stoi(line.substr(str.length(), pos1-str.length()));
            
        if (idProvider == idProvider_t) {
            str = "Cleaner";
            size_t pos2 = line.find(";", pos1+1);
            int idCleaner = stoi(line.substr(pos1+str.length()+1, pos2-pos1-str.length()));
            list.push_back(this->listeCleaners.at(idCleaner));
        }
    }
    fic.close();
    return list;
}

void System::ConsulterDonneesPurificateur(Provider &fournisseurConnecte, int idPurificateur) {
    Cleaner cln = fournisseurConnecte.ConsulterDonneesPurificateur(idPurificateur);
    if (cln.GetId()!=-1 && cln.GetLatitude()!=0.0 && cln.GetLongitude()!=0.0){
        cout << "--> "<< cln << endl;
    } else if (cln.GetId()==-1 && cln.GetLatitude()==0.0 && cln.GetLongitude()==0.0){
        cout << "--> Vous n'avez pas un purificateur d'id " << idPurificateur << endl;
    }
} 

bool System::VerifierFiabiliteCapteur(Administrateur & admin, int idSensorToCheck, double precision) {
    string periode = "2019-01-01 12:00:00to2019-12-31 12:00:00";
    bool capteurDeParticulier = false;
    map<int, list<int>> sensorsIndividualUsers = this->getListeSensorsIndividualUsers();
    for (auto &i : sensorsIndividualUsers) {
        list<int> listeSensors = i.second;
        for (auto & j : listeSensors) {
            if (idSensorToCheck == j) {
                capteurDeParticulier = true;
                break;
            }
        }
        if (capteurDeParticulier) break;
    }

    if (capteurDeParticulier)
    {

        Sensor capteurChoisi = this->listeCapteurs.at(idSensorToCheck);

        // Récupération mesures du capteur
        Zone zone = Zone(capteurChoisi.GetLatitude(), capteurChoisi.GetLongitude(), 50);
        list<Measurements> listeMesuresAVerifier = this->getListeMesure(capteurChoisi.GetId());

        // Récupération des mesures des autres capteurs

        list<Sensor> sensorDeLaZone = this->GetListeCapteurs_zone(zone);
        list<Measurements> listeMesuresReference;

        for (auto &it1 : sensorDeLaZone)
        {
            if (it1.GetId() != capteurChoisi.GetId())
            {
                for (auto &it2 : this->getListeMesure(it1.GetId()))
                {
                    listeMesuresReference.push_back(it2);
                }
            }
        }

        // Calcule qualité air (dans un but de performance toutes les qualités de sont pas calculées d'office)
        double qualiteO3 = this->CalculerQualiteAir(listeMesuresAVerifier, periode, "O3");
        double qualiteO3Ref = this->CalculerQualiteAir(listeMesuresReference, periode, "O3");

        cout << "--> Qualité O3 du capteur choisi : " << qualiteO3 << endl;
        cout << "--> Qualité O3 des autres capteurs : " << qualiteO3Ref << endl;

        if ((abs(qualiteO3 - qualiteO3Ref) / qualiteO3Ref) <= precision)
        {
            cout << "--> 03 PASSED" << endl;
            double qualiteNO2 = this->CalculerQualiteAir(listeMesuresAVerifier, periode, "NO2");
            double qualiteNO2Ref = this->CalculerQualiteAir(listeMesuresReference, periode, "NO2");

            cout << "--> Qualité NO2 du capteur choisi : " << qualiteNO2 << endl;
            cout << "--> Qualité NO2 des autres capteurs : " << qualiteNO2Ref << endl;

            if ((abs(qualiteNO2 - qualiteNO2Ref) / qualiteNO2Ref) <= precision)
            {
                cout << "--> NO2 PASSED" << endl;
                double qualiteSO2 = this->CalculerQualiteAir(listeMesuresAVerifier, periode, "SO2");
                double qualiteSO2Ref = this->CalculerQualiteAir(listeMesuresReference, periode, "SO2");

                cout << "--> Qualité SO2 du capteur choisi : " << qualiteSO2 << endl;
                cout << "--> Qualité SO2 des autres capteurs : " << qualiteSO2Ref << endl;

                if ((abs(qualiteSO2 - qualiteSO2Ref) / qualiteSO2Ref) <= precision)
                {
                    cout << "--> SO2 PASSED" << endl;
                    double qualitePM10 = this->CalculerQualiteAir(listeMesuresAVerifier, periode, "PM10");
                    double qualitePM10Ref = this->CalculerQualiteAir(listeMesuresReference, periode, "PM10");

                    cout << "--> Qualité PM10 du capteur choisi : " << qualitePM10 << endl;
                    cout << "--> Qualité PM10 des autres capteurs : " << qualitePM10Ref << endl;

                    if ((abs(qualitePM10 - qualitePM10Ref) / qualitePM10Ref) <= precision)
                    {
                        cout << "--> PM10 PASSED" << endl;
                        cout << "--> Le capteur est fiable" << endl;
                        cout << "--> D'après un intervalle de confiance de " << precision * 100 << "%" << endl;
                        return true;
                    }
                }
            }
        }
        
        // Exclure ce capteur et ses measurements
        Sensor sensorExclu = this->listeCapteurs.at(idSensorToCheck);
        map<int, Sensor>::iterator it = this->listeCapteurs.find(sensorExclu.GetId());
        this->listeCapteurs.erase(it);
        this->listeCapteurs_exclu.insert(pair<int, Sensor>(sensorExclu.GetId(), sensorExclu));
        map<int, list<Measurements>>::iterator it1 = this->listeMesures.find(sensorExclu.GetId());
        this->listeMesures.erase(it1);
        ///////////////////////////////////////////////
        cout << "--> A exclure : mesures incompatibles avec celles de capteur reference" << endl;
        cout << "--> D'après un intervalle de confiance de " << precision * 100 << "%" << endl;
        return false;
    } else {
        cout << "--> Ce n'est pas un capteur de particulier ou il a été exclu." << endl;
        return false;
    }
} //----- Fin de VerifierFiabiliteCapteur


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

System::System(const System &unMeasurements)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <System>" << endl;
#endif
} //----- Fin de System (constructeur de copie)

System::System()
{
    size_t sz;
    ifstream fic;
    ifstream fic1;
    string line;
    string line1;
    // -------------Initialisation de la ListeCapteurs ----------------------
    fic.open("dataset/sensors.csv");
    fic1.open("dataset/measurements.csv");
    while (!fic.eof())
    {
        getline(fic, line);
        if (line.length() == 0) break;
        string str = "Sensor";
        size_t pos1 = line.find(";");
        int idSensor = stoi(line.substr(str.length(), pos1 - str.length()), &sz);
        size_t pos2 = line.find_first_of(";", pos1 + 1);
        double lat = stod(line.substr(pos1 + 1, pos2 - pos1 - 1), &sz);
        double lon = stod(line.substr(pos2 + 1), &sz);
        Sensor unSensor(idSensor, lat, lon);
        this->listeCapteurs.insert(pair<int, Sensor>(idSensor, unSensor));

        list<Measurements> uneListeMesures;
        uneListeMesures.clear();
        while (!fic1.eof())
        {
            getline(fic1, line1);
            if (line1.length() == 0) break;
            size_t pos11 = line1.find(";");
            size_t pos12 = line1.find(";", pos11 + 1);
            size_t pos13 = line1.find(";", pos12 + 1);
            int idSensor1 = 200;
            if (pos11 != string::npos && pos12 != string::npos && pos13 != string::npos)
                idSensor1 = stoi(line1.substr(pos11 + 7, pos12 - pos11 - 7), &sz);
            if (idSensor1 != idSensor)
                break;

            string instant = line1.substr(0, pos11);
            double mesure = stod(line1.substr(pos13 + 1), &sz);
            string attribut = line1.substr(pos12 + 1, pos13 - pos12 - 1);
            Measurements uneMesure(instant, attribut, mesure);
            uneListeMesures.push_back(uneMesure);
        }
        this->listeMesures.insert(pair<int, list<Measurements>>(idSensor, uneListeMesures));
    }

    User u;
    this->listeUsers.insert(pair<int, User>(u.GetId(), u));
    fic1.close();
    fic.close();

    ifstream fic2("dataset/cleaners.csv");
    while( !fic2.eof() ) {
        string line;
        getline(fic2, line);
        if (line == "") break;
        string str = "Cleaner";
        size_t pos1 = line.find(";");
        int idCleaner = stoi(line.substr(str.length(), pos1-str.length()));
        size_t pos2 = line.find(";", pos1+1);
        double lat = stod(line.substr(pos1+1, pos2-pos1));
        size_t pos3 = line.find(";", pos2+1);
        double longi = stod(line.substr(pos2+1, pos3-pos2));
        size_t pos4 = line.find(";", pos3+1);
        string debut = line.substr(pos3+1, pos4-pos3-1);
        size_t pos5 = line.find(";", pos4+1);
        string fin = line.substr(pos4+1, pos5-1-pos4);
        Cleaner unCleaner(idCleaner, lat, longi, debut, fin);
        this->listeCleaners.insert(pair<int, Cleaner>(idCleaner, unCleaner));
    }
    fic2.close();
    this->read_file_login();
} //----- Fin de System

System::~System()
{
    this->listeCapteurs.clear();
    this->listeCapteurs_exclu.clear();
    this->listeMesures.clear();
    this->listeUsers.clear();
    this->listeIUser.clear();
    this->listeProvider.clear();
    this->listeAdmin.clear();
    this->listeCleaners.clear();
} //----- Fin de ~System

#endif // System_H