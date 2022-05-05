#include <iostream>
using namespace std;

#include "System.h"
#include "User.h"
#include "Provider.h"
#include "Sensor.h"
#include "IndividualUser.h"

int main(int argc, char* argv[]) {
//     System system;
//     system.GetListeMesure(0);
//     User connected;
//     //User *u = new User("Gh","bada","m@l","1234");
//     Provider* u = new Provider();
//     connected = u->creerCompte(1,"jean","albert", "a@e.fr", "azerty");
//     cout << connected <<endl;
//     Cleaner c=u->consulterDonneesPurificateur();
    
    User connected;
    IndividualUser* iu = new IndividualUser();
    connected = iu->creerCompte(0,"Gh","bada","m@l","1234");

    if (connected.seConnecter("m@l","1234")){
        cout << connected;
        cout << iu->consulterScore()<< endl;
        iu->setScore(2);
        cout << iu->consulterScore()<< endl;
        cout << iu->consulterDonneesCapteur(70) << endl;
    }
    
    return 0;
}
