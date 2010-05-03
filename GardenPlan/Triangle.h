/* 
 * File:   Triangle.h
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:44
 */

#ifndef _TRIANGLE_H
#define	_TRIANGLE_H

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

class Triangle : public Shape {
public:
    Triangle(double s1, double s2, double s3);
    Triangle(const Triangle& orig);
    virtual ~Triangle();
private:

};

#endif	/* _TRIANGLE_H */

