#include "Helpers.h"

template<class T>
void swap(T& a, T& b) {
	T cur = a;
	b = a;
	a = cur;
}

template<class T>
T min(T* array, int size) {
	if (size <= 0)
		return;
	T min = array[0];
	for (int i = 0; i < size; i++)
		if (array[i] < min)
			min = array[i];
	return min;
}

template<class T>
T max(T* array, int size){
	if (size <= 0)
		return;
	T max = array[0];
	for (int i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}