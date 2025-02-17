template<class t, const int maxCapacity>
inline RingBuffer<t, maxCapacity>::RingBuffer() :
	head(nullptr), tail(nullptr), size(0), capacity(maxCapacity)
{
	buffer.resize(capacity); // sets vector it to the max size
}

template<class t, const int maxCapacity>
inline void RingBuffer<t, maxCapacity>::clear() {
	buffer.clear();
}

template<class t, const int maxCapacity>
inline void RingBuffer<t, maxCapacity>::enqueue(const t& element) {
	buffer.push_back(element);
}

template<class t, const int maxCapacity>
inline void RingBuffer<t, maxCapacity>::dequeue(const t& element) {
}

template<class t, const int maxCapacity>
inline bool RingBuffer<t, maxCapacity>::isEmpty() const {
	return false;
}

template<class t, const int maxCapacity>
inline bool RingBuffer<t, maxCapacity>::isFull() const {
	return false;
}

template<class t, const int maxCapacity>
inline int RingBuffer<t, maxCapacity>::bufferSize() const {
}

template<class t, const int maxCapacity>
inline int RingBuffer<t, maxCapacity>::bufferCapacity() const {
}