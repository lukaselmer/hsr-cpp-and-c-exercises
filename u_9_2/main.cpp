/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 29. April 2010, 10:43
 */

#include <iostream>
#include "Person.h"

using namespace std;

int main(int argc, char** argv) {
    Person* pMensch1 = new Person("Adam");
    Person mensch2("Eva");
    Person* pMensch3 = new Person("Abel", pMensch1, &mensch2);
    Person mensch4("Kain", pMensch1, &mensch2);
    Person mensch5("Seth", pMensch1, &mensch2);
    Person mensch6("Enosch", &mensch5, 0);

    cout << *pMensch1 << endl;
    cout << mensch2 << endl;
    cout << *pMensch3 << endl;
    cout << mensch4 << endl;
    cout << mensch5 << endl;

    delete pMensch3;
    cout << *pMensch1 << endl;
    delete pMensch1;
    cout << mensch4 << endl;
}

