// 2014年12月 第D题
// 最小生成树（Kruskal + 并查集）
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge
{
    int u, v, w; // u --w--> v
    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }
};

struct DSU
{
    vector<int> parent; // 我的根节点
    vector<int> size;   // 我所在连通块大小

    DSU(int n) : parent(n + 1), size(n + 1, 1)
    {
        for (int i = 1; i <= n; i++)
            parent[i] = i; // 根节点初始化为自己
    }

    int find(int x) // 找我的根节点
    {
        if (parent[x] == x)
            return x;

        parent[x] = find(parent[x]); //? 路径压缩
        return parent[x];
    }

    bool unite(int a, int b) // 尝试合并可修边的a与b，返回连接是否需要加边
    {
        a = find(a);
        b = find(b);

        if (a == b) // 同根，即已连通
            return false;
        if (size[a] < size[b]) // 强制连通块大小顺序, a > b
            swap(a, b);

        parent[b] = a;      // 小块的根，设置为大块的根。也就完成了合并（小树认大根，即并入大树）
        size[a] += size[b]; // 顺便更新下块大小
        return true;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end()); // 由于已经为Edge类型重载过"<"，故可直接sort

    DSU dsu(n);
    long long ans = 0;
    int chosen = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        if (dsu.unite(edges[i].u, edges[i].v)) // unite返回true，则此两可选择；否则已选择，不必管
        {
            ans += edges[i].w;
            chosen++;
        }

        // 剪枝，如果已选n-1个渠，必然全图联通，可提前终止
        if (chosen == n - 1)
            break;
    }

    if (chosen < n - 1)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}