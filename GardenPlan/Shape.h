/* 
 * File:   Shape.h
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:48
 */

#ifndef _SHAPE_H
#define	_SHAPE_H

#include <string>

class Shape {
public:
    virtual ~Shape();
    virtual int pegs() const = 0;
    virtual double surface() const = 0;
    virtual double ropes() const = 0;
    double seeds(/*double seedsPerSquareMeter = 0.1*/) const;
    std::string toString() const;
};

#endif	/* _SHAPE_H */

