/* 
 * File:   Ellipse.cpp
 * Author: Lukas Elmer
 * 
 * Created on 4. Mai 2010, 07:44
 */

#include <cmath>
#include "Ellipse.h"

Ellipse::Ellipse(double _axial_length1, double _axial_length2) : axial_length1(_axial_length1), axial_length2(_axial_length2) {
}

Ellipse::~Ellipse() {
}

int Ellipse::pegs() const {
    return 2;
}

double Ellipse::surface() const {
    const double PI = 4.0 * atan(1.0);
    return PI * axial_length1 * axial_length2;
}

double Ellipse::ropes() const {
    const double PI = 4.0 * atan(1.0);
    double fi = (axial_length1 - axial_length2) / (axial_length1 + axial_length2);
    return PI * (axial_length1 + axial_length2) * (1 + ((3 * fi * fi) / (10 + sqrt(4 - (3 * fi * fi)))));
}
