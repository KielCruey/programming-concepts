#include <iostream>
#include <stdlib.h>

#include "mergeSort.hpp"

MergeSortAlgorithm::MergeSortAlgorithm() {
    this->v = new std::vector<int>();
}

// pushes back all element to the class internal vector
MergeSortAlgorithm::MergeSortAlgorithm(std::vector<int>& vec)
{
    this->v = new std::vector<int>;

    // checks empty vector
    if (vec.size() == 0)
        v->push_back(0);
    else
        for (int i = 0; i < vec.size(); i++)
            this->v->push_back(vec.at(i));
}

std::vector<int>* MergeSortAlgorithm::getVector() {
    return this->v;
}

void MergeSortAlgorithm::setVector(std::vector<int>* v) {
    this->v = v;
}

// Merges to sorted sub-lists
void MergeSortAlgorithm::merge(std::vector<int> &vec, unsigned int start, unsigned int middle, unsigned int end){
    // Initialize left-hand elements
    unsigned int elements_left = middle - start + 1;
    std::vector<int> tmp_left;

    // Initialize right-hand elements
    unsigned int elements_right = end - middle;
    std::vector<int> tmp_right;

    for(unsigned int i = 0; i < elements_left; i++)
        tmp_left.push_back(vec[start + i]);
    
    for(unsigned int i = 0; i < elements_right; i++)
        tmp_right.push_back(vec[middle + 1 + i]);

    // Compare vectors and add elements to the final result
    unsigned int i = 0;
    unsigned int j = 0;
    int pos = start;

    while((i < tmp_left.size()) && (j < tmp_right.size())){
        // Add left-hand element if it's smaller
        // Otherwise add right-hand element 
        if(tmp_left[i] <= tmp_right[j]){
            vec[pos] = tmp_left[i];
            i++;
        }
        else{
            vec[pos] = tmp_right[j];
            j++;
        }

        // Increment position in final vector
        pos++;
    }

    // Clean up remaining left-hand elements
    while(i < tmp_left.size()){
        vec[pos] = tmp_left[i];
        i++;
        pos++;
    }
    
    // Clean up remaining right-hand elements
    while(j < tmp_right.size()){
        vec[pos] = tmp_right[j];
        j++;
        pos++;
    }
}

// Recursive function for sorting the array
void MergeSortAlgorithm::merge_sort(std::vector<int> &vec, int l, int r){

    // error checking
    if (l < 0)
        throw std::invalid_argument("L received negative value");

    if (l > (int)getVector()->size())
        throw std::invalid_argument("L greater than vector's max size");

    if(r < 0)
        throw std::invalid_argument("R received negative value");

    if(r > (int)getVector()->size())
        throw std::invalid_argument("R greater than vector's max size");

    // Merge until we are left with a single element
    if (l < r) {
        // Calculate mid-point of vector
        int mid = (l + r) / 2;

        // Sort the sub-vectors
        merge_sort(vec, l, mid);
        merge_sort(vec, mid + 1, r);

        // Merge the two sub-lists 
        merge(vec, l, mid, r);
    }
}

