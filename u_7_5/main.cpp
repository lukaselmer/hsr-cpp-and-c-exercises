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
ostream & operator<<(ostream& os, const vector<vector<T> > & v) {
    copy(v.begin(), v.end(), ostream_iterator<vector<T> > (os, "\n"));
    return os;
}

template < typename T >
T generateRational() {
    static int i = 0;
    return (T(1) / T(++i));
}

template < typename T >
vector<vector<T> > generateAndTransform(int up_to = 20) {
    vector<vector<T> > vv(3, vector<T>(up_to));
    generate(vv.at(0).begin(), vv.at(0).end(), generateRational<T>);
    transform(vv.at(0).begin(), vv.at(0).end(), vv.at(1).begin(), square<T>);
    transform(vv.at(0).begin(), vv.at(0).end(), vv.at(1).begin(), vv.at(2).begin(), product<T>);
    return vv;
}

int main(int argc, char** argv) {
    cout << generateAndTransform<Rational> () << endl;
    cout << generateAndTransform<int> () << endl;
}
