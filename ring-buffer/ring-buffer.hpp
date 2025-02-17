#include <vector>

template<class t, const int maxCapacity = 20>
class RingBuffer
{
public:
	RingBuffer();

	void clear();
	void enqueue(const t& element); // adds element to tail
	void dequeue(const t& element); // deletes element to from tail
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