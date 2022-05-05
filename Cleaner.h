//
// Created by henri on 04/05/2022.
//
#include "Provider.h"
#include <string>
#include <chrono>
#ifndef PROJET_AIRWATCHER_MAIN_CLEANER_H
#define PROJET_AIRWATCHER_MAIN_CLEANER_H


class Cleaner {
public:
    Cleaner (int CleanerID,float lattitude,float longitude,string Debut,string Fin);
    friend ostream & operator <<(ostream& out, const Cleaner & unCleaner);
protected:
    int cleanerID;
    float Lattitude;
    float Longitude;
    string debut;
    string fin;

};


#endif //PROJET_AIRWATCHER_MAIN_CLEANER_H
