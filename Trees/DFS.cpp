#include <iostream>
#include <queue>
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

void BFSTraversal(Node *root)
{
    //Level Order Traversal
    queue<Node *> pq;
    if (root == NULL)
    {
        return;
    }
    pq.push(root);
    Node *temp;
    while (!pq.empty())
    {
        temp = pq.front();
        cout << temp->data << " ";
        pq.pop();
        if (temp->left != NULL)
            pq.push(temp->left);
        if (temp->right != NULL)
            pq.push(temp->right);
    }
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
    BFSTraversal(root);
}