#include "heap.hpp"

// ======== Heap ========
Heap::Heap() {
	currentSize = NULL;
	currentCapacity = NULL;

	v = new std::vector<int>();
}

Heap::~Heap() {
	delete v;

	v = nullptr;
}

int Heap::parent(int index) {
	return index / 2;
}

int Heap::left(int index) {
	return (2 * index) + 1;
}

int Heap::right(int index){ 
	return (2 * index) + 2;
}

// ======== MaxHeap ========
MaxHeap::MaxHeap()
	: Heap()
{ }

void MaxHeap::heapify(std::vector<int>& v, int index) {
	int l = left(index);
	int r = right(index);
	int max = index; // largest value

	// checking left and parent node
	if (l <= v.size() && v.at(l) > v.at(index)) max = l;
	else max = index;

	// checking right node and the pervious max
	if (r <= v.size() && v.at(r) > v.at(max)) max = r;

	if (max != index) {
		std::swap(v.at(index), v.at(max));
		heapify(v, max);
	}
}

void MaxHeap::buildHeap(std::vector<int>& v, int size){
}

void MaxHeap::heapSort(std::vector<int>& V, int size) {
}

void MaxHeap::insert(std::vector<int>& V, int x, int key) {
}

int MaxHeap::heapMaximum(std::vector<int>* V) {
	return 0;
}

int MaxHeap::extractMax(std::vector<int>& V, int newSize) {
	return 0;
}

void MaxHeap::increaseKey(std::vector<int>& V, int x, int key) {
}

// ======== MinHeap ========
MinHeap::MinHeap() 
	: Heap()
{ }

// take in an in vector and makes sure the current values in the tree hold the heap properities
void MinHeap::heapify(std::vector<int>& v, int index) {
	int l = left(index);
	int r = right(index);
	int min = index; // smallest value

	// l node is within the V size and checking if left node is smaller
	if (l < v.size() && v.at(l) < v.at(index)) min = l; // left index
	else min = index; // parent
	
	// r node is within the V size and checking if right node is smaller
	if (r < v.size() && v.at(r) < v.at(min)) min = r; // right index
	
	if (min != index) {
		std::swap(v.at(index), v.at(min));
		heapify(v, min);
	}
}

// builds heap with some given vector, while withholding the heap properities
void MinHeap::buildHeap(std::vector<int>& v, int size) {
	for (int i = size / 2; 0 <= i; i--) {
		heapify(v, i);
	}
}

// takes all of the elements in the vector,
// and sorts them from lowest element value to the end 
// and highest element values from the beginning
void MinHeap::heapSort(std::vector<int>& v, int size) {
	buildHeap(v, size);

	for (int i = size - 1; 1 < size; i--) {
		std::swap(v[0], v[i]);
		size--;
		heapify(v, 0);
	}
}

// grabs root node, or returns an exception if vector is empty
int MinHeap::heapMinimum(std::vector<int>& v) {
	// checks if no elements in the heap
	if (v.size() < 1)
		fprintf(stderr, "heap underflow -- empty heap");

	return v.at(0);
}

// grabs minimum value, then minHeapifies the heap to hold heap properities
int MinHeap::extractMin(std::vector<int>& v, int newSize) {
	int min = heapMinimum(v);
	v.at(0) = v.at(newSize - 1);
	this->currentSize = newSize - 1;
	heapify(v, 0);

	return min;
}

// V is member vector, position is the value in the heap to decrease, key is the new value to replace
// inserting a value might violate the heap characteristic, while loop makes sure it doesn't
void MinHeap::decreaseKey(std::vector<int>& V, int position, int key) {
	// real index in the vector
	position--; 

	// error checking
	if (key > V.at(position)) {
		fprintf(stderr, "new key is larger then current key");
		return;
	}
		
	// set new key to heap position
	V.at(position) = key;

	// makes sure changing a key's value doesn't violates heap properities 
  	while (position > 0 && V.at(parent(position)) > V.at(position)) {
		std::swap(V.at(position), V.at(parent(position)));
		position = parent(position);
	}
}

// V is a vector, vSize is the currentSize member variable, and key is the new value to be inserted
// function adds a value to the end of the vector, then swaps around the values unit it holds the heap properities
void MinHeap::insert(std::vector<int>& V, int vSize, int key) {
	this->v->push_back(INT_MAX);

	decreaseKey(V, currentSize, key);
}

