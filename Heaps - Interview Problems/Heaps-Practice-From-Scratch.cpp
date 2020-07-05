#include <iostream>
#include <vector>
using namespace std;

class Heap
{
private:
    vector<int> heap;
    int left(int root);
    int right(int root);
    int parent(int child);
    void heapifyDown(int root);
    void heapifyUp(int element);
    void buildHeap(vector<int> heap);

public:
    int extractMax();
    void Insert(int element);
    void RemoveTop();
    int size();
    void DisplayHeap();
};

void Heap::DisplayHeap()
{
    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }
}

int Heap::extractMax()
{
    return heap[0];
}

void Heap::Insert(int element)
{
    heap.push_back(element);
    heapifyUp(element);
}

void Heap::RemoveTop()
{
    swap(heap[0], heap[heap.size() - 1]);
    heapifyUp(heap.size() - 1);
}

int Heap::size()
{
    return heap.size();
}

void Heap::buildHeap(vector<int> heap)
{
    int n = heap.size();
    for (int i = n / 2; i >= 0; i--)
    {
        heapifyDown(i);
    }
}

void Heap::heapifyUp(int element)
{
    int p = parent(element);
    if (heap[element] > heap[p] && element >= 0 && p >= 0)
    {
        swap(heap[element], heap[p]);
        heapifyUp(p);
    }
}

void Heap::heapifyDown(int root)
{
    int l = left(root);
    int r = right(root);

    int largest = root;

    if (heap[largest] < heap[l] && l < heap.size())
    {
        largest = l;
    }

    if (heap[largest] < heap[r] && r < heap.size())
    {
        largest = r;
    }

    if (heap[largest] != root)
    {
        swap(heap[largest], heap[root]);
        heapifyDown(largest);
    }
}

int Heap::parent(int child)
{
    if (child <= heap.size() && child > 0)
        return (child - 1) / 2;
    return -1;
}

int Heap::left(int root)
{
    int left = 2 * root + 1;
    if (left <= heap.size())
        return left;
    return -1;
}

int Heap::right(int root)
{
    int right = 2 * root + 2;
    if (right <= heap.size())
        return right;
    return -1;
}

int main()
{
    Heap h;

    h.Insert(10);
    h.Insert(20);
    h.Insert(5);
    h.Insert(25);
    h.Insert(30);
    h.Insert(2);
    // h.DeleteMin();
    int root = h.extractMax();
    h.DisplayHeap();
    cout << endl;
    cout << "Root: " << root << endl;
}