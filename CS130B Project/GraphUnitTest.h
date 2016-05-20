#ifndef GRAPH_UNIT_TEST_H
#define GRAPH_UNIT_TEST_H

#include <iostream>
#include <string>
#include "Graph.h"
#include "Weight.h"

void testGraphToString() {
	//GRAPH WITH ONE NODE
	Graph* g1 = new Graph(1);
	assertEquals("0->()",g1->toString(),"Graph with one Node");
	
	//GRAPH WITH TWO NODE
	Graph* g2 = new Graph(2);
	assertEquals("0->()\n1->()", g2->toString(),"Graph with 2 Nodes");
	
	int arr[1] = { 0 };
	weight w = weight(1, arr);

	//ERROR CASE
	g2->addEdges(3,3,w);
	assertEquals("0->()\n1->()", g2->toString(), "Add Edge check the Error Cases");

	//GRAPH WITH 2 NODES AND 1 EDGE
	g2->addEdges(0, 1, w);
	assertEquals("0->(1)\n1->(0)", g2->toString(), "Graph with 2 Nodes and 1 Edge");

	//GRAPH WITH 3 NODES AND 1 EDGE
	Graph* g3 = new Graph(3);
	g3->addEdges(0, 1, w);
	assertEquals("0->(1)\n1->(0)\n2->()", g3->toString(), "Graph with 3 Nodes and 1 Edge");

	//GRAPH WITH 3 NODES AND 2 EDGE
	g3->addEdges(1, 2, w);
	assertEquals("0->(1)\n1->(0,2)\n2->(1)", g3->toString(), "Graph with 3 Nodes and 2 Edges");
}

void RunAllGraphUnitTests() {
	testGraphToString();
}

#endif // !GRAPH_UNIT_TEST_H