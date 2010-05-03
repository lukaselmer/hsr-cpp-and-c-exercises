/* 
 * File:   Shape.h
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:48
 */

#ifndef _SHAPE_H
#define	_SHAPE_H

#include <sstream>
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
    virtual ~Shape();
    virtual int pegs() = 0;
    virtual double surface() = 0;
    virtual double ropes() = 0;
    double seeds();
    std::string toString();
private:

};

#endif	/* _SHAPE_H */

