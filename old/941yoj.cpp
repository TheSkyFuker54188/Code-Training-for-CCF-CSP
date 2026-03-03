#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
const int INF = 1e9;

int n, m;
int dist[MAXN];         // 相邻村庄间的距离
int pos[MAXN];          // 村庄的绝对位置
long long prefix[MAXN]; // 位置的前缀和，用于快速计算区间距离
int dp[MAXN][MAXN];     // dp[i][j]表示前i个村庄建j口井的最小距离和
int cost[MAXN][MAXN];   // 预计算的区间成本

// 计算区间[l,r]放一口井的最小距离和，O(1)复杂度
long long getCost(int l, int r)
{
    if (l == r)
        return 0;

    // 中位数村庄
    int mid = (l + r) >> 1;

    // 使用前缀和计算区间和
    // 左侧: pos[mid]*(mid-l+1) - (prefix[mid] - prefix[l-1])
    // 右侧: (prefix[r] - prefix[mid]) - pos[mid]*(r-mid)
    long long leftCost = 1LL * pos[mid] * (mid - l + 1) - (prefix[mid] - prefix[l - 1]);
    long long rightCost = (prefix[r] - prefix[mid]) - 1LL * pos[mid] * (r - mid);

    return leftCost + rightCost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // 读取相邻村庄距离并计算绝对位置
    pos[1] = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> dist[i];
        pos[i + 1] = pos[i] + dist[i];
    }

    // 计算前缀和
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + pos[i];
    }

    // 预计算所有可能区间的cost
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            cost[i][j] = getCost(i, j);
        }
    }

    // 初始化dp数组
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    // 动态规划
    for (int j = 1; j <= m; j++)
    {
        for (int i = j; i <= n; i++)
        {
            for (int k = j - 1; k < i; k++)
            {
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + cost[k + 1][i]);
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}
