#include <iostream>
using namespace std;

#include "System.h"
#include "User.h"
#include "Provider.h"
int main(int argc, char* argv[]) {
    System system;
    system.GetListeMesure(0);
    User connected;
    //User *u = new User("Gh","bada","m@l","1234");
    Provider* u = new Provider();
    connected = u->creerCompte(1,"jean","albert", "a@e.fr", "azerty");
    cout << connected <<endl;
    Cleaner c=u->consulterDonneesPurificateur();
    return 0;
}
