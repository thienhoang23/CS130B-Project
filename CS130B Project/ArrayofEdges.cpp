
#include "ArrayofEdges.h"
#include "Edge.h"
#include "Weight.h"
#include "SpanningTree.h"

ArrayofEdges::ArrayofEdges(int numE) { 
	this->numE = numE;
	this->current = 0;
	this->array = new ArrayNode[numE];
}

void ArrayofEdges::addEdge(Edge e) {
	this->array[current].e = e;
	this->array[current].avail = ArrayNode::AVAILABLE;
	this->array[current].ofv = max(e.getWeight()->getVector(), e.getDim());
	this->current++;
}

void ArrayofEdges::addEdge(Edge* e) {
	this->addEdge(*e);
}

bool ArrayofEdges::in(Edge e) {
	for (int i = 0; i < numE; i++)
		if ((this->array[i].e == e) && (this->array[i].avail == ArrayNode::AVAILABLE))
			return true;
	return false;
}

void ArrayofEdges::remove(Edge e) {
	//USED FOR ADDING AN EDGE FROM E TO SPANNING TREE
	for (int i = 0; i < numE; i++)
		if (this->array[i].e == e /*&& array[i].avail == ArrayNode::AVAILABLE*/) {
			this->array[i].avail = ArrayNode::USED_IN_TREE;
		}
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
		if (array[i].avail != ArrayNode::USED_IN_TREE) {
			weight temp = *array[i].e.getWeight();
			temp = temp + w;
			array[i].ofv = max(temp.getVector(), temp.getDim());
		}
	}
}

void ArrayofEdges::UpdateBestPossibleAddition() {
	int index = 0;
	int minOFV = INT_MAX;
	Edge minEdge = this->array[0].e;
	for (int i = 0; i < numE; i++) {
		if(array[i].isCycle == false){
			if (array[i].avail == ArrayNode::AVAILABLE) {
				if (array[i].ofv < minOFV) {
					minOFV = array[i].ofv;
					minEdge = array[i].e;
					index = i;
				}
				else if (array[i].ofv == minOFV && array[i].e < minEdge) {
					minOFV = array[i].ofv;
					minEdge = array[i].e;
					index = i;
				}
			}
		}
		
	}
	if(index >= 0)
		this->current = index;
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
	for (int i = 0; i < numE; i++) {
		if (array[i].avail != ArrayNode::USED_IN_TREE) {
			if ((st.getVertex(array[i].e.getV1()).getKnown() == true) &&
				(st.getVertex(array[i].e.getV2()).getKnown() == true) && 
				(st.CanGetFrom(array[i].e.getV1(), array[i].e.getV2(),-1)==true))
			{
				array[i].isCycle = true;
			}
			else {
				array[i].isCycle = false;
			}
		}
	}
}