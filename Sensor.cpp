using namespace std;
#include "Sensor.h"

int Sensor::GetId() {
    return sensorId;
}

double Sensor::GetLatitude() {
    return latitude;
}

double Sensor::GetLongitude() {
    return longitude;
}

ostream & operator<<(ostream & out, const Sensor & unSensor) {
    out << unSensor.sensorId << " " << unSensor.latitude << " " << unSensor.longitude;
    return out; 
}


bool operator == ( Sensor & unSensor1, Sensor & unSensor2 ){
    bool res = false;
    if ( unSensor1.GetId() == unSensor2.GetId()){
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

