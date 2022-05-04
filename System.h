#if ! defined (SYSTEM_H)
#define SYSTEM_H

#include <map>
#include <fstream>

#include "Sensor.h"

class System {
public:
    System();
    ~System();
private:
    map<int, Sensor> listeCapteurs;
};

#endif