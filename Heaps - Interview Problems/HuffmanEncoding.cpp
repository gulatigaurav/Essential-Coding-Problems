#include <iostream>
#include <queue>
using namespace std;

struct minHeapNode
{

    char data;
    int frequency;
    struct minHeapNode *left, *right;
    minHeapNode(char data, int frequency)
    {
        left = NULL;
        right = NULL;
        this->data = data;
        this->frequency = frequency;
    }
};

struct compare
{
    bool operator()(minHeapNode *l, minHeapNode *r)
    {
        return (l->left > r->right);
    }
};

void printCodes(struct minHeapNode *root, string s)
{
    if (!root)
    {
        return;
    }
    if (root->data != '$')
    {
        cout << root->data << ": " << s << "\n";
    }
    printCodes(root->left, s + "0");
    printCodes(root->right, s + "1");
}

void HuffmanCodes(char arr[], int freq[], int size)
{
    struct minHeapNode *left, *right, *top;
    priority_queue<minHeapNode *, vector<minHeapNode *>, compare> minHeap;
    for (int i = 0; i < size; i++)
    {
        minHeap.push(new minHeapNode(arr[i], freq[i]));
    }

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        top = new minHeapNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}