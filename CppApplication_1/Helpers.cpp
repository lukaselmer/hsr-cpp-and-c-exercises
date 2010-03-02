#include "Helpers.h"
#include <iostream>
#include <string>
using namespace std;

string getHelloMessage() {
    return theMessage;
}

void printHello() {
    cout << getHelloMessage() << endl;
}

