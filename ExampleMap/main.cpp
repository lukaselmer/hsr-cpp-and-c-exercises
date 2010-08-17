#include <map>
#include <string>
#include <iostream>
#include <iterator>
#include <sstream>
#include <bits/stl_function.h>

using namespace std;

template <typename _PairType1, typename _PairType2>
struct PairToString {
    string operator()(pair<_PairType1, _PairType2> p) {
        stringstream ss;
        ss << p.first << ": " << p.second;
        return ss.str();
    }
};

int main(int argc, char** argv) {
    map<string, int> highscores;
    highscores["luke"] = 999;
    highscores["hans"] = 323;
    highscores["root"] = 998;
    highscores.insert(make_pair("peter", 777)); // = highscores["peter"] = 777
    transform(highscores.begin(), highscores.end(),
            ostream_iterator<string > (cout, "\n"), PairToString<string, int>());
    return 0;
}

