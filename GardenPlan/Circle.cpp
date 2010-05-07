/* 
 * File:   Circle.cpp
 * Author: Lukas Elmer
 * 
 * Created on 4. Mai 2010, 07:55
 */

#include "Circle.h"
#include <cmath>

Circle::~Circle() {
}

double Circle::ropes() {
    const double PI = 4.0 * atan(1.0);
    return 2 * PI * radius;
}

int Circle::pegs() {
    return 2;
}

double Circle::surface() {
    const double PI = 4.0 * atan(1.0);
    return PI * radius * radius;
}
