#include "pch.h"
#include "heap-tests.hpp"

// ========== tests ==========
namespace HeapTests {
	TEST_F(HeapFixture, HeapMaximum_Grabs_Root_Node) {
		std::vector<int> testV = { 4 };
		
		MaxHeap h = MaxHeap();
		h.heapMaximum(*getVector());

		EXPECT_EQ(getVector()->at(0), testV.at(0));
	}

	TEST_F(HeapFixture, HeapMaximum_Null_Heap) {
		std::vector<int> nullV = {};

		MaxHeap h = MaxHeap();

		ASSERT_THROW(h.heapMaximum(nullV), std::runtime_error);
	}

	TEST_F(HeapFixture, BuildMaxHeap_Normal_Conditions) {
		std::vector<int> testV = { 4 };

		MaxHeap h = MaxHeap();
		h.buildHeap(*getVector(), getVector()->size());

		EXPECT_EQ(getVector()->at(0), testV.at(0));
	}
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