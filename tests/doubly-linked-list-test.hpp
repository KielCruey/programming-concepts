#include "../doubly-linked-list/doubly-linked-list.hpp"

// test fixture

class DLListTest : public testing::Test
{
public:
	DLListTest(DLList<int>* list = nullptr);
	~DLListTest() = default;

	DLList<int>* getList();
	void setList(DLList<int>* list);

protected:
	virtual void SetUp() override;
	virtual void TearDown() override;

private:
	DLList<int>* list;
};