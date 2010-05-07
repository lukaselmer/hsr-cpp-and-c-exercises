/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:42
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <boost/shared_ptr.hpp>
#include "Diamond.h"
#include "GardenPlan.h"
#include "Shape.h"
#include "Square.h"
#include "Ellipse.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "ShapePtr.h"

#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

using namespace std;
using namespace boost;

using namespace std;

void square() {
    Square s(3);
}

void rectangle() {
    Rectangle r(4, 9);
}

void triangle() {
    Triangle t(3, 6, 6.70820393);
}

void diamond() {
    Diamond d(4, 4, 60);
}

void circle() {
    Circle c(1);
}

void elipse() {
    Ellipse e(1, 2);
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
