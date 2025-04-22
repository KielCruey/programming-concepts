#include "pch.h"

#include "singly-cirular-linked-list-test.hpp"

// ===== SCLListTest Class =====
SCLLTest::SCLLTest(SCLList<int>* list) :
	list(list)
{ }

SCLList<int>* SCLLTest::getList() {
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

	// ===== list node tests =====
	EXPECT_EQ(getList()->getCurrent(), node1);
	EXPECT_EQ(getList()->getCurrent()->next, node1);
}

TEST_F(SCLLTest, AddToHead_OneElement) {
	getList()->addToHead(1);
	auto node1 = getList()->getCurrent();
	getList()->addToHead(2);
	auto node2 = getList()->getCurrent();

	// ===== list node tests =====
	EXPECT_EQ(getList()->getCurrent(), node2);
	EXPECT_EQ(getList()->getCurrent()->next, node1);
	EXPECT_EQ(getList()->getCurrent()->next->next, node2); // circles around
}

TEST_F(SCLLTest, AddToHead_MoreThanOneElement) {
	getList()->addToHead(1);
	auto node1 = getList()->getCurrent();
	getList()->addToHead(2);
	auto node2 = getList()->getCurrent();
	getList()->addToHead(3);
	auto node3 = getList()->getCurrent();

	// ===== list node tests =====
	EXPECT_EQ(getList()->getCurrent(), node3);
	EXPECT_EQ(getList()->getCurrent()->next, node2);
	EXPECT_EQ(getList()->getCurrent()->next->next, node1);
	EXPECT_EQ(getList()->getCurrent()->next->next->next, node3); // circles around
}

// ----------- addToTail() ----------
TEST_F(SCLLTest, AddToTail_NullList) {
	getList()->addToTail(1);
	auto node1 = getList()->getCurrent();

	// ===== list node tests =====
	EXPECT_EQ(getList()->getCurrent(), node1);
	EXPECT_EQ(getList()->getCurrent()->next, node1); // circles around
}

TEST_F(SCLLTest, AddToTail_NonNullList_OneElement) {
	getList()->addToTail(1);
	auto node1 = getList()->getCurrent();
	getList()->addToTail(2);
	auto node2 = getList()->getCurrent()->next;

	// ===== list node tests =====
	EXPECT_EQ(getList()->getCurrent(), node1);
	EXPECT_EQ(getList()->getCurrent()->next, node2);
	EXPECT_EQ(getList()->getCurrent()->next->next, node1); // circles around
}

TEST_F(SCLLTest, AddToTail_NonNullList_MoreThanTwoElements) {
	getList()->addToTail(1);
	auto node1 = getList()->getCurrent();
	getList()->addToTail(2);
	auto node2 = getList()->getCurrent()->next;
	getList()->addToTail(3);
	auto node3 = getList()->getCurrent()->next->next;

	// ===== list node tests =====
	EXPECT_EQ(getList()->getCurrent(), node1);
	EXPECT_EQ(getList()->getCurrent()->next, node2);
	EXPECT_EQ(getList()->getCurrent()->next->next, node3);
	EXPECT_EQ(getList()->getCurrent()->next->next->next, node1); // circles around
}

// ----------- deleteFromHead() ----------
TEST_F(SCLLTest, DeleteFromHead_NullList) {
	getList()->deleteFromHead();

	EXPECT_EQ(getList()->getCurrent(), nullptr);
}

TEST_F(SCLLTest, DeleteFromHead_NonNullList) {
	getList()->addToHead(1);
	auto node1 = getList()->getCurrent();

	auto numb1 = getList()->deleteFromHead();

	EXPECT_EQ(*numb1, 1);
}

/*
TEST_F(SCLLTest, DeleteFromHead_NonNullList_MoreThanOne) {
	getList()->addToHead(1);
	auto node1 = getList()->getCurrent();
	getList()->addToHead(2);
	auto node2= getList()->getCurrent()->next;

	EXPECT_EQ(node1->data = 5);
}
*/