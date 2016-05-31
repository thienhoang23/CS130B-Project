#ifndef DISJOINT_SET_ARRAY_UNIT_TEST
#define DISJOINT_SET_ARRAY_UNIT_TEST

#include "DisjointSet.h"
#include "DisjointSetArray.h"
#include "tddFuncs.h"

void RunAllDisjointSetArrayTests() {
	DisjointSetArray* DSA = new DisjointSetArray(5);
	assertEquals(false, DSA->inSameSet(1, 3), "No CONNECTION Yet");
	DSA->Union(1, 3);
	assertEquals(true, DSA->inSameSet(1, 3), "After Union 1 and 3");
	DSA->Redefinition();
	assertEquals(4, DSA->getCurSize(), "Test Redefinition after 1 Union on an array of 5");
	assertEquals(4, DSA->getHeadOfSet(3)->getID(), "Head at of Set 3 After Redefinition");
	assertEquals(true, DSA->VertexInHead(3, 1), "True Test Vertex in Head");
	assertEquals(false, DSA->VertexInHead(3, 2), "False Test Vertex in Head");
	DSA->Union(3, 4);
	assertEquals(true, DSA->inSameSet(1, 4), "Union 3 and 4");
	DSA->Redefinition();
	assertEquals(3, DSA->getCurSize(), "CurSize after Union 3 and 4");
	assertEquals(5, DSA->getHeadOfSet(3)->getID(), "Head at of Set 3 After 2nd Redefinition");
	assertEquals(true, DSA->VertexInHead(4, 1), "True Test Vertex in Head");
	assertEquals(false, DSA->VertexInHead(4, 3), "False Test Vertex in Head");
}

#endif // !DISJOINT_SET_ARRAY_UNIT_TEST