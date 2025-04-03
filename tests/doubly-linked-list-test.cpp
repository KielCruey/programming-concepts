#include "pch.h"

#include "doubly-linked-list-test.hpp"

// ===== DLListTest Class =====
DLListTest::DLListTest(DLList<int>* list) :
	list(list)
{ }
void DLListTest::SetUp() {
	list = new DLList<int>();
}

void DLListTest::TearDown() {
	delete list;
}

DLList<int>* DLListTest::getList() {
	return this->list;
}

void DLListTest::setList(DLList<int>* list) {
	this->list = list;
}

// ===== DLList Confirms =====
// ===========================

// ------ isEmpty() ------
TEST_F(DLListTest, IsEmpty_EmptyList) {
	EXPECT_TRUE(getList()->isEmpty());
}

TEST_F(DLListTest, IsEmpty_NonEmptyList) {
	getList()->addToHead(3);

	EXPECT_FALSE(getList()->isEmpty());
}

// ------ isInList() ------
TEST_F(DLListTest, IsInList_NoElement) {
	EXPECT_FALSE(getList()->isInList(2));
}

TEST_F(DLListTest, IsInList_ElementFound) {
	getList()->addToHead(2);

	EXPECT_TRUE(getList()->isInList(2));
}

// ------ addToHead() ------
TEST_F(DLListTest, AddToHead_NullList) {
	getList()->addToHead(2);

	auto node1 = getList()->getHead();

	// ===== list tests =====
	EXPECT_EQ(getList()->getHead(), getList()->getTail()); // links are the same

	// ===== node tests =====
	EXPECT_EQ(node1->data, 2); // node value
	EXPECT_EQ(node1->next, nullptr); // node's next link
	EXPECT_EQ(node1->previous, nullptr); // node's previous link
}

TEST_F(DLListTest, AddToHead_NonNullList) {
	getList()->addToHead(2);
	auto node3 = getList()->getHead();
	getList()->addToHead(3);
	auto node2 = getList()->getHead();
	getList()->addToHead(4);
	auto node1 = getList()->getHead();

	// ===== list tests =====
	EXPECT_NE(getList()->getHead(), getList()->getTail()); // head/tail aren't the same

	// ===== node tests =====
	EXPECT_EQ(node1->previous, nullptr); // node1's previous link
	EXPECT_EQ(node1->next,node2); // node1's next link
	EXPECT_EQ(node1->data, 4); // node1's data

	EXPECT_EQ(node2->previous, node1); // node2's previous link
	EXPECT_EQ(node2->next, node3); // node2's next link
	EXPECT_EQ(node2->data, 3); // node2's data

	EXPECT_EQ(node3->previous, node2);  // node3's previous link
	EXPECT_EQ(node3->next, nullptr); // node2's next link
	EXPECT_EQ(node3->data, 2); // node3's data
}

// ------ addToTail() ------
TEST_F(DLListTest, AddToTail_NullList) {
	getList()->addToTail(2);
	auto node1 = getList()->getTail();

	// ===== list tests =====
	EXPECT_EQ(getList()->getTail(), getList()->getHead()); // list's head/tail aren't the same

	// ===== node tests =====
	EXPECT_EQ(node1->previous, nullptr); // node1's previous link
	EXPECT_EQ(node1->next, nullptr); // node1's next link
	EXPECT_EQ(node1->data, 2); // node3's data
}

TEST_F(DLListTest, AddToTail_NonNullList) {
	getList()->addToTail(2);
	auto node1 = getList()->getTail();
	getList()->addToTail(1);
	auto node2 = getList()->getTail();
	getList()->addToTail(0);
	auto node3 = getList()->getTail();

	auto node = new DLLNode<int>(2);

	// ===== list tests =====
	EXPECT_NE(getList()->getTail(), getList()->getHead());

	// ===== node tests =====
	EXPECT_EQ(node1->previous, nullptr); // node1's previous link
	EXPECT_EQ(node1->next, node2); // node1's next link
	EXPECT_EQ(node1->data, 2); // node1's data

	EXPECT_EQ(node2->previous, node1); // node2's previous link
	EXPECT_EQ(node2->next, node3); // node2's next link
	EXPECT_EQ(node2->data, 1); // node2's data

	EXPECT_EQ(node3->previous, node2); // node3's previous link
	EXPECT_EQ(node3->next, nullptr); // node3's next link
	EXPECT_EQ(node3->data, 0); // node2's data
}