#ifndef _VERTEX_H_
#define _VERTEX_H_
#include "LinkedList.h"

class Vertex
{
protected:
	LinkedList* l;
	int id;
	bool known;
public:
	Vertex(int id,LinkedList* list);
	Vertex();
	LinkedList* getList() { return l; }
	int getID() { return id; }
	void setID(int id) { this->id = id; }
};
#endif

