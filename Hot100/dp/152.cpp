/* 为什么不用前缀积？
数组中可能包含 0
单独为了处理0而分段的话，还不如直接用动态规划（本质上还是动态规划） */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> a;
    int x;
    while (cin >> x)
    {
        a.push_back(x);
    }
    int n = a.size();

    int imax = a[0];
    int imin = a[0];
    int ans = a[0];

    for (int i = 1; i < n; i++)
    {
        int old_max = imax;
        int old_min = imin;
        imax = max({old_max * a[i], old_min * a[i], a[i]});
        imin = min({old_min * a[i], old_max * a[i], a[i]});

        ans = max(ans, imax);
    }
    cout << ans;
}