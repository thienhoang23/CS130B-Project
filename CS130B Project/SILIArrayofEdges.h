#ifndef SILIArrayofEdges_H_
#define SILIArrayofEdges_H_

#include "ArrayofEdges.h"
#include "DisjointSet.h"
#include "SpanningTree.h"
#include "DisjointSetArray.h"
#include "Weight.h"

class SILIArrayofEdges :public ArrayofEdges {
public:
	SILIArrayofEdges(int numE) :ArrayofEdges(numE)
	{
	}
	void addEdge(Edge e) {
		array[current].DSAvail = false;
		ArrayofEdges::addEdge(e);
	}
	void addEdge(Edge* e) {
		this->addEdge(*e);
	}
	Edge getEdgeAt(int i) {
		return array[i].e;
	}
	void UpdateAvailForSet(DisjointSetArray& const DSArray, int index) {
		for (int i = 0; i < numE; i++) {
			if ((DSArray.VertexInHead(array[i].e.getV1(), index)&&
				!DSArray.VertexInHead(array[i].e.getV2(),index))||
				(DSArray.VertexInHead(array[i].e.getV2(), index) &&
				!DSArray.VertexInHead(array[i].e.getV1(), index)))
				//ONE IS IN THE SET, THE OTHER IS NOT
				array[i].DSAvail = true;
			else
				array[i].DSAvail = false;
		}
	}
	void UpdateOFV(weight w) {
		for (int i = 0; i < numE; i++) {
			if (array[i].avail != ArrayNode::USED_IN_TREE &&
				array[i].DSAvail == true) {
				weight temp = *array[i].e.getWeight();
				temp = temp + w;
				array[i].ofv = max(temp.getVector(), temp.getDim());
			}
		}
	}

	void RegularUpdateOFV(weight w) {
		for (int i = 0; i < numE; i++) {
			if (array[i].avail != ArrayNode::USED_IN_TREE) {
				weight temp = *array[i].e.getWeight();
				temp = temp + w;
				array[i].ofv = max(temp.getVector(), temp.getDim());
			}
		}
	}

	void UpdateBestPossibleAddition() {
		int index = 0;
		int minOFV = INT_MAX;
		Edge minEdge = this->array[0].e;
		for (int i = 0; i < numE; i++) {
			if (array[i].isCycle == false) {
				if (array[i].avail != ArrayNode::USED_IN_TREE &&
					array[i].DSAvail == true) {
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
		if (index >= 0)
			this->current = index;
	}
};
#endif // !SILIArrayofEdges_H_