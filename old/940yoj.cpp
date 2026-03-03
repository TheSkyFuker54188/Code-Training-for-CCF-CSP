#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int max(int a, int b) { return a > b ? a : b; }

int k, n, m;
int man[100][100];  // 要塞 j 被玩家 i 的 man[i][j] 名士兵攻击
int cost[100][100]; // 第 j + 1 次获得要塞 i 总计需要 cost[i][j] 名士兵

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }
void init_values()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            cost[i][j] = 2 * man[j][i] + 1;
        qsort(cost[i], k, sizeof(int), cmp);
    }
}

// 简化但高效的动态规划求解
int solve_efficient()
{
    // 使用一维数组，简单直观
    int dp[20001] = {0};

    // 对每个要塞进行处理
    for (int i = 1; i <= n; i++)
    {
        // 从大到小遍历士兵数量，避免重复计算
        for (int j = m; j >= 0; j--)
        {
            // 尝试不同的攻占方式
            for (int attempt = 0; attempt < k; attempt++)
            {
                int soldiers = cost[i - 1][attempt];
                if (j >= soldiers)
                {
                    int gain = (attempt + 1) * i;
                    dp[j] = max(dp[j], dp[j - soldiers] + gain);
                }
                else
                {
                    // cost已排序，不需要继续检查
                    break;
                }
            }
        }
    }

    return dp[m];
}

// 针对超大规模测试点的优化解法
int solve_extreme_case()
{
    int dp[20001] = {0};

    // 预处理每个要塞的最小攻占成本
    int min_cost[100];
    for (int i = 0; i < n; i++)
    {
        min_cost[i] = cost[i][0]; // 已经排序过，第一个是最小的
    }

    // 对每个要塞进行处理
    for (int i = 1; i <= n; i++)
    {
        int current_min = min_cost[i - 1];

        // 只处理有意义的士兵数量
        for (int j = m; j >= current_min; j--)
        {
            // 这个内循环是主要的计算瓶颈，需要优化
            for (int attempt = 0; attempt < k; attempt++)
            {
                int soldiers = cost[i - 1][attempt];

                // 超出可用士兵，提前结束
                if (j < soldiers)
                    break;

                // 计算新得分
                int gain = (attempt + 1) * i;
                int new_score = dp[j - soldiers] + gain;

                // 只有能提高分数时才更新
                if (new_score > dp[j])
                {
                    dp[j] = new_score;
                }
            }
        }
    }

    return dp[m];
}

// 终极优化解法
int solve_ultimate()
{
    int dp[20001] = {0};

    // 预计算要塞的有效攻占情况
    struct Attack
    {
        int soldiers;
        int gain;
    };
    Attack attacks[100][100];     // [要塞][攻占方式]
    int attack_counts[100] = {0}; // 每个要塞有效的攻占方式数量

    for (int i = 0; i < n; i++)
    {
        int valid_count = 0;
        int best_gain_for_soldiers[20001] = {0}; // 临时数组，记录每个兵力下的最大收益

        for (int j = 0; j < k; j++)
        {
            int soldiers = cost[i][j];
            int gain = (j + 1) * (i + 1);

            // 跳过无效攻占方式（更多士兵但收益更低）
            if (soldiers > m)
                continue;

            if (best_gain_for_soldiers[soldiers] < gain)
            {
                best_gain_for_soldiers[soldiers] = gain;

                // 只记录最优的攻占方式
                bool is_best = true;
                for (int p = 0; p < valid_count; p++)
                {
                    if (attacks[i][p].soldiers <= soldiers && attacks[i][p].gain >= gain)
                    {
                        is_best = false;
                        break;
                    }
                    // 删除被当前方式支配的其他攻占方式
                    if (attacks[i][p].soldiers >= soldiers && attacks[i][p].gain <= gain)
                    {
                        attacks[i][p] = attacks[i][valid_count - 1];
                        valid_count--;
                        p--;
                    }
                }

                if (is_best)
                {
                    attacks[i][valid_count].soldiers = soldiers;
                    attacks[i][valid_count].gain = gain;
                    valid_count++;
                }
            }
        }

        attack_counts[i] = valid_count;
    }

    // 主DP循环
    for (int i = 0; i < n; i++)
    {
        // 从大到小遍历士兵数量
        for (int j = m; j >= 0; j--)
        {
            for (int a = 0; a < attack_counts[i]; a++)
            {
                int soldiers = attacks[i][a].soldiers;
                if (j >= soldiers)
                {
                    int new_score = dp[j - soldiers] + attacks[i][a].gain;
                    if (new_score > dp[j])
                    {
                        dp[j] = new_score;
                    }
                }
            }
        }
    }

    return dp[m];
}

int main()
{
    scanf("%d%d%d", &k, &n, &m);

    // 读取每个玩家对每个要塞的攻击兵力
    for (int player = 0; player < k; player++)
        for (int fortress = 0; fortress < n; fortress++)
            scanf("%d", &man[player][fortress]);

    init_values();

    // 根据规模选择解法
    if (k >= 50 && n >= 50 && m >= 10000)
    {
        printf("%d\n", solve_ultimate());
    }
    else if (k >= 20 && n >= 20)
    {
        printf("%d\n", solve_extreme_case());
    }
    else
    {
        printf("%d\n", solve_efficient());
    }

    return 0;
}
