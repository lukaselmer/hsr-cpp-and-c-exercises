/* 
 * File:   Main.cpp
 * Author: Lukas Elmer
 *
 * Created on 11. März 2010, 12:50
 */
#include <boost/assign/list_inserter.hpp> // for 'insert()'
#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/assert.hpp>
#include <stdlib.h>
#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using namespace boost::assign; // bring 'insert()' into scope

using namespace std;

int main(int argc, char** argv) {
    typedef char type;
    map<char, int> m; // = map_list_of('a', 0) ('e', 0) ('i', 0)('o', 0) ('u', 0);

    while (cin) {
        char c = getchar();
        if (c == '.')
            break;
        if (m.count(c) > 0) {

        }

    }
    //cout << count(istream_iterator<type>(cin), istream_iterator<type>(), 'a') endl;


    return (EXIT_SUCCESS);
}

