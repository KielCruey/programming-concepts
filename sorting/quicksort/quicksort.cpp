#include <algorithm> // swap

#include "pch.h"
#include "quicksort.hpp"

void Quicksort::quicksort(int* a, int lowIndex, int highIndex) {
    if (lowIndex < highIndex) {
        int pivotIndex = partition(a, lowIndex, highIndex);

        // recursive part
        quicksort(a, lowIndex, pivotIndex - 1); // low side 
        quicksort(a, pivotIndex + 1, highIndex); // high side
    }
}

int Quicksort::partition(int* a, int lowIndex, int highIndex) {
    int pivot = a[highIndex]; // last element is pivot
    int i = lowIndex - 1;

    for (int j = lowIndex; j < highIndex; j++) {
        if (a[j] < pivot) {
            i++;
            std::swap(a[i], a[j]);
        }
    }

    std::swap(a[i + 1], a[highIndex]);
    return i + 1;
}