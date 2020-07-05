#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *NewNode(int key)
{
    Node *node = new Node();
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int calculateSumofParentNodes(Node *root, int x)
{
    int cnt = 0;
    if (root == NULL)
        return 0;
    if (root->left != NULL && root->left->data == x)
        cnt += root->data;
    if (root->right != NULL && root->right->data == x)
        cnt += root->data;
    return cnt + calculateSumofParentNodes(root->left, x) + calculateSumofParentNodes(root->right, x);
}

int main()
{
    Node *root = NewNode(4);        /*        4        */
    root->left = NewNode(2);        /*       / \       */
    root->right = NewNode(5);       /*      2   5      */
    root->left->left = NewNode(7);  /*     / \ / \     */
    root->left->right = NewNode(2); /*    7  2 2  3    */
    root->right->left = NewNode(2);
    root->right->right = NewNode(3);
    int x = 2;
    int sum = calculateSumofParentNodes(root, x);
    cout << sum << "\n";
}