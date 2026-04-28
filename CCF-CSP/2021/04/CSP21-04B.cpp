// 2020-4-B 邻域均值
//! 暴力肯定不行
#include <iostream>
#include <algorithm>

using namespace std;

int a[600][600];
int main()
{
    int n, L, r, t;
    cin >> n >> L >> r >> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int y_d = max(0, i - r);
        int y_u = min(n - 1, i + r);
        for (int j = 0; j < n; j++)
        {
            int x_l = max(0, j - r);
            int x_r = min(n - 1, j + r);

            for (int y = y_d; y < y_u; y++)
            {
                for (int x = x_l; x < x_r; x++)
                {

                }
            }
        }
    }
}