#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"
#include "Algorithm.h"
#include "ArrayofEdges.h"
#include "PILIArrayofEdges.h"
#include "SILIArrayofEdges.h"
#include "SpanningTree.h"
#include "tddFuncs.h"
#include <sstream>
/*#include "WeightUnitTest.h"
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
*/
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
	cout << endl;
	cout << "UNIT TEST FOR DISJOINT SET" << endl;
	RunAllDisjoinSetUnitTest();
	cout << endl;
	cout << "UNIT TEST FOR DISJOINT SET ARRAY" << endl;
	RunAllDisjointSetArrayTests();
	cout << endl;
	cout << "UNIT TEST FOR SILI ARRAY OF EDGES" << endl;
	RunAllSILIArrayOfEdgesUnitTest();
	cout << endl;
	cout << "ALGORITHM TESTS" << endl;
	RunAllKILITest();
	cout << endl;
	*/
	string line;
	ifstream myfile("../InputOutput/Input1.2.txt");
	getline(myfile, line);
	int Method = stoi(line);
	getline(myfile, line);
	int numV = stoi(line);
	getline(myfile, line);
	int numE = stoi(line);
	getline(myfile, line);
	int dim = stoi(line);
	getline(myfile, line);
	int OutputType = stoi(line);
	Graph* G = new Graph(numV);
	SpanningTree* ST = new SpanningTree(numV,dim);
	ArrayofEdges* AE;
	string MethodType;
	if (Method == 1) {
		AE = new ArrayofEdges(numE);
		MethodType = "KILI";
	}	
	else if (Method == 2) {
		AE = new PILIArrayofEdges(numE);
		MethodType = "PILI";
	}
	else if (Method == 3) {
		AE = new SILIArrayofEdges(numE);
		MethodType = "SILI";
	}
	else if (Method == 4) {
		AE = new ArrayofEdges(numE);
		MethodType = "FILI";
	}
	else {
		AE = new ArrayofEdges(numE);
		MethodType = "YILI";
	}
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			weight* w = new weight(dim);
			string substring;
			stringstream ssin(line);
			ssin >> substring;
			int v1 = stoi(substring);
			ssin >> substring;
			int v2 = stoi(substring);
			int i = 0;
			while (ssin.good(), i < dim) {
				ssin >> substring;
				w->addValue(stoi(substring));
				++i;
			}
			Edge* e = new Edge(v1, v2, w);
			AE->addEdge(e);
			G->addEdges(e);
		}
		myfile.close();
	}
	if (Method == 1)
		KILI(*G, *AE, *ST);
	else if (Method == 2) {
		PILIArrayofEdges* PAE = dynamic_cast<PILIArrayofEdges*>(AE);
		PILI(*G, *PAE, *ST);
	}
	else if (Method == 3) {
		SILIArrayofEdges* SAE = dynamic_cast<SILIArrayofEdges*>(AE);
		SILI(*G, *SAE, *ST);
	}
	else if (Method == 4)
		FILI(*G, *AE, *ST);
	else
		YILI(*G, *AE, *ST);
	if (OutputType == 1) {
		AE->Sort();
		cout << AE->Output();
		cout << ST->getWeight()->Output() << endl;
		cout << MethodType << " " << ST->getOFV();
	}
	else {
		cout << ST->getWeight()->Output() << endl;
		cout << MethodType << " " << ST->getOFV();
	}
	char c;
	cin >> c;
	return 0;
}