/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 14. Mai 2010, 14:48
 */

#include <stdlib.h>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <boost/bind.hpp>
#include <iterator>

using namespace std;

ostream & operator<<(ostream&os, const vector<string>&vec) {
    copy(vec.begin(), vec.end(), ostream_iterator<string > (os, "\n"));
    return os;
}

vector<string> split_spaces(string sentence) {
    vector<string> strings;
    boost::split(strings, sentence, boost::is_any_of(" "));
    return strings;
}

void make_variety(vector<string> & unordered_results, vector<string> & tmp_variety, string word) {
    unordered_results.push_back(boost::join(tmp_variety, " "));
    rotate(tmp_variety.begin(), tmp_variety.begin() + 1, tmp_variety.end());
}

void make_varieties(vector<string> & unordered_results, vector<string> initial_variety) {
    vector<string> tmp_variety = initial_variety;
    for_each(initial_variety.begin(), initial_variety.end(), bind(make_variety, boost::ref(unordered_results), boost::ref(tmp_variety), _1));
}

bool cmp_str(string a, string b) {
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    return a.compare(b) < 0;
}

int main(int argc, char** argv) {
    vector<string> vec;

    string line;
    while (getline(cin, line)) {
        if (line == "") break;
        vec.push_back(line);
    }

    vector<vector<string> > vv(vec.size());
    transform(vec.begin(), vec.end(), vv.begin(), split_spaces);

    vector<string> results;
    for_each(vv.begin(), vv.end(), bind(make_varieties, boost::ref(results), _1));

    sort(results.begin(), results.end(), cmp_str);
    cout << results << endl;

    return (EXIT_SUCCESS);
}
