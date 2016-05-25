#ifndef ARRAY_OF_EDGES_H_
#define ARRAY_OF_EDGES_H_

#include "ArrayNode.h"
#include "Edge.h"
#include "Weight.h"
#include "SpanningTree.h"

class ArrayofEdges {
private:
	int numE, current;
	ArrayNode* array;
public:
	ArrayofEdges(int numE);
	int getNumE() { return numE; }
	void addEdge(Edge e);
	void addEdge(Edge* e);
	Edge getEdgeAt(int i) { return array[i].e; }
	ArrayNode getEdgeWrapperAt(int i) { retrun array[i]; }
	bool in(Edge e);
	void remove(Edge e);
	void remove(Edge* e);
	std::string toString();
	void UpdateOFV(weight w);
	void UpdateOFV(weight* w) {
		return UpdateOFV(*w);
	}
	void Update(weight w) {
		this->UpdateOFV(w);
		this->current = this->UpdateBestPossibleAddition();
	}
	void Update(weight* w) {
		this->Update(*w);
	}
	int UpdateBestPossibleAddition();
	Edge BestPossibleAddition() { return array[current].e; }
	ArrayofEdges& operator =(const ArrayofEdges& rhs);
	void DetectCycleFormingEdges(SpanningTree& const st);
}

#endif // !ARRAY_OF_EDGES_H_