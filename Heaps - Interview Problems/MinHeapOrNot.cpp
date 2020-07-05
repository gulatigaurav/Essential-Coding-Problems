#include <iostream>
using namespace std;

bool checkMinHeap(int arr[], int root, int n)
{
    if (2 * root + 2 > n) // confirmed leaf node
    {
        return true;
    }
    int left = 2 * root + 1;
    int right = 2 * root + 2;
    if ((left < n && arr[left] <= arr[root]) || (right <= n && arr[right] <= arr[root]))
    {
        return true;
    }
    bool ans = checkMinHeap(arr, left, n);
    bool ans2 = checkMinHeap(arr, right, n);
    return ans && ans2;
}

int main()
{
    int arr[6] = {1, 4, 6, 5, 7, 3};
    int n = 6;
    bool ans = checkMinHeap(arr, 0, n);
    cout << ans << " ";
}
// 1 4 6 5