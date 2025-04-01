#include "pch.h"

#include "linked-list-test.hpp"

// ===== SLListTest Class =====
SLListTest::SLListTest(SLList<int>* list)
	: list(list)
{ }

SLList<int>* SLListTest::getList() {
	return this->list;
}

void SLListTest::setList(SLList<int>* list) {
	this->list = list;
}

void SLListTest::SetUp() {
	list = new SLList<int>();
}

void SLListTest::TearDown() {
	delete list;
}

// ===== SLList Confirms =====
// ===========================
// ------ isEmpty() ------
TEST_F(SLListTest, IsEmpty_EmptyList) {
	// case #1 -- empty list
	EXPECT_EQ(getList()->isEmpty(), true);
}

TEST_F(SLListTest, IsEmpty_NonEmptyList) {
	// case #2 -- non-empty list
	getList()->addToHead(1);

	EXPECT_EQ(getList()->isEmpty(), false);
}

// ------ addToHead() ------
TEST_F(SLListTest, AddToHead_NullList) {
	getList()->addToHead(2);

	EXPECT_EQ(getList()->getHead()->data, 2);
}

TEST_F(SLListTest, AddToHead) {
	getList()->addToHead(2);
	getList()->addToHead(1);
	getList()->addToHead(0);
	getList()->addToHead(-10);
	getList()->addToHead(-20);

	EXPECT_EQ(getList()->getHead()->data, -20);
	EXPECT_EQ(getList()->getHead()->next->data, -10);
	EXPECT_EQ(getList()->getHead()->next->next->data, 0);
	EXPECT_EQ(getList()->getHead()->next->next->next->data, 1);
	EXPECT_EQ(getList()->getHead()->next->next->next->next->data, 2);
}

// ------ addToTail() ------
TEST_F(SLListTest, AddToTail_NullList) {
	getList()->addToTail(5);

	EXPECT_EQ(getList()->getHead()->data, 5);
}

TEST_F(SLListTest, AddToTail) {
	getList()->addToTail(5);
	getList()->addToTail(4);
	getList()->addToTail(3);
	getList()->addToTail(2);
	getList()->addToTail(1);

	EXPECT_EQ(getList()->getHead()->data, 5);
	EXPECT_EQ(getList()->getHead()->next->data, 4);
	EXPECT_EQ(getList()->getHead()->next->next->data, 3);
	EXPECT_EQ(getList()->getHead()->next->next->next->data, 2);
	EXPECT_EQ(getList()->getHead()->next->next->next->next->data, 1);
}

// ------ deleteFromHead() ------
TEST_F(SLListTest, DeleteFromHead_NullList) {
	EXPECT_EQ(getList()->deleteFromHead(), nullptr);
}

TEST_F(SLListTest, DeleteFromHead_OnlyOneElement) {
	SLLNode<int>* valueNode = nullptr;
	getList()->addToHead(1);

	getList()->deleteFromHead();

	EXPECT_EQ(getList()->getHead(), valueNode);
}

TEST_F(SLListTest, DeleteFromHead_MoreThanOneElement) {
	getList()->addToHead(1);
	SLLNode<int>* valueNode = getList()->getHead();
	getList()->addToHead(10);

	getList()->deleteFromHead();

	EXPECT_EQ(getList()->getHead(), valueNode);
}

// ------ deleteFromTail() ------
TEST_F(SLListTest, DeleteFromTail_NullList) {
	getList()->deleteFromTail();

	EXPECT_EQ(getList()->getTail(), nullptr);
}

TEST_F(SLListTest, DeleteFromTail_OnlyOneElement) {
	getList()->addToHead(1);

	getList()->deleteFromTail();

	EXPECT_EQ(getList()->getTail(), nullptr);
}

TEST_F(SLListTest, DeleteFromTail_MoreThanOneElement) {
	getList()->addToHead(1);
	SLLNode<int>* valueNode = getList()->getTail();

	getList()->deleteFromTail();

	EXPECT_EQ(getList()->getTail(), nullptr);
}

// ------ deleteSLLNode() ------
TEST_F(SLListTest, DeleteSLLNode_NullList) {
	EXPECT_EQ(getList()->deleteSLLNode(1), nullptr);
}

// case #1
TEST_F(SLListTest, DeleteSLLNode_OnlyOneElement) {
	getList()->addToHead(10);
	int nodeData = getList()->getHead()->data;

	int* value = getList()->deleteSLLNode(10);
	int value1 = *value;

	EXPECT_EQ(value1, nodeData); // checks numbers are the same
}

// case #2
TEST_F(SLListTest, DeleteSLLNode_MoreThanOneElement_DeleteHead) {
	getList()->addToHead(10);
	getList()->addToHead(30);
	int nodeData = getList()->getHead()->data;

	int* value = getList()->deleteSLLNode(30);
	int value1 = *value;

	EXPECT_EQ(value1, nodeData); // checks numbers are the same
}

// case #3 -- condition #1
TEST_F(SLListTest, DeleteSLLNode_MoreThanOneElement_DeleteMiddle) {
	getList()->addToHead(10);
	getList()->addToHead(20);
	int nodeData = getList()->getHead()->data;
	getList()->addToHead(30);

	int* value = getList()->deleteSLLNode(20);
	int value1 = *value;

	EXPECT_EQ(value1, nodeData); // checks numbers are the same
}

// case #3 -- condition #2
TEST_F(SLListTest, DeleteSLLNode_MoreThanOneElement_DeleteTail) {
	getList()->addToHead(10);
	int nodeData = getList()->getHead()->data;
	getList()->addToHead(20);
	getList()->addToHead(30);

	int* value = getList()->deleteSLLNode(10);
	int value1 = *value;

	EXPECT_EQ(value1, nodeData); // checks numbers are the same
}

// ------ isInList() ------
TEST_F(SLListTest, IsInList_NoElement) {
	getList()->addToHead(10);

	EXPECT_EQ(getList()->isInList(0), false);
}

TEST_F(SLListTest, IsInList_YesElement) {
	getList()->addToHead(10);

	EXPECT_EQ(getList()->isInList(10), true);
}