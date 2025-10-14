#include "sorting.hpp"

// ========= constructors =========
Sorting::Sorting(std::vector<int>* v) {
    this->v = v;
}

// ========= functions =========
// --------- comparison sorting ---------
// rElement is the right most pointer
// lElement is the left most pointer
std::vector<int>* Sorting::insertionSort() {
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

std::vector<int> *Sorting::bubbleSort() {
    return nullptr;
}

std::vector<int> *Sorting::selectionSort() {
    return nullptr;
}

std::vector<int> *Sorting::minHeapSort() {
    return nullptr;
}

std::vector<int> *Sorting::maxHeapSort() {
    return nullptr;
}

std::vector<int> *Sorting::quickSort() {
    return nullptr;
}

// --------- non-comparison sorting ---------
std::vector<int> *Sorting::countingSort() {
    return nullptr;
}

std::vector<int> *Sorting::radixSort() {
    return nullptr;
}

std::vector<int> *Sorting::bucketSort() {
    return nullptr;
}

// ========= getters/setters =========
void Sorting::setVector(std::vector<int>* v) {
    this->v = v;
}

std::vector<int>* Sorting::getVector() {
    return this->v;
}