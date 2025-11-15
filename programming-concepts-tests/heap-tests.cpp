#include "pch.h"
#include "heap-tests.hpp"

// ========== tests ==========
namespace HeapTests {
	TEST_F(HeapFixture, Parent) {
		MaxHeap h = MaxHeap();

 		auto parent0 = h.parent(0); // index 0's parent
		auto parent1 = h.parent(1); // index 1's parent
		auto parent2 = h.parent(2); // index 2's parent
		auto parent3 = h.parent(3); // index 3's parent
		auto parent4 = h.parent(4); // index 4's parent
		auto parent5 = h.parent(5); // index 5's parent
		auto parent6 = h.parent(6); // index 6's parent
		auto parent7 = h.parent(7); // index 7's parent
		auto parent8 = h.parent(8); // index 8's parent
		auto parent9 = h.parent(9); // index 9's parent

		// "-1" is null in this context
		EXPECT_EQ(parent0, -1);
		EXPECT_EQ(parent1, 0);
		EXPECT_EQ(parent2, 0);
		EXPECT_EQ(parent3, 1);
		EXPECT_EQ(parent4, 1);
		EXPECT_EQ(parent5, 2);
		EXPECT_EQ(parent6, 2);
		EXPECT_EQ(parent7, 3);
		EXPECT_EQ(parent8, 3);
		EXPECT_EQ(parent9, 4);
	}

	TEST_F(HeapFixture, Left) {
		MaxHeap h = MaxHeap();

		auto left0 = h.left(0); // index 0's left node
		auto left1 = h.left(1); // index 1's left node
		auto left2 = h.left(2); // index 2's left node
		auto left3 = h.left(3); // index 3's left node
		auto left4 = h.left(4); // index 4's left node
		auto left5 = h.left(5); // index 5's left node
		auto left6 = h.left(6); // index 6's left node
		auto left7 = h.left(7); // index 7's left node
		auto left8 = h.left(8); // index 8's left node
		auto left9 = h.left(9); // index 9's left node

		// "-1" is null in this context
		EXPECT_EQ(left0, 1);
		EXPECT_EQ(left1, 3);
		EXPECT_EQ(left2, 5);
		EXPECT_EQ(left3, 7);
		EXPECT_EQ(left4, 9);
		EXPECT_EQ(left5, 11);
		EXPECT_EQ(left6, 13);
		EXPECT_EQ(left7, 15);
		EXPECT_EQ(left8, 17);
		EXPECT_EQ(left9, 19);
	}

	TEST_F(HeapFixture, Right) {
		MaxHeap h = MaxHeap();

		auto right0 = h.right(0); // index 0's left node
		auto right1 = h.right(1); // index 1's left node
		auto right2 = h.right(2); // index 2's left node
		auto right3 = h.right(3); // index 3's left node
		auto right4 = h.right(4); // index 4's left node
		auto right5 = h.right(5); // index 5's left node
		auto right6 = h.right(6); // index 6's left node
		auto right7 = h.right(7); // index 7's left node
		auto right8 = h.right(8); // index 8's left node
		auto right9 = h.right(9); // index 9's left node

		// "-1" is null in this context
		EXPECT_EQ(right0, 2);
		EXPECT_EQ(right1, 4);
		EXPECT_EQ(right2, 6);
		EXPECT_EQ(right3, 8);
		EXPECT_EQ(right4, 10);
		EXPECT_EQ(right5, 12);
		EXPECT_EQ(right6, 14);
		EXPECT_EQ(right7, 16);
		EXPECT_EQ(right8, 18);
		EXPECT_EQ(right9, 20);
	}
}

namespace MaxHeapTests {
	// ==== Heapify ====
	TEST_F(HeapFixture, Heapify_Normal_Conditions) {
		std::vector<int> results = { 4, 16, 3, 2, 7, 9, 10, 14, 8, 1 };

		MaxHeap h = MaxHeap();
		h.heapify(*getVector(), 1); // heapify index 1 which is "1" from test fixture

		for (int i = 0; i < getVector()->size(); i++) {
			EXPECT_EQ(getVector()->at(i), results.at(i));
		}
	}

	TEST_F(HeapFixture, Heapify_Normal_Conditions_With_Right_Node_Null) {
		std::vector<int> results = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

		MaxHeap h = MaxHeap();
		h.heapify(*getVector(), 4); // heapify index 1 which is "1" from test fixture

		for (int i = 0; i < getVector()->size(); i++) {
			EXPECT_EQ(getVector()->at(i), results.at(i));
		}
	}

	TEST_F(HeapFixture, Heapify_Normal_Conditions_With_Left_Right_Nodes_Null) {
		std::vector<int> results = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };

		MaxHeap h = MaxHeap();
		h.heapify(*getVector(), 5); // heapify index 1 which is "1" from test fixture

		for (int i = 0; i < getVector()->size(); i++) {
			EXPECT_EQ(getVector()->at(i), results.at(i));
		}
	}

	// ==== BuildMaxHeap ====
	TEST_F(HeapFixture, BuildMaxHeap_Normal_Conditions) {
		std::vector<int> testV = { 1, 2, 3, 4, 5, 6, 7, 8 };
		std::vector<int> results = { 8, 5, 7, 4, 1, 6, 3, 2 };

		MaxHeap h = MaxHeap();
		h.buildHeap(testV, testV.size());

		for(int i = 0; i < testV.size(); i++)
			EXPECT_EQ(testV.at(i), results.at(i));
	}

	// ==== HeapMaximum ====
	TEST_F(HeapFixture, HeapMaximum_Null_Heap) {
		std::vector<int> results = {};

		MaxHeap h = MaxHeap();

		EXPECT_THROW(h.heapMaximum(results), std::runtime_error);
	}

	TEST_F(HeapFixture, HeapMaximum_Normal_Conditions) {
		std::vector<int> results = { 4 };
		
		MaxHeap h = MaxHeap();
		h.heapMaximum(*getVector());

		EXPECT_EQ(getVector()->at(0), results.at(0));
	}

	// ==== HeapSort ====
	TEST_F(HeapFixture, HeapSort_Normal_Conditions) {
		std::vector<int> results = { 1, 2, 3, 4, 7, 8, 9, 10, 14, 16 };

		MaxHeap h = MaxHeap();
		h.heapSort(*getVector(), getVector()->size());

		for (int i = 0; i < getVector()->size(); i++)
			EXPECT_EQ(getVector()->at(i), results.at(i));
	}



}

namespace MinHeapTests {

}

// ========== test fixture ==========
HeapFixture::HeapFixture(std::vector<int>* v) 
	: v(v)
{ }

void HeapFixture::SetUp() {
	v = new std::vector<int>{ 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
}

void HeapFixture::TearDown() {
	delete v;
}