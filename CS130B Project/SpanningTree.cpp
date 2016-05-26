#include "SpanningTree.h"
#include "Edge.h"

void SpanningTree::addEdges(int v1, int v2, weight w) {
	Graph::addEdges(v1, v2, w);
	g[v1].setKnown(true);
	g[v2].setKnown(true);
	*this->w = *this->w + w;
	this->updateOFV();
}

void SpanningTree::removeEdge(int v1, int v2) {
	weight w_del = this->getEdgeWeight(v1,v2);
	g[v1].RemoveConnection(v2);
	g[v2].RemoveConnection(v1);
	*this->w = *this->w - w_del;
	this->updateOFV();
}

void SpanningTree::removeEdge(Edge* e) {
	removeEdge(e->getV1(), e->getV2());
}
