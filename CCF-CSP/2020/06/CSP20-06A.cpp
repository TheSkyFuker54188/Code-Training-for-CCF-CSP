// 2020-6-A 线性分类器
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<pair<int, int>> a;
    vector<pair<int, int>> b;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        char type;
        cin >> x >> y >> type;
        if (type == 'A')
            a.push_back({x, y});
        else if (type == 'B')
            b.push_back({x, y});
    }

    for (int i = 0; i < m; i++)
    {
        long long theta0, theta1, theta2;
        cin >> theta0 >> theta1 >> theta2;

        bool ok = true;
        int signA = 0, signB = 0;

        // 检查 A 类点是否都在直线同侧
        for (int j = 0; j < a.size(); j++)
        {
            long long val = theta0 + theta1 * a[j].first + theta2 * a[j].second;
            int cur_sign = val > 0 ? 1 : -1;
            if (j == 0)
                signA = cur_sign;
            else if (cur_sign != signA)
            {
                ok = false;
                break;
            }
        }

        // 如果 A 类点已经不满足，不再检查 B 类点
        if (ok)
        {
            // 检查 B 类点是否都在直线同侧，且与 A 类点不在同一侧
            for (int j = 0; j < b.size(); j++)
            {
                long long val = theta0 + theta1 * b[j].first + theta2 * b[j].second;
                int cur_sign = val > 0 ? 1 : -1;
                if (j == 0)
                    signB = cur_sign;
                else if (cur_sign != signB)
                {
                    ok = false;
                    break;
                }
            }
            if (signA == signB)
                ok = false;
        }

        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}