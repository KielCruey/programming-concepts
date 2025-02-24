template <class t>
class Functions
{
public:
	Functions() = default;

	static t add(t num1, t num2);
	static t subtract(t num1, t num2);
	static t multiply(t num1, t num2);
	static t divide(t num1, t num2);
};

#include "functions.inl"