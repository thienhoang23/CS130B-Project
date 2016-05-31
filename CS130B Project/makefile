all: executeiy

executeit: Main.o Algorithm.o ArrayNode.o ArrayofEdges.o DisjointSet.o DisjointSetArray.o Edge.o Graph.o Helpers.o LinkedList.o Node.o PILIArrayofEdges.o SILIArrayofEdges.o SpanningTree.o Stack.o StackNode.o TrippletEdges.o Vertex.o Weight.o
	g++ -g -o executeit  Main.o Algorithm.o ArrayNode.o ArrayofEdges.o DisjointSet.o DisjointSetArray.o Edge.o Graph.o Helpers.o LinkedList.o Node.o PILIArrayofEdges.o SILIArrayofEdges.o SpanningTree.o Stack.o StackNode.o TrippletEdges.o Vertex.o Weight.o


Algorithm.o: Algorithm.h SpanningTree.h Graph.h Stack.h TrippletEdges.h Node.h Helpers.h Weight.h PILIArrayofEdges.h SILIArrayofEdges.h DisjointSet.h DisjointSetArray.h
	g++ -c -g Algorithm.h

ArrayNode.o: ArrayNode.h Edge.h
	g++ -c -g ArrayNode.h

ArrayofEdges.o: ArrayofEdges.h ArrayofEdges.cpp ArrayNode.h Edge.h Weight.h SpanningTree.h
	g++ -c -g ArrayofEdges.cpp

DisjointSet.o: DisjointSet.h 
	g++ -c -g DisjointSet.h

DisjointSetArray.o: DisjointSetArray.h DisjointSet.h
	g++ -c -g DisjointSetArray.h

Edge.o: Edge.h Edge.cpp Weight.h
	g++ -c -g Edge.cpp

Graph.o: Graph.h Graph.cpp Vertex.h Weight.h Edge.h
	g++ -c -g Graph.cpp

Helpers.o: Helpers.h
	g++ -c -g Helpers.h

LinkedList.o: LinkedList.h LinkedList.cpp Weight.h Node.h
	g++ -c -g LinkedList.cpp

Node.o: Node.h
	g++ -c -g Node.h

PILIArrayofEdges.o: PILIArrayofEdges.h ArrayofEdges.h Edge.h SpanningTree.h ArrayNode.h Weight.h
	g++ -c -g PILIArrayofEdges.h

SILIArrayofEdges.o: SILIArrayofEdges.h ArrayofEdges.h DisjointSet.h SpanningTree.h DisjointSetArray.h Weight.h
	g++ -c -g SILIArrayofEdges.h

SpanningTree.o: SpanningTree.h SpanningTree.cpp Graph.h Weight.h Edge.h Helpers.h
	g++ -c -g SpanningTree.cpp

Stack.o: Stack.h Stack.cpp StaclNode.h
	g++ -c -g Stack.cpp

StackNode.o: StackNode.h
	g++ -c -g StackNode.h

TrippletEdges.o: TrippletEdges.h Edge.h
	g++ -c -g TrippletEdges.h

Vertex.o: Vertex.h Vertex.cpp LinkedList.h
	g++ -c -g Vertex.cpp

Weight.o: Weight.h Weight.cpp Helper.h
	g++ -c -g Weight.cpp

Main.o: Main.cpp Graph.h Algorithm.h ArrayofEdges.h PILIArrayofEdge.h SILIArrayofEdges.h SpanningTree.h
	g++ -c -g Main.cpp

clean:
	-rm *.o *~ *# executeit
