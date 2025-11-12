#include "heap.hpp"

// ======== Heap ========
Heap::Heap(std::vector<int>* v) 
	: v(v)
{
	currentSize = NULL;
	currentCapacity = NULL;
}

Heap::~Heap() {
	delete v;

	v = nullptr;
}

// ======== helpers ========
int Heap::countingIndex(int i) {
	return i + 1;
}

int Heap::cppIndex(int i) {
	return i - 1;
}

// ======== functions ========
int Heap::parent(int index) {
	// request root's parent
	if (index == 0) 
		return -1; // meaning NULL parent node

	auto i = std::floor(countingIndex(index) / 2);
	return cppIndex(i); // converts to 0 base array counting
}

int Heap::left(int index) {
	auto i = 2 * countingIndex(index);
	return cppIndex(i); // converts to 0 base array counting
}

int Heap::right(int index){ 
	auto i = (2 * countingIndex(index)) + 1;
	return cppIndex(i); // converts to 0 base array counting
}

// ======== MaxHeap ========
MaxHeap::MaxHeap(std::vector<int>* v)
	: Heap(v)
{ }

// v is a vector of elements
// index can be what node or the size of the vector to heapify
// this function only "sorts" only the left/right node in the priority queue
void MaxHeap::heapify(std::vector<int>& v, int index) {
	int l = left(index);
	int r = right(index);
	int max = index;

	// checking left and parent node
	if (l < v.size() && v.at(l) > v.at(index)) max = l;
	else max = index;

	// checking right node and the previous max
	if (r < v.size() && v.at(r) > v.at(max)) max = r;

	// left or right node is swapped with parent
	if (max != index) {
		std::swap(v.at(index), v.at(max));
		heapify(v, max);
	}
}

// v is a vector of elements
// size is the vector's size -- the maximum value
// buildHeap function does build heap without violating heap properities
void MaxHeap::buildHeap(std::vector<int>& v, int vSize){
	this->currentSize = vSize;

	for (int i = vSize / 2; i > 0; i--) {
		heapify(v, vSize);
	}
}

// v is a vector of elements
// size is the vector's size -- the maximum value
// builds heap, then changes the max which min value then heaps without violating heap properities
// heapSort function will sort all the elements from lowest to highest values
void MaxHeap::heapSort(std::vector<int>& v, int vSize) {
	buildHeap(v, vSize);

	for (int i = vSize; i > 0; i--) {
		std::swap(v.at(vSize - 1), v.at(0)); // swaps max value with min value
		this->currentSize--;
		heapify(v, 0); // sorts only the root value, most likely breaks heap properities
	}
}

// v is a vector of elements
// returns root node if non-empty vector
int MaxHeap::heapMaximum(std::vector<int>& v) {
	if (v.empty()) {
		throw std::runtime_error("empty vector -- can't execute 'extractMax' function");
	}
		
	return v.at(0);
}

// v is a vector of elements
// returns max value
int MaxHeap::extractMax(std::vector<int>& v) {
	int max = heapMaximum(v);
	v.at(0) = v.at(v.size() - 1);
	this->currentSize--;
	heapify(v, currentSize);

	return max;
}

// v is a vector of elements
// x is the object in the vector
// key is the new key to be changed to
void MaxHeap::increaseKey(std::vector<int>& v, int newKey, int oldKey) {
	int i; // index for oldKey's position

	// checks if the new key value to be changed is less that the current object trying to change
	if (oldKey < newKey) {
		fprintf(stderr, "new key is smaller than current key");
		return;
	}
		
	newKey = oldKey;

	// find index where the oldKey is at
	auto it = find(v.begin(), v.end(), oldKey);

	/*
	while (i > 0 && v.at(parent(i)) < v.at(i)) {
		std::swap(v.at(i), v.at(parent(i)));
		i = parent(i);
	}
	*/
}

// v is a vector of elements
// x in the new object to be inserted of the size "n" vector
void MaxHeap::insert(std::vector<int>& v, int x, int key) {

}

// ======== MinHeap ========
MinHeap::MinHeap(std::vector<int>* v)
	: Heap(v)
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
int MinHeap::extractMin(std::vector<int>& v) {
	int min = heapMinimum(v);
	v.at(0) = v.at(v.size() - 1);
	this->currentSize = v.size() - 1;
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

