#include "../singly-circular-linked-list/singly-circular-linked-list.hpp"

// test fixture
class SCLLTest : public testing::Test 
{
public:
	SCLLTest(SCLList<int>* list = nullptr);
	~SCLLTest() = default;

	SCLList<int>* getList();
	void setList(SCLList<int>* list);

protected:
	virtual void SetUp() override;
	virtual void TearDown() override;

private:
	SCLList<int>* list;
};