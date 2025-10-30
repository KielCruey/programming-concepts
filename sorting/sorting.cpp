#include <utility> // swap
#include <stdexcept> //invalid_argument 

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

// Recursive function for sorting the array
std::vector<int>* Sorting::mergeSort(int l, int r){
    // error checking
    if (l < 0)
        throw std::invalid_argument("MergeSort -- L received negative value");

    if (l > (int)getVector()->size())
        throw std::invalid_argument("MergeSort -- L greater than vector's max size");

    if(r < 0)
        throw std::invalid_argument("MergeSort -- R received negative value");

    if(r > (int)getVector()->size())
        throw std::invalid_argument("MergeSort -- R greater than vector's max size");

    // Merge until we are left with a single element
    if (l < r) {
        // Calculate mid-point of vector
        int mid = (l + r) / 2;

        // Sort the sub-vectors
        mergeSort(l, mid);
        mergeSort(mid + 1, r);

        // Merge the two sub-lists 
        merge(l, mid, r);
    }

    return v;
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

// ========= PRIVATE FUNCTIONS =========
// Merges to sorted sub-lists
void Sorting::merge(int start, int middle, int end) {
    // Initialize left-hand elements
    int elements_left = middle - start + 1;
    std::vector<int> tmp_left;

    // Initialize right-hand elements
    int elements_right = end - middle;
    std::vector<int> tmp_right;

    for (int i = 0; i < elements_left; i++)
        tmp_left.push_back(this->v->at(start + i));

    for (int i = 0; i < elements_right; i++)
        tmp_right.push_back(this->v->at(middle + 1 + i));

    // Compare vectors and add elements to the final result
    int i = 0;
    int j = 0;
    int pos = start;

    while ((i < tmp_left.size()) && (j < tmp_right.size())) {
        // Add left-hand element if it's smaller
        // Otherwise add right-hand element 
        if (tmp_left[i] <= tmp_right[j]) {
            this->v->at(pos) = tmp_left[i];
            i++;
        }
        else {
            this->v->at(pos) = tmp_right[j];
            j++;
        }

        // Increment position in final vector
        pos++;
    }

    // Clean up remaining left-hand elements
    while (i < tmp_left.size()) {
        this->v->at(pos) = tmp_left[i];
        i++;
        pos++;
    }

    // Clean up remaining right-hand elements
    while (j < tmp_right.size()) {
        this->v->at(pos) = tmp_right[j];
        j++;
        pos++;
    }
}