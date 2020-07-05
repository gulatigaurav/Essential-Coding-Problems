#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkOperator(char i)
{
    if (i == '/' || i == '*' || i == '+' || i == '-')
    {
        return true;
    }
    return false;
}

bool checkHigherPrecedence(char i, char j)
{
    if (i == '/')
        return true;
    if (i == '*' && j != '/')
        return true;
    if (i == '+' && (j != '*' || j != '/'))
        return true;
    return false;
}

void convertToPostfix(string s)
{
    stack<char> st;
    string out = "";
    for (char i : s)
    {
        if (checkOperator(i))
        {
            while (!st.empty() && checkHigherPrecedence(st.top(), i))
            {
                out += st.top();
                st.pop();
            }
            st.push(i);
        }
        else
        {
            out += i;
        }
    }

    while (!st.empty())
    {
        out += st.top();
        st.pop();
    }

    cout << "Out " << out << " ";
}

int main()
{
    string s = "A+B*C-D";

    convertToPostfix(s);

    return 0;
}