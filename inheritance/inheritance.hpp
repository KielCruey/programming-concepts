#include <string>

// Derived1Level1 and Derived2Level1 classes inherent from a VIRTUAL bases class,
// because this example shows the diamond inheritance. Derived1Level2's parents
// must be virtual or Derived1Level2 would get a runtime error, because it would 
// be confused on which parent parent to use and would also give you two instances
// of the BaseClass. Virtual keyword prevents this from happening

// ================ BaseClass ================
class BaseClass
{
public:
	void f(const char* s = "unknown");

protected:
	void g(const char* s = "unknown");

private:
	void h();
};

// ================ Derived1Level1 ================
class Derived1Level1 : public virtual BaseClass
{
public:
	void f(const char* s = "unknown");
	void h(const char* s = "unknown");
};

// ================ Derived2Level1 ================
class Derived2Level1 : public virtual BaseClass
{
public:
	void f(const char* s = "unknown");
};

// ================ Derived1Level2 ================
class Derived1Level2 : public Derived1Level1 , public Derived2Level1
{
public:
	void f(const char* s = "unknown");
};