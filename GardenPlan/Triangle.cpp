/* 
 * File:   Triangle.cpp
 * Author: Lukas Elmer
 * 
 * Created on 3. Mai 2010, 19:44
 */

#include "Triangle.h"
#include <math.h>

using namespace std;

Triangle::Triangle(double _side1, double _side2, double _side3) : side1(_side1), side2(_side2), side3(_side3) {
}

Triangle::~Triangle() {
}

int Triangle::pegs() const {
    return 3;
}

double Triangle::surface() const { // Heronsche Flächenformel
    double s = (side1 + side2 + side3) / 2.0;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

double Triangle::ropes() const {
    return side1 + side2 + side3;
}
