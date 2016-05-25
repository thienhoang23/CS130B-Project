#ifndef _ALGORITHM_H_
#define _ALGORTIHM_H_
#include "ArrayofEdges.h"
#include "SpanningTree.h"
#include "Graph.h"
#include "Stack.h"
#include "TrippletEdges.h"

void LocalIterativeImprovment(ArrayofEdges& E, SpanningTree& ST, Graph& const G) {
	int start, end;
	int current = 0;
	int size = 0;
	TrippletEdges* ArrayofTE = new TrippletEdges[E.getNumE()];
	for (int i = 0; i < E.getNumE(); i++) {
		if (E.getEdgeWrapperAt(i).isCycle == true) {
			start = E.getEdgeAt(i).getV1();
			end = E.getEdgeAt(i).getV2();
			size++;
		}
		TrippletEdges = FindBestPossibleReplacementEdge(ST, start, end, E.getEdgeAt(i));
	}
}

TrippletEdges FindBestPossibleReplacementEdge(SpanningTree& const ST, int start, int end, Edge e) {
	Stack* stack= new Stack();

}

//Edge* KILI();

//Edge* PILI();

//Edge* SILI();

//Edge* LILI();

//Edge* YILI();

#endif // !_ALGORITHM_H_