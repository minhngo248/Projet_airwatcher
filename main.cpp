#include <iostream>
using namespace std;

#include "System.h"

int main(int argc, char* argv[]) {
    System *system = new System();
    //cout << *system;

    Zone* zoneTest = new Zone(44,-1,150);
    list<Sensor> sensorDeLaZone = system->GetListeCapteurs_zone(*zoneTest,"lol");

    for(auto& i : sensorDeLaZone) {
        cout << i << endl;
    }
    
    return 0;
}
