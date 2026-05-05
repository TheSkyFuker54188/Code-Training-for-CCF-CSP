// 2021-4-B 邻域均值
//? 二维前缀和
#include <iostream>
#include <algorithm>

using namespace std;

int a[605][605];
int sumv[605][605];

int main()
{
    int n, L, r, t;
    cin >> n >> L >> r >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            sumv[i][j] = sumv[i - 1][j] + sumv[i][j - 1] - sumv[i - 1][j - 1] + a[i][j];
            /* 上面的整块 + 左边的整块 - 左上角重复算那一块 + 当前格子(a[i][j]) */
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int y1 = max(1, i + 1 - r);
        int y2 = min(n, i + 1 + r);
        for (int j = 0; j < n; j++)
        {
            int x1 = max(1, j + 1 - r);
            int x2 = min(n, j + 1 + r);
            int cnt = (y2 - y1 + 1) * (x2 - x1 + 1);
            int total = sumv[y2][x2] - sumv[y1 - 1][x2] - sumv[y2][x1 - 1] + sumv[y1 - 1][x1 - 1];
            if (total <= cnt * t)
            {
                ans++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}

/*
原数组不变，但你要反复查询某一段连续区间或某个矩形区域的总和、数量、平均值、是否满足阈值
? “暴力每次都要重复扫一遍同样的元素”

一维前缀和：sum(l,r)=s[r]−s[l−1]
 二维前缀和：sumv[i][j] = sumv[i - 1][j] + sumv[i][j - 1] - sumv[i - 1][j - 1] + a[i][j]

 ! 什么时候不用前缀和：
区间中间要频繁修改
查询不是连续区间，而是杂乱集合
要求最大值、最小值、排序后的信息
要维护的是复杂状态，不是简单累加量
*/