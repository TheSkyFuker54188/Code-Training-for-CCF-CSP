// 2021-9-B 非零段划分
//?
#include <iostream>
#include <vector>
using namespace std;

const int MAXA = 10000; // Ai <= 10000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    int maxA = 0;

    vector<vector<int>> pos(MAXA + 1);
    // 外层数组（10001 个空名单）
    // 内层数组，每个值的所在位置

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > 0)
        {
            maxA = max(maxA, a[i]);
            pos[a[i]].push_back(i);
        }
    }

    vector<bool> active(n, false); // 当前位置是否为陆地
    int cnt = 0;                   // 当前非零段数
    int ans = 0;                   // 历史最大非零段数

    for (int v = maxA; v >= 1; v--)
    {
        if (pos[v].empty())
            continue;
        for (int i : pos[v])
        {
            active[i] = true;
            cnt++;

            if (i > 0 && active[i - 1])
                cnt--; // 与左段合并
            if (i < n - 1 && active[i + 1])
                cnt--; // 与右段合并
        }

        if (cnt > ans)
            ans = cnt;
    }
    cout << ans << endl;
}