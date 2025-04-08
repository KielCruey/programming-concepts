#include "pch.h"

#include "singly-cirular-linked-list-test.hpp"

// ===== SCLListTest Class =====
SCLLTest::SCLLTest(SCLList<int>* list) :
	list(list)
{ }

SCLList<int>* SCLLTest::getList() const {
	return this->list;
}

void SCLLTest::setList(SCLList<int>* list) {
	this->list = list;
}

void SCLLTest::SetUp() {
	list = new SCLList<int>();
}

void SCLLTest::TearDown() {
	delete list;
}

// ===== SCLListTest Confirms =====
// ================================
// ----------- isEmpty() ----------
TEST_F(SCLLTest, IsEmpty_NullList) {
	EXPECT_TRUE(getList()->isEmpty());
}

TEST_F(SCLLTest, IsEmpty_NonNullList_OneElement) {
	getList()->addToHead(1);

	EXPECT_FALSE(getList()->isEmpty());
}

// ----------- addToHead() ----------
TEST_F(SCLLTest, AddToHead_NullList) {
	getList()->addToHead(1);
	auto node1 = getList()->getCurrent();

	auto node = new SCLLNode<int>(2);

	EXPECT_EQ(getList()->getCurrent(), node);
}