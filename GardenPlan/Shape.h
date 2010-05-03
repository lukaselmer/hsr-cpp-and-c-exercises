/* 
 * File:   Shape.h
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:48
 */

#ifndef _SHAPE_H
#define	_SHAPE_H

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

class Shape {
public:
    Shape();
    Shape(const Shape& orig);
    virtual ~Shape();
private:

};

#endif	/* _SHAPE_H */

