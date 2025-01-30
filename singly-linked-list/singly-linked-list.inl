// =============== SLLNode ===============
template<class t>
SLLNode<t>::SLLNode() :
	data(0), next(0)
{ }

template<class t>
SLLNode<t>::SLLNode(t data, SLLNode<t>* next) :
	data(data), next(next)
{ }

// =============== SLLNode ===============
template <class t>
SLList<t>::SLList(SLLNode<t>* head, SLLNode<t>* tail) : 
	head(head), tail(tail)
{ }

template <class t>
SLList<t>::~SLList() {
	// edge condition -- checks if the list has no nodes at all
	if (isEmpty())
		return;

	// deletes every node
	for (SLLNode<t>* p; isEmpty();)
	{
		p = head->next;
		delete head;
		head = p;
	}
}

template <class t>
bool SLList<t>::isEmpty() {
	return head == nullptr;
}

template <class t>
void SLList<t>::addToHead(t data) {
	SLLNode<t>* tmp = new SLLNode<t>(data);
	tmp->next = head; // current head is tmp's next node
	head = tmp; // head is now pointing to tmp

	// checks if the list is empty
	if (tail == nullptr)
		tail = head;
}

template <class t>
void SLList<t>::addToTail(t data) {
	// if not empty
	if (tail != nullptr)
	{
		tail->next = new SLLNode<t>(data); // tail's next node is the new node
		tail = tail->next; // tail is now pointing to 
	}
	// if empty, then tail and head are the same node
	else
		head = tail = new SLLNode<t>(data);
}

template <class t>
// returns content from deleted head node
t* SLList<t>::deleteFromHead() {
	// list is not empty
	if (!isEmpty())
	{
		int data = head->data; // creates new data for the delete node - it will be returned
		SLLNode<t>* tmp = head;

		// only one node in the list
		if (head == tail)
			head = tail = nullptr;
		else
			head = head->next; // assigning head to next node

		delete tmp;

		return &data;
	}
	else
		return nullptr;
}

template <class t>
t* SLList<t>::deleteFromTail() {
	// edge condition -- list is empty
	if (!isEmpty())
	{
		int data = tail->data;

		// only one node to delete
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
		}
		// more than one node in list
		else
		{
			SLLNode<t>* tmp;

			// finds the second to last node,
			// because singly linked list doesn't allow to go back one node
			for (tmp = head; tmp->next != tail; tmp = tmp->next);

			delete tail;
			tail = tmp;
			tail->next = nullptr; // makes sure tail's next nodes is null
		}

		return &data;
	}
	else
		return nullptr;
}

template <class t>
void SLList<t>::deleteSLLNode(t nodeData) {
	// if not a empty list
	if (head != nullptr) {
		// only one node in the list
		if (head == tail && nodeData == head->data)
		{
			delete head;
			head = tail = nullptr;
		}
		// if data are happens to be head's data, but more than one node
		else if (nodeData == head->data)
		{
			SLLNode<t>* tmp = head;
			head = head->next;
			delete tmp;
		}
		// data is somewhere in the middle of the linked list
		else
		{
			SLLNode<t>* current, * forward;

			// current and forward move until forward has the node with the data, and it's not the last node in the list
			for (current = head, forward = head->next;
				forward != nullptr && !(forward->data == nodeData);
				current = current->next, forward = forward->next);

			if (forward != nullptr)
			{
				current->next = forward->next; // current points to forward's next node, ultimately skipping cur node all together

				// edge conition, if forward node is actually the tail node
				if (forward == tail)
					tail = current;

				delete forward;
			}
		}
	}
}

template <class t>
bool SLList<t>::isInList(t data) const {
	SLLNode<t>* tmp;

	// searches for the data in the list
	for (tmp = head; tmp != nullptr && !(tmp->data == data); tmp = tmp->next);

	return tmp != nullptr;
}
