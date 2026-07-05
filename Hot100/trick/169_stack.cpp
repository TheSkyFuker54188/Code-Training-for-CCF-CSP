#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int n;
    int x;
    vector<int> a;
    while (cin >> x)
        a.push_back(x);

    n = a.size();

    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
            s.push(a[i]);

        if (s.top() != a[i])
            s.pop();

        else
            s.push(a[i]);
    }
    cout << s.top();
}