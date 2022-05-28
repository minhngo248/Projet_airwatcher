#include <iostream>
#include <limits>
#include <chrono>
using namespace std;

#include "service/System.h"
#include "modele/User.h"
#include "modele/Administrateur.h"
#include "modele/Provider.h"
#include "modele/IndividualUser.h"

int main(int argc, char *argv[])
{
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
            cout << "\n----------------- Menu (1) Particulier : --------------" << endl;
            cout << "       1 : Creer un compte" << endl;
            cout << "       2 : Se connecter" << endl;
            cout << "       3 : Revenir à au menu principal " << endl;
            cout << "Saisir un chiffre entre 1 et 3 : ";
            cin >> lecture;

            while (!(lecture == "3"))
            {
                if (lecture == "1")
                {
                    cout << "\n----------------- Compléter votre compte : --------------" << endl;
                    cout << "\t\tEntrez votre nom : ";
                    cin >> lecture1;
                    cout << "\t\tEntrez votre prénom : ";
                    cin >> lecture2;
                    cout << "\t\tEntrez votre email : ";
                    cin >> lecture3;
                    cout << "\t\tEntrez votre mot de passe : ";
                    cin >> lecture4;
                    system.CreerCompte(lecture1, lecture2, lecture3, lecture4, 1);
                }
                else if (lecture == "2")
                {
                    cout << "\n----------------- Connexion : -------------- " << endl;
                    cout << "\t\tEntrez votre email : ";
                    cin >> lecture1;
                    cout << "\t\tEntrez votre mot de passe : ";
                    cin >> lecture2;

                    auto start = std::chrono::high_resolution_clock::now();
                    IndividualUser particulierConnecte = system.SeConnecterIUser(lecture1, lecture2);
                    list<Sensor> listeSensor = system.getListeSensorsIndividualUser(particulierConnecte.GetId());
                    particulierConnecte.SetListeCapteurs(listeSensor);
                    auto finish = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed = finish - start;
                    cout << "Temps d'exécution: " << elapsed.count() << " s\n";

                    if (particulierConnecte.GetId() != -1)
                    {

                        cout << "\n----------------- Menu (2) Particulier : --------------" << endl;
                        cout << "       1 : Consulter mon score" << endl;
                        cout << "       2 : Consulter les données d'un capteur" << endl;
                        cout << "       3 : Calculer la qualité de l'air dans une zone géographique" << endl;
                        cout << "       4 : Classifier les capteurs " << endl;
                        cout << "       5 : Se déconnecter " << endl;
                        cout << "Saisir un chiffre entre 1 et 5 : ";
                        cin >> lecture;

                        while (!(lecture == "5"))
                        {
                            if (lecture == "1")
                            {
                                system.ConsulterScore(particulierConnecte);
                            }
                            else if (lecture == "2")
                            {
                                cout << "\t\tEntrez l'id du capteur : ";
                                cin >> lecture5;

                                auto start = std::chrono::high_resolution_clock::now();
                                system.ConsulterDonneesCapteur(particulierConnecte, lecture5);
                                auto finish = std::chrono::high_resolution_clock::now();
                                std::chrono::duration<double> elapsed = finish - start;
                                cout << "Temps d'exécution: " << elapsed.count() << " s\n";
                            }
                            else if (lecture == "3")
                            {
                                cout << "\t\tEntrez la latitude de la zone : ";
                                cin >> lecture6;
                                cout << "\t\tEntrez la longitude de la zone : ";
                                cin >> lecture7;
                                cout << "\t\tEntrez le rayon de la zone : ";
                                cin >> lecture8;
                                Zone uneZone(lecture6, lecture7, lecture8);

                                auto start = std::chrono::high_resolution_clock::now();
                                system.CalculerQualiteAir_zone(uneZone);
                                auto finish = std::chrono::high_resolution_clock::now();
                                std::chrono::duration<double> elapsed = finish - start;
                                cout << "Temps d'exécution: " << elapsed.count() << " s\n";
                            }
                            else if (lecture == "4")
                            {
                                cout << "\t\tEntrez l'id du capteur référence : ";
                                cin >> lecture5;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "\t\tEntrez une période en respactant le format '2019-01-01 12:00:00to2019-02-02 12:00:00'\n ";
                                cout << "\t\tRentrez '-1' si vous voulez prendre en compte toutes les données : ";
                                getline(cin, lecture4);
                                cout << "\t\tChoisissez un type de mesure (O3, NO2, SO2, PM10) : ";
                                cin >> lecture3;

                                auto start = std::chrono::high_resolution_clock::now();
                                system.ClassifierCapteurs(lecture5, lecture4, lecture3);
                                auto finish = std::chrono::high_resolution_clock::now();
                                std::chrono::duration<double> elapsed = finish - start;
                                cout << "Temps d'exécution: " << elapsed.count() << " s\n";
                            }
                            cout << "----------------- Menu (2) Particulier : --------------" << endl;
                            cout << "       1 : Consulter mon score" << endl;
                            cout << "       2 : Consulter les données de mon capteur" << endl;
                            cout << "       3 : Calculer la qualité de l'air dans une zone géographique" << endl;
                            cout << "       4 : Classifier les capteurs " << endl;
                            cout << "       5 : Se déconnecter " << endl;
                            cout << "Saisir un chiffre entre 1 et 5 : ";
                            cin >> lecture;
                        }
                    }
                }
                cout << "\n----------------- Menu (1) Particulier : --------------" << endl;
                cout << "       1 : Creer un compte" << endl;
                cout << "       2 : Se connecter" << endl;
                cout << "       3 : Revenir à au menu principal " << endl;
                cout << "Saisir un chiffre entre 1 et 3 : ";
                cin >> lecture;
            }
        }
        else if (lecture == "2")
        {

            cout << "\n----------------- Menu (1) Fournisseur : --------------" << endl;
            cout << "       1 : Creer un compte" << endl;
            cout << "       2 : Se connecter" << endl;
            cout << "       3 : Revenir à au menu principal " << endl;
            cout << "Saisir un chiffre entre 1 et 3 : ";
            cin >> lecture;

            while (!(lecture == "3"))
            {
                if (lecture == "1")
                {
                    cout << "\n----------------- Compléter votre compte : --------------" << endl;
                    cout << "\t\tEntrez votre nom : ";
                    cin >> lecture1;
                    cout << "\t\tEntrez votre prénom : ";
                    cin >> lecture2;
                    cout << "\t\tEntrez votre email : ";
                    cin >> lecture3;
                    cout << "\t\tEntrez votre mot de passe : ";
                    cin >> lecture4;
                    system.CreerCompte(lecture1, lecture2, lecture3, lecture4, 2);
                }
                else if (lecture == "2")
                {
                    cout << "\n----------------- Connexion : -------------- " << endl;
                    cout << "\t\tEntrez votre email : ";
                    cin >> lecture1;
                    cout << "\t\tEntrez votre mot de passe : ";
                    cin >> lecture2;
                    auto start = std::chrono::high_resolution_clock::now();
                    Provider fournisseurConnecte = system.SeConnecterProvider(lecture1, lecture2);
                    list<Cleaner> listCleaner = system.GetListePurificateurByProvider(fournisseurConnecte.GetId());
                    fournisseurConnecte.SetListePuri(listCleaner);
                    auto finish = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed = finish - start;
                    cout << "Temps d'exécution: " << elapsed.count() << " s\n";

                    if (fournisseurConnecte.GetId() != -1)
                    {
                        cout << "\n----------------- Menu (2) Fournisseur : --------------" << endl;
                        cout << "       1 : Consulter les données d'un purificateur" << endl;
                        cout << "       2 : Calculer la qualité de l'air dans une zone géographique" << endl;
                        cout << "       3 : Classifier les capteurs " << endl;
                        cout << "       4 : Se déconnecter " << endl;
                        cout << "Saisir un chiffre entre 1 et 4 : ";
                        cin >> lecture;

                        while (!(lecture == "4"))
                        {
                            if (lecture == "1")
                            {
                                cout << "\t\tEntrez l'id du purificateur : ";
                                cin >> lecture5;
                                system.ConsulterDonneesPurificateur(fournisseurConnecte, lecture5);
                            }
                            else if (lecture == "2")
                            {
                                cout << "\t\tEntrez la latitude de la zone : ";
                                cin >> lecture6;
                                cout << "\t\tEntrez la longitude de la zone : ";
                                cin >> lecture7;
                                cout << "\t\tEntrez le rayon de la zone : ";
                                cin >> lecture8;
                                Zone uneZone(lecture6, lecture7, lecture8);

                                auto start = std::chrono::high_resolution_clock::now();
                                system.CalculerQualiteAir_zone(uneZone);
                                auto finish = std::chrono::high_resolution_clock::now();
                                std::chrono::duration<double> elapsed = finish - start;
                                cout << "Temps d'exécution: " << elapsed.count() << " s\n";
                            }
                            else if (lecture == "3")
                            {
                                cout << "\t\tEntrez l'id du capteur référence : ";
                                cin >> lecture5;
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "\t\tEntrez une période en respactant le format '2019-01-01 12:00:00to2019-02-02 12:00:00'\n ";
                                cout << "\t\tRentrez '-1' si vous voulez prendre en compte toutes les données : ";
                                getline(cin, lecture4);
                                cout << "\t\tChoisissez un type de mesure (O3, NO2, SO2, PM10) : ";
                                cin >> lecture3;

                                auto start = std::chrono::high_resolution_clock::now();
                                system.ClassifierCapteurs(lecture5, lecture4, lecture3);
                                auto finish = std::chrono::high_resolution_clock::now();
                                std::chrono::duration<double> elapsed = finish - start;
                                cout << "Temps d'exécution: " << elapsed.count() << " s\n";
                            }
                            cout << "\n----------------- Menu (2) Fournisseur : --------------" << endl;
                            cout << "       1 : Consulter les données d'un purificateur" << endl;
                            cout << "       2 : Calculer la qualité de l'air dans une zone géographique" << endl;
                            cout << "       3 : Classifier les capteurs " << endl;
                            cout << "       4 : Se déconnecter " << endl;
                            cout << "Saisir un chiffre entre 1 et 4 : ";
                            cin >> lecture;
                        }
                    }
                }
                cout << "\n----------------- Menu (1) Fournisseur : --------------" << endl;
                cout << "       1 : Creer un compte" << endl;
                cout << "       2 : Se connecter" << endl;
                cout << "       3 : Revenir à au menu principal " << endl;
                cout << "Saisir un chiffre entre 1 et 3 : ";
                cin >> lecture;
            }
        }
        else if (lecture == "3")
        {
            Administrateur admin;
            cout << "\n----------------- Menu Admin: --------------" << endl;
            cout << "       1 : Vérifier la fiabilité d'un capteur" << endl;
            cout << "       2 : Calculer la qualité de l'air dans une zone géographique" << endl;
            cout << "       3 : Classifier les capteurs " << endl;
            cout << "       4 : Revenir au menu principal " << endl;
            cout << "Saisir un chiffre entre 1 et 4 : ";
            cin >> lecture;

            while (!(lecture == "4"))
            {
                if (lecture == "1")
                {
                    cout << "\t\tEntrez l'id du capteur : ";
                    cin >> lecture5;
                    cout << "\t\tEntrez la précision : ";
                    cin >> lecture6;
                    auto start = std::chrono::high_resolution_clock::now();
                    system.VerifierFiabiliteCapteur(admin, lecture5, lecture6);
                    auto finish = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed = finish - start;
                    cout << "Temps d'exécution: " << elapsed.count() << " s\n";
                }
                else if (lecture == "2")
                {
                    cout << "\t\tEntrez la latitude de la zone : ";
                    cin >> lecture6;
                    cout << "\t\tEntrez la longitude de la zone : ";
                    cin >> lecture7;
                    cout << "\t\tEntrez le rayon de la zone : ";
                    cin >> lecture8;
                    Zone uneZone(lecture6, lecture7, lecture8);

                    auto start = std::chrono::high_resolution_clock::now();
                    system.CalculerQualiteAir_zone(uneZone);
                    auto finish = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed = finish - start;
                    cout << "Temps d'exécution: " << elapsed.count() << " s\n";
                }
                else if (lecture == "3")
                {
                    cout << "\t\tEntrez l'id du capteur référence : ";
                    cin >> lecture5;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\t\tEntrez une période en respactant le format '2019-01-01 12:00:00to2019-02-02 12:00:00'\n ";
                    cout << "\t\tRentrez '-1' si vous voulez prendre en compte toutes les données : ";
                    getline(cin, lecture4);
                    cout << "\t\tChoisissez un type de mesure (O3, NO2, SO2, PM10) : ";
                    cin >> lecture3;

                    auto start = std::chrono::high_resolution_clock::now();
                    system.ClassifierCapteurs(lecture5, lecture4, lecture3);
                    auto finish = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed = finish - start;
                    cout << "Temps d'exécution: " << elapsed.count() << " s\n";
                }
                cout << "\n----------------- Menu Admin: --------------" << endl;
                cout << "       1 : Vérifier la fiabilité d'un capteur" << endl;
                cout << "       2 : Calculer la qualité de l'air dans une zone géographique" << endl;
                cout << "       3 : Classifier les capteurs " << endl;
                cout << "       4 : Revenir au menu principal " << endl;
                cout << "Saisir un chiffre entre 1 et 4 : ";
                cin >> lecture;
            }
        }
        else if (lecture == "4")
        {

            cout << "\n----------------- Menu Utilisateur: --------------" << endl;
            cout << "       1 : Calculer la qualité de l'air dans une zone géographique" << endl;
            cout << "       2 : Classifier les capteurs " << endl;
            cout << "       3 : Revenir à au menu principal " << endl;

            cout << "Saisir un chiffre entre 1 et 3 : ";
            cin >> lecture;

            while (!(lecture == "3"))
            {
                if (lecture == "1")
                {
                    cout << "\t\tEntrez la latitude de la zone : ";
                    cin >> lecture6;
                    cout << "\t\tEntrez la longitude de la zone : ";
                    cin >> lecture7;
                    cout << "\t\tEntrez le rayon de la zone : ";
                    cin >> lecture8;
                    Zone uneZone(lecture6, lecture7, lecture8);

                    auto start = std::chrono::high_resolution_clock::now();
                    system.CalculerQualiteAir_zone(uneZone);
                    auto finish = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed = finish - start;
                    cout << "Temps d'exécution: " << elapsed.count() << " s\n";
                }
                else if (lecture == "2")
                {
                    cout << "\t\tEntrez l'id du capteur référence : ";
                    cin >> lecture5;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\t\tEntrez une période en respactant le format '2019-01-01 12:00:00to2019-02-02 12:00:00'\n ";
                    cout << "\t\tRentrez '-1' si vous voulez prendre en compte toutes les données : ";
                    getline(cin, lecture4);
                    cout << "\t\tChoisissez un type de mesure (O3, NO2, SO2, PM10) : ";
                    cin >> lecture3;

                    auto start = std::chrono::high_resolution_clock::now();
                    system.ClassifierCapteurs(lecture5, lecture4, lecture3);
                    auto finish = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsed = finish - start;
                    cout << "Temps d'exécution: " << elapsed.count() << " s\n";
                }
                cout << "\n----------------- Menu Utilisateur: --------------" << endl;
                cout << "       1 : Calculer la qualité de l'air dans une zone géographique" << endl;
                cout << "       2 : Classifier les capteurs " << endl;
                cout << "       3 : Revenir à au menu principal " << endl;

                cout << "Saisir un chiffre entre 1 et 4 : ";
                cin >> lecture;
            }
        }
    } while (!(lecture == "5"));
    return 0;
}
