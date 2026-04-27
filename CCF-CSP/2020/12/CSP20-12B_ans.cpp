// 2020-12-B 期末预测之最佳阈值
//? 优化解法 —— 增量更新
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int m;
    cin >> m;
    vector<pair<int, int>> p(m);

    for (int i = 0; i < m; i++)
        cin >> p[i].first >> p[i].second;

    sort(p.begin(), p.end());

    int best_theta = p[0].first;

    int cur_correct = 0;
    for (int i = 0; i < m; i++)
    {
        if (p[i].second == 1)
            cur_correct++;
    }
    int best_correct = cur_correct;

    int i = 0;
    while (i < m)
    {
        int y = p[i].first;
        while (p[i].first == y // 同分数“当前组”
               && i < m)
        { //* 提前计算“如果阈值升到下一个值，他们会带来多少净变化”
            // 阈值从 y 跳到更大值时，该组样本预测会从 1 变为 0。
            if (p[i].second == 1)
                cur_correct--;
            else
                cur_correct++;
            i++;
        }

        if (i < m)
        {
            int next_theta = p[i].first;
            if (cur_correct > best_correct //
                || (cur_correct == best_correct && next_theta > best_theta))
            {
                best_correct = cur_correct;
                best_theta = next_theta;
            }
        }
    }

    cout << best_theta;
}