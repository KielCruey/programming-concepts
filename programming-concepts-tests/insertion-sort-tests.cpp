#include "pch.h"

namespace InsertionTests {
	TEST(InsertionSort, Valid) {
		std::vector<int> v = { 2, 8, 5, 3, 9, 4 };

		// lowest to highest
		std::vector<int> testV = { 2, 3, 4, 5, 8, 9 };

		InsertionSort is = InsertionSort();
		is.setVector(&v);

		std::vector<int>* newV = is.insertionSort();

		for(int i = 0; i < v.size(); i++)
			EXPECT_EQ(newV->at(i), testV.at(i));
	}
}