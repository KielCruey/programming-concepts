#include "doubly-linked-list-queue.hpp"

int main()
{
	Queue<int> queue1;
	Queue<int> queue2;
	Queue<int> queue3;
	Queue<int> queue4;

	// testing isEmpty()
	// case #1 -- empty
	auto inEmpty1 = queue1.isEmpty();
	// case #2 -- non-empty
	queue1.enqueue(-5);
	auto isEmpty2 = queue1.isEmpty();

	// testing clear()
	queue1.clear();

	// testing front
	queue2.enqueue(11);
	queue2.enqueue(22);
	auto front = queue2.front();

	// testing enqueue
	queue3.enqueue(99);

	// testing dequeue
	queue4.enqueue(1);
	queue4.enqueue(2);
	queue4.enqueue(3);
	queue4.enqueue(4);
	auto el = queue4.dequeue();

	return 0;
}