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

	auto nodeData = getList()->getHead()->data;
	auto nodeNext = getList()->getHead()->next;
	auto nodePrevious = getList()->getHead()->previous;
	auto headLink = getList()->getHead();
	auto tailLink = getList()->getTail();

	DLLNode<int>* node = new DLLNode<int>(2);

	// ===== list tests =====
	EXPECT_EQ(headLink, tailLink); // links are the same

	// ===== node tests =====
	EXPECT_EQ(getList()->getHead()->data, nodeData); // node value
	EXPECT_EQ(nodeNext, nullptr); // node's next link
	EXPECT_EQ(nodePrevious, nullptr); // node's previous link
}

TEST_F(DLListTest, AddToHead_NonNullList) {

}