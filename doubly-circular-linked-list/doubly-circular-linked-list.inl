// ========== DCLLNode ==========
template<class t>
DCLLNode<t>::DCLLNode(t* data, DCLLNode<t>* next, DCLLNode<t>* previous) :
	data(data), next(next), previous(previous)
{ }

template<class t>
DCLLNode<t>::~DCLLNode() {
	this->next = nullptr;
	this->previous = nullptr;
	this->data = nullptr;
	delete this->data;
}

// copy constructor
template<class t>
DCLLNode<t>::DCLLNode(const DCLLNode<t>&other) {
	this->data = other.data;
	this->next = other.next;
	this->previous = other.previous;
}

// copy assignment operator
template<class t>
DCLLNode<t>& DCLLNode<t>::operator=(const DCLLNode<t> other) {
	// checks if other isn't the same object
	if (this != &other)	{
		this->data = other.data;
		this->next = other.next;
		this->previous = other.previous;
	}

	return *this;
}

// ========== DCLList ==========
template<class t>
DCLList<t>::DCLList(DCLLNode<t>* head, DCLLNode<t>* tail) :
	head(head), tail(tail)
{ 
	if (head != nullptr && tail != nullptr) {
		this->head->next = this->head->previous = tail; // head's links both point to tail
		this->tail->next = this->tail->previous = head; // tail's links both point to head
	}
	else if (head != nullptr && tail == nullptr)
	{
		this->tail = head;
		this->head->next = this->head->previous = head; // head's links point to itself
		this->tail->next = this->tail->previous = this->tail; // tail's links point to itself
	}
	else if (tail != nullptr && head == nullptr)
	{
		this->head = tail;
		this->tail->next = this->tail->previous = tail; // tail's links point to itself
		this->head->next = this->head->previous = this->head; // head's links point to itself
	}	
}

template<class t>
DCLList<t>::~DCLList() {
	// edge condition -- no nodes in list
	if (isEmpty())
		return;

	// deletes every node in list
	for (DCLLNode<t>* tmp = head; !isEmpty();) {
		tmp = head->next; // tmp assigning to new 'head'

		// nulling out the references and deleting node
		head->next = nullptr;
		head->previous = nullptr;
		delete head;

		// one node left
		if (tmp == tail)
		{
			tail->previous = nullptr;
			tail->next = nullptr;

			head = tail = nullptr;
		}
		// more than 2 nodes	
		else {
			tmp->previous = tail;
			tail->next = tmp;

			head = tmp;
		}
	}
}

template <class t>
bool DCLList<t>::isEmpty() {
	return head == nullptr && tail == nullptr;
}

template<class t>
void DCLList<t>::addToHead(const t data) {
	DCLLNode<t>* tmp = new DCLLNode<t>(new t(data));

	// empty list
	if (isEmpty())	{
		head = tail = tmp;
		
		// linking the tail node
		tail->next = head;
		tail->previous = head;
		
		// linking the head node
		head->next = tail;
		head->previous = tail;
	}
	// non-empty list
	else {
		tmp->next = head;
		tail->next = tmp; // making it circular
		head->previous = tmp;
		tmp->previous = tail; // making it circular again
		head = tmp; // head is now pointing to the new node called tmp
	}
}

template<class t>
void DCLList<t>::addToTail(const t data) {
	DCLLNode<t>* tmp = new DCLLNode<t>(new t(data));

	// if empty, then tail and head are the same node
	if(isEmpty()) {
		head = tail = tmp;
		head->next = tail;
		head->previous = tail;
	}
	// if not empty
	else
	{
		tail->next = tmp; // tail's next node is the new node
		tmp->previous = tail; // new node's previous is "old" tail
		tmp->next = head; // making it circular again
		head->previous = tmp;
		tail = tmp; // "new" tail gets renamed to correct tail
	}
}

template<class t>
t* DCLList<t>::deleteFromHead() {
	// list is not empty
	if (!isEmpty())
	{
		t* data = head->data; // creates new data for the delete node - it will be returned
		DCLLNode<t>* tmp = head;

		// only one node in list
		if (head == tail) {
			head = tail = nullptr;
		}
		// 1 or more node(s) in list
		else {
			head = head->next; // renaming head
			head->previous = tail; // assigning head's broken link
			tail->next = tail; // assigning tail's broken link
		}

		delete tmp;
		return data;
	}
	else
		return nullptr;
}

template<class t>
t* DCLList<t>::deleteFromTail() {
	// edge condition -- list is empty
	if (!isEmpty())
	{
		t* data = tail->data;
		DCLLNode<t>* tmp = tail;

		// only one node to delete
		if (head == tail)
			head = tail = nullptr;
		// more than one node in list
		else
		{
			tail = tail->previous; // renaming tail
			head->previous = tail; // assigning head's broken link
			tail->next = head; // assigning tail's broken link
		}
		 
		delete tmp;
		return data;
	}
	else
		return nullptr;
}

template<class t>
void DCLList<t>::deleteDCLLNode(t data) {
	// if not a empty list
	if (head != nullptr) {
		// only one head node in the list
		if (head == tail && data == *(head->data))
		{
			delete head;
			head = tail = nullptr;
		}
		// if data are happens to be head's data, but more than one node
		else if (data == *(head->data))
		{
			DCLLNode<t>* tmp = head;
			head = head->next; // renaming head
			head->previous = tail; // connecting head's broken link
			tail->next = head; // connecting tail's broken link
			delete tmp;
		}
		else if (data == *(tail->data))
		{
			DCLLNode<t>* tmp = tail;
			tail->previous = tail;
			tail->next = head;
			head->previous = tail;
			delete tmp;
		}
		// data is somewhere in the middle of the linked list
		else
		{
			DCLLNode<t>* current, * forward, * deleteNode;

			// current and forward move until forward has the node with the data, and it's not the last node in the list
			for (current = head, forward = head->next;
				(forward != tail) && (*(forward->data) != data);
				current = current->next, forward = forward->next);

			current->next = forward->next; // skiping the node to be deleted
			deleteNode = forward;
			forward = forward->next; // renaming forward
			forward->previous = current; // sets previous to current

			delete deleteNode;
		}
	}
}

template<class t>
bool DCLList<t>::isInList(t data) const {
	DCLLNode<t>* tmp;

	// looks at tails data
	if (*(tail->data) == data)
		return true;

	// searches for the data in the list -- but doesn't look at tail's data
	for (tmp = head; *(tmp->data) != data && tmp != tail; tmp = tmp->next);

	return *(tmp->data) == data;
}