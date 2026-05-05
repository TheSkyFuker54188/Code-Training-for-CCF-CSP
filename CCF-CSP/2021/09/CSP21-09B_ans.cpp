// 2021-9-B 非零段划分
//? 增量更新
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

    // 记录每个值出现的位置，0 直接忽略（永远是水）
    vector<vector<int>> pos(MAXA + 1);

    for (int i = 0; i < n; ++i)
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

    // 从大到小激活陆地
    for (int v = maxA; v >= 1; --v)
    {
        if (pos[v].empty())
            continue;

        for (int i : pos[v])
        {
            active[i] = true;
            cnt++; // 先当作独立的新段

            // 检查左邻
            if (i > 0 && active[i - 1])
                cnt--; // 与左段合并
            // 检查右邻
            if (i < n - 1 && active[i + 1])
                cnt--; // 与右段合并
        }

        // 此时 p = v，对应的非零段数为 cnt
        if (cnt > ans)
            ans = cnt;
    }

    cout << ans << "\n";
    return 0;
}