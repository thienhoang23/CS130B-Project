#ifndef DISJOINT_SET_UNIT_TEST_H_
#define DISJOINT_SET_UNIT_TEST_H_

#include "DisjointSet.h"
#include "tddFuncs.h"
#include <string>

void DisjointSetTest1() {
	DisjointSet* DS1 = new DisjointSet(1);
	DisjointSet* DS2 = new DisjointSet(2);
	DisjointSet* DS3 = new DisjointSet(3);
	DisjointSet* DS4 = new DisjointSet(4);
	DisjointSet* DS5 = new DisjointSet(5);
	DisjointSet* DS6 = new DisjointSet(6);
	DS1->Union(*DS2);
	assertEquals(1, DS1->getHead()->getID(), "Union Smaller to Bigger: Test GetHead from the top");
	assertEquals(1, DS2->getHead()->getID(), "Union Smaller to Bigger: Test GetHead from the bottom");
	DS4->Union(*DS3);
	assertEquals(3, DS4->getHead()->getID(), "UNION FROM BIGGER TO SMALLER");
	DS3->Union(*DS2);
	assertEquals(1, DS3->getPointer()->getID(), "UNION 2 SETS OF SIZE BIGGER THAN 1");
	assertEquals(1, DS4->getPointer()->getID(), "POINTER FROM BOTTOM OF THE UNIONED SET");
	DS5->Union(*DS4);
	assertEquals(1, DS5->getPointer()->getID(), "UNION TO THE BOTTOM OF THE UNIONED SET");
	assertEquals(true, *DS5 == *DS1, "SAME SET COMPARISON 1");
	assertEquals(true, *DS1 == *DS1, "SAME SET COMPARISON 2");
	assertEquals(true, *DS2 == *DS3, "SAME SET COMPARISON 3");
	assertEquals(true, *DS5 == *DS3, "SAME SET COMPARISON 4");
	assertEquals(false, *DS6 == *DS1, "DIFFERENT SET COMPARISON");
}

void DisjointSetTest2() {
	DisjointSet* DS1 = new DisjointSet(1);
	DisjointSet* DS2 = new DisjointSet(2);
	DisjointSet* DS3 = new DisjointSet(3);
	DisjointSet* DS4 = new DisjointSet(4);
	DisjointSet* DS5 = new DisjointSet(5);
	DisjointSet* DS6 = new DisjointSet(6);
	DS4->Union(*DS5);
	DS4->Union(*DS6);
	DS2->Union(*DS3);
	DS1->Union(*DS2);
	DS1->Union(*DS4);
	cout << "MASSIVE UNION TEST" <<endl;
	assertEquals(1, DS2->getPointer()->getID(), "DS2 TEST");
	assertEquals(1, DS3->getPointer()->getID(), "DS3 TEST");
	assertEquals(1, DS4->getPointer()->getID(), "DS4 TEST");
	assertEquals(1, DS5->getPointer()->getID(), "DS5 TEST");
	assertEquals(1, DS6->getPointer()->getID(), "DS6 TEST");
	assertEquals(true, *DS2 == *DS6, "EQUAL FROM FAR DISTANCE");
}

void RunAllDisjoinSetUnitTest() {
	DisjointSetTest1();
	DisjointSetTest2();
}
#endif // !DISJOINT_SET_UNIT_TEST_H_