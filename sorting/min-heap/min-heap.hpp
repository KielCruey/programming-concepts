#include <vector>
class HEAP
{
public:
    HEAP(int capacity = NULL, int size = NULL, int* H = nullptr) :
        capacity(capacity), size(size), H(H)
    { }

    void Heapify(HEAP* h, int index);
    void BuildHeap(HEAP* h, int size);
    void Heapsort(HEAP* h, int size);
    int ExtractMin(HEAP* h);
    void DecreaseKey(HEAP* h, int index, int newKey);
    HEAP* Insertion(HEAP *v, int size, int newElement);

    // ======== getters/setters ========
    int getParentNode(HEAP* h, int currentIndex);
    int getLeftChild(HEAP* h, int currentIndex);
    int getRightChild(HEAP* h, int currentIndex);
    int getMinimum(HEAP* h);

private:

    int capacity; // capacity of the heap
    int size; // current size of the heap
    int* H; // array of indices to the ELEMENT array
};

