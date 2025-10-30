#include <utility> // swap

#include "sorting.hpp"

// ========= constructors =========
Sorting::Sorting(std::vector<int>* v) {
    this->v = v;
}

// ========= functions =========
// --------- comparison sorting ---------
// insertion sort places right element the correct location in between elements that have been already sorted
// sorting occurs from beginning element(s) to end element(s) in the vector
// r is the right most element
// l is the left most element
std::vector<int>* Sorting::insertionSort() {
    for (int r = 1; r < v->size(); r++) {
        int key = v->at(r);
        int l = r - 1; // one to the left of "r"

        // checks if lElement is larger than key
        while (l >= 0 && v->at(l) > key) {
            v->at(l + 1) = v->at(l); // move left element one to the right
            l--;
        }

        v->at(l + 1) = key; // places key at correct location of already sorted elements
    }

    return this->v;
}

// bubble sort checks adjacent two elements next to each other, and swaps them making the right element larger
// sorting occurs from end element(s) to beginning element(s)
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

    return this->v;
}

// iterates all element from the right of the sorted partition, then finds the smalles element,
// and swaps with index right of the sorted partitions
// sorting occurs from beginning element(s) to end element(s) in the vector
// cMin is current minimum
// cItem is current item
std::vector<int>* Sorting::selectionSort() {
    // need to check for edge condition, vector must be at lease 2 elements in size


    // going through all elements in array
    for (int cItem = 0; cItem < v->size() - 1; cItem++) {
        int indexMin = cItem; // original assumption -- may change

        // element in front of the first CItem
        for (int cMin = cItem + 1; cMin < v->size(); cMin++) {
            // find the minimum element, make that your base for comparing
            if (v->at(cMin) < v->at(indexMin)) {
                indexMin = cMin;
            }    
        }

        if(indexMin != cItem)
            std::swap(v->at(cItem), v->at(indexMin));
    }

    return this->v;
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

std::vector<int>* Sorting::mergeSort() {
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