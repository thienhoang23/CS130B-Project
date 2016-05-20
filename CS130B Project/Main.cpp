#include <iostream>
#include "WeightUnitTest.h"
#include "LinkedListUnitTest.h"
#include "GraphUnitTest.h"
using namespace std;

int main() {
	cout << "UNIT TEST FOR WEIGHT" << endl;
	RunAllWeightUnitTests();
	cout << endl;
	cout << "UNIT TEST FOR LINKED LIST" << endl;
	RunAllLinkedListUnitTests();
	cout << "UNIT TEST FOR GRAPH" << endl;
	RunAllGraphUnitTests();
	char c;
	cin >> c;
	return 0;
}