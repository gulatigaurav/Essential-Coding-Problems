#include <iostream>
#include <vector>
#include <string>
using namespace std;

void reverseArray(string &s, int i, int j)
{
    /*  
        Recursive Approach        
    */
    if (i >= j)
        return;
    else
    {
        swap(s[i], s[j]);
        i++;
        j--;
        reverseArray(s, i, j);
    }
}

int main()
{
    string s = "Hello World";
    cout << s << "\n";
    int i = 0;
    int j = s.length() - 1;

    reverseArray(s, i, j);
    // while (i < j)
    // {
    //     // s[i] = tolower(s[i]);
    //     // s[j] = tolower(s[j]);
    //     swap(s[i], s[j]);
    //     i++;
    //     j--;
    // }
    cout << s << "\n";
    return 0;
}
