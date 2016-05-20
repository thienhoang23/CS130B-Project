#ifndef NODE_H
#define NODE_H

#include <string>

struct Node {
	int vertex_id;
	Node* next;
	weight w;
	Node(int id, weight w) {
		this->vertex_id = id;
		this->next = nullptr;
		this->w = w;
	}
	std::string toString() {
		return std::to_string(vertex_id);
	}
};

#endif // !NODE_H