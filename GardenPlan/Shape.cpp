/* 
 * File:   Shape.cpp
 * Author: Lukas Elmer
 * 
 * Created on 3. Mai 2010, 19:48
 */

#include <sstream>
#include "Shape.h"

using namespace std;

Shape::~Shape() {
}

double Shape::seeds() {
    return surface() * 0.1;
}

string Shape::toString() {
    stringstream s;
    s << typeid (*this).name() + 1 << " " << pegs() << " " << ropes() << " " << seeds();
    return s.str();
}

