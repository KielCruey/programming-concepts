#include <vector>

template<class t, int capacity = 30>
class Stack
{
public:
	Stack();

	void clear();
	bool isEmpty();
	t& topElement();
	t pop();
	void push(const t& element);

private:
	std::vector<t> pool;
};

#include "general-stack.inl"