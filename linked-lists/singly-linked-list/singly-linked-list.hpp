// a singly linked list only has node data and a pointer pointing to the next node. 
template <class t>
class SLLNode
{
public:
	SLLNode();
	SLLNode(t data, SLLNode<t>* next = nullptr);

	t data;
	SLLNode<t>* next;
};

template <class t>
class SLList
{
public:
	SLList(SLLNode<t>* head = nullptr, SLLNode<t>* tail = nullptr);
	~SLList();

	bool isEmpty();
	void addToHead(t data);
	void addToTail(t data);
	t* deleteFromHead(); // delete the head and return its data
	t* deleteFromTail(); // delete the tail and return its data
	void deleteSLLNode(t nodeData);
	bool isInList(t data) const;

private:
	SLLNode<t>* head;
	SLLNode<t>* tail;
};

#include "singly-linked-list.inl"


