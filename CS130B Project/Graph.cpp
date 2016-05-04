#include "Graph.h"

Graph::Graph(int numV, int numE) {
	this->NumV = numV;
	this->numE = numE;
	this->g = new Vertex[NumV];
}

void Graph::addEdges(int v1, int v2, weight w) {
	g[v1].getList().add(g[v2].getID(),w);
	g[v2].getList().add(g[v1].getID(),w);
	numE++;
}