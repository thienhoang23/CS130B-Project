#include "Graph.h"
#include <iostream>
#include <string>

Graph::Graph(int numV, int numE) {
	this->numV = numV;
	this->numE = numE;
	this->g = new Vertex[numV];
	for (int i = 0; i < numV; i++)
		g[i].setID(i);
}

Graph::Graph(int numV) {
	this->numV = numV;
	this->numE = 0;
	this->g = new Vertex[numV];
	for (int i = 0; i < numV; i++)
		g[i].setID(i);
}

void Graph::addEdges(int v1, int v2, weight w) {
	if (v1 >= numV || v2 >= numV)
		return;
	g[v1].getList()->add(g[v2].getID(),w);
	g[v2].getList()->add(g[v1].getID(),w);
	numE++;
}

std::string Graph::toString() {
	if (g == nullptr)
		return "()";
	std::string result = "";
	for (int i = 0; i < numV; i++) {
		result += std::to_string(g[i].getID());
		result += "->";
		result += g[i].getList()->toString();
		if(i!=numV-1)
			result += '\n';
	}
	return result;
}