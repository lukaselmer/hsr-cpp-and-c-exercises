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
    Rational(long, long = 1);
    Rational(const Rational& orig);
    virtual ~Rational();

    Rational & operator+=(const Rational&);
    Rational & operator-=(const Rational&);
    Rational & operator*=(const Rational&);
    Rational & operator/=(const Rational&);

    void print(std::ostream& = std::cout) const;
    Rational& normalize();
    void makePositive();
    Rational abs() const;
    bool isZero() const;
private:
    bool negative;
    unsigned long numerator;
    unsigned long denumerator;
};

#endif	/* _RATIONAL_H */
