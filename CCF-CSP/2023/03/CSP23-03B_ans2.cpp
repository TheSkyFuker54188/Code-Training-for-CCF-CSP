// 2023-03-B 垦田计划
//? 贪心法 + 桶排序思想

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// cnt[t] 表示：要把所有当前耗时为 t 天的区域，
// 全部缩短 1 天（即都变成 t-1 天）所需要的资源总量。
// 因为 t 最大可能到 100000，所以开 100005 足够。
long long cnt[100005];

int main()
{
    // 关闭同步，加速 cin / cout
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;         // 区域总数
    long long m;   // 手中资源数量
    int k;         // 最少允许的天数
    cin >> n >> m >> k;

    int max_t = 0;  // 所有区域中最大的原始耗时
    for (int i = 0; i < n; i++)
    {
        int t, c;
        cin >> t >> c;
        // 把同一耗时的区域的资源需求累加起来
        cnt[t] += c;
        max_t = max(max_t, t);
    }

    // current_t 表示当前所有区域中的最大耗时
    int current_t = max_t;

    // 只要当前最大耗时大于 k，并且我们有可能把它降下去，就尝试削减
    while (current_t > k)
    {
        // 检查手上的资源 m 是否足够把当前所有耗时 = current_t 的区域全部减少 1 天（变为 current_t - 1 天）
        if (m >= cnt[current_t])
        {
            // 够，那就把这些资源花出去
            m -= cnt[current_t];

            // 这些区域现在耗时变成了 current_t - 1，
            // 如果以后还想把它们从 current_t - 1 再往下降，
            // 就需要把它们的“降价成本”合并到 cnt[current_t - 1] 中
            cnt[current_t - 1] += cnt[current_t];

            // 当前最大耗时整体下降了 1
            current_t--;
        }
        else
        {
            // 不够，无法把当前所有耗时最长的区域都降 1 天，
            // 那么总时间就不可能再缩短了，直接结束
            break;
        }
    }

    // 输出最终可以达到的最小总耗时
    cout << current_t << "\n";
    return 0;
}