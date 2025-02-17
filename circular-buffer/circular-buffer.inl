template<class t, const int maxCapacity>
inline CircularBuffer<t, maxCapacity>::CircularBuffer() :
	head(nullptr), tail(nullptr), size(0), capacity(maxCapacity)
{
	buffer.resize(capacity); // sets it to the max size
}

template<class t, const int maxCapacity>
inline void CircularBuffer<t, maxCapacity>::clear() {
}

template<class t, const int maxCapacity>
inline void CircularBuffer<t, maxCapacity>::push(const t& element) {
}

template<class t, const int maxCapacity>
inline void CircularBuffer<t, maxCapacity>::pop(const t& element) {
}

template<class t, const int maxCapacity>
inline t CircularBuffer<t, maxCapacity>::front() {
	return t();
}

template<class t, const int maxCapacity>
inline t CircularBuffer<t, maxCapacity>::back() {
	return t();
}

template<class t, const int maxCapacity>
inline bool CircularBuffer<t, maxCapacity>::isEmpty() const {
	return false;
}

template<class t, const int maxCapacity>
inline bool CircularBuffer<t, maxCapacity>::isFull() const {
	return false;
}

template<class t, const int maxCapacity>
inline int CircularBuffer<t, maxCapacity>::bufferSize() const {
}

template<class t, const int maxCapacity>
inline int CircularBuffer<t, maxCapacity>::bufferCapacity() const {
}