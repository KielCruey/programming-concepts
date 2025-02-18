#include "ring-buffer.hpp"

int main()
{
	RingBuffer<int> rBuffer;

	rBuffer.addBack(5);

	return 0;
}