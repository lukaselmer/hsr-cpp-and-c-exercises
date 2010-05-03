/* 
 * File:   Diamond.h
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:44
 */

#ifndef _DIAMOND_H
#define	_DIAMOND_H

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

class Diamond : public Shape {
public:
    Diamond(double s1, double s2, double degrees);
    Diamond(const Diamond& orig);
    virtual ~Diamond();
private:

};

#endif	/* _DIAMOND_H */

