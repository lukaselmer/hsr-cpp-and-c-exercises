/* 
 * File:   Rational.cpp
 * Author: Lukas Elmer
 * 
 * Created on 3. April 2010, 14:12
 */

#include "Rational.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

Rational::Rational(numericType _numerator, numericType _denumerator) : numerator(_numerator < 0 ? _numerator * -1 : _numerator),
denumerator(_denumerator < 0 ? _denumerator * -1 : _denumerator), negative(_numerator < 0 ^ _denumerator < 0) {
    if (denumerator == 0) throw std::invalid_argument("Bad denumerator, division by zero!");
    if (numerator == 0) setZero();
    normalize();
}

Rational & Rational::additionOrSubtraction(const Rational& r, bool subtraction) {
    if (!r.isZero()) {
        if (isZero()) set(r);
        else {
            numerator *= r.denumerator;
            absNumericType adjustment_value = r.numerator * denumerator;
            denumerator *= r.denumerator;
            if (negative ^ (subtraction ? r.negative : !r.negative)) numerator += adjustment_value;
            else {
                if (numerator == adjustment_value) setZero();
                else if (numerator > adjustment_value) numerator -= adjustment_value;
                else { //numerator > addition
                    numerator = adjustment_value - numerator;
                    chs();
                }
            }
        }
    }
    normalize();
    return *this;
}

Rational & Rational::operator+=(const Rational& r) {
    return additionOrSubtraction(r, false);
}

Rational & Rational::operator-=(const Rational& r) {
    return additionOrSubtraction(r, true);
}

Rational & Rational::operator*=(const Rational& r) {
    if (!isZero()) {
        if (r.isZero()) {
            setZero();
        } else {
            numerator *= r.numerator;
            denumerator *= r.denumerator;
            if (r.negative) chs();
        }
    }
    return *this;
}

Rational & Rational::operator/=(const Rational& r) {
    if (r.isZero()) throw std::invalid_argument("Bad divider, division by zero!");
    if (!isZero()) {
        numerator *= r.denumerator;
        denumerator *= r.numerator;
        if (r.negative) chs();
    }
    return *this;
}

void Rational::print(ostream& out) const {
    out << (negative ? "-" : "") << numerator << "/" << denumerator << endl;
}

Rational& Rational::abs() {
    negative = false;
    return *this;
}

Rational& Rational::chs() {
    negative = !negative;
    return *this;
}

Rational& Rational::normalize() {
    if (numerator != 0 && numerator != 1 && denumerator != 1) {
        for (absNumericType normalize_with = 2; normalize_with <= (numerator > denumerator ? denumerator : numerator); normalize_with++) {
            if ((numerator % normalize_with) == 0 && (denumerator % normalize_with) == 0) {
                numerator /= normalize_with;
                denumerator /= normalize_with;
                normalize_with--; // Do it again if it worked
            }
        }
    }
    return *this;
}

Rational& Rational::set(const Rational& r) {
    numerator = r.numerator;
    denumerator = r.denumerator;
    negative = r.negative;
    return *this;
}

Rational& Rational::setZero() {
    numerator = 0;
    denumerator = 1;
    negative = false;
    return *this;
}

bool Rational::isZero() const {
    return numerator == 0;
}

Rational operator+(const Rational& r1, const Rational& r2) {
    return Rational(r1) += r2;
}

Rational operator-(const Rational& r1, const Rational& r2) {
    return Rational(r1) -= r2;
}

Rational operator*(const Rational& r1, const Rational& r2) {
    return Rational(r1) *= r2;
}

Rational operator/(const Rational& r1, const Rational& r2) {
    return Rational(r1) /= r2;
}

