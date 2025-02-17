#include <vector>

template<class t, const int maxCapacity = 20>
class CircularBuffer
{
public:
	CircularBuffer();

	void clear();
	void push(const t& element); // adds element to tail
	void pop(const t& element); // add element to head
	t front(); // deletes element from front
	t back(); // deletes element from back
	bool isEmpty() const;
	bool isFull() const;
	int bufferSize() const; // total lenght of buffer
	int bufferCapacity() const; // the number of current elements in buffer

private:
	std::vector<t> buffer;
	t* head; // pointers to elements
	t* tail;
	int size; // currently how many elements are in buffer
	const int capacity; // max size
};

#include "circular-buffer.inl"