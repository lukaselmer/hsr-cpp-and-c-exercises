/* 
 * File:   Rectangle.h
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 20:15
 */

#ifndef _RECTANGLE_H
#define	_RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double _height, double _width);
    virtual ~Rectangle();
    virtual int pegs() const;
    virtual double surface() const;
    virtual double ropes() const;
private:
    double height, width;
};

#endif	/* _RECTANGLE_H */

