/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 3. April 2010, 22:28
 */

#include "Rational.h"

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template < typename T >
T square(const T& r) {
    return r * r;
}

template < typename T >
T product(const T& r1, const T& r2) {
    return r1 * r2;
}

template < typename T >
ostream & operator<<(ostream& os, const vector<T>& v) {
    copy(v.begin(), v.end(), ostream_iterator<T > (os, "\n"));
    return os;
}

template < typename T >
void generate(T(*f)(int)) {
    vector<T> v1, v2, v3;

    for (int i = 1; i <= 20; i++) {
        v1.push_back((*f)(i));
    }
    cout << v1 << endl;

    v2.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), square<T>);
    cout << v2 << endl;

    v3.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), product<T>);
    cout << v3 << endl;
}

template < typename T >
T constructRational(int i) {
    return T(1, i);
}

template < typename T >
T constructRationalDouble(int i) {
    return 1.0 / i;
}

int main(int argc, char** argv) {
    generate<Rational > (constructRational<Rational>);
    generate<double > (constructRationalDouble<double>);
}

