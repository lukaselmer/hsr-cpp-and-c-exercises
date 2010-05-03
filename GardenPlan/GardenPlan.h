/* 
 * File:   GardenPlan.h
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:43
 */

#ifndef _GARDENPLAN_H
#define	_GARDENPLAN_H

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
#include "ShapePtr.h"

class GardenPlan {
public:
    GardenPlan();
    GardenPlan(const GardenPlan& orig);
    virtual ~GardenPlan();
    void push_back(ShapePtr shapePtr);
    std::ostream& print(std::ostream& os);
private:

};

#endif	/* _GARDENPLAN_H */

