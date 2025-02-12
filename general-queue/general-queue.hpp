template<class t, const int size = 20>
class ArrayQueue
{
public:
	ArrayQueue(); // initializes to -1 -- an out of bound value

	void enqueue(t element); // adds to last position
	t dequeue(); // eliminates from first position
	int length(); // maximum indexes in queue
	bool isFull();
	bool isEmpty();

private:
	int first, last; // index elements for storage[]
	t storage[size] = { 0 }; // zeros out all contents of array
};

#include "general-queue.inl"