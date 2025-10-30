#pragma once

#include <vector>

class MergeSortAlgorithm
{
public:
	MergeSortAlgorithm();
	MergeSortAlgorithm(std::vector<int>& vec); // takes in stack vector and copies it to class's vector

	// ======= getters/setters =======
	std::vector<int>* getVector();
	void setVector(std::vector<int>* v);

	// Recursive function for sorting the array -- splitting the array
	void merge_sort(std::vector<int>& vec, int l, int r);

private:
	// Merges to sorted sub-lists
	void merge(unsigned int start, unsigned int middle, unsigned int end);

	std::vector<int>* v = nullptr;
};