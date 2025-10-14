#include "general-stack.hpp"

int main()
{
	Stack<int> stack1;
	Stack<int> stack2;
	Stack<int> stack3;

	// testing isEmpty()
	// case #1 -- empty stack
	auto isEmpty = stack1.isEmpty();

	// case #2 -- non-empty stack
	stack1.push(5);
	auto isEmpty2 = stack1.isEmpty();

	// testing clear()
	stack2.push(1);
	stack2.push(2);
	stack2.push(3);
	stack2.push(4);
	stack2.clear();

	// testing topElement()
	auto top = stack1.topElement();

	// testing pop()
	stack3.push(11);
	stack3.push(22);
	stack3.push(33);
	stack3.push(44);
	auto value = stack3.pop();

	return 0;
}