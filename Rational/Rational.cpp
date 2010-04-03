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

Rational::Rational(long _numerator, long _denumerator) :
numerator(_numerator < 0 ? _numerator * -1 : _numerator),
denumerator(_denumerator < 0 ? _denumerator * -1 : _denumerator),
negative(_numerator < 0 ^ _denumerator < 0) {
    if (denumerator == 0) throw std::invalid_argument("Bad denumerator, division by zero!");
    if (numerator == 0) {
        denumerator = 1;
        negative = false;
    }
}

Rational::Rational(const Rational& orig) {
}

Rational::~Rational() {
}

void Rational::print(ostream& out) const {
    out << (negative ? "-" : "") << numerator << "/" << denumerator << endl;
}

Rational& Rational::normalize() {
    if (numerator != 0 && numerator != 1 && denumerator != 1) {
        for (long normalize_with = 2; normalize_with <= (numerator > denumerator ? denumerator : numerator); normalize_with++) {
            if ((numerator % normalize_with) == 0 && (denumerator % normalize_with) == 0) {
                numerator /= normalize_with;
                denumerator /= normalize_with;
                normalize_with--; // Do it again if it worked
            }
        }
    }
    return *this;
}

Rational & Rational::operator+=(const Rational& r) {
    if (!r.isZero()) {
        if (isZero()) {
            numerator = r.numerator;
            denumerator = r.denumerator;
            negative = r.negative;
        } else {
            numerator *= r.denumerator;
            numerator += r.numerator * denumerator;
            denumerator *= r.denumerator;
        }
    }
    normalize();
    return *this;
}

Rational & Rational::operator-=(const Rational& r) {

    return *this;
}

Rational & Rational::operator*=(const Rational& r) {

    return *this;
}

Rational & Rational::operator/=(const Rational& r) {

    return *this;
}

bool Rational::isZero() const {
    return numerator == 0;
}

void Rational::makePositive() {
    negative = false;
}

Rational Rational::abs() const {
    Rational r(*this);
    r.makePositive();
    return r;
    
}



