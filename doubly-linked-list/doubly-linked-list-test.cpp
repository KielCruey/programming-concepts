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

// ========= isEmpty() =========
TEST_F(DLListTest, IsEmpty_EmptyList) {
	EXPECT_TRUE(getList()->isEmpty());
}

TEST_F(DLListTest, IsEmpty_NonEmptyList) {
	getList()->addToHead(3);

	EXPECT_FALSE(getList()->isEmpty());
}

// ========= isInList() =========
TEST_F(DLListTest, IsInList_NoElement) {
	EXPECT_FALSE(getList()->isInList(2));
}

TEST_F(DLListTest, IsInList_ElementFound) {
	getList()->addToHead(2);

	EXPECT_TRUE(getList()->isInList(2));
}

// ========= addToHead() =========
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

// ========= addToTail() =========
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

	// ===== list tests =====
	EXPECT_NE(getList()->getTail(), getList()->getHead()); // not the same nodes

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

// ========= deleteDLLNode() =========
TEST_F(DLListTest, DeleteDLLNode_NullList) {
	EXPECT_EQ(getList()->deleteDLLNode(2), nullptr);
}

TEST_F(DLListTest, DeleteDLLNode_OnlyOneNode) {
	getList()->addToHead(3);
	auto nodeValue = getList()->getHead()->data;

	auto deletedValue = *getList()->deleteDLLNode(3);

	// ===== list tests =====
	EXPECT_EQ(getList()->getHead(), nullptr);
	EXPECT_EQ(getList()->getTail(), nullptr);

	// ===== node tests =====
	EXPECT_EQ(deletedValue, nodeValue); // node's data
}

TEST_F(DLListTest, DeleteDLLNode_MoreThanOneNode_DeleteHead) {
	getList()->addToHead(3);
	auto node3 = getList()->getHead();
	getList()->addToHead(2);
	auto node2 = getList()->getHead();
	getList()->addToHead(1);
	auto node1 = getList()->getHead();

	auto deletedValue = *getList()->deleteDLLNode(1);

	// ===== list tests =====
	EXPECT_EQ(getList()->getHead(), node2);
	EXPECT_EQ(getList()->getTail(), node3);

	// ===== node tests =====
	EXPECT_EQ(deletedValue, 1);

	EXPECT_EQ(getList()->getHead()->previous, nullptr);
	EXPECT_EQ(getList()->getHead()->next, node3);
	
	EXPECT_EQ(getList()->getTail()->previous, node2);
	EXPECT_EQ(getList()->getTail()->next, nullptr);
}

TEST_F(DLListTest, DeleteDLLNode_DeleteInTheMiddle) {
	getList()->addToHead(3);
	auto node3 = getList()->getHead();
	getList()->addToHead(2);
	auto node2 = getList()->getHead();
	getList()->addToHead(1);
	auto node1 = getList()->getHead();

	auto deletedValue = *getList()->deleteDLLNode(2);

	// ===== list tests =====
	EXPECT_EQ(getList()->getHead(), node1);
	EXPECT_EQ(getList()->getTail(), node3);

	// ===== node tests =====
	EXPECT_EQ(deletedValue, 2); // node2's value deleted

	EXPECT_EQ(node1->previous, nullptr); // node1's previous link
	EXPECT_EQ(node1->next, node3); // node1's previous link
	EXPECT_EQ(node1->data, 1); // node1's data

	EXPECT_EQ(node3->previous, node1); // node3's previous link
	EXPECT_EQ(node3->next, nullptr); // node1's previous link
	EXPECT_EQ(node3->data, 3); // node1's data
}

TEST_F(DLListTest, DeleteDLLNode_DeleteTheTail) {
	getList()->addToHead(3);
	auto node3 = getList()->getHead();
	getList()->addToHead(2);
	auto node2 = getList()->getHead();
	getList()->addToHead(1);
	auto node1 = getList()->getHead();

	auto deletedValue = *getList()->deleteDLLNode(3);

	// ===== list tests =====
	EXPECT_EQ(getList()->getHead(), node1);
	EXPECT_EQ(getList()->getTail(), node2);

	// ===== node tests =====
	EXPECT_EQ(deletedValue, 3); // node3's value deleted

	EXPECT_EQ(node1->previous, nullptr); // node1's previous link
	EXPECT_EQ(node1->next, node2); // node1's previous link
	EXPECT_EQ(node1->data, 1); // node1's data

	EXPECT_EQ(node2->previous, node1); // node2's previous link
	EXPECT_EQ(node2->next, nullptr); // node2's previous link
	EXPECT_EQ(node2->data, 2); // node2's data
}

// ========= deleteFromHead() =========
TEST_F(DLListTest, DeleteFromHead_NullList) {
	EXPECT_EQ(getList()->deleteFromHead(), nullptr);

	// ===== list tests =====
	EXPECT_EQ(getList()->getHead(), nullptr);
	EXPECT_EQ(getList()->getTail(), nullptr);
}

TEST_F(DLListTest, DeleteFromHead_OnlyOneElement) {
	getList()->addToHead(1);
	auto node = getList()->getHead();

	auto deletedValue = *getList()->deleteFromHead();

	// ===== list tests =====
	EXPECT_EQ(getList()->getHead(), nullptr);
	EXPECT_EQ(getList()->getTail(), nullptr);

	// ===== node tests =====
	EXPECT_EQ(deletedValue, 1); // deleted nodes value
}

TEST_F(DLListTest, DeleteFromHead_MoreThenOneElement) {
	getList()->addToHead(3);
	auto node3 = getList()->getHead();
	getList()->addToHead(2);
	auto node2 = getList()->getHead();
	getList()->addToHead(1);
	auto node1 = getList()->getHead();;
	
	auto deletedValue = *getList()->deleteFromHead();
	
	// ===== list tests =====
	EXPECT_EQ(getList()->getHead(), node2);

	// ===== node tests =====
	EXPECT_EQ(deletedValue, 1);

	EXPECT_EQ(node2->previous, nullptr); // node2's previous link
	EXPECT_EQ(node2->next, node3); // node2's next link
	EXPECT_EQ(node2->data, 2); // node2's value

	EXPECT_EQ(node3->previous, node2); // node3's previous link
	EXPECT_EQ(node3->next, nullptr); // node3's next link
	EXPECT_EQ(node3->data, 3); // node3's data
}

// ========= deleteFromTail() =========
TEST_F(DLListTest, DeleteFromTail_NullList) {
	auto node = new DLLNode<int>(9);

	EXPECT_EQ(getList()->deleteFromTail(), nullptr);

	// ===== list tests =====
	EXPECT_EQ(getList()->getHead(), nullptr);
	EXPECT_EQ(getList()->getTail(), nullptr);
}

TEST_F(DLListTest, DeleteFromTail_OnlyOneElement) {
	getList()->addToTail(1);
	auto deletedValue = *getList()->deleteFromTail();

	// ===== list tests =====
	EXPECT_EQ(getList()->getHead(), nullptr);
	EXPECT_EQ(getList()->getTail(), nullptr);
	
	// ===== node tests =====
	EXPECT_EQ(deletedValue, 1);
}

TEST_F(DLListTest, DeleteFromTail_MoreThenOneElement) {
	getList()->addToTail(3);
	auto node3 = getList()->getTail();
	getList()->addToTail(2);
	auto node2 = getList()->getTail();
	getList()->addToTail(1);
	auto node1 = getList()->getTail();;

	auto deletedValue = *getList()->deleteFromTail();

	// ===== list tests =====
	EXPECT_EQ(getList()->getHead(), node3);
	EXPECT_EQ(getList()->getTail(), node2);

	// ===== node tests =====
	EXPECT_EQ(deletedValue, 1);

	EXPECT_EQ(node2->previous, node3); // node2's previous link
	EXPECT_EQ(node2->next, nullptr); // node2's next link
	EXPECT_EQ(node2->data, 2); // node2's value

	EXPECT_EQ(node3->previous, nullptr); // node3's previous link
	EXPECT_EQ(node3->next, node2); // node3's next link
	EXPECT_EQ(node3->data, 3); // node3's data
}