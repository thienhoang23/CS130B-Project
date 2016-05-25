#include "Stack.h"
#include "StackNode.h"
#include <string>

Stack::Stack() {
	head = nullptr;
}

//DESCTRUCTOR
Stack::~Stack() {
	while (this->head != nullptr) {
		StackNode *cur = this->head;
		this->head = this->head->next;
		delete cur;
	}
}

std::string Stack::toString() {
	if (head == nullptr)
		return "()";
	std::string result = "(";
	for (StackNode* cur = head; cur != nullptr; cur = cur->next) {
		result += std::to_string(cur->vertex_id);
		if (cur->next!=nullptr)
			result += ",";
	}
	result += ")";
	return result;
}

void Stack::push(int id) {
	if (head == nullptr) 
		head = new StackNode(id);
	else {
		StackNode* temp = new StackNode(id);
		temp->next = head;
		head = temp;
	}
}

void Stack::push(StackNode*n) {
	n->next=head;
	head = n;
}

StackNode* Stack::pop() {
	if (head == nullptr)
		return nullptr;
	StackNode* temp = head;
	head = head->next;
	return temp;
}