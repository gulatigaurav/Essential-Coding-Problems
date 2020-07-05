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
    return node;
}

bool CheckMirror(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    return (root1->data == root2->data && CheckMirror(root1->left, root2->right) && CheckMirror(root1->right, root2->left));
}

int main()
{
    Node *a = NewNode(1);
    Node *b = NewNode(1);
    a->left = NewNode(2);
    a->right = NewNode(3);
    a->left->left = NewNode(4);
    a->left->right = NewNode(5);

    b->left = NewNode(3);
    b->right = NewNode(2);
    b->right->left = NewNode(5);
    b->right->right = NewNode(4);

    CheckMirror(a, b) ? cout << "Yes" : cout << "No";
}