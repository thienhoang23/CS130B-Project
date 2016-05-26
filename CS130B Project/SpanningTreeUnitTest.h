#ifndef SPANNING_TREE_UNIT_TEST_H_
#define SPANNING_TREE_UNIT_TEST_H_

#include "tddFuncs.h"
#include "SpanningTree.h"
#include "Edge.h"
#include "Weight.h"

void RunAllSpanningTreeUnitTests() {
	SpanningTree* ST = new SpanningTree(3,2);
	assertEquals("0->()\n1->()\n2->()", ST->toString(),"EMPTY SPANNING TREE");
	assertEquals(0, ST->getOFV(), "OFV OF AN EMPTY SPANNING TREE");
	assertEquals("(0,0)", ST->getWeight()->toString(), "WEIGHT OF AN EMPTY SPANNING TREE");
	int arr1[2] = { 1,1 };
	int arr2[2] = { 2,2 };
	int arr3[2] = { 1,2 };
	weight* w1 = new weight(2,arr1);
	weight* w2 = new weight(2,arr2);
	weight* w3 = new weight(2, arr3);
	ST->addEdges(0, 1, w1);
	assertEquals("0->(1)\n1->(0)\n2->()", ST->toString(),"INSERT ONE EDGE");
	ST->addEdges(0, 2, w2);
	assertEquals("0->(1,2)\n1->(0)\n2->(0)", ST->toString(), "INSERT 2 EDGES IN TOTAL");
	ST->addEdges(1, 2, w3);
	assertEquals("0->(1,2)\n1->(0,2)\n2->(0,1)", ST->toString(), "INSERT 3 EDGES IN TOTAL");
	assertEquals("(4,5)", ST->getWeight()->toString(), "WEIGHT AFTER INSERTED 3 EDGES");
	assertEquals(5, ST->getOFV(), "OFV AFTER INSERTED 3 EDGES");
	ST->removeEdge(0, 1);
	assertEquals("0->(2)\n1->(2)\n2->(0,1)", ST->toString(), "TEST REMOVE EDGES");
	assertEquals("(3,4)", ST->getWeight()->toString(), "WEIGHT AFTER 1 REMOVE");
	assertEquals(4, ST->getOFV(), "OFV AFTER 1 REMOVE");
}

#endif // !SPANNING_TREE_UNIT_TEST_H_