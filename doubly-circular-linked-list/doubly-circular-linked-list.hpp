template <class t>
class DCLLNode
{
public:
	DCLLNode(t* data, DCLLNode<t>* next = nullptr, DCLLNode<t>* previous = nullptr);
	~DCLLNode();

	DCLLNode(const DCLLNode<t>& other); // copy constructor
	DCLLNode<t>& operator=(const DCLLNode<t> other); // copy assignment operator

	t* data;
	DCLLNode<t>* next;
	DCLLNode<t>* previous;
};

template <class t>
class DCLList
{
public:
	DCLList(DCLLNode<t>* head = nullptr, DCLLNode<t>* tail = nullptr);
	~DCLList();

	bool isEmpty();
	void addToHead(const t data);
	void addToTail(const t data);
	t* deleteFromHead(); // delete the head and return its data
	t* deleteFromTail(); // delete the tail and return its data
	void deleteDCLLNode(t data);
	bool isInList(t data) const;

private:
	DCLLNode<t>* head;
	DCLLNode<t>* tail;
};

#include "doubly-circular-linked-list.inl"