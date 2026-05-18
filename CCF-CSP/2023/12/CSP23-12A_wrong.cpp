// 2023-12-A 仓库规划
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int a[1000 + 1][10];

inline bool small(int i, int j)
{
    bool small = true;
    for (int ii = 0; ii < m; ii++)
    {
        if (a[i][ii] > a[j][ii])
            small = false;
    }
    return small;
}

int main()
{
    freopen("in.txt", "r", stdin);
    cin >> n >> m;

    int order[n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i < n; i++)
    {
        int cnt = 1;
        for (int j = i + 1; j <= n; j++)
        {
            if (small(i, j))
                cnt++;
        }
        order[cnt] = i;
    }

    for (int i = 1; i <= n; i++)
        cout << order[i] << "\n";
}