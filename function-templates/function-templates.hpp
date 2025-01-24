class Functions
{
public: 
	// basic example of a function template
	template<typename t>
	t minimum(t a, t b);

	// different function from above, and allows references -- overloading the function
	template<typename t>
	t* minimum(t* a, t* b);

	// can have a different return type from the input parameters
	template<typename t, typename rt>
	rt maximum(t a, t b);

	// have the function to deduce the return type by using the 'auto' keyword
	template<typename t>
	auto equal(t a, t b);
};

#include "function-templates.inl"