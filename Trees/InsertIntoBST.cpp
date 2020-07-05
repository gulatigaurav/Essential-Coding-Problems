// This is an iterative approach, An alternative approach is to use Recursion
// But this would be take an extra O(n) for recursive stack
// Whereas Iterative approach would take constant(O(1)) space

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *right, *left;
};

Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void InOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

Node *Insert(Node *root, int key)
{

    if (root == NULL)
    {
        return newNode(key);
    }

    else
    {
        if (root->data < key)
        {
            root->right = Insert(root->right, key);
        }
        else if (root->data > key)
        {
            root->left = Insert(root->left, key);
        }
    }

    return root;
}

// void Insert(Node *&root, int key)
// {
//     while (1)
//     {
//         if (root == NULL)
//         {
//             root = newNode(key);
//             return;
//         }
//         else if (root->data < key)
//         {
//             root = root->right;
//         }
//         else if (root->data > key)
//         {
//             root = root->left;
//         }
//         else
//         {
//             // Element already exists
//             throw "Element already exists";
//         }
//     }
// }

int main()
{
    Node *root = NULL;
    root = Insert(root, 10);
    Insert(root, 20);
    cout << root->data << " ";
    // InOrderTraversal(root);
}