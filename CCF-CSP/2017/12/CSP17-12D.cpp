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

struct Edge
{
    int to;
    int type;
    int weight;
};

struct Node
{
    int u;    // 当前路口
    int L;    // 当前末尾连续小道的长度
    int cost; // 当前总疲劳度

    bool operator>(const Node &other) const
    {
        return cost > other.cost;
    }
};

vector<Edge> adj[505];
int dist[505][1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int t, u, v, c;
    for (int i = 0; i < m; i++)
    {
        cin >> t >> u >> v >> c;
        adj[u].push_back({v, t, c});
        adj[v].push_back({u, t, c});
    }

    memset(dist, 0x3f, sizeof(dist));

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    //初始化
    dist[1][0] = 0;
    pq.push({1, 0, 0});

    //开始探索（总疲劳度从小到大顺序遍历各种走法）
    while (!pq.empty())
    {
        Node curr = pq.top();
        pq.pop();

        int u = curr.u;
        int L = curr.L;
        int cost = curr.cost;

        if (cost > dist[u][L])
            continue;

        for (const auto &edge : adj[u])
        {
            int v = edge.to;
            int type = edge.type;
            int c = edge.weight;

            if (type == 0)
            {
                int new_cost = cost + c;
                if (new_cost < dist[v][0])
                {
                    dist[v][0] = new_cost;
                    pq.push({v, 0, new_cost});
                }
            }
            else
            {
                int new_L = L + c;
                if (new_L <= 1000)
                {
                    int new_cost = cost - L * L + new_L * new_L;
                    if (new_cost < dist[v][new_L])
                    {
                        dist[v][new_L] = new_cost;
                        pq.push({v, new_L, new_cost});
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int i = 0; i <= 1000; i++)
        ans = min(ans, dist[n][i]);

    cout << ans << endl;

    return 0;
}