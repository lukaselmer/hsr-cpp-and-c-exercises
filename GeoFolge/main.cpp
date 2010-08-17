#include "GeoFolge.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/bind.hpp>

using namespace std;
using namespace boost;

int main(int argc, char** argv) {
    // Speichere 0.5^0 - 0.5^20 ung gebe sie aus
    vector<double> v(GeoFolge(0.5, 0), GeoFolge(21));
    copy(v.begin(), v.end(), ostream_iterator<double>(cout, "\n"));

    // Speichere Kehrwerte
    vector<double> v2(v.size());
    transform(v.begin(), v.end(), v2.begin(), bind(divides<double>(), 1, _1));
    copy(v2.begin(), v2.end(), ostream_iterator<double>(cout, "\n"));

    // Multipliziere und gebe aus
    vector<double> v3(v.size());
    transform(v.begin(), v.end(), v2.begin(), v3.begin(), multiplies<double>());
    cout << fixed;
    cout.precision(1);
    copy(v3.begin(), v3.end(), ostream_iterator<double>(cout, "; "));
    return 0;
}

