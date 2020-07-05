#include <iostream>
#include <queue>
using namespace std;

class Stack
{

private:
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
    }

    void Push(int x);
    int Pop();
    int Size();
    int Top();
};

int Stack::Top()
{
    // Since New element is always appended to the back
    return q1.size() > q2.size() ? q1.back() : q2.back();
}

int Stack::Size()
{
    return q1.size() > q2.size() ? q1.size() : q2.size();
}

int Stack::Pop()
{
    if (q1.empty())
    {
        // Transfer n - 1 elements from q2 -> q1;
        while (q2.size() != 1)
        {
            int ele = q2.front();
            q1.push(ele);
            q2.pop();
        }
        int ele = q2.front();
        q2.pop();
        return ele;
    }

    else if (q2.empty())
    {
        while (q1.size() != 1)
        {
            int ele = q1.front();
            q2.push(ele);
            q1.pop();
        }
        int ele = q1.front();
        q1.pop();
        return ele;
    }
}

void Stack::Push(int x)
{

    if (q1.empty())
    {
        q2.push(x);
    }
    else if (q2.empty())
    {
        q1.push(x);
    }
}

int main()
{
    Stack *obj = new Stack();
    obj->Push(10);
    obj->Push(20);
    obj->Push(30);
    int el = obj->Pop();
    int size = obj->Size();
    int top = obj->Top();
    cout << size << " " << top << " " << el << "\n";
}