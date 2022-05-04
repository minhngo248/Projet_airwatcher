#include "System.h"

using namespace std;

System::System() {
    size_t sz;
    ifstream fic;
    string line;
    // -------------Initialisation de la ListeCapteurs ----------------------
    fic.open("dataset/sensors.csv");
    while ( !fic.eof() ) {
        fic >> line;
        string str = "Sensor";
        size_t pos1 = line.find(";");
        int idSensor = stoi(line.substr(str.length(), pos1-str.length()), &sz);
        size_t pos2 = line.find_first_of(";", pos1+1);
        double lat = stod(line.substr(pos1+1, pos2-pos1-1), &sz);
        double lon = stod(line.substr(pos2 + 1), &sz);
        
        Sensor unSensor(idSensor, lat, lon);
        this->listeCapteurs.insert(pair<int, Sensor>(idSensor, unSensor));
    }
    fic.close();
    // ----------------------------------------------------------------------
}

System::~System() {
    this->listeCapteurs.empty();
}