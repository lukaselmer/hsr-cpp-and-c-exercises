/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 10. August 2010, 17:30
 */

#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    vector<int>::iterator it(v.begin());
    cout << *it << endl;
    cout << *(++++it) << endl;
    cout << *it << endl;
    return 0;
}

