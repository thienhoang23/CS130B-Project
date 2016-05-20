#ifndef LINKED_LIST_UNIT_TEST_H
#define LINKED_LIST_UNIT_TEST_H

#include "tddFuncs.h"
#include "LinkedList.h"
#include "Node.h"
#include "Weight.h"
#include <iostream>

using namespace std;

void TestLinkedListConstructor() {
	//DEFAULT CONSTRUCTOR
	LinkedList* l = new LinkedList();
	assertEquals("()", l->toString(), "Default Constructor");
	delete l;
}

void TestLinkedListAdding(){
	LinkedList* l = new LinkedList();
	int arr[1] = { 1 };
	weight w = weight(1, arr);
	std::cout << "Adding by id and weight" << std::endl;
	l->add(0, w);
	assertEquals("(0)", l->toString(), "Adding 1 node");
	assertEquals("0", l->getHead()->toString(), "Correct head position");
	assertEquals("0", l->getTail()->toString(), "Correct tail position");
	l->add(1, w);
	assertEquals("(0,1)", l->toString(), "Adding 2 node");
	assertEquals("0", l->getHead()->toString(), "Correct head position");
	assertEquals("1", l->getTail()->toString(), "Correct tail position");
	std::cout << "Adding by Node" << std::endl;
	Node* n = new Node(0, w);
	l->add(n);
	assertEquals("(0,1,0)", l->toString(),"Adding by Node");
	assertEquals("0", l->getHead()->toString(), "Correct head position");
	assertEquals("0", l->getTail()->toString(), "Correct tail position");
	delete l;
}

void RunAllLinkedListUnitTests() {
	TestLinkedListConstructor();
	TestLinkedListAdding();
}

#endif // !LINKED_LIST_UNIT_TEST_H