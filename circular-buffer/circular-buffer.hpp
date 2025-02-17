#include <vector>

template<class t, const int length = 20>
class CircularBuffer
{
public:
	CircularBuffer();

	void clear();
	void push(); // adds element to tail
	void pop(); // add element to head
	t front();
	t back();
	bool isEmpty() const;
	bool isFull() const;
	void bufferSize() const; // total lenght of buffer
	void capacity() const; // the number of current elements in buffer

private:
	std::vector<t> buffer;
	t* head;
	t* tail;
	const int size;
};

#include "circular-buffer.inl"