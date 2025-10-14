#include "insertion-sort.hpp"

// ========= constructors =========
InsertionSort::InsertionSort(std::vector<int>* v) {
    this->v = v;
}

// ========= functions =========
// rElement is the right most pointer
// lElement is the left most pointer
std::vector<int>* InsertionSort::insertionSort() {
    for(int rElement = 1; rElement < v->size(); rElement++) {
        int key = v->at(rElement);
        int lElement = rElement - 1;

        while(lElement >= 0 && v->at(lElement) > key) {
            v->at(lElement + 1) = v->at(lElement);
            lElement--; 
        }

        v->at(lElement + 1) = key;
    }
    
    return v;
}

// ========= getters/setters =========
void InsertionSort::setVector(std::vector<int>* v) {
    this->v = v;
}

std::vector<int>* InsertionSort::getVector() {
    return this->v;
}