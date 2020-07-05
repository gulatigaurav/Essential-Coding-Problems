#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

string longestSubstring(string s)
{
    unordered_set<int> elements;
    string out = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (elements.find(s[i]) == elements.end())
        {
            elements.insert(s[i]);
            out += s[i];
        }
    }
    return out;
}

int main()
{
    string s = "aababcda";

    string ans = longestSubstring(s);
    cout << ans;
}