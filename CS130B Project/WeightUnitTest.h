#ifndef WEIGHT_UNIT_TEST_H
#define WEIGHT_UNIT_TEST_H

#include "tddFuncs.h"
#include "Weight.h"
#include <iostream>

using namespace std;

void TestWeightConstructor() {
	//TEST DEFAULT CONSTRUCTOR
	weight* w0 = new weight();
	string actualValue0 = w0->toString();
	assertEquals("", actualValue0, "Default Constructor");
	delete w0;
	//TEST DIMENSION 1 VECTOR
	int arr1[1] = { 1 };
	weight* w1 = new weight(1, arr1);
	string actualValue1 = w1->toString();
	assertEquals("(1)", actualValue1, "Dimension One Vector Constructor");
	delete w1;
	//TEST DIM 2 VECTOR
	int arr2[2] = { 1,2 };
	weight* w2 = new weight(2, arr2);
	string actualValue2 = w2->toString();
	assertEquals("(1,2)", actualValue2, "Dimension Two Vector Constructor");
	delete w2;
	//TEST DIM 3 VECTOR
	int arr3[3] = { 1,2,3 };
	weight* w3 = new weight(3, arr3);
	string actualValue3 = w3->toString();
	string expectedValue3 = "(1,2,3)";
	assertEquals(expectedValue3, actualValue3, "Dimension Three Vector Constructor");
	delete w3;
}
void TestWeightAdding() {
	//Test DIM 1 Vector
	int arr1[1] = { 1 };
	weight w1 = weight(1, arr1);
	weight w2 = weight(1, arr1);
	weight w12 = w1 + w2;
	string actual = w12.toString();
	string expect = "(2)";
	assertEquals(expect, actual, "Adding Dimension One Vector");

	//Test DIM 2 Vector
	int arr2[2] = { 1,2 };
	w1 = weight(2, arr2);
	w2 = weight(2, arr2);
	w12 = w1 + w2;
	actual = w12.toString();
	expect = "(2,4)";
	assertEquals(expect, actual, "Adding Dimension Two Vector");
}

void TestWeightMinus() {
	//Test DIM 1 Vector
	int arr1[1] = { 1 };
	weight w1 = weight(1, arr1);
	weight w2 = weight(1, arr1);
	weight w12 = w1 - w2;
	string actual = w12.toString();
	string expect = "(0)";
	assertEquals(expect, actual, "Minus Dimension One Vector");

	//Test DIM 2 Vector
	int arr2[2] = { 1,2 };
	w1 = weight(2, arr2);
	w2 = weight(2, arr2);
	w12 = w1 - w2;
	actual = w12.toString();
	expect = "(0,0)";
	assertEquals(expect, actual, "Minus Dimension One Vector");
}

void TestWeightComparisonMethod() {
	int arr1[2] = { 1,2 };
	weight w1 = weight(2, arr1);
	int arr2[2] = { 3,4 };
	weight w2 = weight(2, arr2);
	weight w3 = weight(2, arr2);
	int arr3[2] = { 1,4 };
	weight w4 = weight(2, arr3);
	assertEquals(-1, w1.compare(w2), "Less Than Test");
	assertEquals(1, w2.compare(w1), "More Than Test");
	assertEquals(0, w2.compare(w3), "Equal Test");
	assertEquals(-1, w1.compare(w4), "Less Than Test with Equal Min");
	assertEquals(1, w4.compare(w1), "More Than Test with Equal Min");
}

void TestWeightEqualOperator() {
	int arr1[2] = { 1,2 };
	weight w1 = weight(2, arr1);
	weight w2 = weight(2, arr1);
	int arr2[2] = { 3,4 };
	weight w3 = weight(2, arr2);
	assertEquals(true, w1 == w1, "Equal To Self");
	assertEquals(true, w1 == w2, "Equal To Different Vector");
	assertEquals(false, w3 == w1, "Not Equal");
}

void TestWeightGreaterOperator() {
	int arr1[2] = { 1,2 };
	weight w1 = weight(2, arr1);
	weight w2 = weight(2, arr1);
	int arr2[2] = { 3,4 };
	weight w3 = weight(2, arr2);
	int arr3[2] = { 1,4 };
	weight w4 = weight(2, arr3);
	assertEquals(false, w1 > w1, "Greater Than To Self");
	assertEquals(false, w1 > w2, "Greater than Equal");
	assertEquals(true, w3 > w1, "True Greater");
	assertEquals(true, w4 > w1, "True Greater With Same Min");
}

void RunAllWeightUnitTests() {
	TestWeightConstructor();
	TestWeightAdding();
	TestWeightMinus();
	TestWeightComparisonMethod();
	TestWeightEqualOperator();
	TestWeightGreaterOperator();
}

#endif // !WEIGHT_UNIT_TEST_H