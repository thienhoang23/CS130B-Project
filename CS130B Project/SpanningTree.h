#ifndef SPANNING_TREE_H_
#define SPANNING_TREE_H_
#include "Graph.h"
#include "Weight.h"
#include "Edge.h"
#include "Helpers.h"
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
	int getDim() { return w->getDim(); }
	int getOFV() { return ofv; }
	void addEdges(int v1, int v2, weight w);
	void addEdges(int v1, int v2, weight* w) {
		return this->addEdges(v1, v2, *w);
	}
	void addEdges(Edge e) {
		this->addEdges(e.getV1(), e.getV2(), e.getWeight());
	}
	void removeEdge(int v1,int v2);
	void removeEdge(Edge* e);
	void updateOFV() { this->ofv = max(w->getVector(), w->getDim()); }
	bool CanGetFrom(int v1, int v2, int called) {
		if (g[v1].getID() == v2)
			return true;
		if (isLeaf(v1) && called != -1) //Avoid the start case
			return false;
		if (isNeighbor(v1, v2))
			return true;
		for (Node* cur = g[v1].getList()->getHead(); cur != nullptr; cur = cur->next) {
			if (cur->vertex_id == called)
				continue;
			bool result_of_rec = CanGetFrom(cur->vertex_id, v2, v1);
			if (result_of_rec == true)
				return true;
			else
				continue;
		}
		return false;
	}
};
#endif // !SPANNING_TREE_H_
