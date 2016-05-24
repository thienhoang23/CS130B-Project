#include "Vertex.h"
#include "LinkedList.h"
#include "Node.h"

Vertex::Vertex(int id, LinkedList* list) {
	this->id = id;
	this->l = list;
	this->known = false;
}

Vertex::Vertex() {
	id = 0;
	l = new LinkedList();
	this->known = false;
}

bool Vertex::isConnected(int vertex_id) {
	return l->in(vertex_id);
}

void Vertex::RemoveConnection(int vertex_id) {
	return l->remove(vertex_id);
}