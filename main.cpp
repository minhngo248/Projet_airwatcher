#include <iostream>
using namespace std;

#include "service/System.h"
#include "modele/Administrateur.h"
#include "modele/Provider.h"
#include "modele/IndividualUser.h"

void testerCreerCompte(int ID, string unNom, string unPrenom, string unEmail, string unMdp, int type){
    // type =1 pour un particulier, type =2 pour un fournisseur
    if (type == 1) {
        IndividualUser iUser;
        iUser.CreerCompte(ID,unNom,unPrenom,unEmail,unMdp);
    }
    if (type == 2) {
        Provider provider;
        provider.CreerCompte(ID,unNom,unPrenom,unEmail,unMdp);
    }
}

IndividualUser testerSeConnecterParticulier(string unEmail, string unMdp){
    IndividualUser iUser;
    bool rst = iUser.seConnecter(unEmail,unMdp);
    if (rst == true) {
        cout << "Connexion OK !" <<endl;
    } else {
        cout << "Email ou mot de passe incorrect !" <<endl;
    }
    return iUser;
}

Provider testerSeConnecterFournisseur(string unEmail, string unMdp){
    Provider pUser;
    bool rst = pUser.seConnecter(unEmail,unMdp);
    if (rst == true) {
        cout << "Connexion OK !" <<endl;
    } else {
        cout << "Email ou mot de passe incorrect !" <<endl;
    }
    return pUser;
}

void testerConsulterScore (IndividualUser &particulierConnecte) {
    cout << "--> Votre score est : "<<particulierConnecte.consulterScore() << endl;
}

void testerConsulterDonneesCapteur(IndividualUser &particulierConnecte, int idCapteur) {
    Sensor capt = particulierConnecte.ConsulterDonneesCapteur(idCapteur);
    if (capt.GetId()!=-1 && capt.GetLatitude()!=0.0 && capt.GetLongitude()!=0.0){
        cout << "--> "<< capt << endl;
    } else if (capt.GetId()==-1 && capt.GetLatitude()==0.0 && capt.GetLongitude()==0.0){
        cout << "--> Vous n'avez pas un capteur d'id " << idCapteur << endl;
    }
}

void testerConsulterDonneesPurificateur(Provider &fournisseurConnecte, int idPurificateur) {
    Cleaner cln = fournisseurConnecte.ConsulterDonneesPurificateur(idPurificateur);
    if (cln.GetId()!=-1 && cln.GetLatitude()!=0.0 && cln.GetLongitude()!=0.0){
        cout << "--> "<< cln << endl;
    } else if (cln.GetId()==-1 && cln.GetLatitude()==0.0 && cln.GetLongitude()==0.0){
        cout << "--> Vous n'avez pas un purificateur d'id " << idPurificateur << endl;
    }
}

void testerVerifierFiabiliteCapteur(int idCapteur, double precision) {
    Administrateur admin;
    admin.verifierFiabiliteCapteur(idCapteur,precision);
}

void testerClassifierCapteurs(int idCapteurRef, string periode,string typeMesure) {
    System system;
    multimap<double, int> listeCroissante = system.ClassifierCapteurs(2, periode, typeMesure);
    cout << "IdCap   |   " << "similitude" << endl;
    for(auto& i:listeCroissante) {
        cout << i.second << "   " << i.first << endl;
    }
    listeCroissante.clear();
}

void testerCalculerQualiteAir_zone(double unLat, double unLong, double unRayon) {
    Zone uneZone(unLat, unLong, unRayon);
    System system;
    list<pair<string, double>> qualite = system.CalculerQualiteAir_zone(uneZone);
    cout << "Attribut |" << " Mesure" << endl;
    for (auto& i:qualite) {
        cout << i.first << "   " << i.second << endl;
    }
    qualite.clear();
}

int main(int argc, char* argv[]) {

    char lecture[100];
    char lecture1[100];
    char lecture2[100];
    char lecture3[100];
    char lecture4[100];
    int lecture5;
    double lecture6; 
    double lecture7;
    double lecture8;

    cout << "\n----------------- Menu principal : Je suis un : --------------" <<endl;
    cout << "       1 : Particulier" <<endl;
    cout << "       2 : Fournisseur" <<endl;
    cout << "       3 : Admin" <<endl;
    cout << "       4 : Utilisateur" <<endl;
    cout << "       5 : Quitter     " <<endl;

    cout << "Saisir un chiffre entre 1 et 5 : ";
    fscanf(stdin,"%99s",lecture);


    while (strcmp(lecture,"5")!=0) 
    {
        if (strcmp(lecture,"1")==0) 
        {
            cout << "\n----------------- Menu (1) Particulier : --------------" <<endl;
            cout << "       1 : Creer un compte" <<endl;
            cout << "       2 : Se connecter" <<endl;
            cout << "       3 : Revenir à au menu principal " <<endl;
            cout << "Saisir un chiffre entre 1 et 3 : ";
            fscanf(stdin,"%99s",lecture);

            while (strcmp(lecture,"3")!=0) {
                if (strcmp(lecture,"1")==0) {
                    cout << "\n----------------- Compléter votre compte : --------------"<<endl ;
                    cout << "\t\tEntrez votre id : " ;
                    fscanf(stdin,"%d",&lecture5);
                    cout << "\t\tEntrez votre nom : " ;
                    fscanf(stdin,"%99s",lecture1);
                    cout << "\t\tEntrez votre prénom : " ;
                    fscanf(stdin,"%99s",lecture2);
                    cout << "\t\tEntrez votre email : " ;
                    fscanf(stdin,"%99s",lecture3);
                    cout << "\t\tEntrez votre mot de passe : " ;
                    fscanf(stdin,"%99s",lecture4);
                    testerCreerCompte(lecture5,lecture1,lecture2,lecture3,lecture4, 1); 
                } else if (strcmp(lecture,"2")==0) {
                    cout << "\n----------------- Connexion : -------------- "<<endl ;
                    cout << "\t\tEntrez votre email : " ;
                    fscanf(stdin,"%99s",lecture1);
                    cout << "\t\tEntrez votre mot de passe : " ;
                    fscanf(stdin,"%99s",lecture2);
                    IndividualUser particulierConnecte = testerSeConnecterParticulier(lecture1,lecture2);
                    if (particulierConnecte.GetSizeListeCapteurs() != 0) {
                        
                        cout << "\n----------------- Menu (2) Particulier : --------------" <<endl;
                        cout << "       1 : Consulter mon score" <<endl;
                        cout << "       2 : Consulter les données d'un capteur" <<endl;
                        cout << "       3 : Se déconnecter " <<endl;
                        cout << "Saisir un chiffre entre 1 et 3 : ";
                        fscanf(stdin,"%99s",lecture);

                        while (strcmp(lecture,"3")!=0) {
                            if (strcmp(lecture,"1")==0) {
                                testerConsulterScore(particulierConnecte);
                            } else if (strcmp(lecture,"2")==0) {
                                cout << "\t\tEntrez l'id du capteur : " ;
                                fscanf(stdin,"%d",&lecture5);
                                testerConsulterDonneesCapteur(particulierConnecte, lecture5);
                            }
                            cout << "----------------- Menu (2) Particulier : --------------" <<endl;
                            cout << "       1 : Consulter mon score" <<endl;
                            cout << "       2 : Consulter les données d'un capteur" <<endl;
                            cout << "       3 : Se déconnecter " <<endl;
                            cout << "Saisir un chiffre entre 1 et 3 : ";
                            fscanf(stdin,"%99s",lecture);
                        }
                    }
                }
                cout << "\n----------------- Menu (1) Particulier : --------------" <<endl;
                cout << "       1 : Creer un compte" <<endl;
                cout << "       2 : Se connecter" <<endl;
                cout << "       3 : Revenir à au menu principal " <<endl;
                cout << "Saisir un chiffre entre 1 et 3 : ";
                fscanf(stdin,"%99s",lecture);
            }
        } else if (strcmp(lecture,"2")==0) 
        {
            cout << "\n----------------- Menu (1) Fournisseur : --------------" <<endl;
            cout << "       1 : Creer un compte" <<endl;
            cout << "       2 : Se connecter" <<endl;
            cout << "       3 : Revenir à au menu principal " <<endl;
            cout << "Saisir un chiffre entre 1 et 3 : ";
            fscanf(stdin,"%99s",lecture);

            while (strcmp(lecture,"3")!=0) {
                if (strcmp(lecture,"1")==0) {
                    cout << "\n----------------- Compléter votre compte : --------------"<<endl ;
                    cout << "\t\tEntrez votre id : " ;
                    fscanf(stdin,"%d",&lecture5);
                    cout << "\t\tEntrez votre nom : " ;
                    fscanf(stdin,"%99s",lecture1);
                    cout << "\t\tEntrez votre prénom : " ;
                    fscanf(stdin,"%99s",lecture2);
                    cout << "\t\tEntrez votre email : " ;
                    fscanf(stdin,"%99s",lecture3);
                    cout << "\t\tEntrez votre mot de passe : " ;
                    fscanf(stdin,"%99s",lecture4);
                    testerCreerCompte(lecture5,lecture1,lecture2,lecture3,lecture4, 2); 
                } else if (strcmp(lecture,"2")==0) {
                    cout << "\n----------------- Connexion : -------------- "<<endl ;
                    cout << "\t\tEntrez votre email : " ;
                    fscanf(stdin,"%99s",lecture1);
                    cout << "\t\tEntrez votre mot de passe : " ;
                    fscanf(stdin,"%99s",lecture2);
                    Provider fournisseurConnecte = testerSeConnecterFournisseur(lecture1,lecture2);
                    if (fournisseurConnecte.GetSizeListePurificateurs() != 0) {
                        
                        cout << "\n----------------- Menu (2) Fournisseur : --------------" <<endl;
                        cout << "       1 : Consulter les données d'un purificateur" <<endl;
                        cout << "       2 : Se déconnecter " <<endl;
                        cout << "Saisir un chiffre : ";
                        fscanf(stdin,"%99s",lecture);

                        while (strcmp(lecture,"2")!=0) {
                            if (strcmp(lecture,"1")==0) {
                                cout << "\t\tEntrez l'id du purificateur : " ;
                                fscanf(stdin,"%d",&lecture5);
                                testerConsulterDonneesPurificateur(fournisseurConnecte, lecture5);
                            }
                            cout << "\n----------------- Menu (2) Fournisseur : --------------" <<endl;
                            cout << "       1 : Consulter les données d'un purificateur" <<endl;
                            cout << "       2 : Se déconnecter " <<endl;
                            cout << "Saisir un chiffre : ";
                            fscanf(stdin,"%99s",lecture);
                        }
                    }
                }
                cout << "\n----------------- Menu (1) Fournisseur : --------------" <<endl;
                cout << "       1 : Creer un compte" <<endl;
                cout << "       2 : Se connecter" <<endl;
                cout << "       3 : Revenir à au menu principal " <<endl;
                cout << "Saisir un chiffre entre 1 et 3 : ";
                fscanf(stdin,"%99s",lecture);
            }
        } else if (strcmp(lecture,"3")==0) 
        {
            cout << "\n----------------- Menu Admin: --------------" <<endl;
            cout << "       1 : Vérifier la fiabilité d'un capteur" <<endl;
            cout << "       2 : Revenir au menu principal " <<endl;
            cout << "Saisir un chiffre : ";
            fscanf(stdin,"%99s",lecture);

            while (strcmp(lecture,"2")!=0) {
                if (strcmp(lecture,"1")==0) {
                    cout << "\t\tEntrez l'id du capteur : " ;
                    fscanf(stdin,"%d",&lecture5);
                    cout << "\t\tEntrez la précision : " ;
                    fscanf(stdin,"%le",&lecture6);
                    testerVerifierFiabiliteCapteur(lecture5,lecture6);
                }
                cout << "\n----------------- Menu Admin: --------------" <<endl;
                cout << "       1 : Vérifier la fiabilité d'un capteur" <<endl;
                cout << "       2 : Revenir au menu principal " <<endl;
                cout << "Saisir un chiffre : ";
                fscanf(stdin,"%99s",lecture);
            }
        } else if (strcmp(lecture,"4")==0) 
        {
            cout << "\n----------------- Menu Utilisateur: --------------" <<endl;
            cout << "       1 : Calculer la qualité de l'air dans une zone géographique" <<endl;
            cout << "       2 : Classifier les capteurs " <<endl;
            cout << "       3 : Revenir à au menu principal " <<endl;

            cout << "Saisir un chiffre entre 1 et 4 : ";
            fscanf(stdin,"%99s",lecture);

            while (strcmp(lecture,"3")!=0) {
                if (strcmp(lecture,"1")==0) {
                    cout << "\t\tEntrez la latitude de la zone : " ;
                    fscanf(stdin,"%le",&lecture6);
                    cout << "\t\tEntrez la longitude de la zone : " ;
                    fscanf(stdin,"%le",&lecture6);
                    cout << "\t\tEntrez le rayon de la zone : " ;
                    fscanf(stdin,"%le",&lecture6);
                    testerCalculerQualiteAir_zone(lecture6,lecture7,lecture8);
                } else if (strcmp(lecture,"2")==0) {
                    cout << "\t\tEntrez l'id du capteur référence : " ;
                    fscanf(stdin,"%d",&lecture5);
                    cout << "\t\tEntrez une période en respactant le format '2019-01-01 12:00:00to2019-05-05 13:00:00' : " ;
                    fscanf(stdin,"%99s",lecture4);
                    cout << "\t\tChoisissez un type de mesure (O3, NO2, SO2, PM10) : " ;
                    fscanf(stdin,"%99s",lecture3);
                    testerClassifierCapteurs(lecture5, lecture4, lecture3);
                }
                cout << "\n----------------- Menu Utilisateur: --------------" <<endl;
                cout << "       1 : Calculer la qualité de l'air dans une zone géographique" <<endl;
                cout << "       2 : Classifier les capteurs " <<endl;
                cout << "       3 : Revenir à au menu principal " <<endl;

                cout << "Saisir un chiffre entre 1 et 4 : ";
                fscanf(stdin,"%99s",lecture);
            }
            
        }

        cout << "\n----------------- Menu principal : Je suis un : --------------" <<endl;
        cout << "       1 : Particulier" <<endl;
        cout << "       2 : Fournisseur" <<endl;
        cout << "       3 : Admin" <<endl;
        cout << "       4 : Utilisateur" <<endl;
        cout << "       5 : Quitter     " <<endl;

        cout << "Saisir un chiffre entre 1 et 5 : ";
        fscanf(stdin,"%99s",lecture);
    }
    return 0;
}

