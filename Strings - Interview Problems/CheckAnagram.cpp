#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool checkAnagram(string s, string s1)
{
    // sort(s.begin(), s.end());   //O(nlogn)
    // sort(s1.begin(), s1.end()); //O(nlogn)

    int arr[256] = {};

    for (int i = 0; i < s.length(); i++)
    {
        arr[(int)s[i]] += 1;
    }

    for (int i = 0; i < s1.length(); i++)
    {
        arr[(int)s1[i]] -= 1;
    }

    for (int i = 0; i < 256; i++)
    {
        if (arr[i] != 0)
        {
            return false;
        }
    }

    return true;
    // return s == s1;
}

int main()
{
    string s = "alpha";
    string s1 = "lasdp";

    if (s.length() != s1.length())
    {
        return false;
    }

    bool check = checkAnagram(s, s1);

    cout << check << "\n";
    return 0;
}
