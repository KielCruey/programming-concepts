#include "pch.h"

#include <vector>

class SortingFixture : public testing::Test
{
public:
	SortingFixture(std::vector<int>* v = nullptr);

	void setVector(std::vector<int>* v);
	std::vector<int>* getVector();

protected:
	inline virtual void SetUp() override; // called before each test fixture
	inline virtual void TearDown() override; // called after each test fixture

private:
	std::vector<int>* v; // predefined values
};

inline void SortingFixture::setVector(std::vector<int>* v) {
	this->v = v;
}

inline std::vector<int>* SortingFixture::getVector() {
	return this->v;
}