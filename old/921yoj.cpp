#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
vector<vector<int>> g, gr;
vector<bool> used;
vector<int> order, comp;
vector<int> scc_id;
int scc_cnt = 0;

// 1. 第一遍 DFS，记录后序
void dfs1(int u) {
    used[u] = true;
    for (int v : g[u]) if (!used[v]) 
        dfs1(v);
    order.push_back(u);
}

// 2. 第二遍 DFS，在逆图上为每个 SCC 编号
void dfs2(int u) {
    used[u] = true;
    comp.push_back(u);
    for (int v : gr[u]) if (!used[v])
        dfs2(v);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    g.assign(N+1, {});
    gr.assign(N+1, {});
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    // 每个路口的银行现金
    vector<ll> cash(N+1);
    for (int i = 1; i <= N; i++){
        cin >> cash[i];
    }

    int S, P;
    cin >> S >> P;
    vector<int> bars(P);
    for (int i = 0; i < P; i++) {
        cin >> bars[i];
    }

    // Kosaraju 找 SCC
    used.assign(N+1, false);
    for (int u = 1; u <= N; u++){
        if (!used[u]) dfs1(u);
    }

    used.assign(N+1, false);
    scc_id.assign(N+1, 0);
    // 按 reverse 后序遍历
    for (int i = N-1; i >= 0; i--){
        int u = order[i];
        if (!used[u]){
            comp.clear();
            dfs2(u);
            ++scc_cnt;
            for (int x : comp){
                scc_id[x] = scc_cnt;
            }
        }
    }

    // 3. 统计每个 SCC 的总现金
    vector<ll> scc_cash(scc_cnt+1, 0);
    for (int u = 1; u <= N; u++){
        scc_cash[scc_id[u]] += cash[u];
    }

    // 4. 建立 SCC-DAG，去重边
    vector<vector<int>> dag(scc_cnt+1);
    vector<unordered_set<int>> seen(scc_cnt+1);
    for (int u = 1; u <= N; u++){
        int cu = scc_id[u];
        for (int v : g[u]){
            int cv = scc_id[v];
            if (cu != cv && !seen[cu].count(cv)){
                dag[cu].push_back(cv);
                seen[cu].insert(cv);
            }
        }
    }

    // 5. 在 DAG 上做从 start 出发的可达性 BFS，提取可达子图
    int sc = scc_id[S];
    vector<bool> reach(scc_cnt+1, false);
    queue<int> q;
    reach[sc] = true;
    q.push(sc);
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int v : dag[u]){
            if (!reach[v]){
                reach[v] = true;
                q.push(v);
            }
        }
    }

    // 6. 计算可达子图内部的入度
    vector<int> indeg(scc_cnt+1, 0);
    for (int u = 1; u <= scc_cnt; u++){
        if (!reach[u]) continue;
        for (int v : dag[u]){
            if (reach[v]) indeg[v]++;
        }
    }

    // 7. 拓扑排序 + DP 维护从 sc 到每个节点的最大现金
    const ll NEG_INF = LLONG_MIN/4;
    vector<ll> dp(scc_cnt+1, NEG_INF);
    dp[sc] = scc_cash[sc];

    queue<int> topo;
    // 可达子图中入度为 0 的点入队（注意 sc 的入度可能不是 0，也要等它的前驱处理完）
    for (int u = 1; u <= scc_cnt; u++){
        if (reach[u] && indeg[u] == 0) {
            topo.push(u);
        }
    }

    while (!topo.empty()){
        int u = topo.front(); topo.pop();
        // 如果 u 可达且 dp[u] 非负无穷
        if (dp[u] > NEG_INF) {
            for (int v : dag[u]){
                if (!reach[v]) continue;
                dp[v] = max(dp[v], dp[u] + scc_cash[v]);
                if (--indeg[v] == 0) topo.push(v);
            }
        }
    }

    // 8. 在所有酒吧所在的 SCC 中取最大
    ll ans = 0;
    for (int b : bars){
        int cb = scc_id[b];
        if (reach[cb]) {
            ans = max(ans, dp[cb]);
        }
    }

    cout << ans << "\n";
    return 0;
}
