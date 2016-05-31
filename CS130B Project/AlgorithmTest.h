#ifndef ALGORITHM_TEST_H_
#define ALGORITHM_TEST_H_

#include "Algorithm.h"
#include "Weight.h"
#include "Edge.h"
#include "Graph.h"
#include "SpanningTree.h"
#include "ArrayofEdges.h"

//KILI TEST ON 3 VERTICES; No Local Iterative Improvement
void KILITest1() {
	Graph* G = new Graph(3);
	SpanningTree* ST = new SpanningTree(3,2);
	ArrayofEdges* AE = new ArrayofEdges(3);
	int arr01[2] = { 2,4 };
	int arr02[2] = { 1,5 };
	int arr12[2] = { 3,3 };
	weight* w01 = new weight(2, arr01);
	weight* w02 = new weight(2, arr02);
	weight* w12 = new weight(2, arr12);
	Edge* e01 = new Edge(1, 2, w01);
	Edge* e02 = new Edge(1, 3, w02);
	Edge* e12 = new Edge(2, 3, w12);
	G->addEdges(e01);
	G->addEdges(e02);
	G->addEdges(e12);
	AE->addEdge(e01);
	AE->addEdge(e02);
	AE->addEdge(e12);
	KILI(*G, *AE, *ST);
	int arr_test[2] = { 5,7 };
	weight* w_test = new weight(2, arr_test);
	assertEquals("1->(2)\n2->(3,1)\n3->(2)", ST->toString(), "KILI TEST 1: Correct Spanning Tree");
	assertEquals(w_test->toString(), ST->getWeight()->toString(), "KILI TEST 1: Correct weight of the entire Tree");
	assertEquals(7, ST->getOFV(), "KILI TEST 1: Correct OFV of the entire Tree");
}

//KILI TEST ON 4 VERTICES; No Local Iterative Improvement
void KILITest2() {
	Graph* G = new Graph(4);
	SpanningTree* ST = new SpanningTree(4, 2);
	ArrayofEdges* AE = new ArrayofEdges(6);
	int arr01[2] = { 22,18 };
	int arr02[2] = { 15,30 };
	int arr03[2] = { 22,33 };
	int arr12[2] = { 13,20 };
	int arr13[2] = { 1,2 };
	int arr23[2] = { 10,20 };
	weight* w01 = new weight(2, arr01);
	weight* w02 = new weight(2, arr02);
	weight* w03 = new weight(2, arr03);
	weight* w12 = new weight(2, arr12);
	weight* w13 = new weight(2, arr13);
	weight* w23 = new weight(2, arr23);
	Edge* e01 = new Edge(0, 1, w01);
	Edge* e02 = new Edge(0, 2, w02);
	Edge* e03 = new Edge(0, 3, w03);
	Edge* e12 = new Edge(1, 2, w12);
	Edge* e13 = new Edge(1, 3, w13);
	Edge* e23 = new Edge(2, 3, w23);
	G->addEdges(e01);
	G->addEdges(e02);
	G->addEdges(e03);
	G->addEdges(e12);
	G->addEdges(e13);
	G->addEdges(e23);
	AE->addEdge(e01);
	AE->addEdge(e02);
	AE->addEdge(e03);
	AE->addEdge(e12);
	AE->addEdge(e13);
	AE->addEdge(e23);
	KILI(*G, *AE, *ST);
	int arr_test[2] = { 33,40 };
	weight* w_test = new weight(2, arr_test);
	//assertEquals("0->(1)\n1->(2,0)\n2->(1)",ST->toString(),"Correct Spanning Tree");
	assertEquals(w_test->toString(), ST->getWeight()->toString(), "KILI TEST 2: Correct weight of the entire Tree");
	assertEquals(40, ST->getOFV(), "KILI TEST 2: Correct OFV of the entire Tree");
}

//KILI TEST ON 4 VERTICES; With Local Iterative Improvement
void KILITest3() {
	Graph* G = new Graph(4);
	SpanningTree* ST = new SpanningTree(4, 3);
	ArrayofEdges* AE = new ArrayofEdges(4);
	int arr13[3] = { 1,0,0 };
	int arr14[3] = { 0,5,0 };
	int arr34[3] = { 3,0,0 };
	int arr24[3] = { 4,0,0 };
	weight* w13 = new weight(3, arr13);
	weight* w14 = new weight(3, arr14);
	weight* w34 = new weight(3, arr34);
	weight* w24 = new weight(3, arr24);
	Edge* e13 = new Edge(1, 3, w13);
	Edge* e14 = new Edge(1, 4, w14);
	Edge* e34 = new Edge(3, 4, w34);
	Edge* e24 = new Edge(2, 4, w24);
	G->addEdges(e13);
	G->addEdges(e14);
	G->addEdges(e34);
	G->addEdges(e24);
	AE->addEdge(e13);
	AE->addEdge(e14);
	AE->addEdge(e34);
	AE->addEdge(e24);
	KILI(*G, *AE, *ST);
	int arr_test[3] = { 5,5,0 };
	weight* w_test = new weight(3, arr_test);
	assertEquals(w_test->toString(), ST->getWeight()->toString(), "KILI TEST 3: Correct weight of the entire Tree");
	assertEquals(5, ST->getOFV(), "KILI TEST 3: Correct OFV of the entire Tree");
}

//PILI TEST ON 3 VERTICES; No Local Iterative Improvement
void PILITest1() {
	Graph* G = new Graph(3);
	SpanningTree* ST = new SpanningTree(3, 2);
	PILIArrayofEdges* PAE = new PILIArrayofEdges(3);
	int arr12[2] = { 2,4 };
	int arr13[2] = { 1,5 };
	int arr23[2] = { 3,3 };
	weight* w12 = new weight(2, arr12);
	weight* w13 = new weight(2, arr13);
	weight* w23 = new weight(2, arr23);
	Edge* e12 = new Edge(1, 2, w12);
	Edge* e13 = new Edge(1, 3, w13);
	Edge* e23 = new Edge(2, 3, w23);
	G->addEdges(e12);
	G->addEdges(e13);
	G->addEdges(e23);
	PAE->addEdge(e12);
	PAE->addEdge(e13);
	PAE->addEdge(e23);
	PILI(*G, *PAE, *ST);
	int arr_test[2] = { 5,7 };
	weight* w_test = new weight(2, arr_test);
	assertEquals("1->(2)\n2->(1,3)\n3->(2)", ST->toString(), "SILI TEST 1: Correct Spanning Tree");
	assertEquals(w_test->toString(), ST->getWeight()->toString(), "SILI TEST 1: Correct weight of the entire Tree");
	assertEquals(7, ST->getOFV(), "SILI TEST 1: Correct OFV of the entire Tree");
}

//PILI TEST ON 4 VERTICES; No Local Iterative Improvement
void PILITest2() {
	Graph* G = new Graph(4);
	SpanningTree* ST = new SpanningTree(4, 2);
	PILIArrayofEdges* AE = new PILIArrayofEdges(6);
	int arr12[2] = { 22,18 };
	int arr13[2] = { 15,30 };
	int arr14[2] = { 22,33 };
	int arr23[2] = { 13,20 };
	int arr24[2] = { 1,2 };
	int arr34[2] = { 10,20 };
	weight* w12 = new weight(2, arr12);
	weight* w13 = new weight(2, arr13);
	weight* w14 = new weight(2, arr14);
	weight* w23 = new weight(2, arr23);
	weight* w24 = new weight(2, arr24);
	weight* w34 = new weight(2, arr34);
	Edge* e12 = new Edge(1, 2, w12);
	Edge* e13 = new Edge(1, 3, w13);
	Edge* e14 = new Edge(1, 4, w14);
	Edge* e23 = new Edge(2, 3, w23);
	Edge* e24 = new Edge(2, 4, w24);
	Edge* e34 = new Edge(3, 4, w34);
	G->addEdges(e12);
	G->addEdges(e13);
	G->addEdges(e14);
	G->addEdges(e23);
	G->addEdges(e24);
	G->addEdges(e34);
	AE->addEdge(e12);
	AE->addEdge(e13);
	AE->addEdge(e14);
	AE->addEdge(e23);
	AE->addEdge(e24);
	AE->addEdge(e34);
	PILI(*G, *AE, *ST);
	int arr_test[2] = { 33,40 };
	weight* w_test = new weight(2, arr_test);
	//assertEquals("0->(1)\n1->(2,0)\n2->(1)",ST->toString(),"Correct Spanning Tree");
	assertEquals(w_test->toString(), ST->getWeight()->toString(), "PILI TEST 2: Correct weight of the entire Tree");
	assertEquals(40, ST->getOFV(), "PILI TEST 2: Correct OFV of the entire Tree");
}

//PILI TEST ON 4 VERTICES; With Local Iterative Improvement
void PILITest3() {
	Graph* G = new Graph(4);
	SpanningTree* ST = new SpanningTree(4, 3);
	PILIArrayofEdges* PAE = new PILIArrayofEdges(4);
	int arr13[3] = { 1,0,0 };
	int arr14[3] = { 0,5,0 };
	int arr34[3] = { 3,0,0 };
	int arr24[3] = { 4,0,0 };
	weight* w13 = new weight(3, arr13);
	weight* w14 = new weight(3, arr14);
	weight* w34 = new weight(3, arr34);
	weight* w24 = new weight(3, arr24);
	Edge* e13 = new Edge(1, 3, w13);
	Edge* e14 = new Edge(1, 4, w14);
	Edge* e34 = new Edge(3, 4, w34);
	Edge* e24 = new Edge(2, 4, w24);
	G->addEdges(e13);
	G->addEdges(e14);
	G->addEdges(e34);
	G->addEdges(e24);
	PAE->addEdge(e13);
	PAE->addEdge(e14);
	PAE->addEdge(e34);
	PAE->addEdge(e24);
	PILI(*G, *PAE, *ST);
	int arr_test[3] = { 5,5,0 };
	weight* w_test = new weight(3, arr_test);
	assertEquals(w_test->toString(), ST->getWeight()->toString(), "PILI TEST 3: Correct weight of the entire Tree");
	assertEquals(5, ST->getOFV(), "PILI TEST 3: Correct OFV of the entire Tree");
}

//FILI TEST ON 3 VERTICES; No Local Iterative Improvement
void FILITest1() {
	Graph* G = new Graph(3);
	SpanningTree* ST = new SpanningTree(3, 2);
	ArrayofEdges* AE = new ArrayofEdges(3);
	int arr12[2] = { 2,4 };
	int arr13[2] = { 1,5 };
	int arr23[2] = { 3,3 };
	weight* w12 = new weight(2, arr12);
	weight* w13 = new weight(2, arr13);
	weight* w23 = new weight(2, arr23);
	Edge* e12 = new Edge(1, 2, w12);
	Edge* e13 = new Edge(1, 3, w13);
	Edge* e23 = new Edge(2, 3, w23);
	G->addEdges(e12);
	G->addEdges(e13);
	G->addEdges(e23);
	AE->addEdge(e12);
	AE->addEdge(e13);
	AE->addEdge(e23);
	FILI(*G, *AE, *ST);
	int arr_test[2] = { 5,7 };
	weight* w_test = new weight(2, arr_test);
	assertEquals("1->(2)\n2->(1,3)\n3->(2)", ST->toString(), "FILI TEST 1: Correct Spanning Tree");
	assertEquals(w_test->toString(), ST->getWeight()->toString(), "FILI TEST 1: Correct weight of the entire Tree");
	assertEquals(7, ST->getOFV(), "FILI TEST 1: Correct OFV of the entire Tree");
}

//FILI TEST ON 4 VERTICES; With Local Iterative Improvement
void FILITest2() {
	Graph* G = new Graph(4);
	SpanningTree* ST = new SpanningTree(4, 2);
	ArrayofEdges* AE = new ArrayofEdges(6);
	int arr12[2] = { 22,18 };
	int arr13[2] = { 15,30 };
	int arr14[2] = { 22,33 };
	int arr23[2] = { 13,20 };
	int arr24[2] = { 1,2 };
	int arr34[2] = { 10,20 };
	weight* w12 = new weight(2, arr12);
	weight* w13 = new weight(2, arr13);
	weight* w14 = new weight(2, arr14);
	weight* w23 = new weight(2, arr23);
	weight* w24 = new weight(2, arr24);
	weight* w34 = new weight(2, arr34);
	Edge* e12 = new Edge(1, 2, w12);
	Edge* e13 = new Edge(1, 3, w13);
	Edge* e14 = new Edge(1, 4, w14);
	Edge* e23 = new Edge(2, 3, w23);
	Edge* e24 = new Edge(2, 4, w24);
	Edge* e34 = new Edge(3, 4, w34);
	G->addEdges(e12);
	G->addEdges(e13);
	G->addEdges(e14);
	G->addEdges(e23);
	G->addEdges(e24);
	G->addEdges(e34);
	AE->addEdge(e12);
	AE->addEdge(e13);
	AE->addEdge(e14);
	AE->addEdge(e23);
	AE->addEdge(e24);
	AE->addEdge(e34);
	FILI(*G, *AE, *ST);
	int arr_test[2] = { 36,40 };
	weight* w_test = new weight(2, arr_test);
	//assertEquals("0->(1)\n1->(2,0)\n2->(1)",ST->toString(),"Correct Spanning Tree");
	assertEquals(w_test->toString(), ST->getWeight()->toString(), "FILI TEST 2: Correct weight of the entire Tree");
	assertEquals(40, ST->getOFV(), "FILI TEST 2: Correct OFV of the entire Tree");
}

//FILI TEST ON 4 VERTICES; With 3 Local Iterative Improvements
void FILITest3() {
	Graph* G = new Graph(4);
	SpanningTree* ST = new SpanningTree(4,3);
	ArrayofEdges* AE = new ArrayofEdges(6);
	int arr13[3] = { 1,0,0 };
	int arr12[3] = { 1000,0,0 };
	int arr23[3] = { 1000,0,0 };
	int arr14[3] = { 0,5,0 };
	int arr34[3] = { 3,0,0 };
	int arr24[3] = { 4,0,0 };
	weight* w13 = new weight(3, arr13);
	weight* w12 = new weight(3, arr12);
	weight* w23 = new weight(3, arr23);
	weight* w14 = new weight(3, arr14);
	weight* w34 = new weight(3, arr34);
	weight* w24 = new weight(3, arr24);
	Edge* e13 = new Edge(1, 3, w13);
	Edge* e12 = new Edge(1, 2, w12);
	Edge* e23 = new Edge(2, 3, w23);
	Edge* e14 = new Edge(1, 4, w14);
	Edge* e34 = new Edge(3, 4, w34);
	Edge* e24 = new Edge(2, 4, w24);
	G->addEdges(e13);
	G->addEdges(e12);
	G->addEdges(e23);
	G->addEdges(e14);
	G->addEdges(e34);
	G->addEdges(e24);
	AE->addEdge(e13);
	AE->addEdge(e12);
	AE->addEdge(e23);
	AE->addEdge(e14);
	AE->addEdge(e34);
	AE->addEdge(e24);
	FILI(*G, *AE, *ST);
	int arr_test[3] = { 5,5,0 };
	weight* w_test = new weight(3, arr_test);
	assertEquals(w_test->toString(), ST->getWeight()->toString(), "FILI TEST 3: Correct weight of the entire Tree");
	assertEquals(5, ST->getOFV(), "FILI TEST 3: Correct OFV of the entire Tree");
}

//SILI TEST ON 3 VERTICES; No Local Iterative Improvement
void SILITest1() {
	Graph* G = new Graph(3);
	SpanningTree* ST = new SpanningTree(3, 2);
	SILIArrayofEdges* SAE = new SILIArrayofEdges(3);
	int arr12[2] = { 2,4 };
	int arr13[2] = { 1,5 };
	int arr23[2] = { 3,3 };
	weight* w12 = new weight(2, arr12);
	weight* w13 = new weight(2, arr13);
	weight* w23 = new weight(2, arr23);
	Edge* e12 = new Edge(1, 2, w12);
	Edge* e13 = new Edge(1, 3, w13);
	Edge* e23 = new Edge(2, 3, w23);
	G->addEdges(e12);
	G->addEdges(e13);
	G->addEdges(e23);
	SAE->addEdge(e12);
	SAE->addEdge(e13);
	SAE->addEdge(e23);
	SILI(*G, *SAE, *ST);
	int arr_test[2] = { 5,7 };
	weight* w_test = new weight(2, arr_test);
	assertEquals("1->(2)\n2->(1,3)\n3->(2)", ST->toString(), "SILI TEST 1: Correct Spanning Tree");
	assertEquals(w_test->toString(), ST->getWeight()->toString(), "SILI TEST 1: Correct weight of the entire Tree");
	assertEquals(7, ST->getOFV(), "SILI TEST 1: Correct OFV of the entire Tree");
}

//SILI TEST ON 4 VERTICES; No Local Iterative Improvement
void SILITest2() {
	Graph* G = new Graph(4);
	SpanningTree* ST = new SpanningTree(4, 2);
	SILIArrayofEdges* SAE = new SILIArrayofEdges(6);
	int arr12[2] = { 22,18 };
	int arr13[2] = { 15,30 };
	int arr14[2] = { 22,33 };
	int arr23[2] = { 13,20 };
	int arr24[2] = { 1,2 };
	int arr34[2] = { 10,20 };
	weight* w12 = new weight(2, arr12);
	weight* w13 = new weight(2, arr13);
	weight* w14 = new weight(2, arr14);
	weight* w23 = new weight(2, arr23);
	weight* w24 = new weight(2, arr24);
	weight* w34 = new weight(2, arr34);
	Edge* e12 = new Edge(1, 2, w12);
	Edge* e13 = new Edge(1, 3, w13);
	Edge* e14 = new Edge(1, 4, w14);
	Edge* e23 = new Edge(2, 3, w23);
	Edge* e24 = new Edge(2, 4, w24);
	Edge* e34 = new Edge(3, 4, w34);
	G->addEdges(e12);
	G->addEdges(e13);
	G->addEdges(e14);
	G->addEdges(e23);
	G->addEdges(e24);
	G->addEdges(e34);
	SAE->addEdge(e12);
	SAE->addEdge(e13);
	SAE->addEdge(e14);
	SAE->addEdge(e23);
	SAE->addEdge(e24);
	SAE->addEdge(e34);
	SILI(*G, *SAE, *ST);
	int arr_test[2] = { 33,40 };
	weight* w_test = new weight(2, arr_test);
	//assertEquals("0->(1)\n1->(2,0)\n2->(1)",ST->toString(),"Correct Spanning Tree");
	assertEquals(w_test->toString(), ST->getWeight()->toString(), "SILI TEST 2: Correct weight of the entire Tree");
	assertEquals(40, ST->getOFV(), "SILI TEST 2: Correct OFV of the entire Tree");
}

//PILI TEST ON 4 VERTICES; With Local Iterative Improvement
void SILITest3(){
	Graph* G = new Graph(4);
	SpanningTree* ST = new SpanningTree(4, 3);
	SILIArrayofEdges* SAE = new SILIArrayofEdges(6);
	int arr13[3] = { 1,0,0 };
	int arr12[3] = { 1000,0,0 };
	int arr23[3] = { 1000,0,0 };
	int arr14[3] = { 0,5,0 };
	int arr34[3] = { 3,0,0 };
	int arr24[3] = { 4,0,0 };
	weight* w13 = new weight(3, arr13);
	weight* w12 = new weight(3, arr12);
	weight* w23 = new weight(3, arr23);
	weight* w14 = new weight(3, arr14);
	weight* w34 = new weight(3, arr34);
	weight* w24 = new weight(3, arr24);
	Edge* e13 = new Edge(1, 3, w13);
	Edge* e12 = new Edge(1, 2, w12);
	Edge* e23 = new Edge(2, 3, w23);
	Edge* e14 = new Edge(1, 4, w14);
	Edge* e34 = new Edge(3, 4, w34);
	Edge* e24 = new Edge(2, 4, w24);
	G->addEdges(e13);
	G->addEdges(e12);
	G->addEdges(e23);
	G->addEdges(e14);
	G->addEdges(e34);
	G->addEdges(e24);
	SAE->addEdge(e13);
	SAE->addEdge(e12);
	SAE->addEdge(e23);
	SAE->addEdge(e14);
	SAE->addEdge(e34);
	SAE->addEdge(e24);
	SILI(*G, *SAE, *ST);
	int arr_test[3] = { 5,5,0 };
	weight* w_test = new weight(3, arr_test);
	assertEquals(w_test->toString(), ST->getWeight()->toString(), "SILI TEST 3: Correct weight of the entire Tree");
	assertEquals(5, ST->getOFV(), "SILI TEST 3: Correct OFV of the entire Tree");
}

void RunAllKILITest() {
	KILITest1();
	KILITest2();
	KILITest3();
	PILITest1();
	PILITest2();
	PILITest3();
	FILITest1();
	FILITest2();
	FILITest3();
	SILITest1();
	SILITest2();
	SILITest3();
}

#endif // !ALGORITHM_TEST_H_