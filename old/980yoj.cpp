#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void zeroOutdegreeTopologicalSort(int n, int m, vector<pair<int, int>> &edges)
{
    // 构建邻接表并初始化入度计数
    vector<vector<int>> graph(n + 1); // 邻接表
    vector<int> indegree(n + 1, 0);   // 入度数组

    for (const auto &edge : edges)
    {
        int v1 = edge.first, v2 = edge.second;
        graph[v1].push_back(v2); // v1 -> v2
        indegree[v2]++;          // v2 的入度加一
    }

    // 小根堆存储零入度节点（保证编号较小优先）
    priority_queue<int, vector<int>, greater<int>> zeroIndegreeNodes;
    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i] == 0)
        {
            zeroIndegreeNodes.push(i);
        }
    }

    vector<int> result; // 存储拓扑排序结果

    // 拓扑排序主过程
    while (!zeroIndegreeNodes.empty())
    {
        int node = zeroIndegreeNodes.top();
        zeroIndegreeNodes.pop();
        result.push_back(node);

        // 遍历当前节点的出边并更新其邻接点的入度
        for (int neighbor : graph[node])
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
            {
                zeroIndegreeNodes.push(neighbor);
            }
        }
    }

    // 输出结果
    for (int i = 0; i < result.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << result[i];
    }
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    zeroOutdegreeTopologicalSort(n, m, edges);

    return 0;
}
