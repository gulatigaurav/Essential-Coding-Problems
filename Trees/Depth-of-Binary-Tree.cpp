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

int findDepth(Node *root)
{
    queue<Node *> pq;
    if (root == NULL)
    {
        return 0;
    }
    int level = 0;
    pq.push(root);
    Node *temp = NULL;
    while (!pq.empty())
    {
        temp = pq.front();

        int n = pq.size();

        for (int i = 0; i < n; i++)
        {
            if (temp->left)
            {
                pq.push(temp->left);
            }
            if (temp->right)
            {
                pq.push(temp->right);
            }
            pq.pop();
        }
        level += 1;
    }
    return level;
}

int main()
{
    Node *a = NewNode(1);
    Node *b = NewNode(1);
    a->left = NewNode(2);
    a->right = NewNode(3);
    a->left->left = NewNode(4);
    a->left->right = NewNode(5);

    int ans = findDepth(a);
    cout << ans << " ";
}