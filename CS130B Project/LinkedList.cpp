#include "LinkedList.h"
#include "Node.h"
#include <string>

LinkedList::LinkedList() {
	head = tail = nullptr;
}

//DESCTRUCTOR
LinkedList::~LinkedList() {
	while (this->head != nullptr) {
		Node *cur= this->head;
		this->head = this->head->next;
		delete cur;
	}
	this->tail = this->head;
}

void LinkedList::add(Node* n) {
	if (tail == nullptr) {
		tail = n;
		head = tail;
		return;
	}
	this->tail->next = n;
	this->tail = n;
}

void LinkedList::add(int id, weight w) {
	if (tail == nullptr) {
		tail = new Node(id, w);
		head = tail;
		return;
	}
	this->tail->next = new Node(id, w);
	this->tail = tail->next;
}

std::string LinkedList::toString() {
	if (head == nullptr)
		return "()";
	std::string result = "(";
	for (Node* cur = head; cur != nullptr; cur = cur->next) {
		result += std::to_string(cur->vertex_id);
		if (cur != tail)
			result += ",";			
	}
	result += ")";
	return result;
}

bool LinkedList::in(int vetex_id) {
	if (head == nullptr)
		return false;
	for (Node* cur = head; cur != nullptr; cur = cur->next) {
		if (cur->vertex_id == vetex_id)
			return true;
	}
	return false;
}

void LinkedList::remove(int vertex_id) {
	if (in(vertex_id) == false)
		return;
	for (Node* cur = head; cur != nullptr; cur = cur->next)
		if (cur->next->vertex_id == vertex_id) {
			Node* temp = cur->next;
			cur->next = cur->next->next;
			delete temp;
		}
	return;
}