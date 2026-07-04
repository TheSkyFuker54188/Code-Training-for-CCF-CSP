#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<char> a;
    vector<char> ans;

    for (char c : s)
    {
        a.push(c);
        if (c == ']')
        {
            a.pop();
            vector<char> tem;
            while (a.top() != '[')
            {
                tem.push_back(a.top());
                a.pop();
            }
            a.pop();

            int n = 0;
            int bit = 1;
            while (a.top() >= '0' && a.top() <= '9')
            {
                n += (a.top() - '0') * bit;
                bit *= 10;
                a.pop();
            }
            for (int i = 0; i < n; i++)
            {
                ans.insert(ans.end(), tem.begin(), tem.end());
            }
        }
    }

    for (char c : ans)
        cout << c;
}