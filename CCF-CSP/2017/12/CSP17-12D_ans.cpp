// 2017年12月 第D题
// 行车路线
// 单源最短路 拆点 Dijkstra SPFA
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
//* 十进制值大概是 1e9
//! 为什么要用它，而不用真正的 INT_MAX?  防止“整型溢出”

struct Edge
{
    int to;
    int type; // 0 是大道，1 是小道
    int weight;
};

// 优先队列中的状态结点
struct Node
{
    int u;    // 当前路口
    int L;    // 当前末尾连续小道的长度
    int cost; // 当前总疲劳度

    // Dijkstra 需要按 cost 从小到大出队
    bool operator>(const Node &other) const
    {
        return cost > other.cost;
    }
};

int n, m;
vector<Edge> adj[505];
int dist[505][1005];
// dist[节点编号][连续小道长度]
//* 到达路口u且当前末尾已经是连续走了L公里小道时的最小总疲劳度

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int t, u, v, c;
        cin >> t >> u >> v >> c;
        adj[u].push_back({v, t, c});
        adj[v].push_back({u, t, c});
    }

    memset(dist, 0x3f, sizeof(dist));
    //! memset 是按**字节（byte）**来赋值的。由于 int 是 4 个字节，给每个字节塞入十六进制的 3f，这 4 个字节拼在内存里刚好就是 0x3f3f3f3f

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    //? priority_queue<数据类型, 底层容器, 排序规则>
    //? priority_queue默认每次弹出的元素永远是**“最大的”**
    //? greater起到反转作用。只要发现前面比后面大 (greater)，就把大的给‘沉’下去

    // 起点初始化
    dist[1][0] = 0;
    pq.push({1, 0, 0});

    while (!pq.empty())
    {
        Node curr = pq.top();
        pq.pop();

        int u = curr.u;
        int L = curr.L;
        int cost = curr.cost;

        // 如果这个状态由于之前的更新已经不是最优，则舍弃
        if (cost > dist[u][L])
            continue;

        // 如果到达终点（因为是优先队列，第一次遇到了也不可以直接 break，因为有可能别的状态虽然现在大但是加上去的小，
        // 不过由于没有负权边和特殊机制，也可以直接统计，这里稳妥点统一放到最后找答案）

        // 探索周边相邻的路口
        for (const auto &edge : adj[u])
        {
            int v = edge.to;
            int type = edge.type;
            int c = edge.weight;

            if (type == 0)
            {
                // 走大道，连续小道长度清零
                int ncost = cost + c;
                if (ncost < dist[v][0])
                {
                    dist[v][0] = ncost;
                    pq.push({v, 0, ncost});
                }
            }
            else
            {
                // 走小道，连续小道长度累加
                int nL = L + c;
                // 利用题目上限剪枝，如果小道连续长度超过 1000，那耗费已经大于 10^6 了，无需继续走
                if (nL <= 1000)
                {
                    // 更新规则：扣除旧的 L^2 的代价，加上新的 (L+c)^2 的代价
                    int ncost = cost - L * L + nL * nL;
                    if (ncost < dist[v][nL])
                    {
                        dist[v][nL] = ncost;
                        pq.push({v, nL, ncost});
                    }
                }
            }
        }
    }

    // 在到达终点 n 的所有状态里找一个最小代价
    int ans = INF;
    for (int i = 0; i <= 1000; i++)
    {
        ans = min(ans, dist[n][i]);
    }

    cout << ans << "\n";

    return 0;
}