/*
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:42
 */

#include <iostream>
#include <numeric>
#include <boost/bind.hpp>
#include "Diamond.h"
#include "GardenPlan.h"
#include "Shape.h"
#include "Square.h"
#include "Ellipse.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "ShapePtr.h"

using namespace std;

ostream& printList(GardenPlan const & plan, ostream& os) {
    vector<string> results(plan.size());
    transform(plan.begin(), plan.end(), results.begin(), bind(&Shape::toString, bind(&ShapePtr::operator*, _1)));
    copy(results.begin(), results.end(), ostream_iterator<string > (os, "\n"));
    return os;
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
typename F::value_type sum(GardenPlan const & plan, F x) {
    typename F::value_type init = 0;
    return accumulate(plan.begin(), plan.end(), init, x);
}

int main(int argc, char** argv) {
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
    cout << "Rope needed: " << sum(plan, addRope()) << " m" << endl << endl;
    plan.push_back(ShapePtr(new Circle(4)));
    plan.push_back(ShapePtr(new Ellipse(3, 5)));
    printList(plan, cout);
}
