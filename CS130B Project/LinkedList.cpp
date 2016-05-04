#include "LinkedList.h"

LinkedList::LinkedList() {
	head = tail = nullptr;
}

//COPY CONSTRUCTOR
LinkedList::LinkedList(const LinkedList& l) {
	delete[] this;
	*this = l;
}

//ASSIGNMENT OPERATOR
LinkedList& LinkedList::operator=(const LinkedList& l) {
	if (head != nullptr)
		delete this;
	if (l.head == nullptr)
		return;
	this->head = new Node(l.head->vertex_id,l.head->w);
	this->tail = this->head;
	for (Node* it = l.head; it != nullptr; it = it->next)
		this->tail = new Node(it->vertex_id, it->w);
}

//DESCTRUCTOR
LinkedList::~LinkedList() {
	while (head != nullptr) {
		Node *cur= head;
		head = head->next;
		delete cur;
	}
	tail = head;
}

void LinkedList::add(Node* n) {
	this->tail->next = n;
	this->tail = n;
}

void LinkedList::add(int id, weight w) {
	this->tail->next = new Node(id, w);
	this->tail = tail->next;
}