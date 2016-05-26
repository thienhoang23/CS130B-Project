#ifndef STACK_UNIT_TEST_H_
#define STACK_UNIT_TEST_H_

#include "tddFuncs.h"
#include "Stack.h"

void RunAllStackUnitTests() {
	Stack* stack = new Stack();
	assertEquals(true, stack->isEmpty(), "EMPTY STACK TEST");
	assertEquals(-1, stack->peek(), "PEEK EMPTY STACK");
	stack->push(0);
	assertEquals("(0)", stack->toString(), "Push 0");
	assertEquals(0, stack->peek(), "PEEK AFTER 1 PUSH");
	stack->push(1);
	assertEquals("(1,0)", stack->toString(), "Push 1");
	assertEquals(1, stack->peek(), "PEEK AFTER 2 PUSHES");
	assertEquals(false, stack->isEmpty(), "NON EMPTy STACK TEST");
	StackNode* temp = stack->pop();
	assertEquals(1, temp->vertex_id, "First Pop");
	assertEquals(0, stack->peek(), "PEEK AFTER 1 POP");
	delete temp;
	temp = stack->pop();
	assertEquals(0, temp->vertex_id, "Second Pop");
	assertEquals(-1, stack->peek(), "PEEK AFTER 2 POPS");
	delete temp;
	assertEquals(true, stack->isEmpty(), "EMPTY TEST AFTER POPPING ALL");
	assertEquals("()", stack->toString(), "PRINT AN EMPTY LIST");
}

#endif // !STACK_UNIT_TEST_H_