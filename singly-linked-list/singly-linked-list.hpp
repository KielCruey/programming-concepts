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

	// ====== getters/setters ======
	SLLNode<t>* getHead();
	SLLNode<t>* getTail();

	void setHead(SLLNode<t>* head);
	void setTail(SLLNode<t>* tail);

	// ====== functions ======
	void addToHead(t data);
	void addToTail(t data);
	bool isEmpty() const;
	bool isInList(t data) const;
	t* deleteFromHead(); // delete the head and return its data
	t* deleteFromTail(); // delete the tail and return its data
	t* deleteSLLNode(t nodeData);
	
private:
	SLLNode<t>* head;
	SLLNode<t>* tail;
};