#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "Vertex.h"
#include "Weight.h"

class Graph {
protected:
	Vertex* g;
	int NumV,numE;
public:
	Graph(int numV,int numE);
	void addEdges(int v1, int v2, weight w);
};
#endif // !_GRAPH_H_