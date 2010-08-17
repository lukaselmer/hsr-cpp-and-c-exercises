/*
 * File:   newtestclass.cpp
 * Author: Lukas Elmer
 *
 * Created on 17.08.2010, 19:01:55
 */

#include "newtestclass.h"
#include "lru_list.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

void newtestclass::testBegin() {
    lru_list _lru_list;
    const_iterator result = _lru_list.begin();
    if(true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testContains() {
    const_reference e;
    lru_list _lru_list;
    bool result = _lru_list.contains(e);
    if(true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testEmpty() {
    lru_list _lru_list;
    bool result = _lru_list.empty();
    if(true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testEnd() {
    lru_list _lru_list;
    const_iterator result = _lru_list.end();
    if(true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testFront() {
    lru_list _lru_list;
    value_type result = _lru_list.front();
    if(true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testInsert() {
    const_reference e;
    lru_list _lru_list;
    _lru_list.insert(e);
    if(true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testSize() {
    lru_list _lru_list;
    size_type result = _lru_list.size();
    if(true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

