#include "doubly-linked-list.hpp"

int main()
{
	DLList<int>* list1 = new DLList<int>();
	DLList<int>* list2 = new DLList<int>();
	DLList<int>* list3 = new DLList<int>();
	DLList<int>* list4 = new DLList<int>();
	DLList<int>* list5 = new DLList<int>();
	DLList<int>* list6 = new DLList<int>();
	DLList<int>* list7 = new DLList<int>();

	// testing addToHead
	// condition #1 -- empty list
	list1->addToHead(1);
	// condition #2 -- non-empty list
	list1->addToHead(2);

	// testing addToTail
	// condition #1 -- empty list
	list2->addToTail(2);
	// condition #2 -- non-empty list
	list2->addToTail(1);

	// testing deleteFromHead
	// condition #1 -- more than one node in list
	auto data1 = list1->deleteFromHead();
	// condition #2 -- one node in list
	auto data2 = list1->deleteFromHead();
	// condition #3 -- zero nodes in list
	auto data3 = list1->deleteFromHead();

	// testing deleteFromTail
	// condition #1 -- more than one node in list
	auto data4 = list2->deleteFromTail();
	// condition #2 -- one node in list
	auto data5 = list2->deleteFromTail();
	// condition #3 -- zero nodes in list
	auto data6 = list2->deleteFromTail();

	// testing deleteDLLNode()
	// condition #1 -- one head node in list
	list3->addToHead(10);
	list3->deleteDLLNode(10);
	// condition #2 -- delete head but with more than one node in the list
	list4->addToHead(10);
	list4->addToHead(100);
	list4->deleteDLLNode(100);
	// condition #3 -- more than one node but not delete the tail node in the list
	list5->addToHead(10);
	list5->addToHead(100);
	list5->addToHead(1000);
	list5->deleteDLLNode(100);
	// condition #4 -- more than one node and delete the tail node in the list
	list6->addToHead(10);
	list6->addToHead(100);
	list6->addToHead(1000);
	list6->deleteDLLNode(10);

	// testing isInList()
	list7->addToTail(-2);
	list7->addToTail(-1);
	list7->addToTail(0);
	list7->addToTail(1);
	list7->addToTail(2);
	auto num1 = list7->isInList(-2);
	auto num2 = list7->isInList(-1);
	auto num3 = list7->isInList(0);
	auto num4 = list7->isInList(1);
	auto num5 = list7->isInList(2);
	auto num6 = list7->isInList(-100);

	delete list1;
	delete list2;
	delete list3;
	delete list4;
	delete list5;
	delete list6;
	delete list7;

	return 0;
}