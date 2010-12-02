/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 10. August 2010, 15:30
 */

#include <iostream>

using namespace std;

struct A {

    virtual void f() {
        cout << "A" << endl;
    }
};

struct B : A {

    void f() {
        cout << "B" << endl;
    }
};

struct C : B {

    void f() {
        cout << "C" << endl;
    }
};

struct D : C {

    void f() {
        cout << "D" << endl;
    }
};

int main(int argc, char** argv) {
    D d;
    C &c = d;
    B &b = d;
    A &a = d;
    a.f();
    b.f();
    c.f();
    d.f();

    return 0;
}














