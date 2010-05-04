/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:42
 */

#include <iosfwd>
#include <vector>
#include <string>
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
#include "ShapePtr.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

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

int sumPegs(GardenPlan& plan) { // Pro Beet so viele Pflöcke wie die geometrische Figur (Shape) Ecken hat
    vector<int> results(plan.size());
    transform(plan.begin(), plan.end(), results.begin(), bind(&Shape::pegs, bind(&ShapePtr::operator*, _1)));
    return accumulate(results.begin(), results.end(), 0);
}

double sumSeeds(GardenPlan& plan) { // Pro Beet so viele Pflöcke wie die geometrische Figur (Shape) Ecken hat
    vector<double> results(plan.size());
    transform(plan.begin(), plan.end(), results.begin(), bind(&Shape::seeds, bind(&ShapePtr::operator*, _1)));
    return accumulate<vector<double>::iterator, double>(results.begin(), results.end(), 0);
}

double sumRopes(GardenPlan& plan) { // Pro Beet so viele Pflöcke wie die geometrische Figur (Shape) Ecken hat
    vector<double> results(plan.size());
    transform(plan.begin(), plan.end(), results.begin(), bind(&Shape::ropes, bind(&ShapePtr::operator*, _1)));
    return accumulate<vector<double>::iterator, double>(results.begin(), results.end(), 0);
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
    cout << "Pegs needed: " << sumPegs(plan) << endl;
    cout << "Seeds needed: " << sumSeeds(plan) << " kg" << endl;
    cout << "Rope needed: " << sumRopes(plan) << " m" << endl << endl;

    plan.push_back(ShapePtr(new Circle(4)));
    plan.push_back(ShapePtr(new Ellipse(3, 5)));
    printList(plan, cout);
    cout << "Pegs needed: " << sumPegs(plan) << endl;
    cout << "Seeds needed: " << sumSeeds(plan) << " kg" << endl;
    cout << "Rope needed: " << sumRopes(plan) << " m" << endl;

}


//double sum(GardenPlan& plan, double amount) {
//    vector<double> results(plan.size());
//    transform(plan.begin(), plan.end(), results.begin(), bind(&Shape::seeds(), bind(&ShapePtr::operator*, _1)));
//    return accumulate(results.begin(), results.end(), 0);
//}
//
//double addSeeds() { // 0.1kg / Quadratmeter
//    return 0.0;
//}
//
//double addRope() { // Pro Beet benötigen Sie ein Seil in der Länge des Umfangs (m)
//    return 0.0;
//}
