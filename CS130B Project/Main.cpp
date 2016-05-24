#include <iostream>
#include "WeightUnitTest.h"
#include "LinkedListUnitTest.h"
#include "GraphUnitTest.h"
#include "EdgeUnitTest.h"
#include "HeapUnitTest.h"
using namespace std;

int main() {

	//ITERATION0
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
	cout << "UNIT TEST FOR HEAP" << endl;
	RunAllHeapUnitTests();
	char c;
	cin >> c;
	return 0;
}