#include "pch.h"

// ========== CONSTRUCTOR TESTS ==========
// checks if memory is set aside
TEST(Constructor, Default_Constructor) {
	MergeSortAlgorithm* msAlgo = new MergeSortAlgorithm();

	EXPECT_EQ(msAlgo->getVector()->capacity(), 0);
}

// checks if memory is set aside and content(s) of vector
TEST(Constructor, Non_Constructor_Empty_Vector) {
	std::vector<int> tempV = { };
	MergeSortAlgorithm* msAlgo = new MergeSortAlgorithm(tempV);

	EXPECT_EQ(msAlgo->getVector()->capacity(), 1);
	EXPECT_EQ(msAlgo->getVector()->at(0), 0);
}

// check content(s) of vector
TEST(Constructor, Non_Constructor_Populated_Vector) {
	std::vector<int> tempV = { 44, 88, -1,-22 };
	MergeSortAlgorithm * msAlgo = new MergeSortAlgorithm(tempV);

	EXPECT_EQ(msAlgo->getVector()->at(0), 44);
	EXPECT_EQ(msAlgo->getVector()->at(1), 88);
	EXPECT_EQ(msAlgo->getVector()->at(2), -1);
	EXPECT_EQ(msAlgo->getVector()->at(3), -22);
}
// ========== merge_sort TESTS ==========
TEST(MergeSort_Vector_Tests, merge_sort_Valid_Condition_with_Even_Elements) {
	std::vector<int> tempV = { 18,5,3,99 };
	MergeSortAlgorithm* msAlgo = new MergeSortAlgorithm(tempV);

	msAlgo->merge_sort(tempV, 0, tempV.size() - 1);
	msAlgo->setVector(&tempV);

	EXPECT_EQ(msAlgo->getVector()->at(0), 3);
	EXPECT_EQ(msAlgo->getVector()->at(1), 5);
	EXPECT_EQ(msAlgo->getVector()->at(2), 18);
	EXPECT_EQ(msAlgo->getVector()->at(3), 99);
}

TEST(MergeSort_Vector_Tests, merge_sort_Valid_Condition_with_Odd_Elements) {
	std::vector<int> tempV = { 44,-5,83,9,27 };
	MergeSortAlgorithm* msAlgo = new MergeSortAlgorithm(tempV);

	msAlgo->merge_sort(tempV, 0, tempV.size() - 1);
	msAlgo->setVector(&tempV);

	EXPECT_EQ(msAlgo->getVector()->at(0), -5);
	EXPECT_EQ(msAlgo->getVector()->at(1), 9);
	EXPECT_EQ(msAlgo->getVector()->at(2), 27);
	EXPECT_EQ(msAlgo->getVector()->at(3), 44);
	EXPECT_EQ(msAlgo->getVector()->at(4), 83);
}

TEST(MergeSort_L_Tests, merge_sort_L_Negative_Number) {
	try {
		std::vector<int> tempV = { 44,-5,83,9,27 };
		MergeSortAlgorithm* msAlgo = new MergeSortAlgorithm(tempV);

		msAlgo->merge_sort(tempV, -1, tempV.size() - 1);
		msAlgo->setVector(&tempV);

		EXPECT_EQ(msAlgo->getVector()->at(0), 44);
		EXPECT_EQ(msAlgo->getVector()->at(1), -5);
		EXPECT_EQ(msAlgo->getVector()->at(2), 83);
		EXPECT_EQ(msAlgo->getVector()->at(3), 9);
		EXPECT_EQ(msAlgo->getVector()->at(4), 27);
	}
	catch (std::invalid_argument& error)
	{
		EXPECT_EQ(error.what(), std::string("L received negative value"));
	}
}

TEST(MergeSort_L_Tests, merge_sort_L_Greater_Than_Vector_Size) {
	try {
		std::vector<int> tempV = { 44,-5,83,9,27 };
		MergeSortAlgorithm* msAlgo = new MergeSortAlgorithm(tempV);

		msAlgo->merge_sort(tempV, tempV.size() + 4, 0);
		msAlgo->setVector(&tempV);

		EXPECT_EQ(msAlgo->getVector()->at(0), 44);
		EXPECT_EQ(msAlgo->getVector()->at(1), -5);
		EXPECT_EQ(msAlgo->getVector()->at(2), 83);
		EXPECT_EQ(msAlgo->getVector()->at(3), 9);
		EXPECT_EQ(msAlgo->getVector()->at(4), 27);
	}
	catch (std::invalid_argument& error)
	{
		EXPECT_EQ(error.what(), std::string("L greater than vector's max size"));
	}
}

TEST(MergeSort_R_Tests, merge_sort_R_Greater_Than_Vector_Size) {
	try {
		std::vector<int> tempV = { 44,-5,83,9,27 };
		MergeSortAlgorithm* msAlgo = new MergeSortAlgorithm(tempV);
		msAlgo->setVector(&tempV);
		msAlgo->merge_sort(tempV, 0, tempV.size() + 4);
		msAlgo->setVector(&tempV);

		EXPECT_EQ(msAlgo->getVector()->at(0), 44);
		EXPECT_EQ(msAlgo->getVector()->at(1), -5);
		EXPECT_EQ(msAlgo->getVector()->at(2), 83);
		EXPECT_EQ(msAlgo->getVector()->at(3), 9);
		EXPECT_EQ(msAlgo->getVector()->at(4), 27);
	}
	catch (std::invalid_argument & error)
	{
		EXPECT_EQ(error.what(), std::string("R greater than vector's max size"));
	}
}

TEST(MergeSort_LR_Tests, merge_sort_L_Equal_R) {
	std::vector<int> tempV = { 44,-5,83,9,27 };
	MergeSortAlgorithm* msAlgo = new MergeSortAlgorithm(tempV);

	msAlgo->merge_sort(tempV, tempV.size() - 1, tempV.size() - 1);
	msAlgo->setVector(&tempV);

	EXPECT_EQ(msAlgo->getVector()->at(0), 44);
	EXPECT_EQ(msAlgo->getVector()->at(1), -5);
	EXPECT_EQ(msAlgo->getVector()->at(2), 83);
	EXPECT_EQ(msAlgo->getVector()->at(3), 9);
	EXPECT_EQ(msAlgo->getVector()->at(4), 27);
}

TEST(MergeSort_LR_Tests, merge_sort_L_Greater_Than_R_with_Valid_Scope) {
	std::vector<int> tempV = { 44,-5,83,9,27 };
	MergeSortAlgorithm* msAlgo = new MergeSortAlgorithm(tempV);

	msAlgo->merge_sort(tempV, tempV.size() - 1, 0);
	msAlgo->setVector(&tempV);

	EXPECT_EQ(msAlgo->getVector()->at(0), 44);
	EXPECT_EQ(msAlgo->getVector()->at(1), -5);
	EXPECT_EQ(msAlgo->getVector()->at(2), 83);
	EXPECT_EQ(msAlgo->getVector()->at(3), 9);
	EXPECT_EQ(msAlgo->getVector()->at(4), 27);
}

TEST(MergeSort_LR_Tests, merge_sort_R_Greater_Than_L_with_Valid_Scope) {
	std::vector<int> tempV = { 44,-5,83,9,27 };
	MergeSortAlgorithm* msAlgo = new MergeSortAlgorithm(tempV);

	msAlgo->merge_sort(tempV, tempV.size() - 2, 1);
	msAlgo->setVector(&tempV);

	EXPECT_EQ(msAlgo->getVector()->at(0), 44);
	EXPECT_EQ(msAlgo->getVector()->at(1), -5);
	EXPECT_EQ(msAlgo->getVector()->at(2), 83);
	EXPECT_EQ(msAlgo->getVector()->at(3), 9);
	EXPECT_EQ(msAlgo->getVector()->at(4), 27);
}

TEST(MergeSort_R_Tests, merge_sort_R_Negative) {
	try {
		std::vector<int> tempV = { 44,-5,83,9,27 };
		MergeSortAlgorithm* msAlgo = new MergeSortAlgorithm(tempV);

		msAlgo->merge_sort(tempV, 0, -100);
		msAlgo->setVector(&tempV);
	
		EXPECT_EQ(msAlgo->getVector()->at(0), 44);
		EXPECT_EQ(msAlgo->getVector()->at(1), -5);
		EXPECT_EQ(msAlgo->getVector()->at(2), 83);
		EXPECT_EQ(msAlgo->getVector()->at(3), 9);
		EXPECT_EQ(msAlgo->getVector()->at(4), 27);
	}
	catch (std::invalid_argument& error)
	{
		EXPECT_EQ(error.what(), std::string("R received negative value"));
	}
}
