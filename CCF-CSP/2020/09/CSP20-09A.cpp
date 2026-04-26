// 2020-9-A 称检测点查询
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int main()
{
    int n, cx, cy;
    cin >> n >> cx >> cy;
    pair<double, int> dist[n + 1];

    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        dist[i].second = i;
        dist[i].first = pow(cx - x, 2) + pow(cy - y, 2);
    }
    sort(dist+1, dist+n+1);

    cout << dist[1].second << endl
         << dist[2].second << endl
         << dist[3].second;
}