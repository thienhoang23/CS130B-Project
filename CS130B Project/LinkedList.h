#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "Weight.h"
#include "Node.h"
#include <string>

class LinkedList {
private:
	Node* head, *tail;
public:
	Node* getTail() {return tail;}
	Node* getHead(){return head;}
	void add(int id, weight w);
	void add(Node* n);
	LinkedList();
	LinkedList(const LinkedList& l);
	LinkedList& operator =(const LinkedList& l);
	std::string toString();
	~LinkedList();
};

#endif // !_LINKEDLIST_H_
