/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 30. Juli 2010, 12:12
 */

#include <vector>
#include <iostream>
#include <numeric>
#include <functional>
#include <iomanip>
#include <iterator>
#include <string>

#include <boost/bind.hpp>
using namespace std;

void printDoubles(std::ostream &os, double const &d) {
    using namespace std;
    os << setw(10) << setprecision(2) << fixed << d << '\n';
}

int main(int argc, char** argv) {
    using namespace std;
    using namespace boost;
    vector<int> v;
    v.push_back(10);
    v.push_back(8);
    v.push_back(12);
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);

    // summiert alle zahlen
    cout << accumulate(v.begin(), v.end(), 0, plus<int>()) << endl;
    // sum + (i*(i%2)), Summiert alle ungerade Zahlen
    cout << accumulate(v.begin(), v.end(), 0, bind(plus<int>(), _1, bind(multiplies<int>(), bind(modulus<int>(), _2, 2), _2))) << endl;
    // Zählt die Anzahl der ungeraden Zahlen
    cout << accumulate(v.begin(), v.end(), 0, bind(plus<int>(), _1, bind(modulus<int>(), _2, 2))) << endl;
    cout << count_if(v.begin(), v.end(), bind(modulus<int>(), _1, 2)) << endl;
    // Zählt die Anzahl der Zahlen mit Wert 42
    cout << count_if(v.begin(), v.end(), bind(equal_to<int>(), _1, 42)) << endl;

    vector<double> v2;
    // Kopiert alle Werte von v in v2
    copy(v.begin(), v.end(), back_inserter(v2));
    // Ruft die Funktion printDoubles für alle doubles auf. Achtung: ref für den cout!
    for_each(v2.begin(), v2.end(), bind(printDoubles, ref(cout), _1));

    // vergleichen Sie zwei strings lexikographisch, ohne gross/kleinschreibung zu unterscheiden.
    string s1 = "bla", s2 = "blu";
    cout << s1 << " < " << s2 << "? " << lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()) << endl;
    s1 = "bla", s2 = "Blu";
    cout << s1 << " < " << s2 << "? (mit gross/kleinschreibung) " <<
            lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end()) << endl;
    string tmp1 = s1, tmp2 = s2;
    transform(tmp1.begin(), tmp1.end(), tmp1.begin(), ::tolower);
    transform(tmp2.begin(), tmp2.end(), tmp2.begin(), ::tolower);
    cout << s1 << " < " << s2 << "? (ohne gross/kleinschreibung) " <<
            lexicographical_compare(tmp1.begin(), tmp1.end(), tmp2.begin(), tmp2.end()) << endl;

    //suchen Sie in einem std::string nach aufeinanderfolgenden gleichen Zeichen
    //    * Nutzen Sie einen passenden Algorithmus!
    //    * geben Sie alle solche Positionen des std::string aus (braucht eine Schleife)
    // output: auee
    string s3("blaabluueeez");
    string::iterator it = adjacent_find(s3.begin(), s3.end());
    while (*it != *s3.end()) {
        cout << *it;
        it++;
        it = adjacent_find(it, s3.end());
    }
    cout << endl;

    //entfernden Sie aus einem vector<int> alle durch 7 teilbaren Zahlen. endgültig.
    //vector<int> v;
    vector<int> v3;
    v.clear();
    v.push_back(7);
    v.push_back(77);
    v.push_back(14);
    v.push_back(10);
    v.push_back(1);
    v.push_back(3);
    v.push_back(14);
    v.push_back(5);
    v.push_back(27);

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    remove_copy_if(v.begin(), v.end(), back_inserter(v3), bind(equal_to<int>(), bind(modulus<int>(), _1, 7), 0));
    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;

    return 0;
}
