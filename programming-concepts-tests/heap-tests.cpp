#include "pch.h"
#include "heap-tests.hpp"

// ========== tests ==========

namespace HeapTests {
	TEST_F(HeapFixture, Insertion_Normal_Condition) {
		
		MaxHeap h = MaxHeap();
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