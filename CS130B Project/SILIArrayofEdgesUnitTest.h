#ifndef SILI_ARRAY_OF_EDGES_TEST_H
#define SILI_ARRAY_OF_EDGES_TEST_H

#include "SILIArrayofEdges.h"
#include "tddFuncs.h"
#include "Edge.h"
#include "DisjointSet.h"
#include "DisjointSetArray.h"
#include "Weight.h"
void RunAllSILIArrayOfEdgesUnitTest() {
	DisjointSetArray* DSA = new DisjointSetArray(5);
	SILIArrayofEdges* SAE = new SILIArrayofEdges(10);
	int arr[1] = { 1 };
	weight* w = new weight(1, arr);
	
	Edge* e1 = new Edge(1, 2, w);
	Edge* e2 = new Edge(1, 3, w);
	Edge* e3 = new Edge(1, 4, w);
	Edge* e4 = new Edge(1, 5, w);
	Edge* e5 = new Edge(2, 3, w);
	Edge* e6 = new Edge(2, 4, w);
	Edge* e7 = new Edge(2, 5, w);
	Edge* e8 = new Edge(3, 4, w);
	Edge* e9 = new Edge(3, 5, w);
	Edge* e10 = new Edge(4, 5, w);
	SAE->addEdge(e1);
	SAE->addEdge(e2);
	SAE->addEdge(e3);
	SAE->addEdge(e4);
	SAE->addEdge(e5);
	SAE->addEdge(e6);
	SAE->addEdge(e7); 
	SAE->addEdge(e8);
	SAE->addEdge(e9);
	SAE->addEdge(e10);
	SAE->UpdateAvailForSet(*DSA,1);
	assertEquals(true, SAE->getEdgeWrapperAt(0).DSAvail, "Edge Available when considering vertex 1");
	assertEquals(true, SAE->getEdgeWrapperAt(1).DSAvail, "Edge Available when considering vertex 1");
	assertEquals(true, SAE->getEdgeWrapperAt(2).DSAvail, "Edge Available when considering vertex 1");
	assertEquals(true, SAE->getEdgeWrapperAt(3).DSAvail, "Edge Available when considering vertex 1");
	assertEquals(false, SAE->getEdgeWrapperAt(4).DSAvail, "Edge Not Available when considering vertex 1");
	assertEquals(false, SAE->getEdgeWrapperAt(5).DSAvail, "Edge Not Available when considering vertex 1");
	assertEquals(false, SAE->getEdgeWrapperAt(6).DSAvail, "Edge Not Available when considering vertex 1");
	assertEquals(false, SAE->getEdgeWrapperAt(7).DSAvail, "Edge Not Available when considering vertex 1");
	assertEquals(false, SAE->getEdgeWrapperAt(8).DSAvail, "Edge Not Available when considering vertex 1");
	assertEquals(false, SAE->getEdgeWrapperAt(9).DSAvail, "Edge Not Available when considering vertex 1");
}

#endif // !SILI_ARRAY_OF_EDGES_TEST_H