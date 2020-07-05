#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int key)
{
    Node *node = new Node();
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    return node;
};

bool checkSum(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> pq;

    pq.push(root);

    int index = -1, maxSum = 0, level = 0;
    vector<int> sumLevel;
    while (!pq.empty())
    {
        int sum = 0;
        // temp = pq.front();
        int n = pq.size();
        for (int i = 0; i < n; i++)
        {

            Node *temp = pq.front();
            sum += temp->data;
            if (temp->left != NULL)
            {
                pq.push(temp->left);
            }
            if (temp->right != NULL)
            {
                pq.push(temp->right);
            }
            pq.pop();
        }

        sumLevel.push_back(sum);
        if (sum > maxSum)
        {
            maxSum = sum;
            index = level;
        }
        level += 1;
    }

    for (int i : sumLevel)
    {
        cout << i << " ";
    }

    int sumbefore = 0;
    int sumafter = 0;
    int total = 0;
    for (int i : sumLevel)
    {
        total += i;
    }

    int leftSum = 0;
    for (int i = 0; i < index; i++)
    {
        leftSum += sumLevel[i];
    }

    return (leftSum == (total - leftSum - sumLevel[index]));
}

int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left = newNode(2);
    root->right->right->right = newNode(4);
    cout << checkSum(root);
}