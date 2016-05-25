#ifndef STACK_NODE_H_
#define STACK_NODE_H_
#include "StackNode.h"

class Stack
{
private:
	StackNode* head;
public:
	Stack();
	StackNode* getHead() { return head; }
	void push(int id);
	void push(StackNode* n);
	std::string toString();
	StackNode* pop();
	int peek() {
		if (head == nullptr)
			return -1;
		return head->vertex_id;
	}
	~Stack();
}
#endif // !STACK_NODE_H_