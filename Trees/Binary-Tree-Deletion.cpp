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

void printTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "  ";
    printTree(root->left);
    printTree(root->right);
}

void DeleteNode(Node *root, int x)
{
    if (root == NULL)
    {
        return;
    }
    // Step1- find the node that is to be deleted and the one at the end
    // Assuming there are unique nodes
    Node *temp, *current = NULL;
    queue<Node *> pq;
    pq.push(root);

    while (!pq.empty())
    {
        temp = pq.front();
        pq.pop();
        if (temp->data == x)
        {
            current = temp;
        }
        if (temp->left)
            pq.push(temp->left);
        if (temp->right)
            pq.push(temp->right);
    }

    if (current != NULL)
    {
        cout << temp->data << " " << current->data << endl;
        swap(temp->data, current->data);
        temp = NULL;
        // delete temp;
        // free(temp);
        printTree(root);
    }
}

int main()
{
    Node *root = NewNode(10);
    root->left = NewNode(11);
    root->left->left = NewNode(7);
    root->left->right = NewNode(12);
    root->right = NewNode(9);
    root->right->left = NewNode(15);
    root->right->right = NewNode(8);
    printTree(root);
    cout << endl;
    DeleteNode(root, 7);
}