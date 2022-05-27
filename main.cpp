#include <iostream>
#include <limits>
using namespace std;

#include "service/System.h"
#include "modele/User.h"
#include "modele/Administrateur.h"
#include "modele/Provider.h"
#include "modele/IndividualUser.h"

int main(int argc, char* argv[]) {
    System system;
    string lecture;
    string lecture1;
    string lecture2;
    string lecture3;
    string lecture4;
    int lecture5;
    double lecture6; 
    double lecture7;
    double lecture8;
    
    do
    {    
        cout << "\n----------------- Menu principal : Je suis un : --------------" << endl;
        cout << "       1 : Particulier" << endl;
        cout << "       2 : Fournisseur" << endl;
        cout << "       3 : Admin" << endl;
        cout << "       4 : Utilisateur" << endl;
        cout << "       5 : Quitter     " << endl;

        cout << "Saisir un chiffre entre 1 et 5 : ";
        cin >> lecture;

        if (lecture == "1") 
        {
            cout << "\n----------------- Menu (1) Particulier : --------------" <<endl;
            cout << "       1 : Creer un compte" <<endl;
            cout << "       2 : Se connecter" <<endl;
            cout << "       3 : Revenir à au menu principal " <<endl;
            cout << "Saisir un chiffre entre 1 et 3 : ";
            cin >> lecture;

            while ( !(lecture == "3") ) {
                if (lecture == "1") {
                    cout << "\n----------------- Compléter votre compte : --------------"<<endl ;
                    cout << "\t\tEntrez votre nom : " ;
                    cin >> lecture1;
                    cout << "\t\tEntrez votre prénom : " ;
                    cin >> lecture2;
                    cout << "\t\tEntrez votre email : " ;
                    cin >> lecture3;
                    cout << "\t\tEntrez votre mot de passe : " ;
                    cin >> lecture4;
                    system.CreerCompte(lecture1, lecture2, lecture3, lecture4, 1); 
                } else if (lecture == "2") {
                    cout << "\n----------------- Connexion : -------------- "<<endl ;
                    cout << "\t\tEntrez votre email : " ;
                    cin >> lecture1;
                    cout << "\t\tEntrez votre mot de passe : " ;
                    cin >> lecture2;
                    IndividualUser particulierConnecte = system.SeConnecterIUser(lecture1, lecture2);
                    list<Sensor> listeSensor = system.getListeSensorsIndividualUser(particulierConnecte.GetId());
                    particulierConnecte.SetListeCapteurs(listeSensor);
                    if (particulierConnecte.GetSizeListeCapteurs() != 0) {
                        
                        cout << "\n----------------- Menu (2) Particulier : --------------" <<endl;
                        cout << "       1 : Consulter mon score" <<endl;
                        cout << "       2 : Consulter les données d'un capteur" <<endl;
                        cout << "       3 : Se déconnecter " <<endl;
                        cout << "Saisir un chiffre entre 1 et 3 : ";
                        cin >> lecture;

                        while ( !(lecture == "3") ) {
                            if (lecture == "1") {
                                system.ConsulterScore(particulierConnecte);
                            } else if (lecture == "2") {
                                cout << "\t\tEntrez l'id du capteur : " ;
                                cin >> lecture5;
                                system.ConsulterDonneesCapteur(particulierConnecte, lecture5);
                            }
                            cout << "----------------- Menu (2) Particulier : --------------" <<endl;
                            cout << "       1 : Consulter mon score" <<endl;
                            cout << "       2 : Consulter les données d'un capteur" <<endl;
                            cout << "       3 : Se déconnecter " <<endl;
                            cout << "Saisir un chiffre entre 1 et 3 : ";
                            cin >> lecture;
                        }
                    }
                }
                cout << "\n----------------- Menu (1) Particulier : --------------" <<endl;
                cout << "       1 : Creer un compte" <<endl;
                cout << "       2 : Se connecter" <<endl;
                cout << "       3 : Revenir à au menu principal " <<endl;
                cout << "Saisir un chiffre entre 1 et 3 : ";
                cin >> lecture;
            }
        } else if (lecture == "2") {

            cout << "\n----------------- Menu (1) Fournisseur : --------------" <<endl;
            cout << "       1 : Creer un compte" <<endl;
            cout << "       2 : Se connecter" <<endl;
            cout << "       3 : Revenir à au menu principal " <<endl;
            cout << "Saisir un chiffre entre 1 et 3 : ";
            cin >> lecture;

            while ( !(lecture == "3") ) {
                if (lecture == "1") {
                    cout << "\n----------------- Compléter votre compte : --------------"<<endl ;
                    cout << "\t\tEntrez votre nom : " ;
                    cin >> lecture1;
                    cout << "\t\tEntrez votre prénom : " ;
                    cin >> lecture2;
                    cout << "\t\tEntrez votre email : " ;
                    cin >> lecture3;
                    cout << "\t\tEntrez votre mot de passe : " ;
                    cin >> lecture4;
                    system.CreerCompte(lecture1, lecture2, lecture3, lecture4, 2); 
                } else if (lecture == "2") {
                    cout << "\n----------------- Connexion : -------------- "<<endl ;
                    cout << "\t\tEntrez votre email : " ;
                    cin >> lecture1;
                    cout << "\t\tEntrez votre mot de passe : " ;
                    cin >> lecture2;
                    Provider fournisseurConnecte = system.SeConnecterProvider(lecture1,lecture2);
                    list<Cleaner> listCleaner = system.GetListePurificateurByProvider(fournisseurConnecte.GetId());
                    fournisseurConnecte.SetListePuri(listCleaner);
                    if (fournisseurConnecte.GetSizeListePurificateurs() != 0) {
                        cout << "\n----------------- Menu (2) Fournisseur : --------------" <<endl;
                        cout << "       1 : Consulter les données d'un purificateur" <<endl;
                        cout << "       2 : Se déconnecter " <<endl;
                        cout << "Saisir un chiffre : ";
                        cin >> lecture;

                        while ( !(lecture == "2") ) {
                            if (lecture == "1") {
                                cout << "\t\tEntrez l'id du purificateur : " ;
                                cin >> lecture5;
                                system.ConsulterDonneesPurificateur(fournisseurConnecte, lecture5);
                            }
                            cout << "\n----------------- Menu (2) Fournisseur : --------------" <<endl;
                            cout << "       1 : Consulter les données d'un purificateur" <<endl;
                            cout << "       2 : Se déconnecter " <<endl;
                            cout << "Saisir un chiffre : ";
                            cin >> lecture;
                        }
                    }
                }
                cout << "\n----------------- Menu (1) Fournisseur : --------------" <<endl;
                cout << "       1 : Creer un compte" <<endl;
                cout << "       2 : Se connecter" <<endl;
                cout << "       3 : Revenir à au menu principal " <<endl;
                cout << "Saisir un chiffre entre 1 et 3 : ";
                cin >> lecture;
            }
        } else if (lecture == "3") {
            Administrateur admin;
            cout << "\n----------------- Menu Admin: --------------" <<endl;
            cout << "       1 : Vérifier la fiabilité d'un capteur" <<endl;
            cout << "       2 : Revenir au menu principal " <<endl;
            cout << "Saisir un chiffre : ";
            cin >> lecture;

            while ( !(lecture == "2") ) {
                if (lecture == "1") {
                    cout << "\t\tEntrez l'id du capteur : " ;
                    cin >> lecture5;
                    cout << "\t\tEntrez la précision : " ;
                    cin >> lecture6;
                    system.VerifierFiabiliteCapteur(admin, lecture5, lecture6);
                }
                cout << "\n----------------- Menu Admin: --------------" <<endl;
                cout << "       1 : Vérifier la fiabilité d'un capteur" <<endl;
                cout << "       2 : Revenir au menu principal " <<endl;
                cout << "Saisir un chiffre : ";
                cin >> lecture;
            }
        } else if (lecture == "4") {

            cout << "\n----------------- Menu Utilisateur: --------------" <<endl;
            cout << "       1 : Calculer la qualité de l'air dans une zone géographique" <<endl;
            cout << "       2 : Classifier les capteurs " <<endl;
            cout << "       3 : Revenir à au menu principal " <<endl;

            cout << "Saisir un chiffre entre 1 et 3 : ";
            cin >> lecture;

            while ( !(lecture == "3") ) {
                if (lecture == "1") {
                    cout << "\t\tEntrez la latitude de la zone : " ;
                    cin >> lecture6;
                    cout << "\t\tEntrez la longitude de la zone : " ;
                    cin >> lecture7;
                    cout << "\t\tEntrez le rayon de la zone : " ;
                    cin >> lecture8;
                    Zone uneZone(lecture6, lecture7, lecture8);
                    system.CalculerQualiteAir_zone(uneZone);
                } else if (lecture == "2") {
                    cout << "\t\tEntrez l'id du capteur référence : " ;
                    cin >> lecture5;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "\t\tEntrez une période en respactant le format '2019-01-01 12:00:00to2019-02-02 12:00:00' : " ;
                    getline(cin, lecture4);
                    cout << "\t\tChoisissez un type de mesure (O3, NO2, SO2, PM10) : " ;
                    cin >> lecture3;
                    system.ClassifierCapteurs(lecture5, lecture4, lecture3);
                }
                cout << "\n----------------- Menu Utilisateur: --------------" <<endl;
                cout << "       1 : Calculer la qualité de l'air dans une zone géographique" <<endl;
                cout << "       2 : Classifier les capteurs " <<endl;
                cout << "       3 : Revenir à au menu principal " <<endl;

                cout << "Saisir un chiffre entre 1 et 4 : ";
                cin >> lecture;
            } 
        }   
    } while ( !(lecture == "5") );
    return 0;
}

