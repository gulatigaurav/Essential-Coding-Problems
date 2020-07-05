#include <iostream>
#include <vector>
using namespace std;

class Heap
{
private:
    int left(int root);
    int right(int root);
    int parent(int child);
    void heapifyDown(int root);
    void heapifyUp(int root);

public:
    vector<int> heap;
    int size();
    void displayHeap();
    void insert(int element);
    void peek();
    void pop();
};

void Heap::pop()
{
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    heapifyDown(0);
}

void Heap::peek()
{
    cout << heap[0] << "\n";
}

void Heap::insert(int element)
{
    heap.push_back(element);
    heapifyUp(heap.size() - 1);
}

void Heap::displayHeap()
{
    for (auto i : heap)
    {
        cout << i << " ";
    }
}

int Heap::size()
{
    return heap.size();
}

void Heap::heapifyUp(int root)
{
    if (root >= 0 && parent(root) >= 0 && heap[root] < heap[parent(root)])
    {
        swap(heap[root], heap[parent(root)]);
        heapifyUp(parent(root));
    }
}

void Heap::heapifyDown(int root)
{
    int smallest = root;

    int l = left(root), r = right(root);
    if (l < heap.size() && heap[root] > heap[l])
    {
        smallest = l;
    }
    if (r < heap.size() && heap[root] > heap[r])
    {
        smallest = r;
    }
    if (smallest != root)
    {
        swap(heap[smallest], heap[root]);
        heapifyDown(smallest);
    }
}

int Heap::parent(int child)
{
    if (child == 0)
        return -1;
    int p = (child - 1) / 2;
    return p;
}

int Heap::left(int root)
{
    int l = 2 * root + 1;
    if (l < heap.size())
        return l;
    return -1;
}

int Heap::right(int root)
{
    int r = 2 * root + 2;
    if (r < heap.size())
        return r;
    return -1;
}

int main()
{
    Heap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(25);
    h.displayHeap();
    h.pop();
    cout << "\n";
    h.displayHeap();
    return 0;
}