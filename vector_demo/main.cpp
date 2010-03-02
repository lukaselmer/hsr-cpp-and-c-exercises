/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 2. März 2010, 08:31
 */

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

/*
 * 
 */
int main(int argc, char** argv) {
    using namespace std;

    typedef double element;

    
    //element myints[] = {-31e2, 2, 77, 29.14};
    //vector<element> v(myints, myints + sizeof (myints) / sizeof (element));
    vector<element> v;
    cout << endl;
    cout << endl;

    copy(istream_iterator<element>(cin), istream_iterator<element>(), back_inserter(v));
    
    cout << endl;

    copy(v.begin(), v.end(), ostream_iterator<element > (cout, ", "));
    cout << endl;

    copy(v.rbegin(), v.rend(), ostream_iterator<element > (cout, ", "));


    cout << v.size() << " Elemente" << endl;
    //    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    //        cout << *it << endl;
    //    }
    cout << endl;
    cout << endl;

}

