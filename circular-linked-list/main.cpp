#include "singly-circular-linked-list.hpp"

int main()
{
	SCLList<int>* list1 = new SCLList<int>();

	SCLLNode<int>* node1 = new SCLLNode<int>(10);
	SCLList<int>* list2 = new SCLList<int>(node1);

	SCLList<int>* list3 = new SCLList<int>();
	SCLList<int>* list4 = new SCLList<int>();
	SCLList<int>* list5 = new SCLList<int>();
	SCLList<int>* list6 = new SCLList<int>();
	SCLList<int>* list7 = new SCLList<int>();
	SCLList<int>* list8 = new SCLList<int>();
	SCLList<int>* list9 = new SCLList<int>();
	SCLList<int>* list10 = new SCLList<int>();
	SCLList<int>* list11 = new SCLList<int>();

	// testing isEmpty() function
	auto empty = list1->isEmpty();

	auto isEmpty = list2->isEmpty();

	// testing addToHead
	// condition #1 -- empty list
	list3->addToHead(10);
	// condition #2 -- non-empty list
	list3->addToHead(100);

	// testing addToTail
	// condition #1 -- empty list
	list4->addToTail(10);
	// condition #2 -- non-empty list
	list4->addToTail(100);

	// testing deleteFromHead
	// condition #1 -- empty list
	auto num1 = list5->deleteFromHead();
	// condition #2 -- only one node
	list5->addToHead(1);
	auto num2 = list5->deleteFromHead();
	// condition #3 -- 2 or more nodes
	list6->addToHead(9);
	list6->addToHead(99);
	auto num3 = list6->deleteFromHead();

	// testing deleteFromTail
	// condition #1 -- empty list
	auto num4 = list7->deleteFromTail();
	// condition #2 -- only one node
	list7->addToHead(1);
	auto num5 = list7->deleteFromTail();
	// condition #3 -- 2 or more nodes
	list8->addToTail(8);
	list8->addToTail(88);
	list8->addToTail(888);
	list8->addToTail(8888);
	auto num6 = list8->deleteFromTail();

	// testing deleteCSLLNode
	// condition #1 -- null list
	list9->deleteCSLLNode(11);
	// condition #2 -- one node in list
	list9->addToHead(11);
	list9->deleteCSLLNode(11);
	// condition #3 -- 2 or more nodes, but deleting the current node
	list9->addToHead(11);
	list9->addToHead(22);
	list9->addToHead(33);
	list9->deleteCSLLNode(11);
	// condition #4 -- 2 or more nodes, but delete a node in the middle of the list
	list10->addToHead(0);
	list10->addToHead(1);
	list10->addToHead(2);
	list10->addToHead(3);
	list10->addToHead(4);
	list10->addToHead(5);
	list10->deleteCSLLNode(3);

	// testing isInList
	// condition #1 -- null list
	auto inList1 = list11->isInList(9);
	// condition #2 -- current is first node in list
	list11->addToHead(0);
	list11->addToHead(1);
	list11->addToHead(2);
	list11->addToHead(3);
	list11->addToHead(4);
	list11->addToHead(5);
	auto inList2 = list11->isInList(0);
	// condition #3 -- finds a node in the middle of the list
	auto inList3 = list11->isInList(3);
	// condition #4 -- non-null list with no number
	auto inList4 = list11->isInList(9);
	

	return 0;
}