#ifndef STACK_NODE_H
#define STACK_NODE_H


struct StackNode {
	//Variables
	int vertex_id;
	StackNode* next;

	//Constructor
	StackNode(int id) {
		this->vertex_id = id;
		this->next = nullptr;
	}

	//Method
	std::string toString() {
		return std::to_string(vertex_id);
	}
};

#endif // !STACK_NODE_H