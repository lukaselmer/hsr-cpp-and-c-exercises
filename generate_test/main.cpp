/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 6. August 2010, 23:31
 */

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <boost/bind.hpp>

using namespace std;

struct UniqueNumber {
    int current;

    UniqueNumber(int cur = 0) : current(cur) {
    }

    int operator()() {
        return current++;
    }
};

int main(int argc, char** argv) {
    vector<int> vec;
    generate_n(back_inserter(vec), 20, UniqueNumber(10));

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, "\n"));
    remove_copy_if(vec.begin(), vec.end(),
            ostream_iterator<int>(cout, " ist ungerade\n"),
            !boost::bind(modulus<int>(), _1, 2));

    return 0;
}

