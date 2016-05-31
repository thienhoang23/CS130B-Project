#ifndef _EDGE_H_
#define _EDGE_H_
#include "Weight.h"

class Edge {
private:
	weight* w;
	int v1, v2;
public:
	Edge() {
		w = nullptr;
		v1 = v2 = -1;
	}
	Edge(int v1,int v2,weight* w);
	weight* getWeight() { return w; }
	int compare(Edge e);
	int getV1() { return v1; }
	int getV2() { return v2; }
	int getDim() { return w->getDim(); }
	Edge(const Edge& src);
	Edge& operator =(const Edge& rhs);
	friend bool operator ==(Edge& e1, Edge& e2) {
		if ((e1.getV1() == e2.getV1() && e1.getV2() == e2.getV2()) ||
			(e1.getV1() == e2.getV2() && e1.getV2() == e2.getV1()))
			return true;
		return false;
	}
	friend bool operator !=(Edge& e1, Edge& e2) {
		return !(e1 == e2);
	}
	friend bool operator >(Edge& e1, Edge& e2) {
		if (e1.compare(e2) == 1)
			return true;
		return false;
	}
	friend bool operator <(Edge& e1, Edge& e2) {
		if (e1.compare(e2) == -1)
			return true;
		return false;
	}
	std::string toString(); //(v1,v2)
	//TO DO: DESTRUCTOR
};
#endif 