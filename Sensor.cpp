using namespace std;
#include "Sensor.h"



list<Measurements> Sensor::GetListeMesureParType(int sensorId_in, MeasurementsType type) {

}

list<Measurements> Sensor::GetListeMesure(int sensorId_in) {
    list<Measurements> mesMeasurements;
    MeasurementsType* unMeasurementType;
    Measurements* unMeasurement;
    size_t sz;
    size_t pos1;
    size_t pos2;
    size_t pos3;
    int idSensor;
    float mesure;
    string unite;
    ifstream fic;
    string line;
    char lineGet[100];
    string periode;
    string str = "Sensor";

    //string test;
    
    fic.open("dataset/measurements.csv");
    while ( !fic.eof() ) {
        fic.getline(lineGet,100,'\n');
        line = lineGet;

        
        pos1 = line.find(";");
        if(pos1 != string::npos)
        {
            periode = line.substr(0,pos1);
            //cout << periode << endl;
            pos2 = line.find_first_of(";", pos1+1);
            idSensor = stoi(line.substr(pos1+str.length()+1, pos2-(pos1+str.length()+1)), &sz);
            //cout << idSensor << endl;
            if(sensorId_in==idSensor)
            {
                //cout << idSensor << endl;
                pos3 = line.find_first_of(";", pos2+1);
                unite = line.substr(pos2+1, pos3-pos2-1);
                //cout << unite << endl;
                mesure = stod(line.substr(pos3 + 1), &sz);
                //cout << mesure << endl;
                
                unMeasurementType = new MeasurementsType(unite);
                //cout << *unMeasurementType << endl;
                unMeasurement = new Measurements(periode, mesure, unMeasurementType);
                //cout << *unMeasurement << endl;
                //cout << "------------------------" << endl;
                mesMeasurements.push_front(*unMeasurement);
            }
        }
    }
    fic.close();
    return mesMeasurements;
} 

ostream & operator<<(ostream & out, const Sensor & unSensor) {
    out /*<< unSensor.sensorId << " " */<< unSensor.latitude << " " << unSensor.longitude;
    return out; 
}

Sensor::Sensor(int unSensorId, double unLat, double unLong) {
    this->sensorId = unSensorId;
    this->latitude = unLat;
    this->longitude = unLong;
    //mesures=new Measurements(*mes);
}

Sensor::Sensor() 
{

}

Sensor::~Sensor() {
	delete [] mesures; 

}

