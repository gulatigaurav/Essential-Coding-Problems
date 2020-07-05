#include <iostream>
#include <queue>
#include <stack>
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

void ZigZagTraversalTree(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> pq;
    stack<Node *> st;
    int level = 0;
    Node *temp = NULL, *temp2 = NULL;

    pq.push(root);

    while (!pq.empty())
    {
        int n = pq.size();
        for (int i = 0; i < n; i++)
        {
            temp = pq.front();
            if (level % 2 == 0)
                cout << temp->data << "  ";
            else
            {
                temp2 = st.top();
                cout << temp2->data << " ";
            }
            // level % 2 == 0 ? cout << temp->data << " " : cout << st.top()->data << " ";
            if (temp->left)
            {
                pq.push(temp->left);
                if (level % 2 == 0)
                    st.push(temp->left);
            }
            if (temp->right)
            {
                pq.push(temp->right);
                if (level % 2 == 0)
                    st.push(temp->right);
            }
            pq.pop();
            if (level % 2 == 1)
                st.pop();
        }
        level += 1;
        cout << "\n";
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
    root->left->left->left = NewNode(9);
    root->left->left->right = NewNode(11);
    int x = 2;
    ZigZagTraversalTree(root);
    // int sum = calculateSumofParentNodes(root, x);
    // cout << sum << "\n";
}

// queue 4 , 2, 5   || 2, 5
// stack 2, 5 || 2, 5 ||
// 5