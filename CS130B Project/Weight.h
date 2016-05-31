#ifndef _WEIGHT_H_
#define _WEIGHT_H_

#include <iostream>
#include <string>

#include "Helpers.h"

class weight
{
private:
	int* vector;
	int dim;
	int cur;
public:
	~weight();
	weight();
	weight(int dim, int* vector);
	weight(int dim);
	void addValue(int val) {
		vector[cur] = val;
		cur++;
	}
	int* getVector() { return vector; }
	int getDim() { return dim; }
	int compare(weight w);
	weight(const weight& w);
	std::string toString();
	std::string Output() {
		std::string result = "";
		for (int i = 0; i < dim; i++) {
			if (i == dim - 1)
				result += std::to_string(vector[i]);
			else
				result += std::to_string(vector[i]) + " ";
		}
		return result;
	}
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

