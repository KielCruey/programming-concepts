#include <cstdlib>
#include <iostream>

#include "functions.hpp"

int main() {
	Functions<double> functions;

	// testing all the static library functions
	auto sum = functions.add(4.2, 8.33);
	auto subtract = functions.subtract(5.32, 9.31);
	auto multiply = functions.multiply(3.33, 1.5);
	auto divide = functions.divide(5.9, 2.1);

	std::cout << "sum: " << sum << std::endl;
	std::cout << "subtract: " << subtract << std::endl;
	std::cout << "multiply: " << multiply << std::endl;
	std::cout << "divide: " << divide << std::endl;

	return EXIT_SUCCESS;
}