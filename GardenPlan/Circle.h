/* 
 * File:   Circle.h
 * Author: Lukas Elmer
 *
 * Created on 4. Mai 2010, 07:55
 */

#ifndef _CIRCLE_H
#define	_CIRCLE_H

#include "Ellipse.h"

class Circle : public Ellipse {
public:

    Circle(double _radius) : Ellipse(_radius, _radius), radius(_radius) {
    }
    virtual ~Circle();
    virtual double ropes();
    virtual int pegs();
private:
    double radius;
};

#endif	/* _CIRCLE_H */

