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

void print() {
    std::ostringstream os;
    Rational r(2, 4);
    r.print(os);
    ASSERT_EQUAL("2/4\n", os.str());
}

void normalize1() {
    std::ostringstream os;
    Rational r(19, 95);
    r.normalize();
    r.print(os);
    ASSERT_EQUAL("1/5\n", os.str());
}

void normalize2() {
    std::ostringstream os;
    Rational r(4, 88);
    r.normalize();
    r.print(os);
    ASSERT_EQUAL("1/22\n", os.str());
}

void normalize3() {
    std::ostringstream os;
    Rational r(6, 9);
    r.normalize();
    r.print(os);
    ASSERT_EQUAL("2/3\n", os.str());
}

void normalize4() {
    std::ostringstream os;
    Rational r(9, 6);
    r.normalize();
    r.print(os);
    ASSERT_EQUAL("3/2\n", os.str());
}

void negative1() {
    std::ostringstream os;
    Rational r(-9, 6);
    r.normalize();
    r.print(os);
    ASSERT_EQUAL("-3/2\n", os.str());
}

void negative2() {
    std::ostringstream os;
    Rational r(9, -6);
    r.normalize();
    r.print(os);
    ASSERT_EQUAL("-3/2\n", os.str());
}

void negative3() {
    std::ostringstream os;
    Rational r(-9, -6);
    r.normalize();
    r.print(os);
    ASSERT_EQUAL("3/2\n", os.str());
}

void specialCase1() {
    std::ostringstream os;
    Rational r(0, -6);
    r.normalize();
    r.print(os);
    ASSERT_EQUAL("0/1\n", os.str());
}

void specialCase2() {
    ASSERT_THROWS(Rational(3, 0), invalid_argument);
}

void runSuite() {
    cute::suite s;
    s.push_back(CUTE(print));
    s.push_back(CUTE(normalize1));
    s.push_back(CUTE(normalize2));
    s.push_back(CUTE(normalize3));
    s.push_back(CUTE(normalize4));
    s.push_back(CUTE(negative1));
    s.push_back(CUTE(negative2));
    s.push_back(CUTE(negative3));
    s.push_back(CUTE(specialCase1));
    s.push_back(CUTE(specialCase2));
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
