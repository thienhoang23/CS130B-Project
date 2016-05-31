#include <iostream>
#include "WeightUnitTest.h"
#include "LinkedListUnitTest.h"
#include "GraphUnitTest.h"
#include "EdgeUnitTest.h"
#include "StackUnitTest.h"
#include "SpanningTreeUnitTest.h"
#include "ArrayofEdgesUnitTest.h"
#include "AlgorithmTest.h"
#include "SILIArrayofEdgesUnitTest.h"
#include "DisjointSetUnitTest.h"
#include "DisjointSetArrayUnitTest.h"
using namespace std;

int main() {
	/*
	//ITERATION 0
	cout << "UNIT TEST FOR WEIGHT" << endl;
	RunAllWeightUnitTests();
	cout << endl;
	cout << "UNIT TEST FOR LINKED LIST" << endl;
	RunAllLinkedListUnitTests();
	cout << endl;	
	cout << "UNIT TEST FOR GRAPH" << endl;
	RunAllGraphUnitTests();
	cout << endl;

	//ITERATION 1
	cout << "UNIT TEST FOR EDGE" << endl;
	RunAllEdgeUnitTests();
	cout << endl;
	cout << "UNIT TEST FOR STACK" << endl;
	RunAllStackUnitTests();
	cout << endl;
	cout << "UNIT TEST FOR SPANNING TREE" << endl;
	RunAllSpanningTreeUnitTests();
	cout << endl;
	cout << "UNIT TEST FOR ARRAY OF EDGES" << endl;
	RunAllArrayOfEdgesUnitTest();
	cout << endl;*/
	cout << "ALGORITHM TESTS" << endl;
	RunAllKILITest();
	
	//RunAllSILIArrayOfEdgesUnitTest();
	//RunAllDisjoinSetUnitTest();
	//RunAllDisjointSetArrayTests();
	cout << endl;
	char c;
	cin >> c;
	return 0;
}