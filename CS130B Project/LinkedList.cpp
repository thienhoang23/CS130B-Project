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
	if (this->in(n->vertex_id) == true)
		return;
	this->tail->next = n;
	this->tail = n;
}

void LinkedList::add(int id, weight w) {
	if (tail == nullptr) {
		tail = new Node(id, w);
		head = tail;
		return;
	}
	if (this->in(id) == true)
		return;
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
	if (head->vertex_id == vertex_id) {
		//CHECK FOR WHEN THE TARGET IS AT HEAD
		Node* temp = head;
		if (tail == head) {
			head = tail = nullptr;
			delete temp;
		}
		else {
			head = head->next;
			delete temp;
		}
		return;
	}
	for (Node* cur = head; cur->next != nullptr; cur = cur->next) {
		if (cur->next->vertex_id == vertex_id) {
			//next node is the one we want to delete
			Node* temp = cur->next;
			if (tail == cur->next) //next node is the last node
			{
				tail = cur;
				cur->next = cur->next->next;
				delete temp;
				return;
			}
			else
			{
				cur->next = cur->next->next;
				delete temp;
				return;
			}
			return;
		}
	}
}

Node* LinkedList::getNode(int vertex_id) {
	if (in(vertex_id) == false)
		return nullptr;
	for (Node* cur = head; cur != nullptr; cur = cur->next)
		if (cur->vertex_id == vertex_id)
			return cur;
	return nullptr;
}