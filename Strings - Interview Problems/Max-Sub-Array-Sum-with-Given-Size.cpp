#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int maxSumSubArray(const vector<int> &arr, int k)
{

    if (k > arr.size())
    {
        return -1;
    }

    int i = 0, j = 0;

    int runningSum = 0;
    int maxSum = -10000;
    for (i = 0; i < k; i++)
    {
        runningSum += arr[i];
        maxSum = runningSum;
    }

    // i+=1;optional statement, but if we use this we will have to use the conditon in comments in option 24
    j = k;
    while (j < arr.size())
    {
        // cout << i << " " << j << " " << runningSum << " " << endl;
        runningSum += (arr[j] - arr[i - k]); //  runningSum += (arr[j] - arr[j - k]); This is also correct
        maxSum = max(runningSum, maxSum);
        j++;
        i++;
    }
    return maxSum;
}

int main()
{
    // vector<int> arr = {-1, 2, 3, 1, -3, 2};
    vector<int> arr = {2, 3};
    int k = 2;
    int sum = maxSumSubArray(arr, k);
    cout << sum << endl;
}