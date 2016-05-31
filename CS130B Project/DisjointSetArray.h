#ifndef DISJOINT_SET_ARRAY_H
#define DISJOINT_SET_ARRAY_H

#include "DisjointSet.h"

class DisjointSetArray {
private:
	DisjointSet* array;
	int origSize;
	int curSize;
	DisjointSet** heads;
public:
	DisjointSetArray(int size) {
		array = new DisjointSet[size+1];
		heads = new DisjointSet*[size+1];
		origSize = size;
		curSize = size;
		for (int i = 0; i <= size; i++) {
			this->array[i].setID(i);
			heads[i] = &array[i];
		}
	}
	int getOrigSize() { return origSize; }
	DisjointSet* getHeadOfSet(int index) {
		return heads[index]->getHead();
	}
	int getCurSize() { return curSize; }
	void Union(int v1, int v2) {
		array[v1].Union(array[v2]);
	}
	bool inSameSet(int v1, int v2) {
		return array[v1] == array[v2];
	}
	bool inSameSet(DisjointSet& const d1, DisjointSet& const d2) {
		return d1 == d2;
	}
	bool VertexInHead(int v, int index) {
		return array[v] == *heads[index]->getHead();
	}
	void PathCompression() {
		for (int i = 1; i <= origSize; i++)
			array[i].PathCompression();
	}
	void Redefinition() {
		int index = 1;
		bool SameSet=false;
		for (int i = 1; i <= origSize; i++) {
			for (int j = 1; j <= index; j++) {
				if (inSameSet(array[i], *heads[j])) {
					SameSet = true;
					break;
				}
			}
			if (SameSet == false) {
				index++;
				heads[index] = &array[i];
				continue;
			}
			if (SameSet == true) {
				SameSet = false;
				continue;
			}
		}
		curSize = index;
	}
};
	
#endif // !DISJOINT_SET_ARRAY_H;