#if ! defined (SENSOR_H)
#define SENSOR_H
#include<list>

#include "Measurements.h"
#include "MeasurementsType.h"

class Sensor {
public:
    list<Measurements> GetListeMesureParType(int sensorId_in, MeasurementsType type);
    list<Measurements> GetListeMesure(int sensorId_in);
    Sensor(int unSensorId);
    Sensor();
    ~Sensor();
private:
    int sensorId;
    double latitude;
    double longitude;
    Measurements *mesures ;
    //Individual_user id; 
};

#endif
