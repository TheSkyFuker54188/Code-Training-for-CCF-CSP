#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;

int n, m;
vector<int> g[MAXN + 1];

// Tarjan’s SCC
int dfn[MAXN + 1], low[MAXN + 1], scc_id[MAXN + 1], dfsTime = 0, scc_cnt = 0;
bool inStack[MAXN + 1];
stack<int> stk;

void tarjan(int u) {
    dfn[u] = low[u] = ++dfsTime;
    stk.push(u);
    inStack[u] = true;
    for (int v : g[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++scc_cnt;
        while (1) {
            int x = stk.top(); stk.pop();
            inStack[x] = false;
            scc_id[x] = scc_cnt;
            if (x == u) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    // each person implicitly votes for themselves, but self-edges don't change SCC structure

    // 1. Find SCCs
    for (int u = 1; u <= n; u++) {
        if (!dfn[u]) tarjan(u);
    }

    if (scc_cnt == 1) {
        // Whole graph is one SCC: every node reachable from every other
        cout << n << "\n";
        return 0;
    }

    // 2. Build SCC-DAG
    vector<set<int>> dag(scc_cnt + 1), dag_rev(scc_cnt + 1);
    vector<int> sz(scc_cnt + 1, 0), outdeg(scc_cnt + 1, 0);
    for (int u = 1; u <= n; u++) {
        sz[scc_id[u]]++;
        for (int v : g[u]) {
            int cu = scc_id[u], cv = scc_id[v];
            if (cu != cv) {
                if (!dag[cu].count(cv)) {
                    dag[cu].insert(cv);
                    dag_rev[cv].insert(cu);
                    outdeg[cu]++;
                }
            }
        }
    }

    // 3. Find sink SCCs (outdegree zero)
    vector<int> sinks;
    for (int c = 1; c <= scc_cnt; c++) {
        if (outdeg[c] == 0) sinks.push_back(c);
    }
    if (sinks.size() != 1) {
        cout << 0 << "\n";
        return 0;
    }
    int sink = sinks[0];

    // 4. Check if sink is reachable from all SCCs via reversed DAG
    vector<bool> vis(scc_cnt + 1, false);
    queue<int> q;
    vis[sink] = true;
    q.push(sink);
    int reached = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        reached++;
        for (int v : dag_rev[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    if (reached != scc_cnt) {
        cout << 0 << "\n";
    } else {
        // All SCCs can reach the sink SCC
        cout << sz[sink] << "\n";
    }

    return 0;
}
