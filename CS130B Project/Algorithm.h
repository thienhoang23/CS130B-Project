#ifndef _ALGORITHM_H_
#define _ALGORTIHM_H_
#include "ArrayofEdges.h"
#include "SpanningTree.h"
#include "Graph.h"
#include "Stack.h"
#include "TrippletEdges.h"
#include "Node.h"
#include "Helpers.h"
#include "Weight.h"
#include "PILIArrayofEdges.h"
#include "SILIArrayofEdges.h"
#include "DisjointSet.h"
#include "DisjointSetArray.h"

bool FindBestPossibleReplacementEdgeHelper(SpanningTree& const ST, int start, int end, 
	int called, Stack& stack) 
{
	if (ST.getVertex(start).getID() == end) {
		return true;
	}
	if (ST.isLeaf(start) && called != -1) //Avoid the start case
		return false;
	if (ST.isNeighbor(start, end)) {
		stack.push(end);
		return true;
	}
	for (Node* cur = ST.getVertex(start).getList()->getHead(); cur != nullptr; cur = cur->next) {
		if (cur->vertex_id == called)
			continue;
		stack.push(cur->vertex_id);
		bool result_of_rec = FindBestPossibleReplacementEdgeHelper(ST, stack.peek(), end, start, stack);
		if (result_of_rec == true)
			return true;
		else
			stack.pop();
	}
	return false;
}

TrippletEdges FindBestPossibleReplacementEdge(SpanningTree& const ST, ArrayofEdges& AE, int start, int end, Edge e) {
	//USE To create the best replacement edge for each cycle forming edge
	//Might or might not be valid replacement
	Stack* stack = new Stack();
	stack->push(start);
	FindBestPossibleReplacementEdgeHelper(ST, start, end, -1, *stack);
	//Stack contains all the cycle breaking edges in the loop from start to end
	int minOFV = INT_MAX;
	int V1 = e.getV1();
	int V2 = e.getV2();
	int v2 = stack->pop()->vertex_id;
	Edge BestReplacementEdge = *AE.getEdge(v2,stack->peek());
	while (!stack->isEmpty()) {
		int v1 = stack->pop()->vertex_id;
		weight w = ((*ST.getWeight() + *e.getWeight()) - *AE.getEdge(v1, v2)->getWeight());
		int ofv = max(w.getVector(), w.getDim());
		if (ofv < minOFV || ((ofv == minOFV) && (*AE.getEdge(v1, v2)<BestReplacementEdge))) {
			V1 = v1;
			V2 = v2;
			BestReplacementEdge = *AE.getEdge(V1, V2);
			minOFV = ofv;
		}
		v2 = v1;
	}
	TrippletEdges* TE;
	if (V1 != e.getV1() || V2 != e.getV2())
		TE = new TrippletEdges(e, *AE.getEdge(V1, V2), minOFV);
	else
		TE = new TrippletEdges(e, e, minOFV);
	return *TE;
}

void LocalIterativeImprovement(ArrayofEdges& AE, SpanningTree& ST, Graph& const G) {
	while (true)
	{
		int start, end;
		int Min_ofv = ST.getOFV();
		int index = -1;
		int size = 0;
		TrippletEdges* ArrayofTE = new TrippletEdges[AE.getNumE()];
		TrippletEdges TE;

		//CREATING AN ARRAY OF CYCLE FORMING EDGES ALONG WITH THEIR BEST CYCLE BREAKING EDGES
		for (int i = 0; i < AE.getNumE(); i++) {
			if (AE.getEdgeWrapperAt(i).isCycle == true &&
				AE.getEdgeWrapperAt(i).avail != ArrayNode::USED_IN_TREE) {
				start = AE.getEdgeAt(i).getV1();
				end = AE.getEdgeAt(i).getV2();
				size++;
				TE = FindBestPossibleReplacementEdge(ST, AE, start, end, AE.getEdgeAt(i));
			}
			//MAKE SURE THAT THE PAIR OF EDGES IS A POSSIBLE REPLACEMENT
			//ALSO KEEPING TRACK OF THE MinOFV POSITION FOR FAST ACCESS
			if (TE.ofv < Min_ofv && TE.e1 != TE.e2) {
				//Checking Validity
				//Only consider the valid cases for substitution
				Min_ofv = TE.ofv;
				index = size - 1;
			}
			ArrayofTE[size - 1] = TE;
		}

		//SUB THE BEST CYCLE FORMING EDGE FOR THE CYCLE BREAKING EDGE
		if (index >= 0) {
			//cout << "SUBING " << ArrayofTE[index].e1.toString() << " TO " << ArrayofTE[index].e2.toString() << endl;
			ST.addEdges(ArrayofTE[index].e1);
			ST.removeEdge(&ArrayofTE[index].e2);
			AE.remove(ArrayofTE[index].e1);
			AE.SetAvail(ArrayofTE[index].e2, ArrayNode::NOT_USED_IN_TREE);
			AE.Update(ST);
		}
		else
			return;
	}
	
}

void KILI(Graph& const G, ArrayofEdges& AE, SpanningTree& ST) {
	AE.UpdateBestPossibleAddition();
	while (ST.getNumE() != ST.getNumV() - 1) {
		ST.addEdges(AE.BestPossibleAddition());
		AE.remove(AE.BestPossibleAddition());
		AE.Update(ST);
		LocalIterativeImprovement(AE, ST, G);
	}
}

void PILI(Graph& const G, PILIArrayofEdges& AE, SpanningTree& ST) {
	ST.getVertex(1).setKnown(true);
	AE.UpdateAvail(ST);
	AE.UpdateBestPossibleAddition();
	while (ST.getNumE() != ST.getNumV() - 1) {
		ST.addEdges(AE.BestPossibleAddition());
		AE.remove(AE.BestPossibleAddition());
		AE.Update(ST);
		LocalIterativeImprovement(AE, ST, G);
	}
}

void SILI(Graph& const G, SILIArrayofEdges& SAE, SpanningTree& ST) {
	DisjointSetArray* DSA = new DisjointSetArray(G.getNumV());
	while (ST.getNumE() != ST.getNumV() - 1) {
		ArrayofEdges* AE = new ArrayofEdges(DSA->getCurSize()); //Empty Array of Edges to add in the best for each edge
		for (int i = 1; i <= DSA->getCurSize(); i++) {
			//Only Update with regard to the number of disjoint sets
			SAE.UpdateAvailForSet(*DSA, i);
			SAE.Update(ST); //Update the best edge for each set
			AE->addEdge(SAE.BestPossibleAddition());
		}
		for (int i = 0; i < DSA->getCurSize(); i++) {
			AE->DetectCycleFormingEdges(ST);
			if (AE->getEdgeWrapperAt(i).avail != ArrayNode::USED_IN_TREE &&
				AE->getEdgeWrapperAt(i).isCycle == false) {
				ST.addEdges(AE->getEdgeAt(i));
				SAE.remove(AE->getEdgeAt(i));
				DSA->Union(AE->getEdgeAt(i).getV1(), AE->getEdgeAt(i).getV2());
			}
		}
		SAE.DetectCycleFormingEdges(ST);
		SAE.RegularUpdateOFV(*ST.getWeight());
		LocalIterativeImprovement(SAE, ST, G);
		DSA->Redefinition();
	}
}

void FILI(Graph& const G, ArrayofEdges& AE, SpanningTree& ST) {
	for (int i = 1; i < G.getNumV(); i++) {
		ST.addEdges(i, i + 1, G.getEdgeWeight(i, i + 1));
	}
	AE.Update(ST);
	LocalIterativeImprovement(AE, ST, G);
}

void YILI(Graph& const G, ArrayofEdges& AE, SpanningTree& ST) {
	return;
}

#endif // !_ALGORITHM_H_