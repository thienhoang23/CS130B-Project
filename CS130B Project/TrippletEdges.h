#ifndef TRIPPLET_EDGES_H_
#define TRIPPLET_EDGES_H_
#include "Edge.h"

struct TrippletEdges {
	//Variables
	Edge e1, e2;
	int ofv;
	//Constructor
	TrippletEdges() {
		e1 = Edge();
		e2 = Edge();
		ofv = INT_MAX;
	}
	TrippletEdges(Edge e1, Edge e2) {
		this->e1 = e1;
		this->e2 = e2;
		ofv = INT_MAX;
	}
	TrippletEdges(Edge e1, Edge e2,int ofv) {
		this->e1 = e1;
		this->e2 = e2;
		this->ofv = ofv;
	}
};

#endif // !TRIPPLET_EDGES_H_