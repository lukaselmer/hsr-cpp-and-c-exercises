/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 3. April 2010, 14:11
 */

#include "Rational.h"

#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

#include <iostream>
#include <string>

using namespace std;

void testRational(const Rational& r, const string& s);
void testRational(const long numerator, const long denumerator, const string& s);
void testAddition(const long, const long, const long, const long, const string& s);
void testSubtraction(const long, const long, const long, const long, const string& s);
void testMultiplication(const long, const long, const long, const long, const string& s);
void testDivision(const long, const long, const long, const long, const string& s);

void testRational(const Rational& r, const string& s) {
    std::ostringstream os;
    r.print(os);
    ASSERT_EQUAL(s + "\n", os.str());
}

void testRational(const long numerator, const long denumerator, const string& s) {
    testRational(Rational(numerator, denumerator), s);
}

void testAddition(const long numerator1, const long denumerator1,
        const long numerator2, const long denumerator2, const string& s) {
    testRational(Rational(numerator1, denumerator1) + Rational(numerator2, denumerator2), s);
    Rational r(numerator1, denumerator1);
    r += Rational(numerator2, denumerator2);
    testRational(r, s);
}

void testSubtraction(const long numerator1, const long denumerator1,
        const long numerator2, const long denumerator2, const string& s) {
    testRational(Rational(numerator1, denumerator1) - Rational(numerator2, denumerator2), s);
    Rational r(numerator1, denumerator1);
    r -= Rational(numerator2, denumerator2);
    testRational(r, s);
}

void testMultiplication(const long numerator1, const long denumerator1,
        const long numerator2, const long denumerator2, const string& s) {
    testRational(Rational(numerator1, denumerator1) * Rational(numerator2, denumerator2), s);
    Rational r(numerator1, denumerator1);
    r *= Rational(numerator2, denumerator2);
    testRational(r, s);
}

void testDivision(const long numerator1, const long denumerator1,
        const long numerator2, const long denumerator2, const string& s) {
    testRational(Rational(numerator1, denumerator1) / Rational(numerator2, denumerator2), s);
    Rational r(numerator1, denumerator1);
    r /= Rational(numerator2, denumerator2);
    testRational(r, s);
}

void print() {
    testRational(3, 4, "3/4");
}

void normalize() {
    testRational(19, 95, "1/5");
    testRational(4, 88, "1/22");
    testRational(6, 9, "2/3");
    testRational(9, 6, "3/2");
}

void negative() {
    testRational(-9, 6, "-3/2");
    testRational(9, -6, "-3/2");
    testRational(-9, -6, "3/2");
}

void specialCase() {
    testRational(0, 45, "0/1");
    testRational(0, -6, "0/1");
}

void divisionByZero() {
    ASSERT_THROWS(Rational(3, 0), invalid_argument);
    ASSERT_THROWS(Rational(-43, 0), invalid_argument);
}

void addition() {
    // Normal cases
    testAddition(1, 2, 1, 4, "3/4"); // 1/2 + 1/4 = 3/4
    testAddition(-1, 2, 1, 4, "-1/4"); // -1/2 + 1/4 = -1/4
    testAddition(-1, 2, -1, 4, "-3/4");
    testAddition(1, 8, 3, 8, "1/2");
    testAddition(384, 144, 5, 12, "37/12");
    testAddition(777, 777, 222, 222, "2/1");
    // Special cases (Result = 1)
    testAddition(1, 2, 1, 2, "1/1");
    testAddition(3, 8, 10, 16, "1/1");
    // Special cases (Result = -1)
    testAddition(-1, 2, -1, 2, "-1/1");
    testAddition(-3, 8, -10, 16, "-1/1");
    // Special cases (Result = 0)
    testAddition(777, 777, -222, 222, "0/1");
    testAddition(-1, 2, 1, 2, "0/1");
    testAddition(-2, 8, 1, 4, "0/1");
}

void subtraction() {
    // Normal cases
    testSubtraction(1, 2, 1, 4, "1/4");
    testSubtraction(1, 2, -1, 4, "3/4");
    testSubtraction(-1, 2, 1, 4, "-3/4");
    testSubtraction(-1, 2, -1, 4, "-1/4");
    testSubtraction(1, 8, 3, 8, "-1/4");
    testSubtraction(384, 144, 5, 12, "9/4");
    testSubtraction(777, 777, -222, 222, "2/1");
    testSubtraction(-777, 777, 222, 222, "-2/1");
    // Special cases (Result = 1)
    testSubtraction(1, 2, -1, 2, "1/1");
    testSubtraction(3, 8, -10, 16, "1/1");
    // Special cases (Result = -1)
    testSubtraction(-1, 2, 1, 2, "-1/1");
    testSubtraction(-3, 8, 10, 16, "-1/1");
    // Special cases (Result = 0)
    testSubtraction(777, 777, 222, 222, "0/1");
    testSubtraction(-1, 2, -1, 2, "0/1");
    testSubtraction(2, 8, 1, 4, "0/1");
}

void multiplication() {
    // Normal cases
    testMultiplication(3, 2, 1, 4, "3/8");
    testMultiplication(1, 2, -1, 4, "-1/8");
    testMultiplication(-3, 2, 5, 4, "-15/8");
    testMultiplication(-1, 2, -1, 4, "1/8");
    // Special cases (Result = 1)
    testMultiplication(1, 1, 1, 1, "1/1");
    testMultiplication(-1, 1, -1, 1, "1/1");
    // Special cases (Result = -1)
    testMultiplication(-1, 1, 1, 1, "-1/1");
    testMultiplication(1, 1, -1, 1, "-1/1");
    // Special cases (Result = 0)
    testMultiplication(0, 34, 2, 10, "0/1");
    testMultiplication(0, 23, 0, 42, "0/1");
    testMultiplication(34, 23, 0, 4, "0/1");
}

void division() {
    // Normal cases
    testMultiplication(3, 2, 1, 4, "3/8");
    testMultiplication(1, 2, -1, 4, "-1/8");
    testMultiplication(-3, 2, 5, 4, "-15/8");
    testMultiplication(-1, 2, -1, 4, "1/8");
    // Special cases (Result = 1)
    testMultiplication(1, 1, 1, 1, "1/1");
    testMultiplication(-1, 1, -1, 1, "1/1");
    // Special cases (Result = -1)
    testMultiplication(-1, 1, 1, 1, "-1/1");
    testMultiplication(1, 1, -1, 1, "-1/1");
    // Special cases (Result = 0)
    testMultiplication(0, 34, 2, 10, "0/1");
    testMultiplication(0, 23, 0, 42, "0/1");
    testMultiplication(34, 23, 0, 4, "0/1");
}

void runSuite() {
    cute::suite s;
    s.push_back(CUTE(print));
    s.push_back(CUTE(normalize));
    s.push_back(CUTE(negative));
    s.push_back(CUTE(specialCase));
    s.push_back(CUTE(divisionByZero));
    s.push_back(CUTE(addition));
    s.push_back(CUTE(subtraction));
    s.push_back(CUTE(multiplication));
    s.push_back(CUTE(division));
    cute::ide_listener lis;
    cute::makeRunner(lis)(s, "Rational Test Suite");
}

int main(int argc, char** argv) {
    cout << "=======================" << endl;
    cout << "Starting rational tests" << endl;
    cout << "=======================" << endl << endl;

    runSuite();

    cout << endl << "=====" << endl;
    cout << "Done!" << endl;
    cout << "=====" << endl << endl;

    return (EXIT_SUCCESS);
}
