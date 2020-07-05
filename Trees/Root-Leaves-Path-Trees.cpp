// Time Complexity - O(N), Space Complexity - O(N)

#include <iostream>
#include <vector>
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
    return node;
}

void printArray(int path[], int pathLen)
{
    for (int i = 0; i < pathLen; i++)
    {
        cout << path[i] << " ";
    }
}

void RootLeavesPath(Node *root, int path[], int pathLen)
{
    if (root == NULL)
    {
        return;
    }

    path[pathLen] = root->data;
    pathLen += 1;

    if (root->left == NULL && root->right == NULL)
    {
        // Leaf Node
        printArray(path, pathLen);
        cout << endl;
    }

    else
    {
        RootLeavesPath(root->left, path, pathLen);
        RootLeavesPath(root->right, path, pathLen);
    }
}

int main()
{
    Node *root = NewNode(10);
    root->left = NewNode(8);
    root->right = NewNode(2);
    root->left->left = NewNode(3);
    root->left->right = NewNode(5);
    root->right->left = NewNode(2);

    int path[1000];
    RootLeavesPath(root, path, 0);
}