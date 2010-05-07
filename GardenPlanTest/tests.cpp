
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

#include <iostream>
#include <string>

namespace tests {

    using namespace std;

    void rectangle() {
    }

    void square() {
    }

    void triangle() {
    }

    void circle() {
    }

    void elipse() {
    }

    void diamond() {
    }

    void runTests() {
        cout << "==========================" << endl;
        cout << "Starting garden plan tests" << endl;
        cout << "==========================" << endl << endl;

        cute::suite s;
        s.push_back(CUTE(rectangle));
        s.push_back(CUTE(square));
        s.push_back(CUTE(triangle));
        s.push_back(CUTE(circle));
        s.push_back(CUTE(elipse));
        s.push_back(CUTE(diamond));
        cute::ide_listener lis;
        cute::makeRunner(lis)(s, "Rational tests:");

        cout << endl << "=====" << endl;
        cout << "Done!" << endl;
        cout << "=====" << endl << endl;
    }
}
