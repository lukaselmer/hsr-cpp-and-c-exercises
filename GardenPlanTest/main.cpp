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
#include "tests.h"

using namespace std;
using namespace boost;

void printList(GardenPlan& plan, ostream& os) {
    plan.print(os);
}

int getPegs(ShapePtr& shapePtr) {
    return (*shapePtr).pegs();
}

void printPegs(ShapePtr& shapePtr) {
    cout << getPegs(shapePtr) << endl;
}

struct addPegs {
    typedef int value_type;

    value_type operator()(value_type i, ShapePtr ptr) {
        return i + ptr->pegs();
    }
};

struct addSeeds {
    typedef double value_type;

    value_type operator()(value_type i, ShapePtr ptr) {
        return i + ptr->seeds();
    }
};

struct addRope {
    typedef double value_type;

    value_type operator()(value_type i, ShapePtr ptr) {
        return i + ptr->ropes();
    }
};

template< class F >
typename F::value_type sum(GardenPlan& plan, F x) {
    typename F::value_type init = 0;
    return accumulate(plan.begin(), plan.end(), init, x);
}

void runGardenPlan() {
    GardenPlan plan;
    plan.push_back(ShapePtr(new Triangle(3, 6, 6.70820393)));
    plan.push_back(ShapePtr(new Triangle(3, 4, 4)));
    plan.push_back(ShapePtr(new Triangle(3, 4, 4)));
    plan.push_back(ShapePtr(new Diamond(4, 4, 60)));
    plan.push_back(ShapePtr(new Square(3)));
    plan.push_back(ShapePtr(new Square(3)));
    plan.push_back(ShapePtr(new Rectangle(4, 9)));
    printList(plan, cout);
    cout << "Pegs needed: " << sum(plan, addPegs()) << endl;
    cout << "Seeds needed: " << sum(plan, addSeeds()) << " kg" << endl;
    cout << "Rope needed: " << sum(plan, addRope()) << " m" << endl;
    plan.push_back(ShapePtr(new Circle(4)));
    plan.push_back(ShapePtr(new Ellipse(3, 5)));
    printList(plan, cout);
}

int main(int argc, char** argv) {
    //runGardenPlan();
    runTests();
}
