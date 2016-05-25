#include "ArrayofEdges.h"
#include "Edge.h"
#include "Weight.h"
#include "SpanningTree.h"

ArrayofEdges::ArrayofEdges(int dim) {
	this->numE = numE;
	this->current = 0;
	array = new ArrayNode[numE];
}

void ArrayofEdges::addEdge(Edge e) {
	array[current].e = e;
	array[current].avail = ArrayNode::AVAILABLE;
	array[current].ofv = max(e.getWeight()->getVector(), e.getDim());
	current++;
}

void ArrayofEdges::addEdge(Edge* e) {
	this->addEdge(*e);
}

bool ArrayofEdges::in(Edge e) {
	for (int i = 0; i < numE; i++)
		if (array[i].e == e && array[i].avail == ArrayNode::AVAILABLE)
			return true;
	return false;
}

void ArrayofEdges::remove(Edge e) {
	//USED FOR ADDING AN EDGE FROM E TO SPANNING TREE
	for (int i = 0; i < numE; i++)
		if (array[i].e == e && array[i].avail == ArrayNode::AVAILABLE)
			array[i].avail = ArrayNode::USED_IN_TREE;
}

void ArrayofEdges::remove(Edge* e) {
	this->remove(*e);
}

std::string ArrayofEdges::toString() {
	std::string result = "";
	for (int i = 0; i < numE; i++)
		result += array[i].e.toString();
	return result;
}

void ArrayofEdges::UpdateOFV(weight w) {
	for (int i = 0; i < numE; i++) {
		if (array[i].avail == ArrayNode::AVAILABLE) {
			weight temp = *array[i].e.getWeight;
			temp = temp + w;
			array[i].ofv = max(temp.getVector(), temp.getDim());
		}
	}
}

int ArrayofEdges::UpdateBestPossibleAddition() {
	int index = -1;
	int minOFV = 2147483647; //largest int possible
	for(int i = 0; i<numE; i++)
	if(array[i].avail==ArrayNode::AVAILABLE)
		if (array[i].ofv < minOFV) {
			minOFV = array[i].ofv;
			index = i;
		}
	return index;
}

ArrayofEdges& ArrayofEdges::operator =(const ArrayofEdges& rhs) {
	this->numE = rhs.numE;
	this->current = rhs.current;
	for (int i = 0; i < numE; i++) {
		this->array[i] = rhs.array[i];
	}
	return *this;
}

void ArrayofEdges::DetectCycleFormingEdges(SpanningTree& const st) {
	for (int i = 0; i < numE; i++)
		if (array[i].avail != ArrayNode::USED_IN_TREE)
			if (st.getVertex(array[i].e.getV1()).getKnown == true &&
				st.getVertex(array[i].e.getV2()).getKnown == true)
				array[i].isCycle = true;
}