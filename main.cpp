#include <iostream>
#include <cstring>
using namespace std;
#include "User.h"

int main()
{
    bool connected;
    //User *u = new User("Gh","bada","m@l","1234");
    User* u = new User();
    connected = u->seConnecter("m@l","1234");
    cout << connected <<endl;
    return 0;
}