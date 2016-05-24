#ifndef EDGE_UNIT_TEST_H
#define EDGE_UNIT_TEST_H
#include <iostream>
#include <string>
#include "Weight.h"
#include "Edge.h"

void TestEdgeCompare() {
	int v1 = 0;
	int v2 = 1;
	int v3 = 2;
	int arr1[1] = { 1 };
	int arr2[1] = { 2 };
	weight w1 = weight(1, arr1);
	weight w2 = weight(1, arr2);
	Edge* e1 = new Edge(v1, v2, w1);
	Edge* e2 = new Edge(v1, v3, w1); //e1==e2
	Edge* e3 = new Edge(v2, v3, w2); //e3>e1 and e3>e2
	assertEquals(0, e1->compare(*e1), "e1==e1");
	assertEquals(0, e1->compare(*e2), "e1==e2");
	assertEquals(1, e3->compare(*e1), "e3>e1");
	assertEquals(-1, e1->compare(*e3), "e1<e3");
}

void RunAllEdgeUnitTests() {
	TestEdgeCompare();
}

#endif // !EDGE_UNIT_TEST_H