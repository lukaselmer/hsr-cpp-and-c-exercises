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

#include "RubyVector.h"

#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

using namespace std;

template <typename T>
ostream & operator<<(ostream& os, const RubyVector<T> & vec) {
    copy(vec.begin(), vec.end(), ostream_iterator<T > (os, "\n"));
    return os;
}

void push_backs() {
    RubyVector<int> a;
    ASSERT_EQUAL(0, a.size());

    a.push_back(10);
    ASSERT_EQUAL(1, a.size());
    ASSERT_EQUAL(10, a.at(0));

    a.push_back(25);
    ASSERT_EQUAL(2, a.size());
    ASSERT_EQUAL(25, a.at(1));

    a.push_back(33);
    ASSERT_EQUAL(3, a.size());
    ASSERT_EQUAL(33, a.at(2));
}

void indexes1() {
    RubyVector<int> a;
    ASSERT_EQUAL(0, a.size());

    a.push_back(10);
    a.push_back(25);
    a.push_back(33);

    ASSERT_EQUAL(3, a.size());

    ASSERT_EQUAL(10, a.at(0));
    ASSERT_EQUAL(25, a.at(1));
    ASSERT_EQUAL(33, a.at(2));
    ASSERT_EQUAL(10, a.at(-3));
    ASSERT_EQUAL(25, a.at(-2));
    ASSERT_EQUAL(33, a.at(-1));

    ASSERT_EQUAL(10, a[0]);
    ASSERT_EQUAL(25, a[1]);
    ASSERT_EQUAL(33, a[2]);
    ASSERT_EQUAL(10, a[-3]);
    ASSERT_EQUAL(25, a[-2]);
    ASSERT_EQUAL(33, a[-1]);

    ASSERT_THROWS(a[3], out_of_range);
    ASSERT_THROWS(a[-4], out_of_range);
    ASSERT_THROWS(a.at(3), out_of_range);
    ASSERT_THROWS(a.at(-4), out_of_range);
}

void indexes2() {
    RubyVector<string> vec;
    ASSERT_EQUAL(0, vec.size());

    const string a = "bli", b = "bla", c = "blub";

    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);

    ASSERT_EQUAL(3, vec.size());

    ASSERT_EQUAL(a, vec.at(0));
    ASSERT_EQUAL(b, vec.at(1));
    ASSERT_EQUAL(c, vec.at(2));
    ASSERT_EQUAL(a, vec.at(-3));
    ASSERT_EQUAL(b, vec.at(-2));
    ASSERT_EQUAL(c, vec.at(-1));

    ASSERT_EQUAL(a, vec[0]);
    ASSERT_EQUAL(b, vec[1]);
    ASSERT_EQUAL(c, vec[2]);
    ASSERT_EQUAL(a, vec[-3]);
    ASSERT_EQUAL(b, vec[-2]);
    ASSERT_EQUAL(c, vec[-1]);

    ASSERT_THROWS(vec[3], out_of_range);
    ASSERT_THROWS(vec[-4], out_of_range);
    ASSERT_THROWS(vec.at(3), out_of_range);
    ASSERT_THROWS(vec.at(-4), out_of_range);

    //Const vector
    RubyVector<string> const & vec2 = vec;

    ASSERT_EQUAL(3, vec2.size());

    ASSERT_EQUAL(a, vec2.at(0));
    ASSERT_EQUAL(b, vec2.at(1));
    ASSERT_EQUAL(c, vec2.at(2));
    ASSERT_EQUAL(a, vec2.at(-3));
    ASSERT_EQUAL(b, vec2.at(-2));
    ASSERT_EQUAL(c, vec2.at(-1));

    ASSERT_EQUAL(a, vec2[0]);
    ASSERT_EQUAL(b, vec2[1]);
    ASSERT_EQUAL(c, vec2[2]);
    ASSERT_EQUAL(a, vec2[-3]);
    ASSERT_EQUAL(b, vec2[-2]);
    ASSERT_EQUAL(c, vec2[-1]);

    ASSERT_THROWS(vec2[3], out_of_range);
    ASSERT_THROWS(vec2[-4], out_of_range);
    ASSERT_THROWS(vec2.at(3), out_of_range);
    ASSERT_THROWS(vec2.at(-4), out_of_range);
}

void begin_end() {
    RubyVector<int> vec;
    ASSERT_EQUAL(0, accumulate(vec.begin(), vec.end(), 0, plus<int>()));
    vec.push_back(10);
    ASSERT_EQUAL(10, *(vec.end() - 1));
    ASSERT_EQUAL(10, *vec.begin());
    ASSERT_EQUAL(10, accumulate(vec.begin(), vec.end(), 0, plus<int>()));
    vec.push_back(15);
    ASSERT_EQUAL(25, accumulate(vec.begin(), vec.end(), 0, plus<int>()));
    vec.push_back(2);
    ASSERT_EQUAL(27, accumulate(vec.begin(), vec.end(), 0, plus<int>()));
    vec.push_back(-26);
    ASSERT_EQUAL(1, accumulate(vec.begin(), vec.end(), 0, plus<int>()));
    vec.push_back(-2);
    ASSERT_EQUAL(-1, accumulate(vec.begin(), vec.end(), 0, plus<int>()));
    vec.push_back(1);
    ASSERT_EQUAL(1, *(vec.end() - 1));
    ASSERT_EQUAL(0, accumulate(vec.begin(), vec.end(), 0, plus<int>()));
    vec.pop_back();
    ASSERT_EQUAL(-1, accumulate(vec.begin(), vec.end(), 0, plus<int>()));
    ASSERT_EQUAL(-2, *(vec.end() - 1));
    ASSERT_EQUAL(10, *vec.begin());
}

void iterator_constructor() {
    vector<int> normal_vector;
    normal_vector.push_back(42);
    normal_vector.push_back(27);
    normal_vector.push_back(33);
    normal_vector.push_back(11);
    RubyVector<int> vec(normal_vector.begin(), normal_vector.end());
    ASSERT_EQUAL(4, vec.size());
    ASSERT_EQUAL(42, vec.at(0));
    ASSERT_EQUAL(27, vec.at(1));
    ASSERT_EQUAL(33, vec.at(2));
    ASSERT_EQUAL(11, vec.at(3));
}

int main(int argc, char** argv) {
    cout << "==========================" << endl;
    cout << "Starting ruby vector tests" << endl;
    cout << "==========================" << endl << endl;

    cute::suite s;
    s.push_back(CUTE(push_backs));
    s.push_back(CUTE(indexes1));
    s.push_back(CUTE(indexes2));
    s.push_back(CUTE(begin_end));
    s.push_back(CUTE(iterator_constructor));
    cute::ide_listener lis;
    cute::makeRunner(lis)(s, "GardenPlan tests:");

    cout << endl << "=====" << endl;
    cout << "Done!" << endl;
    cout << "=====" << endl << endl;

    return (EXIT_SUCCESS);
}

//int main(int argc, char** argv) {
//    cout << "=================" << endl;
//    cout << "int vector exaple" << endl;
//    cout << "=================" << endl;
//    RubyVector<int> v1;
//    v1.push_back(10);
//    v1.push_back(15);
//    v1.push_back(2);
//    cout << v1 << endl;
//    cout << "Sum: " << accumulate(v1.begin(), v1.end(), 0, plus<int>()) << endl;
//    cout << "Product: " << accumulate(v1.begin(), v1.end(), 1, multiplies<int>()) << endl;
//    cout << "Avertage: " << accumulate(v1.begin(), v1.end(), 0, plus<int>()) / v1.size() << endl;
//    cout << "Value at position 0 [1st element]: " << v1.at(0) << endl;
//    cout << "Value at position 1 [2nd element]: " << v1.at(1) << endl;
//    cout << "Value at position 2 [3rd element]: " << v1.at(2) << endl;
//    cout << "Value at position -1 [last element]: " << v1.at(-1) << endl;
//    cout << "Value at position -2 [2nd last element]: " << v1.at(-2) << endl;
//    cout << "Value at position -3 [3rd last element]: " << v1.at(-3) << endl;
//    cout << endl;
//
//    cout << "====================" << endl;
//    cout << "string vector exaple" << endl;
//    cout << "====================" << endl;
//    RubyVector<string> v2;
//    v2.push_back("Bli");
//    v2.push_back("Bla");
//    v2.push_back("Blub");
//    cout << v2 << endl;
//    cout << "Value at position 0 [1st element]: " << v1.at(0) << endl;
//    cout << "Value at position 1 [2nd element]: " << v1.at(1) << endl;
//    cout << "Value at position 2 [3rd element]: " << v1.at(2) << endl;
//    cout << "Value at position -1 [last element]: " << v1.at(-1) << endl;
//    cout << "Value at position -2 [2nd last element]: " << v1.at(-2) << endl;
//    cout << "Value at position -3 [3rd last element]: " << v1.at(-3) << endl;
//    cout << endl;
//
//    return (EXIT_SUCCESS);
//}

