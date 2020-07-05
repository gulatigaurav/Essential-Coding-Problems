#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluate(string s)
{
    stack<int> st;

    for (char i : s)
    {
        if (i != '*' && i != '+' && i != '-' && i != '/')
        {
            cout << float(i) - 48 << " ";
            st.push((int)i - 48);
        }
        else
        {
            int element = st.top();
            st.pop();
            int element2 = st.top();
            st.pop();

            int cal = 0;
            if (i == '*')
                cal = element * element2;
            if (i == '+')
                cal = element + element2;
            if (i == '/')
                cal = element2 / element;
            if (i == '-')
                cal = element2 - element;
            st.push(cal);
        }
    }

    int result = st.top();
    return result;
}

int main()
{
    string s = "123*+5-";
    int ans = evaluate(s);
    cout << "\n";
    cout << ans << " ";
}