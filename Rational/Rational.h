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

/**
 * This class uses unsigned longs for numerator and denumerator, and an
 * additional flag to mark if the rational is positive(0) or negative(1). That is
 * because we would, with signed longs, loose half of all our possible values
 * e.g -1/-1 == 1/1, -1/1 == 1/-1 etc.
 *
 * There are also some TODO's, which would have to be realized if this application
 * was used for serious projects.
 **/
class Rational {
public:
    typedef long numericType;
    typedef unsigned long absNumericType;
    explicit Rational(numericType = 0, numericType = 1);
    explicit Rational(double);
    explicit Rational(int);

    // TODO: use gcd (greatest common divisor) for this operations
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

    operator double() const; // Very dangerous and probably better like this: "double asDouble() const;"

    void print(std::ostream& = std::cout) const;

    Rational& abs();
    Rational& chs();
    Rational& normalize(); // TODO: use gcd (greatest common divisor) for this operation
    Rational& set(const Rational&);
    Rational& setZero();

    bool isZero() const;
private:
    bool negative;
    absNumericType numerator;
    absNumericType denumerator;

    // TODO: use gcd (greatest common divisor) for this operation
    Rational & additionOrSubtraction(const Rational&, bool addition = false);
};

// boost operators could generate this four functions automatically
Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);
Rational operator*(const Rational&, const Rational&);
Rational operator/(const Rational&, const Rational&);

std::ostream & operator<<(std::ostream&os, const Rational&);

#endif	/* _RATIONAL_H */
