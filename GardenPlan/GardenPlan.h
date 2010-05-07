/* 
 * File:   GardenPlan.h
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:43
 */

#ifndef _GARDENPLAN_H
#define	_GARDENPLAN_H

//typedef std::vector<ShapePtr> GardenPlan;

#include "ShapePtr.h"
#include <vector>
#include <iterator>
#include <boost/bind.hpp>

class GardenPlan : public std::vector<ShapePtr> {
public:
    GardenPlan();
    virtual ~GardenPlan();
    std::ostream& print(std::ostream& os);
private:

};

#endif	/* _GARDENPLAN_H */

