#include "Vertex.h"
#include "LinkedList.h"

Vertex::Vertex(int id, LinkedList list) {
	this->id = id;
	this->l = list;
	this->known = false;
}

Vertex::Vertex() {
	id = 0;
	l = LinkedList();
	this->known = false;
}