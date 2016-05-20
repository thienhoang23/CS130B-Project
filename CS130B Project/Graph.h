#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "Vertex.h"
#include "Weight.h"
#include <string>

class Graph {
protected:
	Vertex* g;
	int numV,numE;
public:
	Graph(int numV,int numE);
	Graph(int numV);
	void addEdges(int v1, int v2, weight w);
	std::string toString();
	//TO DO: DESTRUCTOR
};
#endif // !_GRAPH_H_