template<class t, const int maxCapacity>
inline RingBuffer<t, maxCapacity>::RingBuffer() :
	head(nullptr), tail(nullptr), size(0), capacity(maxCapacity)
{
	buffer.resize(capacity); // sets vector it to the max size
}

template<class t, int maxCapacity>
inline void RingBuffer<t, maxCapacity>::addFront(const t& element) {
	if (isEmpty()) {
		tail = head = buffer[0];
	}
}

template<class t, int maxCapacity>
inline void RingBuffer<t, maxCapacity>::addBack(const t& element) {
	if (isEmpty()) {
		tail = head = buffer[0];
	}
}

template<class t, int maxCapacity>
inline bool RingBuffer<t, maxCapacity>::removeFront() {
	return false;
}

template<class t, int maxCapacity>
inline bool RingBuffer<t, maxCapacity>::removeBack() {
	return false;
}

template<class t, const int maxCapacity>
inline void RingBuffer<t, maxCapacity>::clear() {
	buffer.clear();
}

template<class t, const int maxCapacity>
inline bool RingBuffer<t, maxCapacity>::isEmpty() const {
	return size == 0;
}

template<class t, const int maxCapacity>
inline bool RingBuffer<t, maxCapacity>::isFull() const {
	return size == capacity;
}

template<class t, int maxCapacity>
inline int RingBuffer<t, maxCapacity>::incrementIndex(int index) {
	// edge condition that index overflows past max index
	if ((capacity - 1) < index)
		index = 0; // resets index to first
	else
		index++;

	return index;
}

template<class t, int maxCapacity>
inline int RingBuffer<t, maxCapacity>::decrementIndex(int index) {
	// edge condition that index underflows past min index
	if (index < 0)
		index = capacity - 1; // resets index to last index
	else
		index--;

	return index;
}

template<class t, const int maxCapacity>
inline int RingBuffer<t, maxCapacity>::currentSize() const {
	buffer.size();
}

template<class t, const int maxCapacity>
inline int RingBuffer<t, maxCapacity>::maxCapacity() const {
	buffer.capacity()
}