#include <iostream>
#include <algorithm>
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

int calculateHeight(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int h = 0;
    int l = calculateHeight(root->left);
    int r = calculateHeight(root->right);
    h = max(l, r) + 1;
    return h;
}

int main()
{
    Node *root = NewNode(4);        /*        4        */
    root->left = NewNode(2);        /*       / \       */
    root->right = NewNode(5);       /*      2   5      */
    root->left->left = NewNode(7);  /*     / \ / \     */
    root->left->right = NewNode(2); /*    7  2 2  3
                                    /*             \    */
                                    /*              6   */
    root->right->left = NewNode(2);
    root->right->right = NewNode(3);
    root->right->right->right = NewNode(6);
    int x = 2;
    int h = calculateHeight(root);
    cout << h << "\n";
}