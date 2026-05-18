// 2023-09-B 坐标变换（其二）
//! 暴力超时
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip> //todo 对精度有要求！

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    pair<int, double> o[n + 1];
    //   type,  k/theta
    pair<long long, long long> a[m];
    //          x ,  y

    for (int i = 1; i <= n; i++)
    {
        cin >> o[i].first >> o[i].second;
    }
    for (int i = 0; i < m; i++)
    {
        int ii, jj;
        cin >> ii >> jj;
        cin >> a[i].first >> a[i].second;

        double x = a[i].first, y = a[i].second;
        int p = ii;
        while (p <= jj)
        {
            if (o[p].first == 1) // 拉伸
            {
                x *= o[p].second;
                y *= o[p].second;
            }
            else // 旋转
            {
                double tx = x, ty = y;
                x = tx * cos(o[p].second) - ty * sin(o[p].second);
                y = tx * sin(o[p].second) + ty * cos(o[p].second);
            }
            p++;
        }
        cout << fixed << setprecision(10);
        cout << x << " " << y << "\n";
    }
}