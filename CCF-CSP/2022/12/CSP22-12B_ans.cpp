// 2022-12-B 训练计划
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    pair<int, int> a[m];
    //   前驱,天数
    int t_erly[m];
    int t_late[m];
    bool can = true;

    for (int i = 0; i < m; i++)
    {
        t_erly[i] = 0;
        t_late[i] = n;

        cin >> a[i].first;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].second;
    }

    for (int i = 0; i < m; i++)
    {
        if (a[i].first != 0)
        {
            int pre = a[i].first;
            while (pre != 0)
            {
                t_erly[i] += a[pre - 1].second;
                pre = a[pre - 1].first;
            }
            t_erly[i]++;
        }
        else
            t_erly[i] = 1;

        t_late[i] = n - a[i].second + 1;

        if (t_erly[i] + a[i].second > n + 1)
            can = false;
    }

    for (int i = m - 1; i >= 0; i--)
    {
        if (a[i].first != 0)
        {
            int pre = a[i].first - 1;
            t_late[pre] = min(t_late[pre], t_late[i] - a[pre].second);
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << t_erly[i] << " ";
    }
    cout << endl;
    if (can)
        for (int i = 0; i < m; i++)
        {
            cout << t_late[i] << " ";
        }
}