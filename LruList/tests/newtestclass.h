/*
 * File:   newtestclass.h
 * Author: Lukas Elmer
 *
 * Created on 17.08.2010, 19:01:56
 */

#ifndef NEWTESTCLASS_H
#define	NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(testBegin);
    CPPUNIT_TEST(testContains);
    CPPUNIT_TEST(testEmpty);
    CPPUNIT_TEST(testEnd);
    CPPUNIT_TEST(testFront);
    CPPUNIT_TEST(testInsert);
    CPPUNIT_TEST(testSize);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void testBegin();
    void testContains();
    void testEmpty();
    void testEnd();
    void testFront();
    void testInsert();
    void testSize();

};

#endif	/* NEWTESTCLASS_H */

