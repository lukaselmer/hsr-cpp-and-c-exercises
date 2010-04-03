/* 
 * File:   Rational.h
 * Author: Lukas Elmer
 *
 * Created on 3. April 2010, 14:12
 */

#ifndef _RATIONAL_H
#define	_RATIONAL_H

#include <iosfwd>
#include <iostream>

class Rational {
public:
    Rational(int, int);
    Rational(const Rational& orig);
    virtual ~Rational();
    void print(std::ostream& = std::cout) const;
    void normalize();
private:
    bool negative;
    unsigned int numerator;
    unsigned int denumerator;
};

#endif	/* _RATIONAL_H */

