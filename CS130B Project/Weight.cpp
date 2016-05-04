#include "Weight.h"
#include <algorithm>

weight::weight(int dim, int* vector) {
	this->dim = dim;
	this->vector = new int[dim];
	for (int i = 0; i < dim; i++)
		this->vector[i] = vector[i];
}

int weight::compare(weight w) {
	if (std::min_element(this->vector[0], this->vector[dim - 1]) < std::min_element(w.vector[0], w.vector[dim - 1]))
		return -1;
	else if (std::min_element(this->vector[0], this->vector[dim - 1]) == std::min_element(w.vector[0], w.vector[dim - 1])) {
		if (std::max_element(this->vector[0], this->vector[dim - 1]) < std::max_element(w.vector[0], w.vector[dim - 1]))
			return -1;
		if (std::max_element(this->vector[0], this->vector[dim - 1]) == std::max_element(w.vector[0], w.vector[dim - 1]))
			return 0;
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
};

weight::weight() {
	dim = 0;
	vector = NULL;
}