#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "Vertex.h"
#include "Weight.h"
#include "Edge.h"
#include <string>

class Graph {
protected:
	Vertex* g;
	int numV, numE;
public:
	Graph(int numV, int numE);
	Graph(int numV);
	int getNumV() { return numV; }
	int getNumE() { return numE; }
	weight getEdgeWeight(int v1, int v2) {
		return g[v1].getList()->getNode(v2)->w;
	}
	Vertex getVertex(int i) { return g[i]; }
	void addEdges(int v1, int v2, weight w);
	void addEdges(Edge e) {
		addEdges(e.getV1(), e.getV2(), *e.getWeight());
	}
	void addEdges(Edge* e) {
		addEdges(e->getV1(), e->getV2(), *e->getWeight());
	}
	std::string toString();
	/*	0->(1,2,3)
		1->(0,2,3)
	*/
	bool isKnownNeighbor(int v1,int v2);
	bool isNeighbor(int v1, int v2);
	bool isLeaf(int v);
	//TO DO: DESTRUCTOR
};
#endif // !_GRAPH_H_