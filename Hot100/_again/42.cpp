/* 对于位置 i，它能接的雨水公式是：
min(左侧最高柱子, 右侧最高柱子) - h[i] */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l_max = a[0];
    int r_max = a[n - 1];

    int l = 0;
    int r = n - 1;

    int s = 0;

    while (l < r)
    {
        l_max = max(l_max, a[l]);
        r_max = max(r_max, a[r]);

        if (l_max < r_max)//! 保证一定计算短板处水量
        {
            s += l_max - a[l];
            l++;
        }
        else
        {
            s += r_max - a[r];
            r--;
        }
    }
    cout << s;
}