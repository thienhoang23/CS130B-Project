#ifndef ARRAY_OF_EDGES_UNIT_TEST_H_
#define ARRAY_OF_EDGES_UNIT_TEST_H_

#include "tddFuncs.h"
#include "ArrayofEdges.h"
#include "Weight.h"
#include "Edge.h"

void RunAllArrayOfEdgesUnitTest(){
	ArrayofEdges* AE = new ArrayofEdges(3);
	int arr1[2] = {3,5};
	int arr2[2] = {1,6};
	int arr3[2] = {10,10};
	weight* w1 = new weight(2, arr1);
	weight* w2 = new weight(2, arr2);
	weight* w3 = new weight(2, arr3);
	Edge* e1 = new Edge(0, 1, w1);
	Edge* e2 = new Edge(1, 2, w2);
	Edge* e3 = new Edge(0, 2, w3);
	AE->addEdge(e1);
	AE->addEdge(e2);
	AE->addEdge(e3);
	assertEquals("(0,1)(1,2)(0,2)", AE->toString(), "Array of Edges with 3 edges");
	assertEquals(3,AE->getCurrent(),"MAKE SURE addEdge is working correctly with current");
	assertEquals(3, AE->getNumE(), "Test of numE");
	assertEquals("(0,1)", AE->getEdgeAt(0).toString(), "TEST ON GETTING EDGE AT POSITION 0");
	assertEquals("(1,2)", AE->getEdgeAt(1).toString(), "TEST ON GETTING EDGE AT POSITION 1");
	assertEquals("(0,2)", AE->getEdgeAt(2).toString(), "TEST ON GETTING EDGE AT POSITION 2");
	assertEquals(true, AE->in(e1), "TEST ON in() function");
	AE->UpdateBestPossibleAddition();
	assertEquals(0, AE->getCurrent(), "Test Best Possible Addition");
	int arr4[2] = {5,1};
	weight* w4 = new weight(2,arr4);
	AE->Update(w4);
	assertEquals(1, AE->getCurrent(), "Correctly Reassing the Best Possible Addition");
	AE->remove(e2);
	assertEquals(false, AE->in(e2), "Detect edges not available");
	AE->UpdateBestPossibleAddition();
	assertEquals(0, AE->getCurrent(), "Correctly Reassign Current based on OFV");
}

#endif // !ARRAY_OF_EDGES_UNIT_TEST_H_