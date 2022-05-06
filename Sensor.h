#if ! defined (SENSOR_H)
#define SENSOR_H

#include <string>
#include <iostream>

#include "Measurements.h"

class Sensor {
public:
    int GetId();
    double GetLatitude();
    double GetLongitude();
    friend ostream & operator<<(ostream & out, const Sensor & unSensor);
    
    Sensor(int unSensorId = 0, double unLat = 44.0, double unLong = -1.0);
    virtual ~Sensor();

private:
    int sensorId;
    double latitude;
    double longitude;
};

#endif
