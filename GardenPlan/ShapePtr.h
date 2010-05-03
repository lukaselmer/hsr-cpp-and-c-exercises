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
#include "Shape.h"

class ShapePtr {
public:
    ShapePtr(Shape* shape);
    ShapePtr(const ShapePtr& orig);
    virtual ~ShapePtr();
private:

};

#endif	/* _SHAPEPTR_H */

