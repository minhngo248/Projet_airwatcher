#if ! defined (SENSOR_H)
#define SENSOR_H

#include <list>
#include <fstream>
#include <string>
#include <iostream>

#include "Measurements.h"

class Sensor {
public:

    friend ostream & operator<<(ostream & out, const Sensor & unSensor);
    double GetLatitude();
    double GetLongitude();
    
    Sensor(int unSensorId = 0, double unLat = 44.0, double unLong = -1.0);
    virtual ~Sensor();

private:
    int sensorId;
    double latitude;
    double longitude;
};

#endif
