using namespace std;
#include "Sensor.h"


/*list<Measurements> Sensor::GetListeMesureParType(int sensorId_in, MeasurementsType type) {

}

list<Measurements> Sensor::GetListeMesure(int sensorId_in) {

} */

ostream & operator<<(ostream & out, const Sensor & unSensor) {
    out << unSensor.sensorId << " " << unSensor.latitude << " " << unSensor.longitude;
    return out; 
}

Sensor::Sensor(int unSensorId, double unLat, double unLong) {
    this->sensorId = unSensorId;
    this->latitude = unLat;
    this->longitude = unLong;
}

Sensor::~Sensor() {

}