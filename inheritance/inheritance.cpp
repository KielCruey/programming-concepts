#include <iostream>

#include "inheritance.hpp"

// ================ BaseClass ================
void BaseClass::f(const char* s) {
	std::cout << "Function f() is in BaseClass called from " << s << std::endl;
}

void BaseClass::g(const char* s) {
	std::cout << "Function g() is in BaseClass called from " << s << std::endl;
}

void BaseClass::h() {
	std::cout << "Function h() is in BaseClass" << std::endl;
}

// ================ Derived1Level1 ================
void Derived1Level1::f(const char* s) {
	std::cout << "Function f() is in Derived1Level1 called from " << s << std::endl;
	g("Derived1Level1");
	h("Derived1Level1");
}

void Derived1Level1::h(const char* s) {
	std::cout << "Function h() is in Derived1Level1 called from " << s << std::endl;
}

// ================ Derived2Level1 ================
void Derived2Level1::f(const char* s) {
	std::cout << "Function f() is in Derived2Level1 called from " << s << std::endl;
	g("Derived2Level1");
	// h(); //error: baseCalss::h() isn't accessible -- private function in BaseClass
}

// ================ Derived1Level2 ================
void Derived1Level2::f(const char* s) {
	std::cout << "Function f() is in Derived1Level2 called from " << s << std::endl;
	g("Derived1Level2");

	// special way of calling these functions because Derived1Level2 sees multiple h() and f() functions, so clarifies which one
	Derived1Level1::h("Derived1Level2");
	Derived1Level1::f("Derived1Level2");

	Derived2Level1::f("Derived1Level2");

	BaseClass::f("Derived1Level2");
}
