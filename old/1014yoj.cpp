#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> calculateErdosNumber(int n, int m, vector<pair<int, int>> &edges)
{
    // 构建邻接表
    vector<vector<int>> graph(n + 1);
    for (const auto &edge : edges)
    {
        int v1 = edge.first, v2 = edge.second;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    // 初始化Erdös Number数组，所有人初始为-1
    vector<int> erdosNumber(n + 1, -1);
    queue<int> q;

    // Erdös 的编号为 1，Erdös Number 为 0
    erdosNumber[1] = 0;
    q.push(1);

    // BFS 计算 Erdös Number
    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current])
        {
            if (erdosNumber[neighbor] == -1)
            { // 未访问过的节点
                erdosNumber[neighbor] = erdosNumber[current] + 1;
                q.push(neighbor);
            }
        }
    }

    // 返回结果数组（忽略编号为 0 的节点）
    return vector<int>(erdosNumber.begin() + 1, erdosNumber.end());
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

    vector<int> result = calculateErdosNumber(n, m, edges);

    for (int i = 0; i < result.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}
