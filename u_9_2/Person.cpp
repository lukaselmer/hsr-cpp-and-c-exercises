/* 
 * File:   Person.cpp
 * Author: Lukas Elmer
 * 
 * Created on 29. April 2010, 10:44
 */

#include "Person.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <boost/bind.hpp>
#include <boost/ref.hpp>

using namespace std;
using namespace boost;

Person::Person(const std::string & _name, Person * _dad, Person * _mom) : name(_name), dad(_dad), mom(_mom) {
    if (dad) (*dad).addChild(this);
    if (mom) (*mom).addChild(this);
}

Person::Person(const Person& orig) {
}

Person::~Person() {
    if (dad) dad->removeChild(this);
    if (mom) mom->removeChild(this);
    for_each(children.begin(), children.end(), bind(&Person::removeParent, _1, this));
}

void Person::addChild(Person* child) {
    children.push_back(child);
}

void Person::removeChild(Person* child) {
    children.erase(remove_if(children.begin(), children.end(), bind(equal_to<Person*>(), child, _1)), children.end());
}

void Person::removeParent(Person* parent) {
    if (parent == dad) dad = 0;
    if (parent == mom) mom = 0;
}

ostream& Person::printName(ostream & os) const {
    return os << name << ", ";
}

ostream& Person::print(ostream & os) const {
    os << "==============" << endl;
    os << "Person: " << name << endl;
    if (dad) os << "Dad: " << dad->name << endl;
    if (mom) os << "Mom: " << mom->name << endl;
    os << "Children: ";
    for_each(children.begin(), children.end(), bind(&Person::printName, _1, ref(os)));
    os << endl;
    os << "==============" << endl << endl;
}

ostream & operator <<(ostream & os, Person const & person) {
    person.print(os);
    return os;
}
