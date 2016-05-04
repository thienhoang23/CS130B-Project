#include "Edge.h"
#include "Weight.h"
#include <algorithm>

Edge::Edge(int v1, int v2, weight w) {
	this->v1 = v1;
	this->v2 = v2;
	this->w = w;
}

int Edge::compare(Edge e) {
	weight w2 = e.getWeight();
	return this->w.compare(w2);
}

Edge::Edge(const Edge& src) {
	this->v1 = src.v1;
	this->v2 = src.v2;
	this->w = src.w;
}

Edge& Edge::operator=(const Edge& rhs) {
	this->v1 = rhs.v1;
	this->v2 = rhs.v2;
	this->w = rhs.w;
}

Edge::Edge() {
	v1 = v2 = 0;
	w = weight();
}