#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "Weight.h"

class LinkedList {
private:
	struct Node {
		int vertex_id;
		Node* next;
		weight w;
		Node(int id, weight w) {
			this->vertex_id = id;
			this->next = nullptr;
			this->w = w;
		}
	};
	Node* head, *tail;
public:
	Node* getTail() {return tail;}
	Node* getHead(){return head;}
	void add(int id, weight w);
	void add(Node* n);
	LinkedList();
	LinkedList(const LinkedList& l);
	LinkedList& operator =(const LinkedList& l);
	~LinkedList();
};

#endif // !_LINKEDLIST_H_
