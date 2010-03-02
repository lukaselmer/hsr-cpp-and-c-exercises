#include "Hello.h"
#include <iostream>
#include <string>
using namespace std;

Hello::Hello(std::string message) {
    size_t found = message.find(" ");
    if (found != string::npos)
        std::cout << message.substr(found+1, 2) << std::endl;
    else
        std::cout << "Not two words!" << std::endl; // Error handling?
    std::string s = "";
}

string Hello::getHelloMessage() {
    return message;
}
