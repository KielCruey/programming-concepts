#include "function-templates.hpp"

template<typename t>
t Functions::minimum(t a, t b) {
	return a < b ? a : b;
}

template<typename t>
t* Functions::minimum(t* a, t* b) {
	return *a < *b ? a : b;
}

template<typename t, typename rt>
rt Functions::maximum(t a, t b) {
	return a > b ? a : b;
}

template<typename t>
auto Functions::equal(t a, t b) {
	return a == b ? true : false;
}

int main() {
	Functions functions;

	// can directly tell the function what type the function is using, this case int
	int min1 = functions.minimum<int>(1, 10);

	// the function template can deduce what type is should be, this case int
	int min2 = functions.minimum(5, 8);

	double a = 42;
	double &i = a;
	double b = 59;
	double &s = b;
	// t Functions::minimum(t a, t b) will be called
	double min3 = functions.minimum(i, s);

	double* x = new double(100);
	double* y = new double(80);
	// t* Functions::minimum(t* a, t* b) will be called
	double * min4 = functions.minimum(x, y);

	// ====== having a different return type ======
	// must call fuction directly what types
	int min5 = functions.maximum<double, int>(2.3, 4);

	// function now deduces the output, this case a bool
	auto min6 = functions.equal<double>(8.8, 2.2);

	return 0;
}