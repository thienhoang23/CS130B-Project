#ifndef _HEAP_H_
#define _HEAP_H_

#include "Edge.h"

class Heap {
private:
	int occupied;
	int capacity;
	Edge* array;
	void percolateUp(int index);
	void percolateDown(int index);
	int minOf(int index1, int index2) const;
public:
	Heap();
	Heap(const Heap& src); //copy constructor
	Heap& operator=(const Heap& rhs); //override assignment operator
	Edge* getRoot() { return array; }
	Edge deleteMin();
	void insert(Edge* array,int size);//insert before makeHeap
	void insert(Edge entry);//insert during consolidateTrie
	void resize();
	void makeHeap();
};

#endif // !_HEAP_H_