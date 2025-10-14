#include <vector>

class InsertionSort
{
public:
    InsertionSort(std::vector<int>* v = nullptr);

    std::vector<int>* insertionSort();

    void setVector(std::vector<int>* v);
    std::vector<int>* getVector();

private:
    std::vector<int>* v;
};