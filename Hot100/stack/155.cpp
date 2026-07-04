//? 普通栈+最小栈
#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct MinStack
{
    stack<int> v;
    stack<int> m;
    MinStack() {}
};

MinStack a;

void v_push(int val)
{
    a.v.push(val);
    if (a.m.empty())
    {
        a.m.push(val);
    }
    else
    {
        if (val <= a.m.top())
            a.m.push(val);
    }
}

void v_pop()
{
    int b = a.v.top();
    a.v.pop();
    if (b == a.m.top())
        a.m.pop();
}

void v_top()
{
    cout << a.v.top() << '\n';
}

void getMin()
{
    cout << a.m.top() << '\n';
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string opt;
        cin >> opt;
        if (opt == "push")
        {
            int val;
            cin >> val;
            v_push(val);
        }
        else if (opt == "pop")
        {
            v_pop();
        }
        else if (opt == "top")
        {
            v_top();
        }
        else if (opt == "getMin")
        {
            getMin();
        }
    }
}
