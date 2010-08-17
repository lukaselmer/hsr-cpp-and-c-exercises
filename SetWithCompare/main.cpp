#include <set>
#include <iostream>
#include <boost/assign.hpp>
#include <iostream>

using namespace std;

struct CharCompare : public binary_function<char, char, bool> {
    result_type operator()(first_argument_type const& a,
            second_argument_type const& b) const {
        return tolower(a) < tolower(b);
    }
};

int main(int argc, char** argv) {
    set<char> s1;
    s1.insert('A');
    s1.insert('b');
    s1.insert('C');
    copy(s1.begin(), s1.end(), ostream_iterator<char>(cout, ""));
    cout << endl;
    set<char, CharCompare> s2;
    s2.insert('A');
    s2.insert('b');
    s2.insert('C');
    copy(s2.begin(), s2.end(), ostream_iterator<char>(cout, ""));
    cout << endl;
    return 0;
}

