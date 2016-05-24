#ifndef NODE_H
#define NODE_H

#include <string>

struct Node {
	//Variables
	int vertex_id;
	weight w;
	Node* next;
	
	//Constructor
	Node(int id, weight w) {
		this->vertex_id = id;
		this->next = nullptr;
		this->w = w;
	}

	//Method
	std::string toString() {
		return std::to_string(vertex_id);
	}
};

#endif // !NODE_H