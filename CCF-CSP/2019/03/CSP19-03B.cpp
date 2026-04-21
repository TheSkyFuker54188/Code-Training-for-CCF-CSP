// 2019-3-B 二十四点
#include <iostream>
#include <stack>

using namespace std;

int n;

int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        stack<int> s;
        for (int p = 0; p < 7; p++)
        {
            char tmp = str[p];
            if (tmp >= '0' && tmp <= '9')
            {
                s.push(str[p] - '0');
            }
            else if (tmp == 'x')
            {
                int a = s.top();
                s.pop();
                int b = str[++p] - '0';
                s.push(a * b);
            }
            else if (tmp == '/')
            {
                int a = s.top();
                s.pop();
                int b = str[++p] - '0';
                s.push(a / b);
            }
            else if (tmp == '+')
            {
                s.push(-1);
            }
            else if (tmp == '-')
            {
                s.push(-2);
            }
        }
        stack<int> ss;
        while (!s.empty())
        {
            ss.push(s.top());
            s.pop();
        }
        while (ss.size() != 1)
        {
            int a = ss.top();
            ss.pop();
            int opt = ss.top();
            ss.pop();
            int b = ss.top();
            ss.pop();

            if (opt == -1) //+
                ss.push(a + b);
            else if (opt == -2)
                ss.push(a - b);
        }
        if (ss.top() == 24)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}