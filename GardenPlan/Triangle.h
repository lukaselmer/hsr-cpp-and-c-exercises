/* 
 * File:   Triangle.h
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:44
 */

#ifndef _TRIANGLE_H
#define	_TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle(double _side1, double _side2, double _side3);
    //    Triangle(const Triangle& orig);
    virtual ~Triangle();
    virtual int pegs();
    virtual double surface();
    virtual double ropes();
private:
    double side1, side2, side3;
};

#endif	/* _TRIANGLE_H */

