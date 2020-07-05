#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void printStackContent(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    vector<int> arr = {5, 1, 4, 6, 0};
    stack<int> min;

    min.push(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < min.top())
            min.push(arr[i]);
        else
            min.push(min.top());
    }

    printStackContent(min);

    arr.pop_back();
    min.pop();

    cout << "Min Element " << min.top() << " ";
    return 0;
}