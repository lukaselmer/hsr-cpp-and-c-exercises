#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <boost/bind.hpp>
#include <string>

using namespace std;

template<typename T>
struct counterUp {
    typedef T result_type;

    result_type operator()() {
        return ++count;
    }

    counterUp(int n = 0) :
    count(n) {
    }
private:
    result_type count;
};

int main() {
    vector<int> negNumbers2;
    generate_n(back_inserter(negNumbers2), 21, counterUp<int> (-11));

    cout << endl;
    cout << " ========================" << endl;
    cout << "  Math.abs() by luke :-) " << endl;
    cout << " ========================" << endl << endl;
    cout << "Zahlen:" << endl;
    copy(negNumbers2.begin(), negNumbers2.end(), ostream_iterator<int> (cout, "\n"));

    /**
     * 1. orig > 0 ? => i -> 0, 1
     * 2. i *= 2
     * 3. i -= 1
     * 4. orig *= i
     **/
    transform(negNumbers2.begin(), negNumbers2.end(), negNumbers2.begin(), bind(multiplies<int>(), bind(minus<int>(), bind(multiplies<int>(), bind(less<int>(), 0, _1), 2), 1), _1));

    cout << endl << "Alle negative Zahlen wurden durch ihren Betrag ersetzt:" << endl;
    copy(negNumbers2.begin(), negNumbers2.end(), ostream_iterator<int> (cout, "\n"));
}
