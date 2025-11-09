#ifndef HEAP_H
#define HEAP_H

#include <vector>

class Heap
{
public:
	Heap();
	Heap(std::vector<int>* v);

	// =========== functions ===========
	int parent(int index);
	int left(int index);
	int right(int index);

	void minHeapify(std::vector<int>& V, int index, int newSize);
	void buildMinHeap(std::vector<int>& V, int size);

	void heapSort(std::vector<int>& V, int size);

	int heapMinimum(std::vector<int>* V);
	int extractMin(std::vector<int>& V, int newSize);

	void decreaseKey(std::vector<int>& V, int x, int key);
	void insert(std::vector<int>& V, int x, int key);

	// =========== getters/setters ===========
	void setV(std::vector<int>* v);
	std::vector<int>& getV();

	// =========== variables ===========
	int currentCapacity;
	int currentSize;
	std::vector<int>* v;
};

//implement a fibonacci heap to implete the priority queue

#endif