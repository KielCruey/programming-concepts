#include <list>

template<class t>
class LLStack
{
public:
	LLStack() = default;

	void clear();
	bool isEmpty() const;
	t& topElement();
	t pop();
	void push(const t& element);

private:
	std::list<t> list;
};

#include "linked-list-stack.inl"