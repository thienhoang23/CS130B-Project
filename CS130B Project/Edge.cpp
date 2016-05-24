#include "Edge.h"
#include "Weight.h"

Edge::Edge(int v1, int v2, weight* w) {
	this->v1 = v1;
	this->v2 = v2;
	this->w = w;
}

int Edge::compare(Edge e) {
	return this->w->compare(*e.getWeight());
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
	return *this;
}