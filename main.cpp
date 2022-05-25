#include <iostream>
#include <chrono>
#include <ctime>
#include <assert.h>
using namespace std;

#include "service/System.h"
#include "modele/Administrateur.h"
#include "modele/Provider.h"

// Chrono
chrono::time_point<std::chrono::system_clock> start, fin;

void testerClassifierCapteurs()
{
    System system;
    string periode = "2019-01-01 12:00:00to2019-05-05 13:00:00";

    // respecter le format de saisie la periode
    multimap<double, int> listeCroissante = system.ClassifierCapteurs(2, periode, "PM10");
    cout << "IdCap   |   "
         << "similitude" << endl;
    for (auto &i : listeCroissante)
    {
        cout << i.second << "   " << i.first << endl;
    }
    listeCroissante.clear();
}

void testerCalculerQualiteAir_zone()
{
    Zone uneZone(44.4, 0.4, 100);
    // radius : 100 km
    System system;
    string periode = "2019-01-01 12:00:00to2019-02-02 12:00:00";
    list<pair<string, double>> qualite = system.CalculerQualiteAir_zone(uneZone, periode);
    cout << "Attribut |"
         << " Mesure" << endl;
    for (auto &i : qualite)
    {
        cout << i.first << "   " << i.second << endl;
    }
    qualite.clear();
}

void testerVerifierFiabliteCapteur()
{
    Administrateur a("a", "b", "c", "d");
    Sensor s(24, 44.8, 1.8);
    Sensor sRef(14, 44.4, 1.8);
    // cout << a.verifierFiabiliteCapteur(s, sRef) << endl;
    a.verifierFiabiliteCapteur(s, sRef);
}

int main(int argc, char *argv[])
{
    assert(argc > 1);
    char *choix = argv[1];
    char *temps;
    if (argc >= 3)
    {
        temps = argv[2];
    }

    start = chrono::system_clock::now();

    if (strcmp(choix, "1") == 0)
    {
        testerClassifierCapteurs();
    }
    else if (strcmp(choix, "2") == 0)
    {
        testerCalculerQualiteAir_zone();
    }
    else if (strcmp(choix, "3") == 0)
    {
        testerVerifierFiabliteCapteur();
    }
    fin = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = fin - start;
    if (strcmp(temps, "t") == 0)
    {
        cout << "Temps d'éxecution : " << elapsed_seconds.count() << endl;
    }
    return 0;
}
