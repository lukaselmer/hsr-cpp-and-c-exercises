/* 
 * File:   Cat.cpp
 * Author: Lukas Elmer
 * 
 * Created on 9. August 2010, 01:02
 */

#include "Cat.h"

using namespace std;

struct CatImplementation {
    string name;

    CatImplementation(const string & n) : name(n) {
    }

    string getName() {
        return name;
    }

    void setName(const string & s) {
        name = s;
    }
};

Cat::Cat(const string & n) : pImpl(new CatImplementation(n)) {
}

string Cat::getName() {
    return pImpl->getName();
}

void Cat::setName(const string & s) {
    pImpl->setName(s);
}
