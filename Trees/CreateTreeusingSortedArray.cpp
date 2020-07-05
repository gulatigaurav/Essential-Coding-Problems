#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

Node* newNode(int key) {
  Node* node = new Node;
  node->left = node->right = NULL;
  node->data = key;
  return node;
}

void printInorderTraversal(Node* root) {
  if(root == NULL)
  return;
  printInorderTraversal(root->left);
  cout<<root->data<< " ";
  printInorderTraversal(root->right);
}


void printPreorderTraversal(Node* root) {
  if(root == NULL)
    return;
  cout<<root->data<< " ";
  printInorderTraversal(root->left);
  printInorderTraversal(root->right);
}

Node* BuildTreeUsingArray(int arr[],
                        int start, int end)
{
    if (start > end)
    return NULL;
    int mid = (start + end)/2;
    Node *root = newNode(arr[mid]);
    root->left = BuildTreeUsingArray(arr, start,
                                    mid - 1);
    root->right = BuildTreeUsingArray(arr, mid + 1, end);
    return root;
}

// Node* BuildTreeUsingArray(int arr[], int left, int right) {
//   if(left > right)
//     return NULL;
//
//   int mid = (left + right)/2; // left + (right - left)/2;
//   Node* root = newNode(arr[mid]);x
//   root->left = BuildTreeUsingArray(arr, left, mid-1);
//   root->right = BuildTreeUsingArray(arr, mid+1, right);
//   return root;
// }

int main() {
    // int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = BuildTreeUsingArray(arr, 0, n - 1);
    // printInorderTraversal(root);
    cout << endl;
    printPreorderTraversal(root);
}
