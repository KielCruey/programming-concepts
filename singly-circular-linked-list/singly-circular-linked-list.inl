// ============ CLLNode ============
template<class t>
SCLLNode<t>::SCLLNode() :
	data(0), next(nullptr)
{ }

template<class t>
SCLLNode<t>::SCLLNode(t data, SCLLNode<t>* next) :
	data(data), next(next)
{ }

// ============ CLList ============ 
template<class t>
SCLList<t>::SCLList(SCLLNode<t>* current) :
	current(current)
{ }

template<class t>
SCLList<t>::~SCLList() {
 	// edge condition -- checks if the list has no nodes at all
	if (isEmpty())
		return;

	// node references
	SCLLNode<t>* frontNode;
	SCLLNode<t>* lastNode;
	SCLLNode<t>* deletedNode;

	// only once node pointing it itself
	if (current->next = current) {
		lastNode = current;
		lastNode->next = nullptr;
	}
	else {
		for (lastNode = current; lastNode != nullptr && lastNode->next != current; lastNode = lastNode->next);
		lastNode->next = nullptr; // makes singly circular linked list into a singly linked list
	}

	// deletes every node in list, then cycling to the next node until list is empty
	for (frontNode = current; frontNode != nullptr;) {
		deletedNode = current;
		frontNode = current->next;

		delete deletedNode;
	}
}

template <class t>
SCLLNode<t>* SCLList<t>::getCurrent() {
	return this->current;
}

template <class t>
void SCLList<t>::setCurrent(SCLLNode<t>* current) {
	this->current = current;
}

template<class t>
bool SCLList<t>::isEmpty() {
	return current == nullptr;
}

template<class t>
void SCLList<t>::addToHead(t data) {
	SCLLNode<t>* tmp = new SCLLNode<t>(data);

	// no nodes in the list
	if (current == nullptr) {
		current = tmp;
		current->next = current; // circular part -- points to itself
	}	
	else {
		SCLLNode<t>* lastNode;
		for (lastNode = current; lastNode->next != current; lastNode = lastNode->next);

		lastNode->next = tmp; // makes singly circular linked list into a singly linked list
		tmp->next = current;
		current = tmp; // new current node reference
	}
}

template<class t>
void SCLList<t>::addToTail(const t& data) {
	SCLLNode<t>* tmp = new SCLLNode<t>(data);

	// no nodes in the list
	if (current == nullptr)	{
		current = tmp;
		current->next = current; // circular part
	}
	else {
		SCLLNode<t>* lastNode;

		// searches for last node in list
		for (lastNode = current; lastNode->next != current; lastNode = lastNode->next);

		lastNode->next = tmp;
		tmp->next = current;
	}
}

template<class t>
t* SCLList<t>::deleteFromHead() {
	// no node in list
	if (current == nullptr)
		return nullptr;

	t data;

	// checks if only one node in list
	if (current == current->next) {
		data = current->data;
		delete current;
	}
	// 2 or more nodes in list
	else {
		SCLLNode<t>* tmp = current->next;

		data = tmp->data;
		current->next = tmp->next;
		delete tmp;
	}

	return &data;
}

template<class t>
t* SCLList<t>::deleteFromTail() {
	// no node in list
	if (current == nullptr)
		return nullptr;

	t data = current->data;

	// only one node in list
	if (current == current->next) {
		delete current;
		current = nullptr;
	}
	// 2 or more nodes in list
	else
	{
		SCLLNode<t>* tmp, * forward;
		
		for (tmp = current, forward = current->next; 
			forward != current; 
			forward = forward->next, tmp = tmp->next);

		tmp->next = current;

		delete forward;
	}

	return &data;
}

template<class t>
inline void SCLList<t>::deleteCSLLNode(t nodeData) {

	// if not an empty list
	if (current != nullptr)
	{
		// only one node in list
		if (current == current->next)
		{
			delete current;
			current = nullptr; // makes sure list is nullptr
		}
		// if current's data is the first node, and there's 2 or more nodes
		else if (current->data == nodeData)
		{
			SCLLNode<t>* tmp = current;
			SCLLNode<t>* forward = current->next;
			current = current->next;

			for (; forward->next != tmp; forward = forward->next);

			forward->next = current;
			delete tmp;
		}
		// 2 or more nodes in list, not deleting the first
		else
		{
			SCLLNode<t>* tmp, * forward;

			// tmp and forword increment throughout the list until they reach nodeData's value
			for (tmp = current, forward = current->next;
				forward != current && !(forward->data == nodeData);
				tmp = tmp->next, forward = forward->next);

			tmp->next = forward->next;
			delete forward;
		}
	}
}

template<class t>
inline bool SCLList<t>::isInList(t data) const
{
	SCLLNode<t>* tmp = nullptr;

	// not an empty list
	if (current != nullptr)
	{
		// if only one node in list
		if (current->data == data)
			return true;
		// 2 or more nodes in list
		else
		{
			// 2 or more nodes in list
			for (tmp = current;
				tmp->data != data && tmp->next != current && tmp != nullptr;
				tmp = tmp->next);

			// after looking through the list if last node doesn't have the correct value
			if (data != tmp->data)
				return false;
		}
	}

	return tmp != nullptr;
}
