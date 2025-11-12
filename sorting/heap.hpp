#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <stdexcept>

class Heap
{
public:
	Heap();
	virtual ~Heap();

	// =========== functions ===========
	int parent(int index);
	int left(int index);
	int right(int index);

	virtual void heapify(std::vector<int>& v, int index) = 0;
	virtual void buildHeap(std::vector<int>& v, int size) = 0;
	virtual void heapSort(std::vector<int>& v, int vSize) = 0;
	virtual void insert(std::vector<int>& v, int x, int key) = 0;

	// =========== getters/setters ===========
	inline void setV(std::vector<int>* v);
	inline std::vector<int>* getV() const;

protected:
	int currentSize;
	int currentCapacity;
	std::vector<int>* v;
};

class MaxHeap : public Heap {
public: 
	MaxHeap();
	virtual ~MaxHeap() = default;

	virtual void heapify(std::vector<int>& v, int index) override;
	virtual void buildHeap(std::vector<int>& v, int size) override;
	virtual void heapSort(std::vector<int>& v, int size) override;
	virtual void insert(std::vector<int>& v, int x, int key) override;

	int heapMaximum(std::vector<int>& v);
	void increaseKey(std::vector<int>& v, int newKey, int oldKey);
	int extractMax(std::vector<int>& v);	
};

class MinHeap : public Heap {
public:
	MinHeap();
	virtual ~MinHeap() = default;

	virtual void heapify(std::vector<int>& v, int index) override;
	virtual void buildHeap(std::vector<int>& v, int size) override;
	virtual void heapSort(std::vector<int>& v, int size) override;
	virtual void insert(std::vector<int>& v, int x, int key) override;

	int heapMinimum(std::vector<int>& v);
	void decreaseKey(std::vector<int>& V, int newKey, int oldKey);
	int extractMin(std::vector<int>& v);
};

// =========== getters/setters ===========
void Heap::setV(std::vector<int>* v) {
	this->v = v;
}

std::vector<int>* Heap::getV() const {
	return this->v;
}

#endif