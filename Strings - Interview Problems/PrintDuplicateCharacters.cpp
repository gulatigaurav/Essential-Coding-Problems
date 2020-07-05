#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{

    // Hello World
    // l - 3, o - 2

    string s = "Programming";

    map<char, int> freq;

    for (char i : s)
    {
        freq[i]++;
        // cout << i << " ";
    }

    for (auto i : freq)
    {
        if (i.second > 1)
        {
            cout << i.first << " ";
        }
    }

    return 0;
}
