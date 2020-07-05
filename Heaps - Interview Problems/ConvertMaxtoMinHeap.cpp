#include <iostream>
#include <vector>
using namespace std;

class Heap
{
private:
    void HeapifyDown(int root)
    {
        int left = 2 * root + 1;
        int right = 2 * root + 1;
        if (left >= heap.size())
            left = -1;
        if (right >= heap.size())
            right = -1;

        int smallest = root;
        if (left != -1 && left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right != -1 && right < heap.size() && heap[right] < heap[smallest])
            smallest = left;
        if (smallest != root)
        {
            swap(heap[smallest], heap[root]);
            HeapifyDown(smallest);
        }
    }

    void HeapifyUp(int root)
    {
        if (root < heap.size() && root != -1)
        {
            int parent;
            if (root == 0)
                parent = -1;
            parent = (root - 1) / 2;

            if (heap[parent] > heap[root])
            {
                swap(heap[parent], heap[root]);
                HeapifyUp(parent);
            }
        }
    }

public:
    vector<int> heap;
    void BuildHeap()
    {
        int n = heap.size();
        for (int i = n / 2; i >= 0; i--)
        {
            HeapifyDown(i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            swap(heap[0], heap[i]);

            // Heapify root element to get highest element at root again
            HeapifyDown(0);
        }
    }
    void insert(int element)
    {
        heap.push_back(element);
        HeapifyUp(heap.size() - 1);
    }
    void displayHeap()
    {
        for (int i : heap)
        {
            cout << i << " ";
        }
    }
    void top()
    {
        cout << heap[0] << " ";
    }
};

int main()
{
    const int n = 5;
    int heap[n] = {5, 4, 3, 2, 1};
    Heap h;
    for (int i : heap)
    {
        h.heap.push_back(i);
    }
    h.displayHeap();
}

//       1
//    2       4
//5      3