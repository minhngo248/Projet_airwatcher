using namespace std;

#include "Zone.h"

double Zone::GetLatitude() {
    return latitude;
}

double Zone::GetLongitude() {
    return longitude;
}

double Zone::GetRayon() {
    return rayon;
}

Zone::Zone(double unLat, double unLong, double unRayon) {
    this->latitude = unLat;
    this->longitude = unLong;
    this->rayon = unRayon;
}

Zone::~Zone() {
   
}