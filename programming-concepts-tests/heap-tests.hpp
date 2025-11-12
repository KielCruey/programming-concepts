#include "pch.h"

#include <vector>

class HeapFixture : public testing::Test
{
public:
	HeapFixture(std::vector<int>* v = nullptr);

	inline void setVector(std::vector<int>* v);
	inline std::vector<int>* getVector();

protected:
	virtual void SetUp() override; // called before each test fixture
	virtual void TearDown() override; // called after each test fixture

private:
	std::vector<int>* v; // predefined values
};

inline void HeapFixture::setVector(std::vector<int>* v) {
	this->v = v;
}

inline std::vector<int>* HeapFixture::getVector() {
	return this->v;
}