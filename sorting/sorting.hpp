#include <vector>

class Sorting
{
public:
    Sorting(std::vector<int>* v = nullptr);

    // comparison based sorting
    std::vector<int>* insertionSort();
    std::vector<int>* bubbleSort();
    std::vector<int>* selectionSort();
    std::vector<int>* minHeapSort();
    std::vector<int>* maxHeapSort();
    std::vector<int>* quickSort();
    std::vector<int>* shellSort();

    // non-comparison based sorting
    std::vector<int>* countingSort();
    std::vector<int>* radixSort();
    std::vector<int>* bucketSort();

    void setVector(std::vector<int>* v);
    std::vector<int>* getVector();

private:
    std::vector<int>* v;
};