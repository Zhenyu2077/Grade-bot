//CIS554 HW1
//Due: 11:59PM, Wednesday ( September 9)
//Do not modify main funaiton.
//Do not introduce new functions.
//In-place implementation is required.  Exteranl stuctures are not allowed.
//For example, you are not allowed to copy linked list values to outside, and then process the data and copy them
//back to linked list.

#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;


class Node {
public:
	int value;
	Node* next;
	Node* previous;
	Node() { next = previous = nullptr; }//default constructor
	Node(int i) { value = i; next = previous = nullptr;  db[this] = i; }//constructor

	void* operator new (size_t size) {
		Node* p = ::new Node();
		elementNum++;
		elementCreated++;
		return p;
	}

	void operator delete(void* p)
	{
		elementNum--;
		elementDeleted++;
		db.erase(p);
		::delete(p);
	}

	static void clearNodes() { elementCreated = 0; elementDeleted = 0; db.clear(); }

	static unordered_map<void*, int> db;
	static int elementNum;
	static int elementCreated;
	static int elementDeleted;

};

class DoublyLinkedList {
public:
	Node* head;
	Node* tail;
	DoublyLinkedList() { head = tail = nullptr; }
	void makeRandomList(int m, int n);
	void printForward();
	void printBackward();

	//inplement the following member functions:

	void group();
	void correct_group();
	/*
	Group all occurances of the same numbers together accourding to the order of appearance.

	For a list with values

	7 6 12 4 33 12 6 6 7 ,

	after grouping, it becomes

	7 7 6 6 6 12 12 4 33

	Note that in the original sequence, 7 appears before 6 before 12 before 4 before 33
	*/
	bool isSorted(const DoublyLinkedList& d);
	DoublyLinkedList(const std::initializer_list<int>& V);
	bool compareForward(const DoublyLinkedList& d);
	bool compareBackward(const DoublyLinkedList& d);
	void clearList() {
		if (head == tail && head == nullptr) return;
		Node* p = head;
		while (p != tail) {
			head = p->next;
			delete p;
			p = head;
		}
		delete p;
		head = tail = nullptr;
	}

	~DoublyLinkedList() {
		clearList();
	}
};

