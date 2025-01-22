#include "inheritance.hpp"

int main()
{
	BaseClass bc;
	Derived1Level1 d1l1;
	Derived2Level1 d2l1;
	Derived1Level2 d1l2;

	// baseclass
	bc.f("main(1)");
	//bc.g(); // error -- inaccessible -- the consumer (main function) doesn't have protected scope for the base class
	//bc.h(); // error -- inaccessible -- the consumer (main function) doesn't have private scope for the base class

	// Derived1Level1
	d1l1.f("main(2)");
	//d1l1.g(); // error -- inaccessible -- the consumer (main function) doesn't have protected scope for the base class
	d1l1.h("main(3)");

	// Derived1Level2
	d2l1.f("main(4)");
	//d2l1.g(); // error -- inaccessible -- the consumer (main function) doesn't have protected scope for the base class
	//d2l1.h(); // error -- inaccessible -- the consumer (main function) doesn't have private scope for the base class

	d1l2.f("main(5)");
	//d1l2.g(); // error -- inaccessible -- the consumer (main function) doesn't have protected scope for the base class
	d1l2.h();

	return 0;
}