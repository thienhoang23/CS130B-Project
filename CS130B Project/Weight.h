#ifndef _WEIGHT_H_
#define _WEIGHT_H_

#include <iostream>

#include "Helpers.h"

class weight
{
private:
	int* vector;
	int dim;
public:
	~weight();
	weight();
	weight(int dim, int* vector);
	weight(int dim);
	int* getVector() { return vector; }
	int getDim() { return dim; }
	int compare(weight w);
	weight(const weight& w);
	std::string toString();
	weight& operator =(const weight& w);
	friend weight operator +(weight& w1, weight& w2);
	friend weight operator -(weight& w1, weight& w2);
	friend bool operator ==(weight& w1, weight& w2);
	friend bool operator !=(weight& w1, weight& w2);
	friend bool operator >(weight& w1, weight& w2);
	friend bool operator >=(weight& w1, weight& w2);
	friend bool operator <(weight& w1, weight& w2);
	friend bool operator <=(weight& w1, weight& w2);
};
#endif // !_WEIGHT_H_

