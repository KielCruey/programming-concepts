template <class t>
class SCLLNode
{
public:
	SCLLNode();
	SCLLNode(t data, SCLLNode<t>* next = nullptr);
	~SCLLNode() = default;

	t data;
	SCLLNode<t>* next;
};

template <class t>
class SCLList
{
public:
	SCLList(SCLLNode<t>* current = nullptr);
	~SCLList();

	// ----- getters/setters -----
	SCLLNode<t>* getCurrent();
	void setCurrent(SCLLNode<t>* current);

	// ----- functions -----
	bool isEmpty();
	void addToHead(t data);
	void addToTail(const t& data);
	t* deleteFromHead(); // delete the head and return its data
	t* deleteFromTail(); // delete the tail and return its data
	void deleteCSLLNode(t nodeData);
	bool isInList(t data) const;

protected:
	SCLLNode<t>* current;
};

#include "singly-circular-linked-list.inl"