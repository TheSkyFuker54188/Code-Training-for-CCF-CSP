#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 拓扑排序函数
vector<int> topologicalSort(int n, int m, vector<pair<int, int>> &edges)
{
    // 初始化邻接表和入度数组
    vector<vector<int>> adjList(n + 1); // 邻接表
    vector<int> inDegree(n + 1, 0);     // 入度数组

    // 构建图
    for (auto &edge : edges)
    {
        int v1 = edge.first, v2 = edge.second;
        adjList[v1].push_back(v2);
        inDegree[v2]++;
    }

    // 小根堆存储当前入度为 0 的节点
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            minHeap.push(i);
        }
    }

    // 拓扑排序结果
    vector<int> result;
    while (!minHeap.empty())
    {
        int current = minHeap.top();
        minHeap.pop();
        result.push_back(current);

        // 遍历当前节点的邻居，更新入度
        for (int neighbor : adjList[current])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                minHeap.push(neighbor);
            }
        }
    }

    return result;
}

int main()
{
    // 输入
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].first >> edges[i].second;
    }

    // 计算拓扑排序
    vector<int> result = topologicalSort(n, m, edges);

    // 输出结果
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
