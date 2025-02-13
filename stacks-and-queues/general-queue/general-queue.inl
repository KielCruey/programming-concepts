#include <iostream>

template<class t, int size>
inline ArrayQueue<t, size>::ArrayQueue() :
	first(-1), last(-1)
{ }

template<class t, int size>
inline void ArrayQueue<t, size>::enqueue(t element) {
	if (!isFull()) {
		// depending on compiler -- if last is the last element or undefined element
		if (last == size - 1 || last == -1) {
			storage[0] = element;
			last = 0;

			if (first == -1)
				first = 0;
		}
		else
			storage[++last] = element; // element added to last position
	}
	else
		std::cout << "full queue.\n"; 
}

template<class t, int size>
inline t ArrayQueue<t, size>::dequeue() {
	t element = storage[first];

	// if only nulled queue or one element in array
	if (first == last)
		last = first = -1;
	// first is in last position
	else if (first == size - 1)
		first = 0;
	// first element changes
	else
		first++;

	return element;
}

template<class t, int size>
inline int ArrayQueue<t, size>::length() {
	return size;
}

template<class t, int size>
inline bool ArrayQueue<t, size>::isFull() {
	return first == 0 && last == size - 1 || first == last + 1;
}

template<class t, int size>
inline bool ArrayQueue<t, size>::isEmpty() {
	return first == -1;
}