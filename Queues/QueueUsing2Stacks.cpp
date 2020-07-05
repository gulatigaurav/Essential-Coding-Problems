#include <iostream>
#include <stack>
using namespace std;

class Queue
{

private:
    stack<int> s1;
    stack<int> s2;

public:
    Queue()
    {
    }

    void Push(int x);
    int Pop();
    int Size();
    int Top();
};

int Queue::Top()
{
    if (s2.empty())
    {
        // Copy all elements from s1 -> s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    else
    {
        return s2.top();
    }

    // Since New element is always appended to the back
}

int Queue::Size()
{
    return s1.size() > s2.size() ? s1.size() : s2.size();
}

int Queue::Pop()
{
    if (s2.empty())
    {
        // Copy all elements from s1 -> s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
    }
    else
    {
        s2.pop();
    }
}

void Queue::Push(int x)
{
    s1.push(x);
}

int main()
{
    Queue *obj = new Queue();
    obj->Push(10);
    obj->Push(20);
    obj->Push(30);
    // obj->Pop();
    int size = obj->Size();
    int top = obj->Top();
    cout << size << " " << top << "\n";
}