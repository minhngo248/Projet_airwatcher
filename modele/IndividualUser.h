/*************************************************************************
                           IndividualUser  -  description
                             -------------------
    début                : 04/05/2022
    copyright            : (C) 2022 par Ngoc Minh NGO, Laetitia BÉZIE, Nathan NOWAKOWSKI, Ghizlane BADAOUI, Henri BAILLEUX
    e-mail               : ngoc-minh.ngo@insa-lyon.fr, laetitia.bezie@insa-lyon.fr, nathan.nowakowski@insa-lyon.fr, ghizlane.badaoui@insa-lyon.fr, henri.bailleux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <IndividualUser> (fichier IndividualUser.h) ----------------
#if ! defined (IndividualUser_H)
#define IndividualUser_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include "User.h"
#include "Sensor.h"
#include <list>
#include <iostream>
#include <fstream>
#include "User.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <IndividualUser>
//
//
//------------------------------------------------------------------------

class IndividualUser : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques    
    bool seConnecter(string email_in, string mdp);
    User CreerCompte(int unUserID, string unNom, string unPrenom, string unEmail, string unMdp);
    int consulterScore();
    void setScore(int unScore);
    Sensor ConsulterDonneesCapteur(int idCapteur);
    Sensor CreerSensor(int unSensorID);
    int GetSizeListeCapteurs();

//------------------------------------------------- Surcharge d'opérateurs
    friend ostream & operator <<(ostream& out, const IndividualUser & unIndividualUser);

//-------------------------------------------- Constructeurs - destructeur
    IndividualUser ( const IndividualUser & unIndividualUser );

    IndividualUser ();

    virtual ~IndividualUser ( );
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int userID;
    int score;
    list <Sensor> mesCapteurs;

};



//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool IndividualUser::seConnecter(string email_in, string mdp)
{
    ifstream fChargement;
    char emailTmp[50];
    char idUserTmp[50];
    char mdpTmp[50];
    char typeUser[2];
    char tmp[50];
    char scoreTmp[50];

    fChargement.open("dataset/login.csv");
    if (fChargement)
    {

        while (!fChargement.eof())
        {
            fChargement.getline(typeUser, 200, ';');
            
            if (atoi(typeUser)==1) {
                fChargement.getline(idUserTmp, 200, ';');
                fChargement.getline(tmp, 200, ';'); //nom
                fChargement.getline(tmp, 200, ';'); //prenom
                fChargement.getline(emailTmp, 200, ';');
                
                if (emailTmp == email_in)
                {
                    fChargement.getline(mdpTmp, 200, ';');
                    if (mdpTmp == mdp)
                    {
                        fChargement.getline(scoreTmp, 200, ';');
                        score = atoi(scoreTmp);
                        userID = atoi(idUserTmp);

                        size_t sz;
                        ifstream fic;
                        string line;

                        fic.open("dataset/users.csv");

                        while (!fic.eof())
                        {
                            fic >> line;
                            string str = "User";
                            string str1 = "Sensor";
                            size_t pos1 = line.find(";");
                            int idUser = stoi(line.substr(str.length(), pos1 - str.length()), &sz);
                            int idSensor = stoi(line.substr(pos1 + 1 + str1.length(), line.length() - (pos1 + 1 + str1.length())), &sz);

                            if (idUser == userID)
                            {
                                mesCapteurs.push_back(CreerSensor(idSensor));
                            }
                        }
                        fic.close();
                        return true;
                    }
                } else {
                    fChargement.getline(emailTmp, 1000, '\n');
                }
            } else {
                fChargement.getline(emailTmp, 1000, '\n');
            }
            
        }
    }
    return false;
} //----- Fin de seConnecter


User IndividualUser::CreerCompte(int unUserID, string unNom, string unPrenom, string unEmail, string unMdp)
{
    User user;
    size_t sz;
    ifstream fic;
    string line;
    bool existe = false;

    fic.open("dataset/users.csv");

    while (!fic.eof())
    {
        fic >> line;
        string str = "User";
        string str1 = "Sensor";
        size_t pos1 = line.find(";");
        int idUser = stoi(line.substr(str.length(), pos1 - str.length()), &sz);
        //int idSensor = stoi(line.substr(pos1 + 1 + str1.length(), line.length() - (pos1 + 1 + str1.length())), &sz);

        if (idUser == unUserID)
        {
            if (!existe)
            {
                userID = unUserID;
                score = 0;
                user = User(1, unUserID, unNom, unPrenom, unEmail, unMdp);

                existe = true;
            }
            //mesCapteurs.push_back(CreerSensor(idSensor));
        }
    }
    fic.close();

    if (existe)
    {
        cout << "Profil complet !" << endl;
    }
    else
    {
        cout << "ce UserId n'existe pas !" << endl;
    }
    return user;
}

Sensor IndividualUser::ConsulterDonneesCapteur(int idCapteur)
{
    list<Sensor>::iterator it;
    Sensor monCapteur;

    for (it = mesCapteurs.begin(); it != mesCapteurs.end(); ++it)
    {   
        if (it->GetId() == idCapteur)
        {
            monCapteur = *it;
        }
    }

    return monCapteur;
}

Sensor IndividualUser::CreerSensor(int unSensorID)
{
    Sensor unSensor;
    size_t sz;
    ifstream fic;
    string line;
    double unLat;
    double unLong;

    fic.open("dataset/sensors.csv");

    while (!fic.eof())
    {
        fic >> line;
        string str = "Sensor";
        size_t pos1 = line.find(";");
        int idSensor = stoi(line.substr(str.length(), pos1 - str.length()), &sz);

        if (idSensor == unSensorID)
        {
            size_t pos2 = line.find_first_of(";", pos1 + 1);
            unLat = stod(line.substr(pos1 + 1, pos2 - pos1 - 1), &sz);
            size_t pos3 = line.find_first_of(";", pos2 + 1);
            unLong = stod(line.substr(pos2 + 1, pos3 - pos2 - 1), &sz);

            break;
        }
    }
    unSensor = Sensor(unSensorID, unLat, unLong);
    fic.close();
    return unSensor;
}

int IndividualUser::consulterScore()
{
    return score;
}

void IndividualUser::setScore(int unScore)
{
    score = unScore;
}

int IndividualUser::GetSizeListeCapteurs() {
    return mesCapteurs.size();
}

//------------------------------------------------- Surcharge d'opérateurs

ostream &operator<<(ostream &out, const IndividualUser &unIndividualUser)
{
    out << "UserID:User" << unIndividualUser.userID;
    out << ",email:" << unIndividualUser.email;
    out << ",motDePasse:" << unIndividualUser.motDePasse;
    out << ",nom:" << unIndividualUser.nom;
    out << ",prenom:" << unIndividualUser.prenom;
    out << ",score:" << unIndividualUser.score << endl;
    return out;
}

//-------------------------------------------- Constructeurs - destructeur
IndividualUser::IndividualUser(const IndividualUser &unIndividualUser)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <IndividualUser>" << endl;
#endif
} //----- Fin de IndividualUser (constructeur de copie)

IndividualUser::IndividualUser()
{
#ifdef MAP
    cout << "Appel au constructeur de <IndividualUser>" << endl;
#endif
} //----- Fin de IndividualUser

IndividualUser::~IndividualUser()
{
#ifdef MAP
    cout << "Appel au destructeur de <IndividualUser>" << endl;
#endif
} //----- Fin de ~IndividualUser

#endif // IndividualUser_H