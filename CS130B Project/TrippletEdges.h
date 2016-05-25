#ifndef TRIPPLET_EDGES_H_
#define TRIPPLET_EDGES_H_
#include "Edge.h"

struct TrippletEdges {
	//Variables
	//e1: Cycle forming edge
	//e2: Cycle breaking edge
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
	TrippletEdges& operator=(TrippletEdges& const rhs) {
		this->e1 = rhs.e1;
		this->e2 = rhs.e2;
		this->ofv = rhs.ofv;
		return *this;
	}
};

#endif // !TRIPPLET_EDGES_H_