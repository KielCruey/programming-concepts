#include <iostream>

#include "polymorphism.hpp"

// =========== Class1 ===========
void Class1::f() {
	std::cout << "Funcition f() in Class1" << std::endl;
}

void Class1::g() {
	std::cout << "Funcition g() in Class1" << std::endl;
}

// =========== Class2 ===========
void Class2::f() {
	std::cout << "Funcition f() in Class2" << std::endl;
}

void Class2::g() {
	std::cout << "Funcition g() in Class2" << std::endl;
}

// =========== Class3 ===========
void Class3::h() {
	std::cout << "Funcition h() in Class3" << std::endl;
}
