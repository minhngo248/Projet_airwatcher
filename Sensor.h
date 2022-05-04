#if ! defined (SENSOR_H)
#define SENSOR_H
#include<list>

class Sensor {
public:
    list<Measurements> GetListeMesureParType(int sensorId_in, Measurements_type type);
    list<Measurements> GetListeMesure(int sensorId_in);
    Sensor(int unSensorId);
    Sensor();
    ~Sensor();
private:
    int sensorId;
    double latitude;
    double longitude;
}

#endif