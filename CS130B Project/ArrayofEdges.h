#ifndef ARRAY_OF_EDGES_H_
#define ARRAY_OF_EDGES_H_

#include "ArrayNode.h"
#include "Edge.h"
#include "Weight.h"
#include "SpanningTree.h"

class ArrayofEdges {
protected:
	int numE, current;
	ArrayNode* array;
public:
	ArrayofEdges(int numE);
	int getNumE() { return numE; }
	int getCurrent() { return current; }
	virtual void addEdge(Edge e);
	virtual void addEdge(Edge* e);
	ArrayNode* getEdgeWrapper(int v1, int v2) {
		for (int i = 0; i < numE; i++) {
			if ((array[i].e.getV1() == v1 && array[i].e.getV2() == v2) ||
				(array[i].e.getV2() == v1 && array[i].e.getV1() == v2))
				return &array[i];
		}
		return nullptr;
	}
	ArrayNode* getEdgeWrapper(Edge e) {
		for (int i = 0; i < numE; i++)
			if (array[i].e == e)
				return &array[i];
		return nullptr;
	}
	Edge* getEdge(int v1, int v2) {
		if (getEdgeWrapper(v1, v2) != nullptr)
			return &getEdgeWrapper(v1, v2)->e;
		return nullptr;
	}
	Edge* getEdge(Edge e) {
		if (getEdgeWrapper(e) != nullptr)
			return &getEdgeWrapper(e)->e;
		return nullptr;
	}
	Edge getEdgeAt(int i) { return array[i].e; }
	ArrayNode getEdgeWrapperAt(int i) { return this->array[i]; }
	bool in(Edge e);
	bool in(Edge* e) {
		return this->in(*e);
	}
	void remove(Edge e1);
	void remove(Edge* e);
	std::string toString();//(v1,v2)(v1,v2)
	virtual void UpdateOFV(weight w);
	virtual void UpdateOFV(weight* w) {
		return UpdateOFV(*w);
	}
	void Update(weight* w) {
		this->Update(*w);
	}
	void Update(weight w) {
		this->UpdateOFV(w);
		this->UpdateBestPossibleAddition();
	}
	virtual void Update(SpanningTree& const st) {
		this->DetectCycleFormingEdges(st);
		this->UpdateOFV(*st.getWeight());
		this->UpdateBestPossibleAddition();
	}
	virtual void UpdateBestPossibleAddition();
	Edge BestPossibleAddition() { return array[current].e; }
	ArrayofEdges& operator =(const ArrayofEdges& rhs);
	void DetectCycleFormingEdges(SpanningTree& const st);
	void SetAvail(Edge e, int avail) {
		for (int i = 0; i < numE; i++) {
			if (array[i].e == e)
				array[i].avail = avail;
		}
	}
};

#endif // !ARRAY_OF_EDGES_H_