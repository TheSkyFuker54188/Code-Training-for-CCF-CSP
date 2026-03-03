#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// BFS函数
vector<int> bfs(int n, const vector<vector<int>>& adj) {
    vector<int> visited(n + 1, 0); // 标记节点是否访问
    vector<int> result;           // 保存遍历顺序
    queue<int> q;                 // BFS 队列

    q.push(1);        // 从编号为1的节点开始
    visited[1] = 1;   // 标记节点1为已访问

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);

        // 遍历当前节点的邻居
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1; // 标记为已访问
                q.push(neighbor);      // 加入队列
            }
        }
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    // 构建邻接表
    vector<vector<int>> adj(n + 1); // 邻接表（1-based indexing）
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    // 对邻接表的每个节点的邻居进行排序
    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    // 执行BFS并获取结果
    vector<int> traversal = bfs(n, adj);

    // 输出结果
    for (int node : traversal) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
