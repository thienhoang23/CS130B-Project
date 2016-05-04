#ifndef _WEIGHT_H_
#define _WEIGHT_H_

class weight
{
private:
	int* vector;
	int dim;
public:
	weight();
	weight(int dim, int* vector);
	int compare(weight w);
	weight(const weight& w);
	weight& operator =(const weight& w);
};
#endif // !_WEIGHT_H_

