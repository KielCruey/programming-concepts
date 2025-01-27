#include "singly-linked-list.hpp"

int main()
{
	SLList* list1 = new SLList();
	SLList* list2 = new SLList();
	SLList* list3 = new SLList();
	SLList* list4 = new SLList();
	SLList* list5 = new SLList();
	SLList* list6 = new SLList();
	SLList* list7 = new SLList();

	// testing add to head function
	list1->addToHead(2);
	list1->addToHead(1);
	list1->addToHead(0);
	list1->addToHead(-10);
	list1->addToHead(-20);

	//testing add to tail function
	list2->addToTail(5);
	list2->addToTail(4);
	list2->addToTail(3);
	list2->addToTail(2);
	list2->addToTail(1);

	// testing out delete SLLNode function
	// condition #1 -- only one node
	list3->addToHead(1);
	list3->deleteSLLNode(1);

	// condition #2 -- if data are happens to be head's data, but more than one node
	list4->addToTail(10);
	list4->addToTail(100);
	list4->deleteSLLNode(10);

	// condition #3 -- data is somewhere in the middle of the linked list
	list5->addToTail(10);
	list5->addToTail(100);
	list5->addToTail(1000);
	list5->deleteSLLNode(100);

	// testing delete from head function
	// condtion #1 -- more than 2 nodes
	auto value = list1->deleteFromHead();

	// condtion #2 -- list is empty
	auto* anotherVal = list6->deleteFromHead();

	// testing delete from tail function
	// condtion #1 -- more than 2 nodes
	auto aValue = list2->deleteFromTail();

	// condtion #2 -- list is empty
	auto* otherVal = list6->deleteFromHead();

	// testing is in list function
	auto isInList = list1->isInList(-10);
	auto noInList = list1->isInList(11);

	delete list1;
	delete list2;
	delete list3;
	delete list4;
	delete list5;
	delete list6;
	delete list7;

	return 0;
}