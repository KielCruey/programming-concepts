#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <stdexcept>
#include <cmath> // Required for std::floor

class Heap
{
public:
	Heap(std::vector<int>* v = nullptr);
	virtual ~Heap();

	// =========== helpers ===========
	int countingIndex(int i); // base 1 to n indexing
	int cppIndex(int i); // base 0 to n-1 indexing

	// =========== functions ===========
	int parent(int index);
	int left(int index);
	int right(int index);

	virtual void heapify(std::vector<int>& v, int index) = 0;
	virtual void buildHeap(std::vector<int>& v, int size) = 0;
	virtual void heapSort(std::vector<int>& v, int vSize) = 0;
	virtual void insert(std::vector<int>& v, int newKey) = 0;

	// =========== getters/setters ===========
	inline void setV(std::vector<int>* v);
	inline void setCurrentSize(int currentSize);

	inline std::vector<int>* getV() const;
	inline int getCurrentSize() const;

protected:
	int currentSize;
	std::vector<int>* v;
};

class MaxHeap : public Heap {
public: 
	MaxHeap(std::vector<int>* v = nullptr);
	virtual ~MaxHeap() = default;

	virtual void heapify(std::vector<int>& v, int index) override;
	virtual void buildHeap(std::vector<int>& v, int size) override;
	virtual void heapSort(std::vector<int>& v, int size) override;
	virtual void insert(std::vector<int>& v, int newKey) override;

	int heapMaximum(std::vector<int>& v);
	void increaseKey(std::vector<int>& v, int newKey, int oldKey);
	int extractMax(std::vector<int>& v);	
};

class MinHeap : public Heap {
public:
	MinHeap(std::vector<int>* v = nullptr);
	virtual ~MinHeap() = default;

	virtual void heapify(std::vector<int>& v, int index) override;
	virtual void buildHeap(std::vector<int>& v, int size) override;
	virtual void heapSort(std::vector<int>& v, int size) override;
	virtual void insert(std::vector<int>& v, int newKey) override;

	int heapMinimum(std::vector<int>& v);
	void decreaseKey(std::vector<int>& V, int newKey, int oldKey);
	int extractMin(std::vector<int>& v);
};

// =========== getters/setters ===========
void Heap::setV(std::vector<int>* v) {
	this->v = v;
}

inline void Heap::setCurrentSize(int currentSize) {
	this->currentSize = currentSize;
}

std::vector<int>* Heap::getV() const {
	return this->v;
}

inline int Heap::getCurrentSize() const {
	return this->currentSize;
}

#endif