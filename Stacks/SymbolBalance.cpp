/*
Check Balanced Symbols using inbuilt Stack
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool checkBalanced(string s)
{
    stack<int> st;
    for (int i : s)
    {
        if (i == '(' || i == '{' || i == '[')
        {
            st.push(i);
        }

        else if (i == ')' || i == '}' || i == ']')
        {
            if (st.empty())
                return false;

            int element = st.top();
            st.pop();
            if (element == '(' && i != ')')
                return false;
            if (element == '[' && i != ']')
                return false;
            if (element == '{' && i != '}')
                return false;
        }
    }

    if (st.size() != 0)
    {
        return false;
    }

    return true;
}

int main()
{
    string s = "[(A+B) - [C+D]]";
    bool ans = checkBalanced(s);
    cout << ans << " ";
}