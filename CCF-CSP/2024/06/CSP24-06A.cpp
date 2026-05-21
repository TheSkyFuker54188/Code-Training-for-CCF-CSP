// 2024-06-A 矩阵重塑（其一）
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    int a[n * m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i * m + j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout << a[cnt] << " ";
            cnt++;
            // cout << a[i * q + p] << " ";
        }
        cout << "\n";
    }
}