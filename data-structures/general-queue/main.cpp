#include "general-queue.hpp"

int main()
{
	ArrayQueue<int> queue1;
	ArrayQueue<int> queue2;
	ArrayQueue<int> queue3;
	ArrayQueue<int, 10> queue4;
	ArrayQueue<int, 5> queue5;
	ArrayQueue<int, 5> queue6;

	// testing enqueue()
	// case #1 -- empty queue
	queue1.enqueue(3);
	// case #2 -- non-empty queue
	queue1.enqueue(4);
	// case #3
	for (int i = 0; i < queue2.length(); i++)
		queue2.enqueue(i);

	queue2.enqueue(20); // adding a full element

	// testing dequeue()
	// case #1 -- empty queue
	auto firstEl = queue3.dequeue();
	// case #2 -- non-empty queue
	queue3.enqueue(20);
	auto firstElement = queue3.dequeue();

	// testing length()
	auto q1Length = queue1.length();
	auto q4Length = queue4.length();

	// testing is isFull()
	auto q5IsFull = queue5.isFull();
	for (int i = 0; i < queue5.length(); i++)
		queue5.enqueue(i);

	auto q5Full = queue5.isFull();

	// testing isEmpty()
	auto q6IsEmpty = queue6.isEmpty();
	queue6.enqueue(-10);
	auto qt6Empty = queue6.isEmpty();

	return 0;
}