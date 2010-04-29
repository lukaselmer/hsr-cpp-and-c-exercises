/* 
 * File:   Person.h
 * Author: Lukas Elmer
 *
 * Created on 29. April 2010, 10:44
 */

#ifndef _PERSON_H
#define	_PERSON_H

#include <iosfwd>
#include <vector>
#include <string>

class Person {
public:
    Person(const std::string & name, Person * dad = 0, Person * mom = 0);
    Person(const Person& orig);
    virtual ~Person();
    std::ostream& print(std::ostream & os) const;
    std::ostream& printName(std::ostream & os) const;
private:
    void addChild(Person* child);
    void removeChild(Person* child);
    void removeParent(Person* parent);
    std::vector<Person*> children;
    std::string name;
    Person * dad;
    Person * mom;
};

std::ostream & operator <<(std::ostream & os, Person const & person);

#endif	/* _PERSON_H */

