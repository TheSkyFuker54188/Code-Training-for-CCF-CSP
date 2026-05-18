// 2023-09-A 坐标变换（其一）
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int dx = 0, dy = 0;
    //    x ,  y
    pair<int, int> a[m];

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        dx += x;
        dy += y;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 0; i < m; i++)
    {
        a[i].first += dx;
        a[i].second += dy;
        cout << a[i].first << " " << a[i].second << "\n";
    }
}