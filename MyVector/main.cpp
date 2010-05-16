/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 14. Mai 2010, 11:59
 */

#include <string>
#include <iostream>
#include <iterator>
#include <numeric>

#include "MyVector.h"

/*
 * 
 */
using namespace std;

template <typename T>
ostream & operator<<(ostream& os, const MyVector<T> & vec) {
    copy(vec.begin(), vec.end(), ostream_iterator<T > (os, "\n"));
    return os;
}

int main(int argc, char** argv) {
    cout << "=================" << endl;
    cout << "int vector exaple" << endl;
    cout << "=================" << endl;
    MyVector<int> v1;
    v1.push_back(10);
    v1.push_back(15);
    v1.push_back(2);
    cout << v1 << endl;
    cout << "Sum: " << accumulate(v1.begin(), v1.end(), 0, plus<int>()) << endl;
    cout << "Product: " << accumulate(v1.begin(), v1.end(), 1, multiplies<int>()) << endl;
    cout << "Avertage: " << accumulate(v1.begin(), v1.end(), 0, plus<int>()) / v1.size() << endl;
    cout << "Value at position 0 [1st element]: " << v1.at(0) << endl;
    cout << "Value at position 1 [2nd element]: " << v1.at(1) << endl;
    cout << "Value at position 2 [3rd element]: " << v1.at(2) << endl;
    cout << "Value at position -1 [last element]: " << v1.at(-1) << endl;
    cout << "Value at position -2 [2nd last element]: " << v1.at(-2) << endl;
    cout << "Value at position -3 [3rd last element]: " << v1.at(-3) << endl;
    cout << endl;

    cout << "====================" << endl;
    cout << "string vector exaple" << endl;
    cout << "====================" << endl;
    MyVector<string> v2;
    v2.push_back("Bli");
    v2.push_back("Bla");
    v2.push_back("Blub");
    cout << v2 << endl;
    cout << "Value at position 0 [1st element]: " << v1.at(0) << endl;
    cout << "Value at position 1 [2nd element]: " << v1.at(1) << endl;
    cout << "Value at position 2 [3rd element]: " << v1.at(2) << endl;
    cout << "Value at position -1 [last element]: " << v1.at(-1) << endl;
    cout << "Value at position -2 [2nd last element]: " << v1.at(-2) << endl;
    cout << "Value at position -3 [3rd last element]: " << v1.at(-3) << endl;
    cout << endl;

    return (EXIT_SUCCESS);
}

