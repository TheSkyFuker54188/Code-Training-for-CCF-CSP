// 2014年12月 第D题
// 最小生成树（Kruskal + 并查集）

// CSP14-12D 灌溉：最小生成树（Kruskal + 并查集）
// “连通所有点且总边权最小”
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    int u, v, w;
    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }
};

struct DSU
{
    vector<int> parent, size;

    DSU(int n) : parent(n + 1), size(n + 1, 1)
    {
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long ans = 0;
    int chosen = 0;

    for (const auto &e : edges)
    {
        if (dsu.unite(e.u, e.v))
        {
            ans += e.w;
            ++chosen;
            if (chosen == n - 1)
                break;
        }
    }

    // 题目一般默认可连通；这里做稳妥兜底
    if (chosen < n - 1)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }

    return 0;
}