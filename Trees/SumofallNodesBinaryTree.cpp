// We take the sum using level order traversal
// Recursive function to calculate the sum
// O(N) TC  O(N) SC
// O(N) TC O(N) SC
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int key)
{
    Node *node = new Node();
    // Node node;
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int RecursiveSum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->data + RecursiveSum(root->left) + RecursiveSum(root->right);
}

int calculateSum(Node *root)
{
    int sum = 0;
    Node *temp;
    if (root == NULL)
    {
        return 0;
    }
    queue<Node *> pq; // queue doesn't have top, only priority queue has
    pq.push(root);
    while (!pq.empty())
    {
        temp = pq.front();
        sum += temp->data;
        pq.pop();
        if (temp->left)
        {
            pq.push(temp->left);
        }
        if (temp->right)
        {
            pq.push(temp->right);
        }
    }
    return sum;
}

int main()
{
    Node *root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(9);
    // ? cout << root->data;
    int sum = calculateSum(root);
    int recursiveSum = RecursiveSum(root);
    cout << sum << " " << recursiveSum << "\n";
}