#ifndef DISJOINT_SET_H_
#define DISJOINT_SET_H_

class DisjointSet{
private:
	int id;
	DisjointSet* pointer;
	struct DisjointSetLinkedList
	{
		//VARIALBLES
		DisjointSet* head;
		DisjointSet* tail;
		DisjointSet* next;
		//CONSTRUCTOR
		DisjointSetLinkedList() {
			head = tail = next = nullptr;
		}
		//METHODS
		void addMember(DisjointSet& d) {
			//USED FOR THE SET THAT GETS THE OTHER SET
			if (head == nullptr) {
				//cout << "GETTING SOME HEAD MOTHERFUCKER"<<endl;
				head = &d;
				tail = &d;
				return;
			}
			else {
				//cout << "GIVING THIS FUCKER ONE MORE MEMBER"<< endl;
				tail->Members.next = &d;
				tail = tail->Members.next;
				return;
			}
		}
		void PathCompression() {
			//USED FOR THE UNIONED SET
			//cout << "PATH COMPRESIION MOTHEFUKCER"<<endl;
			if (head == nullptr) {
				//cout << "HEAD EMPTY" << endl;
				return;
			}
			else
				for (DisjointSet* cur = head; cur != nullptr; cur = cur->Members.next)
					cur->PathCompression();
		}
	}Members;
	int size;
	void UnionHelper(DisjointSet& d1, DisjointSet& d2) {
		d2.pointer = &d1;
		d2.PathCompression();
		d1.Members.addMember(d2);
		d2.Members.PathCompression();
		for (DisjointSet* cur = d2.Members.head; cur != nullptr; cur = cur->Members.next) {
			d1.Members.addMember(*cur);
		}
		d1.size = d1.size + d2.size;
		return;
	}
public:
	DisjointSet() {
		id = 0;
		pointer = nullptr;
		Members = DisjointSetLinkedList();
		size = 1;
	}
	DisjointSet(int id) {
		this->id = id;		
		pointer = nullptr;
		Members = DisjointSetLinkedList();
		size = 1;
	}
	int getSize() { return size; }
	void setSize(int size) { this->size = size; }
	int getID() { return id; }
	void setID(int id) { this->id = id; }
	DisjointSet* getPointer() { return pointer; }
	DisjointSet* getHead() {
		if (this->pointer == nullptr)
			return this;
		else
			return this->pointer->getHead();
	}
	void Union(DisjointSet& d) {
		if (this->pointer == &d || d.pointer == this || this->id == d.id)
			//d points to this or this points to d => SAME SET ALREADY
			//OR They are the same
			return;
		if (this->pointer != nullptr && d.pointer != nullptr) {
			//NOT THE HEAD
			if (this->pointer == d.pointer)
				//POINT TO THE SAME HEAD => IN THE SAME SET
				return;
		}
		//ALWAYS POINT TO THE LESSER ONE
		if (this->id < d.id) {
			UnionHelper(*this, d);
			return;
		}
		else {
			UnionHelper(d,*this);
			return;
		}
		
	}
	void PathCompression() {
		if (this->pointer == nullptr)
			return;
		this->pointer = this->getHead();
	}
	friend bool operator == (DisjointSet& d1, DisjointSet& d2) {
		return d1.getHead() == d2.getHead();
	}
	friend bool operator != (DisjointSet& d1, DisjointSet& d2) {
		return !(d1 == d2);
	}
};
#endif // !DISJOINT_SET_H_