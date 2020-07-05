#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, char> t;
// O(nlogk) solution
int main()
{
    string s = "ABCDBAGHCHFAC";
    int k = 3;
    // map<int, int> freq;
    int arr[26] = {};
    for (char i : s)
    {
        arr[i - 65] += 1;
    }

    priority_queue<t, vector<t>, greater<t>> pq; // Min Heap

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == 1)
        {
            if (pq.size() < k)
                pq.push(make_pair(arr[i], (char)i + 65));
            else
            {
                // compare index of next coming element
                if (i < pq.top().first)
                {
                    pq.pop();
                    pq.push(make_pair(arr[i], (char)i + 65));
                }
            }
        }
    }

    while (!pq.empty())
    {
        cout << pq.top().second << " ";
        pq.pop();
    }
}