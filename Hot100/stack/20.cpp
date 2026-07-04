#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<char> a;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
            a.push(c);
        else if (c == ')')
        {
            if (a.empty()||a.top() != '(')
            {
                cout << "false";
                return 0;
            }
            a.pop();
        }
        else if (c == '}')
        {
            if (a.empty()||a.top() != '{')
            {
                cout << "false";
                return 0;
            }
            a.pop();
        }
        else if (c == ']')
        {
            if (a.empty()||a.top() != '[')
            {
                cout << "false";
                return 0;
            }
            a.pop();
        }
    }
    cout << "true";
    return 0;
}