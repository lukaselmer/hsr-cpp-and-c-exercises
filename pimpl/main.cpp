/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 9. August 2010, 01:01
 */

#include <cstdlib>
#include "Cat.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    using namespace std;
    Cat theCat("Fritz");
    Cat otherCat = theCat;
    cout << theCat.getName() << endl;
    cout << otherCat.getName() << endl;
    otherCat.setName("Buubuu");
    cout << theCat.getName() << endl;
    cout << otherCat.getName() << endl;
    return 0;
}

/*
Fritz
Fritz
Buubuu
Buubuu
 */

