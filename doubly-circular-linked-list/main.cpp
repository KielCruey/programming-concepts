#include "doubly-circular-linked-list.hpp"

int main()
{
	int* num1 = new int(1);
	int* num3 = new int(3);
	int* num9 = new int(9);

	// testing DCLLNode constructor
	// case #1 -- no data
	DCLLNode<int>* node1 = new DCLLNode<int>(num1);
	// case #2 -- non zero (0) and empty data data
	DCLLNode<int>* node2 = new DCLLNode<int>(num3);
	DCLLNode<int>* node3 = new DCLLNode<int>(num9);

	// testing DCLList constructor
	// case #1 -- empty list
	DCLList<int>* list1 = new DCLList<int>();
	// case #2 -- non-empty list -- missing tail node
	DCLList<int>* list2 = new DCLList<int>(node2, node3);

	// testing list destructor -- will delete any nodes in list by default
	// case #1 -- empty list
	delete list1;
	// case #2 -- non-empty lists
	delete list2; // both head and tail nodes





	DCLList<int>* list3 = new DCLList<int>();


	



	return 0;
}