// 2020-4-B 邻域均值
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