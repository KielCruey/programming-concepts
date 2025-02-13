template<class t>
inline void Queue<t>::clear() {
	list.clear();
}

template<class t>
inline bool Queue<t>::isEmpty() {
	return list.empty();
}

template<class t>
inline t& Queue<t>::front() {
	return list.front();
}

template<class t>
inline t Queue<t>::dequeue() {
	t element = list.front(); // grabs first index
	list.pop_front(); // deletes front index
	return element;
}

template<class t>
inline void Queue<t>::enqueue(const t& element) {
	list.push_back(element);
}
