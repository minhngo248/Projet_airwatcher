/*************************************************************************
                           IndividualUser  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <IndividualUser> (fichier IndividualUser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "IndividualUser.h"
#include "User.h"
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
User IndividualUser::creerCompte(int unUserID, string unNom, string unPrenom, string unEmail, string unMdp)
{
    User user;
    size_t sz;
    ifstream fic;
    string line;
    bool existe = false;
    
    fic.open("dataset/users.csv");

    while ( !fic.eof() ) {
        fic >> line;
        string str = "User";
        string str1 = "Sensor";
        size_t pos1 = line.find(";");
        int idUser = stoi(line.substr(str.length(), pos1-str.length()), &sz);
        int idSensor = stoi(line.substr(pos1+1+str1.length(), line.length()-(pos1+1+str1.length())), &sz);
        
        if (idUser == unUserID) {
            if (!existe) {
                userID = unUserID;
                score = 0;
                user = User(unNom, unPrenom, unEmail, unMdp);

                existe = true;
            }
            mesCapteurs.push_back(creerSensor(idSensor));
        }
    }
    fic.close();

    if (existe) {
        cout <<"Profil complet !"<< endl;
    } else {
        cout << "ce UserId n'existe pas !"<< endl;
    }
    return user;
}

int IndividualUser::consulterScore()
{
    return score;
}

void IndividualUser::setScore(int unScore){
    score = unScore;
}

Sensor IndividualUser::consulterDonneesCapteur(int idCapteur)
{
    list<Sensor>::iterator it;
    Sensor monCapteur ;

    for (it = mesCapteurs.begin(); it != mesCapteurs.end(); ++it) {
        if (it->GetSensorId() == idCapteur){
            monCapteur = *it;
        }
    }

    return monCapteur;
}

Sensor IndividualUser::creerSensor(int unSensorID){
    Sensor unSensor;
    size_t sz;
    ifstream fic;
    string line;
    double unLat;
    double unLong;
    
    fic.open("dataset/sensors.csv");

    while ( !fic.eof() ) {
        fic >> line;
        string str = "Sensor";
        size_t pos1 = line.find(";");
        int idSensor = stoi(line.substr(str.length(), pos1-str.length()), &sz);
        
        if (idSensor == unSensorID) {
            size_t pos2 = line.find_first_of(";", pos1+1);
            unLat = stod(line.substr(pos1+1, pos2-pos1-1), &sz);
            size_t pos3 = line.find_first_of(";", pos2+1);
            unLong = stod(line.substr(pos2+1, pos3-pos2-1), &sz);
            
            break;
        }
    }
    unSensor = Sensor(unSensorID , unLat, unLong);
    fic.close();
    return unSensor;
}

//------------------------------------------------- Surcharge d'opérateurs
 
ostream & operator << (ostream& out, const IndividualUser & unIndividualUser)
{
    out<<"UserID:User"<< unIndividualUser.userID;
    out<<",email:"<<unIndividualUser.email;
    out<<",motDePasse:"<<unIndividualUser.motDePasse;
    out<<",nom:"<<unIndividualUser.nom;
    out<<",prenom:"<<unIndividualUser.prenom;
    out<<",score:"<<unIndividualUser.score<<endl;
    return out;
}

//-------------------------------------------- Constructeurs - destructeur
IndividualUser::IndividualUser ( const IndividualUser & unIndividualUser )
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <IndividualUser>" << endl;
    #endif
} //----- Fin de IndividualUser (constructeur de copie)


IndividualUser::IndividualUser ()
{
#ifdef MAP
    cout << "Appel au constructeur de <IndividualUser>" << endl;
#endif
} //----- Fin de IndividualUser


IndividualUser::~IndividualUser ( )
{
    #ifdef MAP
        cout << "Appel au destructeur de <IndividualUser>" << endl;
    #endif
} //----- Fin de ~IndividualUser


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

