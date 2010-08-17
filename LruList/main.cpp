#include "lru_list.h"
#include <iostream>
#include <iterator>

using namespace std;

int main(int argc, char** argv) {
    lru_list<double> l;
    l.insert(4);
    l.insert(77);
    l.insert(45);
    l.insert(42);
    l.insert(77);
    // 77, 42, 45, 4
    copy(l.begin(), l.end(), ostream_iterator<double>(cout, ", "));
    cout << endl << boolalpha << l.contains(77) << endl;
    cout << boolalpha << l.contains(333) << endl;
    vector<int> vec = l.asVector<int>();
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ", "));
    return 0;
}

