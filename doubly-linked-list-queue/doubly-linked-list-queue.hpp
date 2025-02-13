#include <list>

template<class t>
class Queue
{
public:
	Queue() = default;

	void clear();
	bool isEmpty();
	t& front(); // grabs first element only
	t dequeue(); // deletes first
	void enqueue(const t& element); // adds last element

private:
	std::list<t> list;
};

#include "doubly-linked-list-queue.inl"