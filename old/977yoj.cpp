#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DFS函数
void dfs(int node, const vector<vector<int>>& adj, vector<int>& visited, vector<int>& result) {
    visited[node] = 1;       // 标记当前节点为已访问
    result.push_back(node);  // 记录当前节点

    // 遍历当前节点的邻居
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) { // 如果未访问，递归调用DFS
            dfs(neighbor, adj, visited, result);
        }
    }
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

    // 初始化访问记录和结果
    vector<int> visited(n + 1, 0); // 记录节点是否已访问
    vector<int> result;            // 存储DFS遍历结果

    // 从编号为1的节点开始DFS
    dfs(1, adj, visited, result);

    // 输出结果
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
