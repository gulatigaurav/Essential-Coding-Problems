#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int longestSubstring(string s)
{
    // "abcdefghiaaac", "abcabcbb", "pwwkew"

    int i = 0;
    int j = 0;
    int n = s.length();

    set<int> elements;
    int len = 0;
    for (int i = 0; i < n;)
    {

        if (elements.find(s[i]) != elements.end())
        {
            elements.erase(s[i]);
            // elements.insert(s[i]);
            i++;
        }
        else
        {
            elements.insert(s[i]);
            len = elements.size() > len ? elements.size() : len;
            i++;
        }
    }
    return len;
}

int main()
{
    string s = "abcabcbb";

    int ans = longestSubstring(s);
    cout << ans;
}