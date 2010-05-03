/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 3. Mai 2010, 19:42
 */

#include <stdlib.h>
#include "Diamond.h"
#include "GardenPlan.h"
#include "Shape.h"
#include "ShapePtr.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"

using namespace std;

void printList(GardenPlan& plan, ostream& os) {
    plan.print(os);
}

int sumPegs(GardenPlan& plan) { // Pro Beet so viele Pflöcke wie die geometrische Figur (Shape) Ecken hat

    return 0;
}

double sum(GardenPlan& plan, double amount) {
    return 0;
}

double addSeeds() { // 0.1kg / Quadratmeter
    return 0.0;
}

double addRope() { // Pro Beet benötigen Sie ein Seil in der Länge des Umfangs (m)
    return 0.0;
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
    cout << "Seeds needed: " << sum(plan, addSeeds()) << " kg" << endl;
    cout << "Rope needed: " << sum(plan, addRope()) << " m" << endl;
}

