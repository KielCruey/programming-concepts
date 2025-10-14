#include "doubly-circular-linked-list.hpp"

int main()
{
	int* num1 = new int(1);
	int* num3 = new int(3);
	int* num9 = new int(9);
	int* num4 = new int(4);
	int* num5 = new int(5);

	// testing DCLLNode constructor
	// case #1 -- no data
	DCLLNode<int>* node1 = new DCLLNode<int>(num1);
	// case #2 -- non zero (0) and empty data data
	DCLLNode<int>* node2 = new DCLLNode<int>(num3);
	DCLLNode<int>* node3 = new DCLLNode<int>(num9);
	DCLLNode<int>* node4 = new DCLLNode<int>(num4);
	DCLLNode<int>* node5 = new DCLLNode<int>(num5);

	// testing DCLList constructor
	// case #1 -- empty list
	DCLList<int>* list1 = new DCLList<int>();
	// case #2 -- non-empty list -- 2 nodes
	DCLList<int>* list2 = new DCLList<int>(node2, node3);
	DCLList<int>* list3 = new DCLList<int>();
	DCLList<int>* list4 = new DCLList<int>(node4, node5);
	DCLList<int>* list5 = new DCLList<int>();
	DCLList<int>* list6 = new DCLList<int>();
	DCLList<int>* list7 = new DCLList<int>();
	DCLList<int>* list8 = new DCLList<int>();
	DCLList<int>* list9 = new DCLList<int>();
	DCLList<int>* list10 = new DCLList<int>();
	DCLList<int>* list11 = new DCLList<int>();
	DCLList<int>* list12 = new DCLList<int>();
	DCLList<int>* list13 = new DCLList<int>();
	DCLList<int>* list14 = new DCLList<int>();
	DCLList<int>* list15 = new DCLList<int>();
	DCLList<int>* list16 = new DCLList<int>();
	DCLList<int>* list17 = new DCLList<int>();
	DCLList<int>* list18 = new DCLList<int>();
	DCLList<int>* list19 = new DCLList<int>();
	DCLList<int>* list20 = new DCLList<int>();
	DCLList<int>* list21 = new DCLList<int>();
	DCLList<int>* list22 = new DCLList<int>();



	// testing isEmpty()
	// case #1 -- empty list
	auto emptyList = list3->isEmpty();
	// case #1 -- non-empty list
	auto nonEmptyList = list4->isEmpty();

	// testing addToHead()
	// case #1 -- empty list
	list5->addToHead(2);
	// case #2 -- non-empty list with one node
	list6->addToHead(2);
	list6->addToHead(3);
	// case #3 -- non-empty list with one node
	list7->addToHead(22);
	list7->addToHead(33);
	list7->addToHead(44);

	// testing addToTail()
	// case #1 -- empty list
	list8->addToTail(2);
	// case #2 -- non-empty list with one node
	list9->addToTail(-5);
	list9->addToTail(-4);
	// case #3 -- non-empty list with one node
	list10->addToTail(22);
	list10->addToTail(33);
	list10->addToTail(44);

	// testing deleteFromHead()
	// case #1 -- empty list
	list11->deleteFromHead();
	// case #2 -- one node in list
	list12->addToHead(-1);
	list12->deleteFromHead();
	// case #3 -- 2 nodes in list
	list13->addToHead(-1);
	list13->addToHead(0);
	list13->deleteFromHead();

	// testing deleteFromTail()
	// case #1 -- empty list
	list14->deleteFromTail();
	// case #2 -- one node in list
	list15->addToTail(-1);
	list15->deleteFromTail();
	// case #3 -- 2 nodes in list
	list16->addToTail(-1);
	list16->addToTail(0);
	list16->deleteFromTail();

	// testing deleteDCLLNode
	// case #1 -- empty list
	list17->deleteDCLLNode(0);
	// case #2 -- only one node
	list18->addToTail(-100);
	list18->deleteDCLLNode(-100);
	// case #3 -- more than 2 nodes in list -- deletes head
	list19->addToTail(-1);
	list19->addToTail(0);
	list19->addToTail(1);
	list19->deleteDCLLNode(-1);
	// case #4 -- more than 2 nodes in list -- deletes tail
	list20->addToTail(-1);
	list20->addToTail(0);
	list20->addToTail(1);
	list20->deleteDCLLNode(1);
	// case #5 -- more than 2 nodes in list -- deletes between head/tail node
	list21->addToTail(-1);
	list21->addToTail(0);
	list21->addToTail(1);
	list21->deleteDCLLNode(0);

	// testing isInList()
	list22->addToTail(-1);
	list22->addToTail(0);
	list22->addToTail(1);
	// case #1 -- not in list
	auto notInList = list22->isInList(1111);
	// case #1 -- is in list
	auto isInList1 = list22->isInList(0);
	auto isInList2 = list22->isInList(1);


	// testing list destructor -- will delete any nodes in list by default
	// case #1 -- empty list
	delete list1;
	// case #2 -- non-empty lists - 2 nodes in list
	delete list2; // both head and tail nodes

	delete list3;
	delete list4;
	delete list5;
	delete list6;
	delete list7;
	delete list8;
	delete list9;
	delete list10;
	delete list11;
	delete list12;
	delete list13;
	delete list14;
	delete list15;
	delete list16;
	delete list17;
	delete list18;
	delete list19;
	delete list20;
	delete list21;
	delete list22;

	return 0;
}