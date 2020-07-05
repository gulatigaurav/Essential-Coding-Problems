#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> createTemporaryArray(vector<char> str)
{
    vector<int> arr(str.size());
    int j = 0;
    for (int i = 1; i < str.size();)
    {
        if (str[i] == str[j])
        {
            arr[j] = 0;
            i++;
            j++;
            // i++ - i is automatically incremented
            // continue;
        }
        else
        {
            if (j != 0)
            {
                j = arr[j - 1];
            }
            else
            {
                arr[i] = 0;
                i++;
            }
        }
    }

    for (auto i : arr)
    {
        cout << i << " ";
    }
}

bool KMP(vector<char> &s, vector<char> &substring)
{
}

int main()
{
    string s = "abcxabcdabcdabcy";
    string subString = "abcdabca";
    vector<char> v(s.begin(), s.end());
    vector<char> v2(subString.begin(), subString.end());

    createTemporaryArray(v2);
    // bool result = KMP(v, v2);
    // cout << result << endl;
}