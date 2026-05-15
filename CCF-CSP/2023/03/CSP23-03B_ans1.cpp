// 2023-03-B 垦田计划
//? 二分法：在可能的天数范围内, 二分查找最小的可行天数

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 存储每块田地的信息
struct Field
{
    int t; // 基础开垦耗时（天）
    int c; // 缩短1天所需资源数量
};

int n;                // 区域总数
long long m;          // 手中资源总量（可能很大，用 long long）
int k;                // 每块区域最少开垦天数
vector<Field> fields; // 所有田地的数据

// 判断目标天数 x 是否可行：即能否用不超过 m 的资源，
// 把所有田地的开垦时间降到 x 天或以下
bool check(int x)
{
    long long cost = 0; // 累计需要投入的资源
    for (int i = 0; i < n; i++)
    {
        // 只有当前田地的耗时超过目标 x 天才需要投入资源
        if (fields[i].t > x)
        {
            // 缩短到 x 天需要缩短 (t - x) 天，每天需要 c 资源
            cost += (long long)(fields[i].t - x) * fields[i].c;
            // 如果在累加过程中已经超过手中的资源 m，就提前结束，不可行
            if (cost > m)
                return false;
        }
    }
    // 总资源需求不超过 m 则方案可行
    return cost <= m;
}

int main()
{
    // 提升cin, cout效率，关闭与C标准库的同步，解除cin与cout的绑定
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 输入区域数量、资源总量、最少天数限制
    cin >> n >> m >> k;
    fields.resize(n);

    int max_t = 0; // 记录所有田地中最大的基础耗时，作为二分查找的上界
    for (int i = 0; i < n; i++)
    {
        cin >> fields[i].t >> fields[i].c;
        max_t = max(max_t, fields[i].t); // 更新最大天数
    }

    // 二分查找的初始范围：最少可以到 k 天，最多就是原来的最大天数
    int l = k, r = max_t;
    int ans = max_t; // 初始答案设为最大天数（不投入任何资源的情况）

    while (l <= r)
    {
        // 取区间的中点，避免直接 (l + r) / 2 可能的溢出
        int mid = l + (r - l) / 2;

        // 检查 mid 天是否可行
        if (check(mid))
        {
            // 如果可行，记录这个天数，并尝试看看能不能再缩短（减小右边界）
            ans = mid;
            r = mid - 1;
        }
        else
        {
            // 如果不可行，说明天数太小，需要增加天数（增大左边界）
            l = mid + 1;
        }
    }

    // 输出找到的最少可行天数
    cout << ans << "\n";
    return 0;
}