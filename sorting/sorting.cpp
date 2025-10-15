#include "sorting.hpp"

// ========= constructors =========
Sorting::Sorting(std::vector<int>* v) {
    this->v = v;
}

// ========= functions =========
// --------- comparison sorting ---------
// r is the right most element
// l is the left most element
std::vector<int>* Sorting::insertionSort() {
    for(int r = 1; r < v->size(); r++) {
        int key = v->at(r);
        int l = r - 1;

        // checks if lElement is larger than key
        while(l >= 0 && v->at(l) > key) {
            v->at(l + 1) = v->at(l);
            l--; 
        }

        v->at(l + 1) = key;
    }
    
    return v;
}

// e is every element
// a is adjacent elements
std::vector<int> *Sorting::bubbleSort() {
    // every element in the vector
    for(int e = 0; e < v->size() - 1; e++) {
        // compares adjacent elements
        for(int a = 0; a < v->size() - e - 1; a++) {
            // checks if lElement is larger than rElement
            if(v->at(a) > v->at(a + 1)) {
                int temp = v->at(a);
                v->at(a) = v->at(a + 1);
                v->at(a + 1) = temp;
            }
        }
    }

    return v;
}

// cMin is current minimum
// cItem is current item
std::vector<int> *Sorting::selectionSort() {
    int cMin, cItem, min;

    for(cMin = 0; cMin < v->size() - 1; cMin++)

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

std::vector<int>* Sorting::shellSort() {
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