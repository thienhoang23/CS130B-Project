#ifndef SPANNING_TREE_UNIT_TEST_H_
#define SPANNING_TREE_UNIT_TEST_H_

#include "tddFuncs.h"
#include "SpanningTree.h"
#include "Edge.h"
#include "Weight.h"

void RunAllSpanningTreeUnitTests() {
	SpanningTree* ST = new SpanningTree(3,2);
	assertEquals("1->()\n2->()\n3->()", ST->toString(),"EMPTY SPANNING TREE");
	assertEquals(0, ST->getOFV(), "OFV OF AN EMPTY SPANNING TREE");
	assertEquals("(0,0)", ST->getWeight()->toString(), "WEIGHT OF AN EMPTY SPANNING TREE");
	int arr1[2] = { 1,1 };
	int arr2[2] = { 2,2 };
	int arr3[2] = { 1,2 };
	weight* w1 = new weight(2,arr1);
	weight* w2 = new weight(2,arr2);
	weight* w3 = new weight(2, arr3);
	ST->addEdges(1, 2, w1);
	assertEquals("1->(2)\n2->(1)\n3->()", ST->toString(),"INSERT ONE EDGE");
	ST->addEdges(1, 3, w2);
	assertEquals("1->(2,3)\n2->(1)\n3->(1)", ST->toString(), "INSERT 2 EDGES IN TOTAL");
	ST->addEdges(2, 3, w3);
	assertEquals("1->(2,3)\n2->(1,3)\n3->(1,2)", ST->toString(), "INSERT 3 EDGES IN TOTAL");
	assertEquals("(4,5)", ST->getWeight()->toString(), "WEIGHT AFTER INSERTED 3 EDGES");
	assertEquals(5, ST->getOFV(), "OFV AFTER INSERTED 3 EDGES");
	ST->removeEdge(1, 2);
	assertEquals("1->(3)\n2->(3)\n3->(1,2)", ST->toString(), "TEST REMOVE EDGES");
	assertEquals("(3,4)", ST->getWeight()->toString(), "WEIGHT AFTER 1 REMOVE");
	assertEquals(4, ST->getOFV(), "OFV AFTER 1 REMOVE");
}

#endif // !SPANNING_TREE_UNIT_TEST_H_