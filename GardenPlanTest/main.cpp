/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:42
 */

#include <vector>
#include "Diamond.h"
#include "GardenPlan.h"
#include "Shape.h"
#include "Square.h"
#include "Ellipse.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

using namespace std;
using namespace boost;

void square() {
    Square s(3);
    //printf("\n%.18f\n\n", d.surface());
    ASSERT_EQUAL(9.0, s.surface());
    ASSERT_EQUAL(0.9, s.seeds());
    ASSERT_EQUAL(4, s.pegs());
    ASSERT_EQUAL(12.0, s.ropes());
}

void rectangle() {
    Rectangle r(4, 9);
    ASSERT_EQUAL(36.0, r.surface());
    ASSERT_EQUAL(3.6, r.seeds());
    ASSERT_EQUAL(4, r.pegs());
    ASSERT_EQUAL(26.0, r.ropes());
}

void triangle() {
    Triangle t(3, 6, 6.70820393);
    ASSERT_EQUAL(9.0, t.surface());
    ASSERT_EQUAL(0.9, t.seeds());
    ASSERT_EQUAL(3, t.pegs());
    ASSERT_EQUAL(15.70820393, t.ropes());
}

void diamond() {
    Diamond d(4, 4, 60);
    ASSERT_EQUAL(13.856406460551018, d.surface());
    ASSERT_EQUAL(1.3856406460551018, d.seeds());
    ASSERT_EQUAL(4, d.pegs());
    ASSERT_EQUAL(16.0, d.ropes());
}

void circle() {
    Circle c(1);
    ASSERT_EQUAL(3.1415926535897931, c.surface());
    ASSERT_EQUAL(0.31415926535897931, c.seeds());
    ASSERT_EQUAL(2, c.pegs());
    ASSERT_EQUAL(6.283185307179586200, c.ropes());
}

void elipse() {
    Ellipse e(1, 2);
    ASSERT_EQUAL(6.2831853071795862, e.surface());
    ASSERT_EQUAL(0.628318530717958620, e.seeds());
    ASSERT_EQUAL(2, e.pegs());
    ASSERT_EQUAL(9.688448216130083800, e.ropes());
}

int main(int argc, char** argv) {
    cout << "==========================" << endl;
    cout << "Starting garden plan tests" << endl;
    cout << "==========================" << endl << endl;

    cute::suite s;
    s.push_back(CUTE(square));
    s.push_back(CUTE(rectangle));
    s.push_back(CUTE(triangle));
    s.push_back(CUTE(diamond));
    s.push_back(CUTE(circle));
    s.push_back(CUTE(elipse));
    cute::ide_listener lis;
    cute::makeRunner(lis)(s, "GardenPlan tests:");

    cout << endl << "=====" << endl;
    cout << "Done!" << endl;
    cout << "=====" << endl << endl;

    return 0;
}
