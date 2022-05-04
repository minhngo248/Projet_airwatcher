#include <iostream>
using namespace std;

#include "System.h"

int main(int argc, char* argv[]) {
    System *system = new System();
    cout << *system;
    return 0;
}
