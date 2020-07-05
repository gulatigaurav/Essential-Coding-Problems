#include <iostream>
#include <vector>
using namespace std;

class Heap
{
private:
    vector<int> heap;
    int left(int parent);
    int right(int parent);
    int parent(int child);
    void heapifyup(int root);
    void heapifydown(int root);
    void buildHeap(vector<int> arr, int n);

public:
    // Heap()
    // {
    // }
    void Insert(int element);
    void DeleteMin();
    int ExtractMin();
    void DisplayHeap();
    int size();
    void FindElementsLessThanK(int root, int k);
};

int Heap::size()
{
    return heap.size();
}
void Heap::Insert(int element)
{
    heap.push_back(element);
    heapifyup(heap.size() - 1);
}

int Heap::ExtractMin()
{
    if (heap.size() >= 1)
        return heap[0];
    return -1;
}

void Heap::DeleteMin()
{

    if (heap.size() == 0)
        return;

    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    heapifydown(0); // since 0 is the new root
}

// Heap Methods

void Heap::DisplayHeap()
{
    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }
}

int Heap::left(int parent)
{
    int l = 2 * parent + 1;
    if (l < heap.size())
    {
        return l;
    }
    return -1;
}

int Heap::right(int parent)
{
    int r = 2 * parent + 2;
    if (r < heap.size())
        return r;
    return -1;
}

int Heap::parent(int child)
{
    int parent = (child - 1) / 2;
    if (child == 0)
    {
        return -1;
    }
    return parent;
}

void Heap::heapifydown(int root)
{
    int l = left(root);
    int r = right(root);
    int smallest = root;
    if (l < heap.size() && heap[l] < heap[smallest])
    {
        smallest = l;
    }

    if (r < heap.size() && heap[r] < heap[smallest])
    {
        smallest = r;
    }
    if (smallest != root)
    {
        swap(heap[smallest], heap[root]);
        heapifydown(smallest);
    }
}

void Heap::heapifyup(int root)
{
    if (root >= 0 && (parent(root) >= 0) && heap[parent(root)] > heap[root])
    {
        swap(heap[parent(root)], heap[root]);
        heapifyup(parent(root));
    }
}

void Heap::FindElementsLessThanK(int root, int k)
{
    if (heap[root] >= k) //
    {
        return;
    }
    cout << heap[root] << " ";
    FindElementsLessThanK(left(root), k);
    FindElementsLessThanK(right(root), k);
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
    int root = h.ExtractMin();
    h.DisplayHeap();
    cout << endl;
    cout << "Root: " << root << endl;

    h.FindElementsLessThanK(0, 11);

    // cout << "Hello World";
}