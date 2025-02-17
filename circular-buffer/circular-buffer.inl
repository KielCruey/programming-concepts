template<class t, int length>
inline CircularBuffer<t, length>::CircularBuffer() :
	size(length)
{
	if (size > 0) {
		buffer[size] = { 0 }; // setting all element to "0"
		
	}
}

template<class t, int length>
inline void CircularBuffer<t, length>::clear() {
}

template<class t, int length>
inline void CircularBuffer<t, length>::push() {
}

template<class t, int length>
inline void CircularBuffer<t, length>::pop() {
}

template<class t, int length>
inline t CircularBuffer<t, length>::front() {
	return t();
}

template<class t, int length>
inline t CircularBuffer<t, length>::back() {
	return t();
}

template<class t, int length>
inline bool CircularBuffer<t, length>::isEmpty() const {
	return false;
}

template<class t, int length>
inline bool CircularBuffer<t, length>::isFull() const {
	return false;
}

template<class t, int length>
inline void CircularBuffer<t, length>::bufferSize() const {
}

template<class t, int length>
inline void CircularBuffer<t, length>::capacity() const {
}