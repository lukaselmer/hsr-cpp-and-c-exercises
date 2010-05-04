/* 
 * File:   ShapePtr.h
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:47
 */

#ifndef _SHAPEPTR_H
#define	_SHAPEPTR_H

#include <vector>
#include <iterator>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include "Shape.h"

class ShapePtr {
public:
    ShapePtr(Shape* _shape);
    Shape & operator*();
private:
    boost::shared_ptr<Shape> sharedPointer;
};

#endif	/* _SHAPEPTR_H */
