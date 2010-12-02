#include <iostream> //fÃ¼r Ausgabe
#include <algorithm> //for_each, copy, remove_if, etc...
#include <vector> //fÃ¼r vector
#include <functional> //fÃ¼r unary-/binary_function, operator klassen (plus, minus, multiplies, equal_to...)
#include <tr1/functional> //fÃ¼r function<>
#include <boost/operators.hpp> //fÃ¼r iterator_helpers
//#include <boost/bind.hpp>

using namespace std;
using namespace tr1;
using namespace placeholders;

struct counting_iterator : boost::forward_iterator_helper<counting_iterator, int> {

    counting_iterator(value_type i) :
    counter(i) {
    }

    value_type operator*() const {
        return counter;
    }

    counting_iterator & operator++() {
        ++counter;
        return *this;
    }

    bool operator==(counting_iterator const &other) const {
        return this->counter == other.counter;
    }

private:
    value_type counter;

};

struct FibIter : boost::input_iterator_helper<FibIter, unsigned long long> {

    FibIter(value_type n = 0) :
    counter(0), fib0(0), fib1(1) {
        for (value_type i = 0; i < n; ++i) {
            operator++();
        }
    }

    value_type operator*() const {
        return fib0;
    }

    FibIter & operator++() {
        ++counter;
        value_type result = fib0 + fib1;
        fib0 = fib1;
        fib1 = result;
        return *this;
    }

    bool operator==(FibIter const &other) const {
        return this->counter == other.counter;
    }

private:
    value_type counter;
    value_type fib0, fib1;
};

//is_prime als Function

bool is_prime(int number) {
    counting_iterator anfang(2);
    counting_iterator ende(number);

    function<bool(int) > modNumber = bind(modulus<int> (), number, _1);
    return (count_if(anfang, ende, modNumber) - (number - 2));
}

//is_prime als Funktor

struct is_prime2 : unary_function<bool, int> {
};

int main(int argc, char * const argv[]) {
    counting_iterator anfang(2);
    counting_iterator ende(100);
    ostream_iterator<int> output(cout, ", ");

    //Alle primezahlen ausgeben
    remove_copy_if(anfang, ende, output, is_prime);

    FibIter fibA(1);
    FibIter fibE(10);

    //Finde erste durch 17 teilbare Fibonacci zahl durch iterieren
    //function<> um festzulegen, welche Parameter und RÃ¼ckgabewerte eine Funktion verwendet.
    //Sehr praktisch bei bind, da bei 'bind' Parameter und RÃ¼ckgabewert nicht bekannt.
    function<bool(unsigned long long) > f = bind(logical_not< unsigned long long> (), bind(modulus<unsigned long long> (), _1, 17));

    FibIter found = find_if(fibA, fibE, f);

    cout << "\n" << *found << endl; //34


    vector<int> vec;
    vec.push_back(1);
    vec.push_back(21);
    vec.push_back(32);
    vec.push_back(17);
    vec.push_back(12);

    ostream_iterator<int> outputIt(cout, ", ");

    counting_iterator anfang2(2);
    counting_iterator ende2(100);

    //Geht nicht!
    remove_copy_if(anfang2, ende2, outputIt, (function<bool(int) >) bind(modulus<int> (), 17, _1));
}
