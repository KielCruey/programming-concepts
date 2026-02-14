#pragma once

class Quicksort {
public:
    void quicksort(int* a, int lowIndex, int highIndex);
    int partition(int* a, int lowIndex, int highIndex); // uses pivot to sort elements
};
