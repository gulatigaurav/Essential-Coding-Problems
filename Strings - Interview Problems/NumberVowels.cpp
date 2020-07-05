#include <iostream>
#include <string>
using namespace std;

void numberVowels(string s)
{
    int cnt = 0;
    int ccnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            cnt++;
        }
        else if ((int)s[i] >= 97 && (int)s[i] <= 122)
        {
            ccnt++;
        }
    }
    cout << cnt << " " << ccnt << " ";
}

int main()
{
    string s = "26a";
    numberVowels(s);
    // cout << ans << ", " << s.length() - ans;
}