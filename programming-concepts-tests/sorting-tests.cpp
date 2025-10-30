#include "pch.h"
#include "sorting-tests.hpp"

namespace InsertionTests {
	TEST_F(SortingFixture, Insertion_Normal_Condition) {
		std::vector<int> testV = { 2, 3, 4, 5, 8, 9 };

		Sorting s = Sorting(getVector());
		s.insertionSort();

		for (int i = 0; i < getVector()->size(); i++)
			EXPECT_EQ(getVector()->at(i), testV.at(i));
	}

}

namespace BubbleTests {
	TEST_F(SortingFixture, Bubble_Normal_Condition) {
		std::vector<int> testV = { 2, 3, 4, 5, 8, 9 };

		Sorting s = Sorting(getVector());
		s.bubbleSort();

		for (int i = 0; i < getVector()->size(); i++)
			EXPECT_EQ(getVector()->at(i), testV.at(i));
	}
}

namespace SelectionSort{
	TEST_F(SortingFixture, Selection_Normal_Condition) {
		std::vector<int> testV = { 2, 3, 4, 5, 8, 9 };

		Sorting s = Sorting(getVector());
		s.selectionSort();

		for (int i = 0; i < getVector()->size(); i++)
			EXPECT_EQ(getVector()->at(i), testV.at(i));
	}
}

// ========== test fixture ==========
SortingFixture::SortingFixture(std::vector<int>* v)
	: v(v)
{ }

void SortingFixture::SetUp() {
	v = new std::vector<int>{ 2, 8, 5, 3, 9, 4 };
}

void SortingFixture::TearDown() {
	delete v;
}

void SortingFixture::setVector(std::vector<int>* v) {
	this->v = v;
}

std::vector<int>* SortingFixture::getVector() {
	return this->v;
}