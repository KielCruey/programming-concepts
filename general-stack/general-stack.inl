template<class t, int capacity>
inline Stack<t, capacity>::Stack() {
	pool.reserve(capacity); // makes vector capacity's size
}

template<class t, int capacity>
inline void Stack<t, capacity>::clear() {
	pool.clear();
}

template<class t, int capacity>
inline bool Stack<t, capacity>::isEmpty() {
	return pool.empty();
}

template<class t, int capacity>
inline t& Stack<t, capacity>::topElement() {
	return pool.back(); // returns the reference to the last element in the stack
}

template<class t, int capacity>
inline t Stack<t, capacity>::pop() {
	t element = pool.back(); // grabs the last element, and assign it
	pool.pop_back(); // deletes element from stack
	return element; // returns last element
}

template<class t, int capacity>
inline void Stack<t, capacity>::push(const t& element) {
	pool.push_back(element);
}