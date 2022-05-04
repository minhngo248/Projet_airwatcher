#if ! defined (SENSOR_H)
#define SENSOR_H
#include<list>
#include <fstream>
#include <string>
#include <iostream>
#include <map>

#include "Measurements.h"

class Sensor {
public:
    list<Measurements> GetListeMesureParType(int sensorId_in, MeasurementsType type);
    list<Measurements> GetListeMesure(int sensorId_in);

    friend ostream & operator<<(ostream & out, const Sensor & unSensor);
    
    Sensor(int unSensorId, double unLat, double unLong);
    Sensor();
    ~Sensor();

    int sensorId;
    double latitude;
    double longitude;

    Measurements *mesures ;
    //Individual_user id; 

};

#endif
