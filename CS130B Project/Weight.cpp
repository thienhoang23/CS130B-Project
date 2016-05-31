#include "Weight.h"
#include "Helpers.h"
#include <iostream>
#include <string>

weight::weight() {
	this->dim = 0;
	this->cur = 0;
	this->vector = nullptr;
}

weight::weight(int dim, int* vector) {
	this->dim = dim;
	this->cur = dim-1;
	this->vector = new int[dim];
	for (int i = 0; i < dim; i++)
		this->vector[i] = vector[i];
}

weight::~weight() {
	delete[] vector;
}

weight::weight(int dim) {
	this->dim = dim;
	this->cur = 0;
	this->vector = new int[dim];
	for (int i = 0; i < dim; i++)
		this->vector[i] = 0;
}

int weight::compare(weight w) {
	if (min(this->vector, this->dim) < min(w.vector, w.dim))
		return -1;
	else if (min(this->vector, this->dim) == min(w.vector, w.dim)) {
		if (max(this->vector, this->dim) < max(w.vector, w.dim))
			return -1;
		else if (max(this->vector, this->dim) == max(w.vector, w.dim))
			return 0;
		else
			return 1;
	}
	else
		return 1;
}

weight::weight(const weight& w) {
	this->dim = w.dim;
	this->vector = new int[dim];
	for (int i = 0; i < dim; i++)
		this->vector[i] = w.vector[i];
}

weight& weight::operator =(const weight& w){
	delete this->vector;
	this->dim = w.dim;
	this->vector = new int[dim];
	for (int i = 0; i < dim; i++)
		this->vector[i] = w.vector[i];
	return *this;
};

std::string weight::toString(){
	if(vector == nullptr)
		return "";
	std::string result = "(";
	for(int i=0;i<dim;i++){
		if(i!=dim-1){
			result+=std::to_string(vector[i]);
			result+= ',';
		}
		else
			result+= std::to_string(vector[i]);
	}
	result+= ')';
	return result;
}

weight operator +(weight& w1, weight& w2) {
	if (w1.dim != w2.dim)
		return w1;
	weight result = w1;
	for (int i = 0; i < w1.dim; i++)
		result.vector[i] += w2.vector[i];
	return result;
}
weight operator -(weight& w1, weight& w2) {
	if (w1.dim != w2.dim)
		return w1;
	weight result = w1;
	for (int i = 0; i < w1.dim; i++)
		result.vector[i] -= w2.vector[i];
	return result;
}

bool operator ==(weight& w1, weight& w2) {
	return (w1.compare(w2) == 0);
}

bool operator >(weight& w1, weight& w2) {
	return (w1.compare(w2) == 1);
}

bool operator !=(weight& w1, weight& w2) {
	return !(w1 == w2);
}

bool operator >=(weight& w1, weight& w2) {
	return (w1>w2)||(w1==w2);
}

bool operator <(weight& w1, weight& w2) {
	return (w1.compare(w2)) == -1;
}

bool operator <=(weight& w1, weight& w2) {
	return !(w1>w2);
}