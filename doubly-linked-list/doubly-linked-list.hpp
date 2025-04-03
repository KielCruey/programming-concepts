template <class t>
class DLLNode
{
public:
	DLLNode();
	DLLNode(const t& data, DLLNode<t> *next = nullptr, DLLNode<t> *previous = nullptr);
	~DLLNode() = default;

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

	// ====== getters/setters ======
	DLLNode<t>* getHead();
	DLLNode<t>* getTail();

	void setHead(DLLNode<t>* head);
	void setTail(DLLNode<t>* tail);

	// ====== functions ======
	bool isEmpty();
	bool isInList(t data) const;
	void addToHead(const t& data);
	void addToTail(const t& data);
	t* deleteDLLNode(t data);
	t* deleteFromHead(); // delete the head and return its data
	t* deleteFromTail(); // delete the tail and return its data
	
protected:
	DLLNode<t>* head;
	DLLNode<t>* tail;
};

#include "doubly-linked-list.inl"