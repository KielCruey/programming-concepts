#include "pch.h"

#include <array>
#include "quicksort.hpp"

// ========== CONSTRUCTOR TESTS ==========
namespace mergesort_class {
	TEST(Quicksort, quicksort_null_array) {
		Quicksort q;
		std::array<int, 0> array = { };

		q.quicksort(array.data(), 0, array.size() - 1);
		
		EXPECT_EQ(array.empty(), true);
	}

	TEST(Quicksort, quicksort_normal_condition) {
		Quicksort q;
		std::array<int, 8> array = { 9, 16, 0, 4, 1, 23, 8, -1 };
		std::array<int, 8> sortedArray = { -1, 0, 1, 4, 8, 9, 16, 23 };

		q.quicksort(array.data(), 0, array.size() - 1);

		for (int i = 0; i < array.size(); i++) 
			EXPECT_EQ(array[i], sortedArray[i]);
	}

	TEST(Quicksort, partition) {
		Quicksort q;
		std::array<int, 4> array = { 16, 9, 0, 4};
		
		int value = q.partition(array.data(), 0, array.size() - 1);

		EXPECT_EQ(value, 1);
	}
}