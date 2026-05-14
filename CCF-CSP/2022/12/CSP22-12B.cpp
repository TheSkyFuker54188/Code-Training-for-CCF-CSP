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
    //!  post数组是错的，因为可能出现同节点有多个后继（这是"根"）
    int post[m];
    //     后继
    int t_erly[m];
    int t_late[m];
    bool can = true;

    for (int i = 0; i < m; i++)
    {
        post[i] = 0;
        t_erly[i] = 0;
        t_late[i] = n;

        cin >> a[i].first;
        if (a[i].first != 0)
        {
            post[a[i].first - 1] = i;
        }
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

        t_late[i] -= a[i].second - 1;
        if (post[i] != 0)
        {
            int pst = post[i];
            while (pst != 0)
            {
                t_late[i] -= a[pst].second;
                pst = post[pst];
            }
        }

        if (t_erly[i] + a[i].second > n + 1)
            can = false;
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