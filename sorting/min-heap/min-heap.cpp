#include <stdio.h>
#include <cmath>
#include <climits> // INT_MIN, INT_MAX
#include <algorithm> // swap

#include "min-heap.hpp"

Heap::Heap(int capacity, int size, int* H)
	: capacity(capacity), size(size), H(H)
{ }

// helper function
// assumes that the current Heap properties are satisfied then, at some index,
// that new index value may violate the Heap properties and moves it to correct location
void Heap::Heapify(Heap* h, int index) {
	// check for only one number -- that is the smallest number
	if (h->size <= 1)
		return;

	int smallestIndex = index;

	int lIndex = getLeftChild(h, index);
	int rIndex = getRightChild(h, index);

	// checking smallest index -- left of index's value
	if (lIndex > 0 && lIndex < h->size && h->H[lIndex] < h->H[index])
		smallestIndex = lIndex;
	else
		smallestIndex = index;

	// checking smallest index -- left to right
	if (rIndex > 0 && rIndex < h->size && h->H[rIndex] < h->H[lIndex])
		smallestIndex = rIndex;

	// changes parent and the smallest key and recursively swaps numbers
	if (index != smallestIndex) {
		std::swap(h->H[index], h->H[smallestIndex]);
		Heapify(h, smallestIndex);
	}
}

// builds a Heap while satisfying the Heap properties
void Heap::BuildHeap(Heap* h, int size) {
	if (size == 0)
		return;

	h->size = size;

	for (int i = static_cast<int>(std::floor((size - 2) / 2)); i >= 0; i--)
		Heapify(h, i);
}

// builds a Heap, then sorts the array, this array with be sorted,
// if it's a max-Heap, the array will be sorted in accending order, 
// if it's a min-Heap, the array will be sorted in descending order
void Heap::Heapsort(Heap* h, int size) {
	BuildHeap(h, size);

	for (int i = size; 1 <= i; i--) {
		h->H[0] = h->H[i];
		h->size--;
		Heapify(h, 0);
	}
}

// grabs the minimum element (the root), then reorders the the Heap to satisfy the Heap properties
int Heap::ExtractMin(Heap* h) {
	// checks if there's two or more elements
	if (h->size < 1) {
		fprintf(stderr, "Heap underflow\n");
		return INT_MIN;
	}

	int minKey = getMinimum(h); // gets root element
	int maxIndex = h->size - 1; // gets last element index
	h->H[0] = h->H[maxIndex]; // last element overwrites root element
	h->size--; // decrease size
	int size = h->size;
	Heapify(h, size);

	return minKey;
}

// helper function
// takes an already existing element, changes the key value, then heapifys
void Heap::DecreaseKey(Heap* h, int index, int newKey) {
	// checks if the replacement newKey is smaller
	if (newKey > h->H[index]) {
		fprintf(stderr, "New key is greater than current key\n");
		return;
	}

	h->H[index] = newKey;

	// makes sure added new key satisfies the Heap properties
	while (index > 0 && h->H[getParentNode(h, index)] > h->H[index]) {
		std::swap(h->H[getParentNode(h, index)], h->H[index]);
		index = getParentNode(h, index);
	}
}

// adds an element to the last position, then heapifys
Heap* Heap::Insertion(Heap* h, int size, int newElement) {
	// checks if there's room in the tree, if not, don't insert
	if (size >= h->capacity) {
		fprintf(stderr, "Heap is full\n");
		return h;
	}

	//h->size++;
	h->H[size] = INT_MAX;
	DecreaseKey(h, size, newElement);

	return h;
}

// ======== getters/setters ========
// returns index
int Heap::getParentNode(Heap* h, int currentIndex) {
	int size = h->size - 1;

	// checks if root node, which has no parent, else returns itself
	if (currentIndex == 0) return 0;
	// check overbound and underbound index
	else if (currentIndex < 0 || currentIndex > size) {
		fprintf(stderr, "Invalid parent index\n");
		return -1;
	}
	// check parent index is valid
	else {
		int parentIndex = static_cast<int>(std::floor((currentIndex - 1) / 2));
		return parentIndex;
	}
}

// returns index
int Heap::getLeftChild(Heap* h, int currentIndex) {
	int size = h->size - 1;

	// checks out of bounds index
	if (currentIndex < 0 || currentIndex > size) {
		fprintf(stderr, "Invalid left child index\n");
		return -1;
	}
	// check valid index
	else {
		int leftChildIndex = 2 * currentIndex + 1;

		if (leftChildIndex < 0 || leftChildIndex > size) {
			fprintf(stderr, "Invalid left child index\n");
			return -1;
		}

		return leftChildIndex;
	}
}

// returns index
int Heap::getRightChild(Heap* h, int currentIndex) {
	int size = h->size;

	// checks out of bounds index
	if (currentIndex < 0 || currentIndex >= size) {
		fprintf(stderr, "Invalid right child index\n");
		return -1;
	}
	// check valid index
	else {
		int rightChildIndex = 2 * currentIndex + 2;

		if (rightChildIndex < 0 || rightChildIndex > size) {
			fprintf(stderr, "Invalid right child index\n");
			return -1;
		}

		return rightChildIndex;
	}
}

// returns index's content
int Heap::getMinimum(Heap* h) {
	// check at least one element exists
	if (h->size < 1) {
		fprintf(stderr, "Empty Array\n");
		return INT_MIN;
	}

	return h->H[0];
}