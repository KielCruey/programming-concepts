template<class t>
inline void LLStack<t>::clear() {
	list.clear();
}

template<class t>
inline bool LLStack<t>::isEmpty() const {
	return list.empty();
}

template<class t>
inline t& LLStack<t>::topElement() {
	return list.back(); // returns the last element
}

template<class t>
inline t LLStack<t>::pop() {
	t element = list.back(); // save the last element
	list.pop_back(); // delete the last element
	return element;
}

template<class t>
inline void LLStack<t>::push(const t& element) {
	list.push_back(element);
}