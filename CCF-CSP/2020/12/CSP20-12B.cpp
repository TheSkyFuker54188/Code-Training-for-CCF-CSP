// 2020-12-B 期末预测之最佳阈值
//! 超时解法
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int m;
    cin >> m;
    pair<int, int> p[m];
    int accuracy[m];

    for (int i = 0; i < m; i++)
    {
        accuracy[i] = 0;
        cin >> p[i].first >> p[i].second;
    }

    for (int i = 0; i < m; i++)
    {
        int theta = p[i].first;
        for (int j = 0; j < m; j++)
        {
            int result = p[j].second;
            int predict = p[j].first >= theta ? 1 : 0;
            if (result == predict)
                accuracy[i]++;
        }
    }
    int max_acc = 0;
    for (int i = 0; i < m; i++)
    {
        if (accuracy[i] > max_acc)
            max_acc = accuracy[i];
    }
    int max_theta = 0;
    for (int i = 0; i < m; i++)
    {
        if (accuracy[i] == max_acc && p[i].first > max_theta)
            max_theta = p[i].first;
    }
    cout << max_theta;
}