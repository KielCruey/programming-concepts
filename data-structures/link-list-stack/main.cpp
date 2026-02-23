#include "linked-list-stack.hpp"

int main()
{
	LLStack<int> stack1;
	LLStack<int> stack2;
	LLStack<int> stack3;

	// testing isEmpty()
	// case #1 -- empty list
	auto empty = stack1.isEmpty();
	// case #2 -- non-empty list
	stack1.push(1);
	auto notEmpty = stack1.isEmpty();

	// testing clear()
	stack2.push(11);
	stack2.push(22);
	stack2.push(33);
	stack2.push(44);
	stack2.clear();

	// testing topElement()
	stack3.push(5);
	stack3.push(10);
	auto topElement = stack3.topElement();

	// testing pop()
	auto popped = stack3.pop();

	return 0;
}