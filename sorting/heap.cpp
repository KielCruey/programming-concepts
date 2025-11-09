#include "heap.h"

// ======== MinHeap ========
Heap::Heap(){
	currentCapacity = NULL;
	currentSize = NULL;
	v = nullptr;
}

Heap::Heap(std::vector<int>* v)
	: v(v)
{
	currentCapacity = NULL;
	currentSize = NULL;
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

// take in an in vector and makes sure the current values in the tree hold the heap properities
void Heap::minHeapify(std::vector<int>& V, int index, int newSize) {
	int l = left(index);
	int r = right(index);
	int min = index; // min heaps index for the smalles value

	// l node is within the V size and checking if left node is smaller
	if (l < newSize && V.at(l) < V.at(index)) min = l; // left index
	else min = index; // parent
	
	// r node is within the V size and checking if right node is smaller
	if (r < newSize && V.at(r) < V.at(min)) min = r; // right index
	
	if (min != index) {
		std::swap(V.at(index), V.at(min));
		minHeapify(V, min, newSize);
	}
}

// builds heap with some given vector, while withholding the heap properities
void Heap::buildMinHeap(std::vector<int>& V, int size) {
	for (int i = size / 2; 0 <= i; i--) {
		minHeapify(V, i, size);
	}
}

// takes all of the elements in the vector,
// and sorts them from lowest element value to the end 
// and highest element values from the beginning
void Heap::heapSort(std::vector<int>& V, int size) {
	buildMinHeap(V, size);

	for (int i = size - 1; 1 < size; i--) {
		std::swap(V[0], V[i]);
		size--;
		minHeapify(V, 0, size);
	}
}

// grabs root node, or returns an exception if vector is empty
int Heap::heapMinimum(std::vector<int>* V) {
	// checks if no elements in the heap
	if (V->size() < 1)
		fprintf(stderr, "heap underflow -- empty heap");

	return V->at(0);
}

// grabs minimum value, then minHeapifies the heap to hold heap properities
int Heap::extractMin(std::vector<int>& V, int newSize) {
	int min = heapMinimum(&V);
	V.at(0) = V.at(newSize - 1);
	this->currentSize = newSize - 1;
	minHeapify(V, 0, this->currentSize);

	return min;
}

// V is member vector, position is the value in the heap to decrease, key is the new value to replace
// inserting a value might violate the heap characteristic, while loop makes sure it doesn't
void Heap::decreaseKey(std::vector<int>& V, int position, int key) {
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
void Heap::insert(std::vector<int>& V, int vSize, int key) {
	this->v->push_back(INT_MAX);
	this->currentCapacity++;
	this->currentSize++;

	decreaseKey(V, currentSize, key);
}

// =========== getters/setters ===========
void Heap::setV(std::vector<int>* v) {
	this->v = v;

	// side effects of setting v
	this->currentCapacity = v->capacity();
	this->currentSize = v->size();
}