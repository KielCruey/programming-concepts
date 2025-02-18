#include <vector>

template<class t, const int maxCapacity = 20>
class RingBuffer
{
public:
	RingBuffer();

	void addFront(const t& element); // adds element to head
	void addBack(const t& element); // adds element to tail
	bool removeFront(); // deletes element to from head
	bool removeBack(); // deletes element to from tail

	void clear();
	bool isEmpty() const;
	bool isFull() const;
	int incrementIndex(int index);
	int decrementIndex(int index);
	int currentSize() const; // the number of current elements in buffer
	int maxCapacity() const; // max size of buffer
	
private:
	std::vector<t> buffer;
	t* head; // pointers to elements
	t* tail;
	int headIndex;
	int tailIndex;
	int size; // currently how many elements are in buffer -- will change
	const int capacity; // max size -- can't change
};

#include "ring-buffer.inl"