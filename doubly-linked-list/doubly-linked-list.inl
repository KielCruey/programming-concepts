// ========== DLLNode ==========
template <class t>
DLLNode<t>::DLLNode() :
	data(0), previous(nullptr), next(nullptr)
{ }

template<class t>
DLLNode<t>::DLLNode(const t& data, DLLNode<t>* next, DLLNode<t>* previous) :
	data(data), previous(previous), next(next)
{ }

// ========== DLList ==========
template<class t>
DLList<t>::DLList(DLLNode<t>* head, DLLNode<t>* tail) :
	head(head), tail(tail)
{ }

template<class t>
DLList<t>::~DLList() {
	// edge condition -- checks if the list has no nodes at all
	if (isEmpty())
		return;

	// deletes every node
	for (DLLNode<t>* p; !isEmpty();)
	{
		// deleting from the head first, then cycling to the next node until list is empty
		p = head->next;
		delete head;
		head = p;
	}
}

template<class t>
bool DLList<t>::isEmpty() {
	return head == nullptr;
}

template<class t>
void DLList<t>::addToHead(t data)
{
	DLLNode<t>* tmp = new DLLNode<t>(data);
	tmp->next = head; // current head is tmp's next node
	head = tmp; // head is now pointing to tmp

	// checks if the list is empty
	if (tail == nullptr)
		tail = head;
}

template<class t>
void DLList<t>::addToTail(const t& data)
{
	// if not empty
	if (tail != nullptr)
	{
		DLLNode<t>* p = new DLLNode<t>(data);

		tail->next = p; // tail's next node is the new node
		p->previous = tail; // new node's previous is "old" tail
		tail = p; // "new" tail gets renamed to correct tail
	}
	// if empty, then tail and head are the same node
	else
		head = tail = new DLLNode<t>(data);
}

template<class t>
t* DLList<t>::deleteFromHead() {
	// list is not empty
	if (!isEmpty())
	{
		int data = head->data; // creates new data for the delete node - it will be returned
		DLLNode<t>* tmp = head;

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

template<class t>
t* DLList<t>::deleteFromTail() {
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
			tail = tail->previous;
			delete tail->next;
			tail->next = nullptr;
		}

		return &data;
	}
	else
		return nullptr;
}

template<class t>
void DLList<t>::deleteDLLNode(t nodeData) {
	// if not a empty list
	if (head != nullptr) {
		// only one head node in the list
		if (head == tail && nodeData == head->data)
		{
			delete head;
			head = tail = nullptr;
		}
		// if data are happens to be head's data, but more than one node
		else if (nodeData == head->data)
		{
			DLLNode<t>* tmp = head;
			head = head->next;
			delete tmp;
		}
		// data is somewhere in the middle of the linked list
		else
		{
			DLLNode<t>* current, * forward;

			// current and forward move until forward has the node with the data, and it's not the last node in the list
			for (current = head, forward = head->next;
				forward != nullptr && !(forward->data == nodeData);
				current = current->next, forward = forward->next);

			if (forward != nullptr)
			{
				DLLNode<t>* p;

				current->next = forward->next; // current points to forward's next node, ultimately skipping cur node all together

				// edge conition, if forward node is actually the tail node
				if (forward == tail)
				{
					tail = current;
				}
				// not the last node in the list
				else
				{
					p = current->next;
					p->previous = current; // sets previous to current
				}

				delete forward;
			}
		}
	}
}

template<class t>
bool DLList<t>::isInList(t data) const {
	DLLNode<t>* tmp;

	// searches for the data in the list
	for (tmp = head; tmp != nullptr && !(tmp->data == data); tmp = tmp->next);

	return tmp != nullptr;
}