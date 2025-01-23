#include "polymorphism.hpp"

int main()
{
	Class1* p;

	Class1 c1;
	Class2 c2;
	Class3 c3;

	// calling Class1's functions in terms of Class1 pointer
	p = &c1;
	p->f();
	p->g();

	// calling Class2's functions in terms of Class1 pointer
	p = (Class1*) &c2;
	p->f();
	p->g(); // g() isn't virtual in Class1, so it calls Class1's g() function

	// calling Class3's functions in terms of Class1 pointer
	p = (Class1*) &c3;
	p->f(); 
	p->g(); // no definition of g() in Class3, so it calls Class1's g() function
	// p->h(); // error -- Class1 has no definition of h(), so it can't even call Class3's h() function

	return 0;
}