#ifndef SPANNING_TREE_H_
#define SPANNING_TREE_H_
#include "Graph.h"
#include "Weight.h"
#include "Edge.h"

class SpanningTree : public Graph{
private:
	weight* w;
	int ofv;
public:
	SpanningTree(int numV, int dim) :Graph(numV),
		ofv(0), w(new weight(dim))
	{
	}
	weight* getWeight() { return w; }
	int getOFV() { return ofv; }
	void addEdges(int v1, int v2, weight w);
	void removeEdge(int v1,int v2);
	void removeEdge(Edge* e);
};
#endif // !SPANNING_TREE_H_
