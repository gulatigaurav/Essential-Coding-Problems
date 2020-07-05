
// Given a binary tree, we need to check it has heap property or not, Binary tree need to fulfill the following two conditions for being a heap –

// It should be a complete tree (i.e. all levels except last should be full). - V.Important
// Every node’s value should be greater than or equal to its child node (considering max-heap). - V.Important

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *NewNode(int key)
{
    Node *node = new Node();
    node->data = key;
    node->left = NULL;
    node->right = NULL;
}

int cntNumberOfNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + cntNumberOfNodes(root->left) + cntNumberOfNodes(root->right);
}

bool CheckComplete(Node *root, int index, int num)
{
    if (root == NULL)
        return true;
    if (index >= num)
        return false;
    return CheckComplete(root->left, 2 * index + 1, num) && CheckComplete(root->right, 2 * index + 2, num);
}

bool CheckHeap(Node *root)
{
    if (root == NULL)
        return true;

    if (root->left && root->data < root->left->data)
        return false;

    if (root->right && root->data < root->right->data)
        return false;

    return CheckHeap(root->left) && CheckHeap(root->right);
}

int main()
{
    struct Node *root = NULL;
    root = NewNode(10);
    root->left = NewNode(9);
    root->right = NewNode(8);
    root->left->left = NewNode(7);
    root->left->right = NewNode(6);
    root->right->left = NewNode(5);
    root->right->right = NewNode(4);
    root->left->left->left = NewNode(3);
    root->left->left->right = NewNode(2);
    root->left->right->left = NewNode(1);
    int cnt = 0;
    cnt = cntNumberOfNodes(root);

    (CheckComplete(root, 0, cnt) && CheckHeap(root)) == 1 ? cout << "Yes" : cout << "No";
}
