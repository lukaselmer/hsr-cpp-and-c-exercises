#include <iostream>
#include <functional>

using namespace std;

struct AddOddNumber : binary_function<int, int, int> {
    //kurz: <first_argument_type, second_argument_type, result_type>
    //typedef int result_type; wird automatisch generiert
    //typedef int first_argument_type; wird automatisch generiert
    //typedef int second_argument_type; wird automatisch generiert

    result_type operator()(first_argument_type para1, second_argument_type para2) {
        if (para1 % 2)
            return para1 + para2;
        return para1;
    }
};

template<typename _Arg1, typename _Arg2, typename _Result>
struct AddOddThing : binary_function<_Arg1, _Arg2, _Result> {
    // re-establish traits !
    typedef typename binary_function<_Arg1, _Arg2, _Result>::result_type result_type;
    typedef typename binary_function<_Arg1, _Arg2, _Result>::first_argument_type first_argument_type;
    typedef typename binary_function<_Arg1, _Arg2, _Result>::second_argument_type second_argument_type;

    result_type operator()(first_argument_type para1, second_argument_type para2) {
        if (para1 % 2)
            return para1 + para2;
        return para1;
    }
};

struct IsEvenNumber : unary_function<int, bool> {
    //typedef bool result_type; automatisch gneriert
    //typedef int argument_type; automatisch gneriert
    result_type operator()(argument_type para1) {
        return !(para1 % 2);
    }
};

int main(int argc, char** argv) {
    IsEvenNumber isEven;
    //cout << a.result_type;
    cout << boolalpha << isEven(1) << endl;
    cout << boolalpha << isEven(2) << endl;
    cout << boolalpha << isEven(3) << endl;
    cout << boolalpha << isEven(4) << endl;
    
    AddOddNumber a;
    //cout << a.result_type;
    cout << a(1, 1) << endl;
    cout << a(2, 1) << endl;
    cout << a(3, 1) << endl;
    cout << a(4, 1) << endl;
    return 0;
}

