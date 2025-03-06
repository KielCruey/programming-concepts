#include <cstdlib> // EXIT_SUCCESS

#include "binary-tree.hpp"

int main() {
	// creating an empty tree
	BST<int> bst1;
	
	// creating an non-empty tree
	BSTNode<int>* node1 = new BSTNode<int>(-2);
	BST<int> bst2(node1);



	// testing isEmpty()
	// case 1 - empty tree
	auto isEmpty1 = bst1.isEmpty();
	// case 1 - non-empty tree
	auto isEmpty2 = bst2.isEmpty();

	// testing search()
	// case 1 - empty tree
	auto* search1 = bst1.search(2);
	// case 2 - non-existing element and non-empty
	auto* search2 = bst2.search(-11);
	// case 3 - existing element
	auto* search3 = bst2.search(-2);

	// testing insert()
	// case 1 - empty tree
	bst1.insert(2); // no insertion
	// case 2 - non-empty tree
	bst2.insert(3); // to right node
	bst2.insert(-11); // to left node

	bst2.insert(5); // to right node

	return EXIT_SUCCESS;
}