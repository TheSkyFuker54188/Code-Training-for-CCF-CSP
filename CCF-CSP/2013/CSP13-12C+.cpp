// 2013年12月 第C题
// 算法 + 数据结构）

#include <iostream>
#include <stack>

using namespace std;

int n;
int h[100000];

stack<int> L;
stack<int> R;

int idx_l[100000];
int idx_r[100000];

long long s[100000];
long long mx = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
    {
        idx_l[i] = -1;
        idx_r[i] = n;
    }

    for (int i = 0; i < n; i++)
    { // 左侧第一个小弟
        while (!L.empty() && h[L.top()] >= h[i])
            L.pop();
        if (!L.empty())
            idx_l[i] = L.top();
        L.push(i);
    }

    for (int i = n - 1; i >= 0; i--)
    { // 右侧第一个小弟
        while (!R.empty() && h[R.top()] >= h[i])
            R.pop();
        if (!R.empty())
            idx_r[i] = R.top();
        R.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        s[i] = (long long)h[i] * (idx_r[i] - idx_l[i] - 1);
        if (s[i] > mx)
            mx = s[i];
    }
    cout << mx;
}