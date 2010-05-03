/* 
 * File:   ShapePtr.h
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:47
 */

#ifndef _SHAPEPTR_H
#define	_SHAPEPTR_H

#include <iosfwd>
#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <boost/shared_ptr.hpp>
#include "Shape.h"

class ShapePtr {
public:
    ShapePtr(Shape* _shape);
    Shape & operator*();
private:
    boost::shared_ptr<Shape> sharedPointer;
};
//
//std::ostream & operator<<(std::ostream& os, ShapePtr& shapePtr) {
//    return os;
//}

#endif	/* _SHAPEPTR_H */

