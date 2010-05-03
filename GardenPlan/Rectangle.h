/* 
 * File:   Rectangle.h
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 20:15
 */

#ifndef _RECTANGLE_H
#define	_RECTANGLE_H

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

class Rectangle : public Shape {
public:
    Rectangle(double s1, double s2);
    Rectangle(const Rectangle& orig);
    virtual ~Rectangle();
private:

};

#endif	/* _RECTANGLE_H */

