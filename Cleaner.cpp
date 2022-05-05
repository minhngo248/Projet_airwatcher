//
// Created by henri on 04/05/2022.
//

#include "Cleaner.h"
ostream & operator<<(ostream& out, const Cleaner & unCleaner)
{
    out<<"CleanerID:"<<unCleaner.cleanerID<<",Lattitude:"<<unCleaner.Lattitude<<",Longitude:"<<unCleaner.Longitude<<",debut:"<<unCleaner.debut<<",fin:"<<unCleaner.fin<<endl;
    return out;
}
Cleaner::Cleaner (int CleanerID,float lattitude,float longitude,string Debut,string Fin){
    cleanerID=CleanerID;
    Lattitude=lattitude;
    Longitude=longitude;
    debut=Debut;
    fin=Fin;
}