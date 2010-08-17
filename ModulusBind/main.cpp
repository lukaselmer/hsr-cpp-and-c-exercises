/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 26. Juli 2010, 01:04
 */

#include <vector>
#include <string>
#include <algorithm>
#include <boost/assign.hpp>
#include <boost/bind.hpp>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    vector<int> v;
    using namespace boost::assign;
    v += 112, 43, 13, 36, 61, 34;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
    transform(v.begin(), v.end(), v.begin(), boost::bind(modulus<int>(), _1, 10));
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ","));
    cout << endl;
    return 0;
}

