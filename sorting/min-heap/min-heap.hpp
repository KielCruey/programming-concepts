#include <vector>
class Heap
{
public:
    Heap(int capacity = NULL, int size = NULL, int* H = nullptr);

    void Heapify(Heap* h, int index);
    void BuildHeap(Heap* h, int size);
    void Heapsort(Heap* h, int size);
    int ExtractMin(Heap* h);
    void DecreaseKey(Heap* h, int index, int newKey);
    Heap* Insertion(Heap *v, int size, int newElement);

    // ======== getters/setters ========
    int getParentNode(Heap* h, int currentIndex);
    int getLeftChild(Heap* h, int currentIndex);
    int getRightChild(Heap* h, int currentIndex);
    int getMinimum(Heap* h);

private:
    int capacity; // capacity of the Heap
    int size; // current size of the Heap
    int* H; // array of indices to the ELEMENT array
};

