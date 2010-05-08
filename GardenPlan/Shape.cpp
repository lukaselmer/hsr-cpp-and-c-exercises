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

double Shape::seeds(/*double seedsPerSquareMeter*/) const { /* Why does this (default value) not work with alogrithms? */
    return surface() * 0.1; //  * seedsPerSquareMeter
}

/**
 * OK, typeid is not be the best idea... But it is fun :-)
 **/
string Shape::toString() const {
    stringstream s;
    s << typeid (*this).name() + 1 << " " << pegs() << " " << ropes() << " " << seeds();
    return s.str();
}

