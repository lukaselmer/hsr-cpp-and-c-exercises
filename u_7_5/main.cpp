/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 3. April 2010, 16:28
 */

#include "Rational.h"

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <boost/bind.hpp>

using namespace std;

namespace std {

    /**
     * Has to be in std namespace because
     * template < typename T > ostream & operator<<(ostream& os, const vector<vector<T> > & v) - function
     * would not find this function
     **/
    template < typename T >
    ostream & operator<<(ostream& os, const vector<T>& v) {
        copy(v.begin(), v.end(), ostream_iterator<T > (os, "\n"));
        return os;
    }
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
    vector<vector<T> > vv(3, vector<T > (up_to)); // Init vv with 3 vectors
    generate(vv.at(0).begin(), vv.at(0).end(), generateRational<T>); // Fill the first vecotr (vv[i]; i==0) with rationals 1-<up_to>
    transform(vv.at(0).begin(), vv.at(0).end(), vv.at(1).begin(), boost::bind(multiplies<T > (), _1, _1)); // Fill the second vector with the square of each element of the first vector
    transform(vv.at(0).begin(), vv.at(0).end(), vv.at(1).begin(), vv.at(2).begin(), multiplies<T > ()); // Fill the second vector with the product of each element of the first and the second vector
    return vv;
}

int main(int argc, char** argv) {
    cout << generateAndTransform<Rational > () << endl;
    cout << generateAndTransform<double> () << endl;
}
