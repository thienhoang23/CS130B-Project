#include "SpanningTree.h"
#include "Edge.h"

void SpanningTree::addEdges(int v1, int v2, weight w) {
	Graph::addEdges(v1, v2, w);
	g[v1].setKnown(true);
	g[v2].setKnown(true);
	*this->w + w;
	this->ofv = max(this->w->getVector(),this->w->getDim());
}

void SpanningTree::removeEdge(int v1, int v2) {
	g[v1].RemoveConnection(v2);
	g[v2].RemoveConnection(v1);
}

void SpanningTree::removeEdge(Edge* e) {
	removeEdge(e->getV1(), e->getV2());
}
