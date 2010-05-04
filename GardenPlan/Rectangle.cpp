/* 
 * File:   Rectangle.cpp
 * Author: Lukas Elmer
 * 
 * Created on 3. Mai 2010, 20:15
 */

#include "Rectangle.h"

Rectangle::Rectangle(double _height, double _width) : height(_height), width(_width) {
}

Rectangle::~Rectangle() {
}

int Rectangle::pegs() {
    return 4;
}

double Rectangle::surface() {
    return height * width;
}

double Rectangle::ropes() {
    return (height * 2) + (width * 2);
}


