using namespace std;

#include "Zone.h"

Zone::Zone(double unLat, double unLong, double unRayon) {
    this->latitude = unLat;
    this->longitude = unLong;
    this->rayon = unRayon;
}

Zone::~Zone() {
   
}