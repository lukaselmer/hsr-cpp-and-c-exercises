/* 
 * File:   Ellipse.h
 * Author: Lukas Elmer
 *
 * Created on 4. Mai 2010, 07:44
 */

#ifndef _ELLIPSE_H
#define	_ELLIPSE_H

#include "Shape.h"

class Ellipse : public Shape {
public:
    Ellipse(double _axial_length1, double _axial_length2);
    virtual ~Ellipse();
    virtual int pegs();
    virtual double surface();
    virtual double ropes();
private:
    double axial_length1, axial_length2;
};

#endif	/* _ELLIPSE_H */

