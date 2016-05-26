#ifndef STACK_H_
#define STACK_H_

#include "StackNode.h"
#include <string>

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
	bool isEmpty() {
		return head == nullptr;
	}
	StackNode* pop();
	int peek() {
		if (head == nullptr)
			return -1;
		return head->vertex_id;
	}
	~Stack();
};
#endif // !STACK_H_