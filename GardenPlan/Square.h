/* 
 * File:   Square.h
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:44
 */

#ifndef _SQUARE_H
#define	_SQUARE_H

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
#include "Rectangle.h"

class Square : public Rectangle {
public:

    Square(double _width) : Rectangle(_width, _width) {
    }
    //Square(const Square& orig);
    virtual ~Square();
private:
};

#endif	/* _SQUARE_H */

