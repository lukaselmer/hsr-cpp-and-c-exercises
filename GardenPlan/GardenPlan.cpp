/* 
 * File:   GardenPlan.cpp
 * Author: Lukas Elmer
 * 
 * Created on 3. Mai 2010, 19:43
 */

#include "GardenPlan.h"

using namespace std;

GardenPlan::GardenPlan() {
}

GardenPlan::GardenPlan(const GardenPlan& orig) {
}

GardenPlan::~GardenPlan() {
}

ostream& GardenPlan::print(ostream& os) {
    vector<string> results(size());
    transform(begin(), end(), results.begin(), bind(&Shape::toString, bind(&ShapePtr::operator*, _1)));
    copy(results.begin(), results.end(), ostream_iterator<string>(os, "\n"));
    return os;
}
