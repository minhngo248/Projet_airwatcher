using namespace std;
#include "Sensor.h"

double Sensor::GetLatitude() {
    return latitude;
}

double Sensor::GetLongitude() {
    return longitude;
}

int Sensor::GetSensorId() {
    return sensorId;
}

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

