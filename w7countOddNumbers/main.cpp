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
    os << setw(10) << setprecision(2) << fixed << d << '\n';
}

int main(int argc, char** argv) {
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
    cout << count_if(v.begin(), v.end(), bind(equal_to<int>(), _1, 42)) << endl << endl;

    vector<double> v2;
    // Kopiert alle Werte von v in v2
    copy(v.begin(), v.end(), back_inserter(v2));
    // Ruft die Funktion printDoubles für alle doubles auf. Achtung: ref für den cout!
    for_each(v2.begin(), v2.end(), bind(printDoubles, ref(cout), _1));
    cout << endl;
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
            lexicographical_compare(tmp1.begin(), tmp1.end(), tmp2.begin(), tmp2.end()) << endl << endl;

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
    cout << endl << endl;

    //entfernden Sie aus einem vector<int> alle durch 7 teilbaren Zahlen. endgültig.
    //vector<int> v;
    vector<int> v3;
    v.clear();
    v.push_back(7);
    v.push_back(3);
    v.push_back(14);
    v.push_back(5);
    v.push_back(27);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    remove_copy_if(v.begin(), v.end(), back_inserter(v3), bind(equal_to<int>(), bind(modulus<int>(), _1, 7), 0));
    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, ", "));
    cout << endl << endl;

    //Geben Sie in einem vector<int> auf der Standardausgabe aus, ersetzen Sie dabei aber
    //alle negativen Zahlen mit 0. Die positiven Zahlen sollen unverändert bleiben.
    //Welchen Standardalgorithmus setzen Sie dafür ein? Gibt es weitere Alternativen?
    v.clear();
    v.push_back(10);
    v.push_back(15);
    v.push_back(-5);
    v.push_back(-27);
    v.push_back(18);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    transform(v.begin(), v.end(), v.begin(), bind(multiplies<int>(), bind(greater<int>(), _1, 0), _1));
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl << endl;


    // *  Ersetzen Sie in einem vector<int> alle negativen Werte durch ihren Absolutbetrag.
    v.clear();
    v.push_back(10);
    v.push_back(15);
    v.push_back(-5);
    v.push_back(-27);
    v.push_back(18);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    transform(v.begin(), v.end(), v.begin(), ::abs);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl << endl;
    //  o nutzen Sie ausschliesslich Standardfunktoren und Algorithmen, nicht die Funktion abs()
    v.clear();
    v.push_back(10);
    v.push_back(15);
    v.push_back(-5);
    v.push_back(-27);
    v.push_back(18);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    transform(v.begin(), v.end(), v.begin(), bind(multiplies<int>(), _1, bind(minus<int>(), bind(multiplies<int>(), bind(greater<int>(), _1, 0), 2), 1)));
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl << endl;

    //Mit welchem Algorithmus können Sie prüfen, ob ein vector sortiert ist?
    v.clear();
    v.push_back(10);
    v.push_back(15);
    v.push_back(-5);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    cout << "Sorted: " << (adjacent_find(v.begin(), v.end(), bind(greater<int>(), _1, _2)) == v.end()) << endl;
    v.clear();
    v.push_back(-4);
    v.push_back(3);
    v.push_back(10);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    cout << "Sorted: " << (adjacent_find(v.begin(), v.end(), bind(greater<int>(), _1, _2)) == v.end()) << endl;
    cout << endl << endl;

    // * Berechnen Sie aus einer liste von Werten (z.B. in einem vector<double>) eine Liste, die die Abstände zweier benachbarter Werte beinhaltet.
    v.clear();
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(10);
    v.push_back(20);
    v.push_back(10);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    adjacent_difference(v.begin(), v.end(), v.begin());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl << endl;

    // * Berechnen Sie aus einer Liste von Werten alle Teilsummen und geben Sie diese auf der Standardausgabe aus
    v.clear();
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(10);
    v.push_back(20);
    v.push_back(10);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    partial_sum(v.begin(), v.end(), v.begin());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl << endl;

    //  o statt Summen alle Teilprodukte
    v.clear();
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(10);
    v.push_back(20);
    v.push_back(10);
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    partial_sum(v.begin(), v.end(), v.begin(), multiplies<int>());
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl << endl;

    // Konstruieren Sie aus Standardfunktoren und bind einen Funktor, der folgenden Ausdruck berechnet (a,b,c sind Platzhalter für Parameter).
    // Vereinfachen Sie ggf. den Ausdruck vor der Umsetzung. Schreiben Sie auch je einen CUTE Test, der Ihren konstruierten Funktor mit
    // verschiedenen Werten für die Parameter prüft:
    // * a*a*42
    cout << bind(multiplies<int>(), 42, bind(multiplies<int>(), _1, _1))(1) << endl;
    cout << bind(multiplies<int>(), 42, bind(multiplies<int>(), _1, _1))(2) << endl;
    cout << bind(multiplies<int>(), 42, bind(multiplies<int>(), _1, _1))(3) << endl << endl;
    // * (a-42)/7
    cout << bind(divides<int>(), bind(minus<int>(), _1, 42), 7)(1) << endl << endl;
    // * (a%2)*a
    cout << bind(multiplies<int>(), _1, bind(modulus<int>(), _1, 2))(1) << endl << endl;

    //TODO...
    // * (a<b)&&(b<a)
    // * !(a > b) && !(b > a)
    // * (a-b)(a-b)
    // * c << a << ',' << b << '\n' // c ist ein ostream&!

    return 0;
}
