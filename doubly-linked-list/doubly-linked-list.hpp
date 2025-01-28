template <class t>
class DLLNode
{
public:
	DLLNode();
	DLLNode(const t& data, DLLNode<t> *next = nullptr, DLLNode<t> *previous = nullptr);

	t data;
	DLLNode<t>* previous;
	DLLNode<t>* next;
};

template <class t>
class DLList
{
public:
	DLList(DLLNode<t>* head = nullptr, DLLNode<t>* tail = nullptr);

	~DLList();

	bool isEmpty();
	void addToHead(t data);
	void addToTail(const t& data);
	t* deleteFromHead(); // delete the head and return its data
	t* deleteFromTail(); // delete the tail and return its data
	void deleteDLLNode(t nodeData);
	bool isInList(t data) const;

protected:
	DLLNode<t>* head;
	DLLNode<t>* tail;
};

#include "doubly-linked-list.inl"