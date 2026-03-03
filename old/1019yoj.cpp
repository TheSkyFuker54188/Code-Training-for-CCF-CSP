#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Graph
{
private:
    int V;
    vector<vector<int>> adj;
    vector<int> disc, low;
    vector<bool> visited;
    int time;
    vector<pair<int, int>> bridges;
    set<int> components[5001];
    int compCount;

    void bridgeDFS(int u, int parent)
    {
        visited[u] = true;
        disc[u] = low[u] = ++time;

        for (int v : adj[u])
        {
            if (v == parent)
                continue;

            if (!visited[v])
            {
                bridgeDFS(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u])
                {
                    bridges.push_back({u, v});
                }
            }
            else
            {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    void findComponents(int u, int comp)
    {
        visited[u] = true;
        components[comp].insert(u);

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                bool isBridge = false;
                for (auto &bridge : bridges)
                {
                    if ((bridge.first == u && bridge.second == v) ||
                        (bridge.first == v && bridge.second == u))
                    {
                        isBridge = true;
                        break;
                    }
                }
                if (!isBridge)
                {
                    findComponents(v, comp);
                }
            }
        }
    }

public:
    Graph(int vertices) : V(vertices)
    {
        adj.resize(V + 1);
        disc.resize(V + 1);
        low.resize(V + 1);
        visited.resize(V + 1);
        time = 0;
        compCount = 0;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int findMinNewEdges()
    {
        // 找桥
        visited.assign(V + 1, false);
        bridges.clear();
        time = 0;

        for (int i = 1; i <= V; i++)
        {
            if (!visited[i])
            {
                bridgeDFS(i, -1);
            }
        }

        // 找双连通分量
        visited.assign(V + 1, false);
        compCount = 0;

        for (int i = 1; i <= V; i++)
        {
            if (!visited[i])
            {
                findComponents(i, compCount++);
            }
        }

        if (compCount <= 1)
            return 0;

        // 计算每个分量的度数（与其他分量相连的桥的数量）
        vector<int> degree(compCount, 0);
        for (auto &bridge : bridges)
        {
            int comp1 = -1, comp2 = -1;
            for (int i = 0; i < compCount; i++)
            {
                if (components[i].count(bridge.first))
                    comp1 = i;
                if (components[i].count(bridge.second))
                    comp2 = i;
            }
            if (comp1 != comp2)
            {
                degree[comp1]++;
                degree[comp2]++;
            }
        }

        // 计算叶子节点的数量（度数为1的分量）
        int leaves = 0;
        for (int i = 0; i < compCount; i++)
        {
            if (degree[i] == 1)
                leaves++;
        }

        return (leaves + 1) / 2;
    }
};

int main()
{
    int F, R;
    cin >> F >> R;

    Graph g(F);
    for (int i = 0; i < R; i++)
    {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }

    cout << g.findMinNewEdges() << endl;
    return 0;
}