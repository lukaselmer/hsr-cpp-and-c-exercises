#ifndef GEOFOLGE_H
#define	GEOFOLGE_H

#include <boost/operators.hpp>

class GeoFolge : public boost::bidirectional_iterator_helper<GeoFolge, double> {
public:

    GeoFolge(value_type _base, int start_pos) : base(_base), exponent(1), current_value(_base) {
        if (exponent < start_pos) {
            while (exponent < start_pos) operator++();
        } else {
            while (exponent > start_pos) operator--();
        }
    }

    GeoFolge(int end) : base(0), exponent(end), current_value(0) {
    }

    GeoFolge & operator++() {
        ++exponent;
        current_value *= base;
        return *this;
    }

    GeoFolge & operator--() {
        --exponent;
        current_value /= base;
        return *this;
    }

    bool operator==(GeoFolge const& other) const {
        return exponent == other.exponent;
    }

    value_type operator*() const {
        return current_value;
    }
private:
    int exponent;
    value_type current_value;
    value_type base;
};

#endif	/* GEOFOLGE_H */

