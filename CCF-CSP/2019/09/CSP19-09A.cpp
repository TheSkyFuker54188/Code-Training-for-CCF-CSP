// 2019-9-A 小明种苹果
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[1001];       // 原果数量
int b[1001][1001]; //[i][j]：i树第j轮去果量
int c[1001];       // 去果数量

int main()
{
    int t = 0;
    int p = 1, k = 0;
    //freopen("in.txt", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j == 0)
                cin >> a[i];
            cin >> b[i][j];
            c[i] += b[i][j];
        }
        if (c[i] < p)
        {
            p = c[i];
            k = i;
        }
        int left = a[i] + c[i];
        t += left;
    }

    cout << t << " " << k << " " << abs(p);
}