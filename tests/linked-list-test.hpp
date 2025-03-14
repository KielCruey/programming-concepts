#include "../singly-linked-list/singly-linked-list.hpp"


class SLListTest : public testing::Test
{
public:
	SLListTest(SLList<int>* list = nullptr);
	~SLListTest() = default;

	SLList<int>* getList();
	void setList(SLList<int>* list);

protected:
	virtual void SetUp() override;
	virtual void TearDown() override;

private:
	SLList<int>* list;
};