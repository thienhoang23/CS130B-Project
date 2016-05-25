#ifndef ARRAY_NODE_H
#define ARRAY_NODE_H
#include "Edge.h"


struct ArrayNode
{
	static const int AVAILABLE = 1; //for adding a node from E to Span. Tree and LII
	static const int USED_IN_TREE = -10; //for adding a node from E to Span. Tree
	static const int NOT_USED_IN_TREE = -100; //for Local Iterative Improvement
	static const int DOES_NOT_EXIST = -1000; //for instantitation
	
	//Variables
	Edge e;
	int ofv;
	int avail;
	bool isCycle;
	//Constructor
	ArrayNode() {
		e = Edge();
		ofv = 0;
		avail = DOES_NOT_EXIST;
		isCycle = false;
	}
	ArrayNode(Edge e) {
		this->e = e;
		ofv = 0;
		avail = AVAILABLE;
	}
	//Methods
	ArrayNode& operator=(const ArrayNode&  rhs) {
		this->ofv = rhs.ofv;
		this->avail = rhs.avail;
		this->e = rhs.e;
		return *this;
	}
	int compare(ArrayNode& a) {
		if (this->ofv < a.ofv)
			return -1;
		if (this->ofv > a.ofv)
			return 1;
		else {
			if (this->e < a.e)
				return -1;
			if (this->e > a.e)
				return 1;
			else
				return 0;
		}
	}
	friend bool operator >(ArrayNode& a1, ArrayNode& a2) {
		return a1.compare(a2) == 1;
	}
	friend bool operator <(ArrayNode& a1, ArrayNode& a2) {
		return a1.compare(a2) == -1;
	}
};
#endif // !ARRAY_NODE_H