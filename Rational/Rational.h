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
    typedef long numericType;
    typedef unsigned long absNumericType;
    explicit Rational();
    explicit Rational(numericType, numericType = 1);
    explicit Rational(double);
    explicit Rational(int);
    //explicit Rational(long);

    Rational & operator+=(const Rational&);
    Rational & operator+=(const double&);
    Rational & operator-=(const Rational&);
    Rational & operator-=(const double&);
    Rational & operator*=(const Rational&);
    Rational & operator*=(const double&);
    Rational & operator/=(const Rational&);
    Rational & operator/=(const double&);
    bool operator==(const Rational&) const;
    bool operator!=(const Rational&) const;
    bool operator<(const Rational&) const;
    bool operator>(const Rational&) const;
    bool operator<=(const Rational&) const;
    bool operator>=(const Rational&) const;
    //operator int() const;
    //    operator long() const;
    operator double() const;

    void print(std::ostream& = std::cout) const;

    Rational& abs();
    Rational& chs();
    Rational& normalize();
    Rational& set(const Rational&);
    Rational& setZero();

    bool isZero() const;
private:
    Rational & additionOrSubtraction(const Rational&, bool addition = false);
    bool negative;
    absNumericType numerator;
    absNumericType denumerator;
};

Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);
Rational operator*(const Rational&, const Rational&);
Rational operator/(const Rational&, const Rational&);
std::ostream & operator<<(std::ostream&os, const Rational&);
#endif	/* _RATIONAL_H */
