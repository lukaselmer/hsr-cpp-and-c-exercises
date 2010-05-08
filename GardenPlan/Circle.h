/* 
 * File:   Circle.h
 * Author: Lukas Elmer
 *
 * Created on 4. Mai 2010, 07:55
 */

#ifndef _CIRCLE_H
#define	_CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:

    Circle(double _radius) : radius(_radius) {
    }
    virtual ~Circle();
    virtual int pegs() const;
    virtual double surface() const;
    virtual double ropes() const;
private:
    double radius;
};

#endif	/* _CIRCLE_H */

