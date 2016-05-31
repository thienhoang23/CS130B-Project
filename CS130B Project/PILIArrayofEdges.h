#ifndef PILI_ARRAY_OF_EDGES
#define PILI_ARRAY_OF_EDGES

#include "ArrayofEdges.h"
#include "Edge.h"
#include "SpanningTree.h"
#include "ArrayNode.h"
#include "Weight.h"

class PILIArrayofEdges : public ArrayofEdges {
public:
	PILIArrayofEdges(int numE) : ArrayofEdges(numE)
	{
	}
	void addEdge(Edge e) {
		array[current].e = e;
		array[current].avail = ArrayNode::NOT_AVAILABLE;
		array[current].ofv = max(e.getWeight()->getVector(), e.getDim());
		current++;
	}
	void addEdge(Edge* e) {
		this->addEdge(*e);
	}
	void UpdateAvail(SpanningTree& const ST) {
		for (int i = 0; i < this->numE; i++) {
			if (this->array[i].avail == ArrayNode::USED_IN_TREE)
				continue;
			if (((ST.getVertex(this->array[i].e.getV1()).getKnown() == true) &&
				(ST.getVertex(this->array[i].e.getV2()).getKnown() == false)) ||
				((ST.getVertex(this->array[i].e.getV1()).getKnown() == false) &&
				(ST.getVertex(this->array[i].e.getV2()).getKnown() == true)))
				this->array[i].avail = ArrayNode::AVAILABLE;
			else
				this->array[i].avail = ArrayNode::NOT_AVAILABLE;
		}
	}
	void Update(SpanningTree& const ST) {
		this->UpdateAvail(ST);
		ArrayofEdges::Update(ST);
	}
};
#endif // !PILI_ARRAY_OF_EDGES