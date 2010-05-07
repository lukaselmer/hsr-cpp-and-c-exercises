/* 
 * File:   Shape.cpp
 * Author: Lukas Elmer
 * 
 * Created on 3. Mai 2010, 19:48
 */

#include <sstream>
#include <iostream>
#include "Shape.h"

using namespace std;

Shape::~Shape() {
}

double Shape::seeds(/*double seedsPerSquareMeter*/) {
    return surface() * 0.1; //  * seedsPerSquareMeter
}

string Shape::toString() {
    stringstream s;
    s << typeid (*this).name() + 1 << " " << pegs() << " " << ropes() << " " << seeds();
    return s.str();
}

