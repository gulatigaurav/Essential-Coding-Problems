#include <iostream>
#include <string>
using namespace std;

bool hasDigitsOnly(string s)
{
    cout << s << "\n";
    for (int i = 0; i < s.length(); i++)
    {
        // cout << s[i] << " " << (int)s[i] << "\n";
        if ((int)s[i] <= 48 || (int)s[i] >= 57)
        {
            return false;
        }
    }
    return true;
    // cout << endl;
}

int main()
{
    string s = "26";
    bool ans = hasDigitsOnly(s);
    cout << ans;
}