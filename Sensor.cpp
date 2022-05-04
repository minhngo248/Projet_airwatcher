using namespace std;

#include "Sensor.h"
#include "Measurements.h"

list<Measurements> Sensor::GetListeMesureParType(int sensorId_in, Measurements_type type) {

}

list<Measurements> Sensor::GetListeMesure(int sensorId_in) {

}

Sensor::Sensor(int unSensorId) {
    this->sensorId = unSensorId;
}