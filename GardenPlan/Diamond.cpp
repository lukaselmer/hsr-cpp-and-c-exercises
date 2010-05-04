/* 
 * File:   Diamond.cpp
 * Author: Lukas Elmer
 * 
 * Created on 3. Mai 2010, 19:44
 */

#include "Diamond.h"
#include <cmath>

using namespace std;

Diamond::Diamond(double _side1, double _side2, double _degrees) : side1(_side1), side2(_side2), degrees(_degrees) {
}

Diamond::~Diamond() {
}

int Diamond::pegs() {
    return 4;
}

double Diamond::surface() {
    const double PI = 4.0 * atan(1.0);
    double surfaceTop = side1 * side1 * sin(degrees * PI / 180) / 2;
    double surfaceBottom = side2 * side2 * sin(degrees * PI / 180) / 2;
    return surfaceTop + surfaceBottom;
}

double Diamond::ropes() {
    return (side1 * 2) + (side2 * 2);
}
