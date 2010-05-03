/* 
 * File:   Diamond.h
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:44
 */

#ifndef _DIAMOND_H
#define	_DIAMOND_H

#include "Shape.h"

class Diamond : public Shape {
public:
    Diamond(double _side1, double _side2, double _degrees);
    //    Diamond(const Diamond& orig);
    virtual ~Diamond();
    virtual int pegs();
    virtual double surface();
    virtual double ropes();
private:
    double side1, side2, degrees;
};

#endif	/* _DIAMOND_H */

