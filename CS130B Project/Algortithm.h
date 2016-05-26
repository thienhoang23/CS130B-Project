#ifndef _ALGORITHM_H_
#define _ALGORTIHM_H_
#include "ArrayofEdges.h"
#include "SpanningTree.h"
#include "Graph.h"
#include "Stack.h"
#include "TrippletEdges.h"

void LocalIterativeImprovment(ArrayofEdges& E, SpanningTree& ST, Graph& const G) {
	int start, end;
	int Min_ofv = ST.getOFV();
	int index = -1;
	int current = 0;
	int size = 0;
	TrippletEdges* ArrayofTE = new TrippletEdges[E.getNumE()];
	
	//CREATING AN ARRAY OF CYCLE FORMING EDGES ALONG WITH THEIR BEST CYCLE BREAKING EDGES
	for (int i = 0; i < E.getNumE(); i++) {
		if (E.getEdgeWrapperAt(i).isCycle == true && E.getEdgeWrapperAt(i).avail!=ArrayNode::USED_IN_TREE){
			start = E.getEdgeAt(i).getV1();
			end = E.getEdgeAt(i).getV2();
			size++;
		}
		/*
		TrippletEdges TE = FindBestPossibleReplacementEdge(ST, start, end, E.getEdgeAt(i));
		if (TE.ofv <= Min_ofv && TE.e1 != TE.e2) {
			Min_ofv = TE.ofv;
			index = size - 1;
		}
		ArrayofTE[size - 1] = TE;*/
	}

	//SUB THE BEST CYCLE FORMING EDGE FOR THE CYCLE BREAKING EDGE
	if (index >= 0) {
		ST.addEdges(ArrayofTE[index].e1);
		ST.removeEdge(ArrayofTE[index].e2);
		E.remove(ArrayofTE[index].e2);
		E.SetAvail(ArrayofTE[index].e1, ArrayNode::NOT_USED_IN_TREE);
	}
}
/*
TrippletEdges FindBestPossibleReplacementEdge(SpanningTree& const ST, int start, int end, Edge e) {
	Stack* stack= new Stack();
	stack->push(start);
	int val = ST.getVertex(start).getList()->getHead()->vertex_id;
	Node*
	while (val != end) {
		if()
		val = ST.getVertex(cur).getList()->getHead()->vertex_id
	}
	//BASE CASE: when cur == end
}
*/
SpanningTree KILI(Graph& const G, ArrayofEdges& E, SpanningTree& ST) {
	while (ST.getNumE != ST.getNumV - 1) {
		ST.addEdges(E.BestPossibleAddition);
		E.remove(E.BestPossibleAddition);
		E.Update(ST.getWeight());
		LocalIterativeImprovment(E, ST, G);
	}
	return ST;
}

//Edge* PILI();

//Edge* SILI();

//Edge* LILI();

//Edge* YILI();

#endif // !_ALGORITHM_H_