#include "Heap.h"
#include "Helpers.h"

Heap::Heap() {
	occupied = 0;
	capacity = 28;
	array = new Edge[capacity+1];
}

Heap::Heap(const Heap& src) {
	//copy constructor
	this->occupied = src.occupied;
	this->capacity = src.capacity;
	this->array = new Edge[capacity+1];
	for (int i = 1; i <= occupied; i++)
		this->array[i] = src.array[i];
}

Heap& Heap::operator=(const Heap& rhs) {
	//overide assignment operator
	this->occupied = rhs.occupied;
	this->capacity = rhs.capacity;
	this->array = new Edge[capacity+1];
	for (int i = 1; i <= occupied; i++)
		this->array[i] = rhs.array[i];
	return *this;
}

void Heap::percolateUp(int index) {//for children
	if (index>occupied || index <= 1) //root
		return;
	if (array[index].compare(array[index / 2]) >= 0) 
		//compare with parent and in the right order
		return;
	if (array[index].compare(array[index / 2])<0) {
		swap(array[index], array[index / 2]);
		this->percolateUp(index / 2);
	}
	return;
}

void Heap::percolateDown(int index) {//for parent
	if (index * 2>occupied) //leaves
		return;
	int minChildIndex = minOf(index * 2, index * 2 + 1);
	if (array[index].compare(array[minChildIndex])<=0)
		//parents are less than children
		return;
	if (array[index].compare(array[minChildIndex])>0) {
		//Parents are more than children
		swap(array[index], array[minChildIndex]);
		percolateDown(minChildIndex);
	}
	return;
}

Edge Heap::deleteMin() {
	Edge MinNode = array[1];
	swap(array[1], array[occupied]);
	occupied--;
	percolateDown(1);
	return MinNode;
}

void Heap::insert(Edge* array, int size) {//used before makeHeap
	if (capacity < size) {
		capacity = size;
		delete this->array;
		this->array = new Edge[capacity+1];
	}
	occupied = size;
	for (int i = 1; i <= occupied; i++)
		this->array[i] = array[i];
}

void Heap::insert(Edge entry) {//used for consolidateTrie()
	if (occupied + 1>capacity)
		this->resize();
	array[occupied + 1] = entry;
	this->percolateUp(occupied + 1);
	this->occupied++;
}

void Heap::resize() {
	Edge* oldHeap = array;
	capacity = capacity * 2;
	array = new Edge[capacity+1];
	for (int i = 1; i <= occupied; i++)
		array[i] = oldHeap[i];
	delete[] oldHeap;
}

void Heap::makeHeap() {
	for (int i = occupied / 2; i >= 1; i--)
		this->percolateDown(i);
}

int Heap::minOf(int index1, int index2) const { //We will input left child first
	if (index2 > occupied) //because we won't call this method if we have no children
		return index1;
	if (array[index1].compare(array[index2])==0)
		return index2; 	//because we would care only about right child and the parent
	if (array[index1].compare(array[index2])<0)
		return index1;
	if (array[index1].compare(array[index2])>0)
		return index2;
	else
		return -1;
}
