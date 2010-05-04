/* 
 * File:   ShapePtr.cpp
 * Author: Lukas Elmer
 * 
 * Created on 3. Mai 2010, 19:47
 */

#include "ShapePtr.h"

ShapePtr::ShapePtr(Shape* _shape) : sharedPointer(_shape) {
}

Shape& ShapePtr::operator*() {
    return *sharedPointer;
}

