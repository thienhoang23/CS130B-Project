#ifndef _EDGE_H_
#define _EDGE_H_
#include "Weight.h"

class Edge {
private:
	weight w;
	int v1, v2;
public:
	Edge();
	Edge(int v1,int v2,weight w);
	weight getWeight() { return w; }
	int compare(Edge e);
	int getV1() { return v1; }
	int getV2() { return v2; }
	Edge(const Edge& src);
	Edge& operator =(const Edge& rhs);
	//TO DO: DESTRUCTOR
};
#endif 