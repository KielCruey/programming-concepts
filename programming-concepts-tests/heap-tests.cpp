#include "pch.h"
#include "heap-tests.hpp"

// ========== tests ==========
namespace HeapTests {
	TEST_F(HeapFixture, Parent) {
		MaxHeap h = MaxHeap();

		// "-1" is null in this context
		EXPECT_EQ(h.parent(0), -1);
		EXPECT_EQ(h.parent(1), 0);
		EXPECT_EQ(h.parent(2), 0);
		EXPECT_EQ(h.parent(3), 1);
		EXPECT_EQ(h.parent(4), 1);
		EXPECT_EQ(h.parent(5), 2);
		EXPECT_EQ(h.parent(6), 2);
		EXPECT_EQ(h.parent(7), 3);
		EXPECT_EQ(h.parent(8), 3);
		EXPECT_EQ(h.parent(9), 4);
	}

	TEST_F(HeapFixture, Left) {
		MaxHeap h = MaxHeap();

		// "-1" is null in this context
		EXPECT_EQ(h.left(0), 1);
		EXPECT_EQ(h.left(1), 3);
		EXPECT_EQ(h.left(2), 5);
		EXPECT_EQ(h.left(3), 7);
		EXPECT_EQ(h.left(4), 9);
		EXPECT_EQ(h.left(5), 11);
		EXPECT_EQ(h.left(6), 13);
		EXPECT_EQ(h.left(7), 15);
		EXPECT_EQ(h.left(8), 17);
		EXPECT_EQ(h.left(9), 19);
	}

	TEST_F(HeapFixture, Right) {
		MaxHeap h = MaxHeap();

		// "-1" is null in this context
		EXPECT_EQ(h.right(0), 2);
		EXPECT_EQ(h.right(1), 4);
		EXPECT_EQ(h.right(2), 6);
		EXPECT_EQ(h.right(3), 8);
		EXPECT_EQ(h.right(4), 10);
		EXPECT_EQ(h.right(5), 12);
		EXPECT_EQ(h.right(6), 14);
		EXPECT_EQ(h.right(7), 16);
		EXPECT_EQ(h.right(8), 18);
		EXPECT_EQ(h.right(9), 20);
	}
}

namespace MaxHeapTests {
	// ==== Heapify ====
	TEST_F(HeapFixture, Heapify_Normal_Conditions) {
		std::vector<int> testV = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		std::vector<int> results = { 2, 1, 6, 3, 4, 5, 0, 7, 8, 9 };

		MaxHeap h = MaxHeap();
		h.setCurrentSize(testV.size());
		h.heapify(testV, 0);

		for (int i = 0; i < testV.size(); i++) {
			EXPECT_EQ(testV.at(i), results.at(i));
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