#include <iostream>
using namespace std;

#include "System.h"

void testerClassifierCapteurs() {
    System system;
    string periode = "2019-01-01 12:00:00to2019-05-05 13:00:00";
    // respecter le format de saisie la periode
    multimap<double, int> listeCroissante = system.ClassifierCapteurs(2, periode, "PM10");
    cout << "IdCap   |   " << "similitude" << endl;
    for(auto& i:listeCroissante) {
        cout << i.second << "   " << i.first << endl;
    }
    listeCroissante.clear();
}

void testerCalculerQualiteAir_zone() {
    Zone uneZone(44.4, 0.4, 100);
    System system;
    map<string, double> qualite = system.CalculerQualiteAir_zone(uneZone);
    cout << "Attribut |" << " Mesure" << endl;
    for (auto& i:qualite) {
        cout << i.first << "   " << i.second << endl;
    }
    qualite.clear();
}

int main(int argc, char* argv[]) {
    //testerClassifierCapteurs();
    testerCalculerQualiteAir_zone();
    return 0;
}
