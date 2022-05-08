using namespace std;
#include "Sensor.h"

int Sensor::getId() {
    return sensorId;
}

double Sensor::getLatitude() {
    return latitude;
}

double Sensor::getLongitude() {
    return longitude;
}

ostream & operator<<(ostream & out, const Sensor & unSensor) {
    out << unSensor.sensorId << " " << unSensor.latitude << " " << unSensor.longitude;
    return out; 
}


bool operator == ( Sensor & unSensor1, Sensor & unSensor2 ){
    bool res = false;
    if ( unSensor1.getId() == unSensor2.getId()){
        res = true;
    }
    return res;
}

Sensor::Sensor(int unSensorId, double unLat, double unLong) {
    this->sensorId = unSensorId;
    this->latitude = unLat;
    this->longitude = unLong;
}

Sensor::~Sensor() {

}

