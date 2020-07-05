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
    vector<int> arr = {5, 2, 0, 6, 0};
    stack<int> min;

    stack<int> st;
    for (auto i : arr)
    {
        st.push(i);
    }

    min.push(arr[0]);

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] <= min.top())
            min.push(arr[i]);
        // else
        //     min.push(min.top());
    }

    printStackContent(min);

    if (arr[arr.size() - 1] == min.top())
    {
        arr.pop_back();
    }
    else
        min.pop();
    // min.pop();

    cout << "Min Element " << min.top() << " ";
    return 0;
}