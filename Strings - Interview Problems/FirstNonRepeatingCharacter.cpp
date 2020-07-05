#include <iostream>
#include <string>
using namespace std;

void firstNonRepeatingCharacter(string s)
{
    int arr[26] = {};

    for (int i = 0; i < s.length(); i++)
    {
        arr[(s[i] - 'a')] += 1;
    }
    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }

    int ans = -1;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == 1)
        {
            ans = i + (int)'a';
            break;
        }
    }
    if (ans != -1)
        cout << (char)ans << endl;
    else
    {
        cout << -1 << endl;
    }
}

int main()
{
    string s = "abcadedfhs";
    // cout << (char)'a' << " ";
    firstNonRepeatingCharacter(s);
    // cout << ans << ", " << s.length() - ans;
}