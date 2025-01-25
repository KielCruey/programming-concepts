#include <iostream>

#include "singly-linked-list.hpp"

// =============== SLLNode ===============
SLLNode::SLLNode(int data, SLLNode* pSLLNode) : data(data), next(next)
{ }

// =============== SLLNode ===============
SLList::SLList(SLLNode* head, SLLNode* tail): head(head), tail(tail)
{ }

SLList::~SLList() {
	// edge condition -- checks if the list has no nodes at all
	if (isEmpty())
		return;

	// deletes every node
	for (SLLNode* p; isEmpty();)
	{
		p = head->next;
		delete head;
		head = p;
	}
}

int SLList::isEmpty() {
	return head == 0;
}

void SLList::addToHead(int data) {
	SLLNode* tmp = new SLLNode(data);
	tmp->next = head; // current head is tmp's next node
	head = tmp; // head is now pointing to tmp

	// checks if the list is empty
	if (tail == 0)
		tail = head;
}

void SLList::addToTail(int data) {
	// if not empty
	if (tail != 0)
	{
		tail->next = new SLLNode(data); // tail's next node is the new node
		tail = tail->next; // tail is now pointing to 
	}
	// if empty, then tail and head are the same node
	else
		head = tail = new SLLNode(data);
}

// returns content from deleted head node
int SLList::deleteFromHead() {
	int data = head->data; // creates new data for the delete node - it will be returned
	SLLNode* tmp = head;

	// only one node in the list
	if (head == tail)
		head = tail = 0;
	else
		head = head->next; // assigning head to next node

	delete tmp;
	
	return data;
}

int SLList::deleteFromTail() {
	int data = tail->data;
	
	if (head == tail)
	{
		delete head;
		head = tail = 0;
	}
	else
	{
		SLLNode* tmp;

		// finds the second to last node
		for (tmp = head; tmp->next != tail; tmp = tmp->next);

		delete tail;
		tail = tmp;
		tail->next = 0; // makes sure tail's next nodes is null
	}

	return data;
}

void SLList::deleteSLLNode(int nodeData) {
	// if not a empty list
	if (head != 0) {
		// only one node in the list
		if (head == tail && nodeData == head->data)
		{
			delete head;
			head = tail = 0;
		}
		// if data are happens to be head's data, but more than one node
		else if (nodeData == head->data)
		{
			SLLNode* tmp = head;
			head = head->next;
			delete tmp;
		}
		// data is somewhere in the middle of the linked list
		else
		{
			SLLNode* current, * forward;

			// current and forward move until forward has the node with the data, and it's not the last node in the list
			for (current = head, forward = head->next;
				forward != 0 && !(forward->data == nodeData);
				current = current->next, forward = forward->next);

			if (forward != 0)
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

bool SLList::isInList(int data) const {
	SLLNode* tmp;

	// searches for the data in the list
	for (tmp = head; tmp != 0 && !(tmp->data == data); tmp = tmp->next);

	return tmp != 0;
}
