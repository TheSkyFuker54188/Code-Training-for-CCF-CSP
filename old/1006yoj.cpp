#include <iostream>
#include <stack>

using namespace std;

stack<int> P, S;
void push(int val)
{
    P.push(val);
    S.push(max(val, S.top()));
}

void pop()
{
    P.pop();
    S.pop();
}

int top()
{
    return P.top();
}

int findMax()
{
    return S.top();
}

int main()
{
    P.push(0x80000000);
    S.push(0x80000000);
    int n;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num == 1)
        {
            int val;
            cin >> val;
            push(val);
        }
        if (num == 2)
        {
            pop();
        }
        if (num == 3)
        {
            cout << top() << endl;
        }
        if (num == 4)
        {
            cout << findMax() << endl;
        }
    }
    return 0;
}