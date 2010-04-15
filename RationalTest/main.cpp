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
    ASSERT_EQUAL(s, os.str());
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
    Rational r(31, 21);
    std::ostringstream os;
    os << r;
    ASSERT_EQUAL("31/21", os.str());
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

void constructorDivisionByZero() {
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
    testDivision(4, 1, 1, 4, "16/1");
    testDivision(1, 8, -1, 4, "-1/2");
    testDivision(-15, 8, 5, 4, "-3/2");
    testDivision(-1, 8, -1, 4, "1/2");
    // Special cases (Result = 1)
    testDivision(1, 1, 1, 1, "1/1");
    testDivision(3, 2, 3, 2, "1/1");
    testDivision(1, 17, 2, 34, "1/1");
    testDivision(-1, 1, -1, 1, "1/1");
    // Special cases (Result = -1)
    testDivision(-1, 1, 1, 1, "-1/1");
    testDivision(1, 1, -1, 1, "-1/1");
    testDivision(10, 13, -10, 13, "-1/1");
    testDivision(-10, 13, 10, 13, "-1/1");
    // Special cases (Result = 0)
    testDivision(0, 34, 2, 10, "0/1");
    testDivision(0, 543, 23, 5332, "0/1");
    // Division by zero
    ASSERT_THROWS(testDivision(0, 23, 0, 42, "0/1"), invalid_argument);
    ASSERT_THROWS(testDivision(34, 23, 0, 4, "0/1"), invalid_argument);
}

void equality() {
    Rational r1(4, 10);
    Rational r2(2, 5);
    Rational r3(-2, 5);
    Rational r4(4, -10);

    ASSERT(r1 == r2);
    ASSERT(!(r1 == r3));
    ASSERT(!(r2 == r3));
    ASSERT(r3 == r4);

    ASSERT(!(r1 != r2));
    ASSERT(r1 != r3);
    ASSERT(r2 != r3);
    ASSERT(!(r3 != r4));
}

void smallerAndBigger() {
    Rational r1(4, 10);
    Rational r2(2, 5);
    Rational r3(-2, 5);
    Rational r4(4, -10);
    Rational r5(1, 2);
    Rational r6(3, 4);

    ASSERT(!(r1 < r2));
    ASSERT(!(r1 > r2));
    ASSERT(!(r2 < r1));
    ASSERT(!(r2 > r1));

    ASSERT(!(r1 < r3));
    ASSERT((r1 > r3));
    ASSERT((r3 < r1));
    ASSERT(!(r3 > r1));

    ASSERT((r4 < r5));
    ASSERT(!(r4 > r5));
    ASSERT(!(r5 < r4));
    ASSERT((r5 > r4));

    ASSERT((r5 < r6));
    ASSERT(!(r5 > r6));
    ASSERT(!(r6 < r5));
    ASSERT((r6 > r5));

    ASSERT((r1 <= r2));
    ASSERT((r1 >= r2));
    ASSERT((r2 <= r1));
    ASSERT((r2 >= r1));

    ASSERT(!(r1 <= r3));
    ASSERT((r1 >= r3));
    ASSERT((r3 <= r1));
    ASSERT(!(r3 >= r1));

    ASSERT((r4 <= r5));
    ASSERT(!(r4 >= r5));
    ASSERT(!(r5 <= r4));
    ASSERT((r5 >= r4));

    ASSERT((r5 <= r6));
    ASSERT(!(r5 >= r6));
    ASSERT(!(r6 <= r5));
    ASSERT((r6 >= r5));
}

/**
 * TODO: complete this test
 * You probably would use static_cast<T>(i) in your implementation
 **/
void typeConversions() {
    Rational r1(7, 3);
    Rational r2(19, 2);
    double d = r1 + 2.2;
    // Generates a warning: converting int from double
    int i = r1 + 0.7;
}

void runSuite() {
    cute::suite s;
    s.push_back(CUTE(print));
    s.push_back(CUTE(normalize));
    s.push_back(CUTE(negative));
    s.push_back(CUTE(specialCase));
    s.push_back(CUTE(constructorDivisionByZero));
    s.push_back(CUTE(addition));
    s.push_back(CUTE(subtraction));
    s.push_back(CUTE(multiplication));
    s.push_back(CUTE(division));
    s.push_back(CUTE(equality));
    s.push_back(CUTE(smallerAndBigger));
    s.push_back(CUTE(typeConversions));
    cute::ide_listener lis;
    cute::makeRunner(lis)(s, "Rational tests:");
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
