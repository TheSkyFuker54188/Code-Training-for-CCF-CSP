#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 105;
const int MAXM = 5005;
const long long INF = 0x3f3f3f3f3f3f3f3f;

// 边结构体
struct Edge
{
    int to;        // 终点
    int next;      // 下一条边的索引
    long long cap; // 容量
};

int n, m, s, t;
int head[MAXN];       // 邻接表头节点
int tot;              // 边的总数
Edge edges[MAXM * 2]; // 存储边，因为每条边都有正反两个方向
int level[MAXN];      // 层次图
int cur[MAXN];        // 当前弧优化

// 添加边
void addEdge(int u, int v, long long c)
{
    // 正向边
    edges[tot].to = v;
    edges[tot].cap = c;
    edges[tot].next = head[u];
    head[u] = tot++;

    // 反向边
    edges[tot].to = u;
    edges[tot].cap = 0; // 初始反向边容量为0
    edges[tot].next = head[v];
    head[v] = tot++;
}

// BFS构建层次图
bool bfs()
{
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s);
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = head[u]; ~i; i = edges[i].next)
        {
            int v = edges[i].to;
            if (level[v] == -1 && edges[i].cap > 0)
            {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }

    return level[t] != -1; // 如果汇点t能被访问到，返回true
}

// DFS寻找增广路径
long long dfs(int u, long long flow)
{
    if (u == t || flow == 0)
        return flow;

    long long rest = flow; // 还能流过的流量
    for (int &i = cur[u]; ~i; i = edges[i].next)
    { // 当前弧优化
        int v = edges[i].to;
        if (level[v] == level[u] + 1 && edges[i].cap > 0)
        {
            long long k = dfs(v, min(rest, edges[i].cap));
            if (k > 0)
            {
                edges[i].cap -= k;
                edges[i ^ 1].cap += k; // 增加反向边的流量
                rest -= k;
                if (rest == 0)
                    break;
            }
        }
    }

    return flow - rest;
}

// Dinic算法计算最大流
long long dinic()
{
    long long maxFlow = 0;
    while (bfs())
    {
        // 复制head数组到cur数组，用于当前弧优化
        memcpy(cur, head, sizeof(head));
        long long flow;
        while ((flow = dfs(s, INF)) > 0)
        {
            maxFlow += flow;
        }
    }
    return maxFlow;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s >> t;

    // 初始化邻接表
    memset(head, -1, sizeof(head));
    tot = 0;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        addEdge(u, v, c);
    }

    // 计算最大流
    long long maxFlow = dinic();

    cout << maxFlow << endl;

    return 0;
}
