// a singly linked list only has node data and a pointer pointing to the next node. 

class SLLNode
{
public:
	SLLNode(int data, SLLNode* next = nullptr);

	int data;
	SLLNode* next;
};

class SLList
{
public:
	SLList(SLLNode* head = nullptr, SLLNode* tail = nullptr);
	~SLList();

	int isEmpty();
	void addToHead(int data);
	void addToTail(int data);
	int* deleteFromHead(); // delete the head and return its data
	int* deleteFromTail(); // delete the tail and return its data
	void deleteSLLNode(int nodeData);
	bool isInList(int data) const;

private:
	SLLNode* head;
	SLLNode* tail;
};