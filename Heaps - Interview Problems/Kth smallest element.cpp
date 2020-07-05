#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    //code
    int test;
    cin >> test;

    while (test--)
    {
        int size;
        cin >> size;

        vector<int> arr;

        for (int i = 0; i < size; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }

        int k;
        cin >> k;
        priority_queue<int> pq; //max heap

        for (int i = 0; i < size; i++)
        {
            pq.push(arr[i]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        cout << pq.top() << endl;
    }

    return 0;
}