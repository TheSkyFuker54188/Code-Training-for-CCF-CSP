#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;

const int MAXN = 505;
vector<int> G[MAXN]; // 邻接表
int dfn[MAXN], low[MAXN], timestamp;
bool isCut[MAXN];          // 标记割点
stack<pair<int, int>> stk; // 边栈
vector<vector<int>> bcc;   // 存储双连通分量
int bcc_id[MAXN];          // 节点所属的双连通分量
vector<int> bct[MAXN];     // 块割树的邻接表
int n_nodes;               // 最大节点编号

// Tarjan算法找割点和双连通分量
void tarjan(int u, int parent)
{
    dfn[u] = low[u] = ++timestamp;
    int child = 0;

    // 使用集合保存已访问的邻接点，避免重复处理
    vector<int> visited;

    for (int v : G[u])
    {
        // 跳过自环
        if (v == u)
            continue;

        // 如果是父节点，且已访问过，跳过
        if (v == parent && find(visited.begin(), visited.end(), v) != visited.end())
            continue;

        if (v == parent)
            visited.push_back(v);

        if (!dfn[v])
        {
            child++;
            stk.push({u, v});
            tarjan(v, u);
            low[u] = min(low[u], low[v]);

            // 找到一个双连通分量
            if (low[v] >= dfn[u])
            {
                if (parent != -1 || child > 1)
                {
                    isCut[u] = true; // u是割点
                }

                vector<int> component;
                pair<int, int> edge;
                do
                {
                    edge = stk.top();
                    stk.pop();
                    if (find(component.begin(), component.end(), edge.first) == component.end())
                        component.push_back(edge.first);
                    if (find(component.begin(), component.end(), edge.second) == component.end())
                        component.push_back(edge.second);
                } while (edge.first != u || edge.second != v);

                bcc.push_back(component);
            }
        }
        else if (dfn[v] < dfn[u])
        {
            stk.push({u, v});
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void buildBlockCutTree()
{
    // 为每个双连通分量分配一个ID
    map<int, vector<int>> cutToBcc;

    for (int i = 0; i < bcc.size(); i++)
    {
        for (int node : bcc[i])
        {
            if (isCut[node])
            {
                cutToBcc[node].push_back(i);
            }
        }
    }

    // 构建块割树
    for (auto &[cut, bccs] : cutToBcc)
    {
        for (int i = 0; i < bccs.size(); i++)
        {
            int bccId = bccs[i];
            bct[cut].push_back(bccId + n_nodes);
            bct[bccId + n_nodes].push_back(cut);
        }
    }
}

// 计算最少救援出口数量和方案数
pair<int, ll> solve_case()
{
    // 如果图是单个点，返回(1, 1)
    if (n_nodes == 1)
        return {1, 1};

    // 对于一个双连通分量的特殊处理
    if (bcc.size() == 1)
    {
        bool hasCut = false;
        for (int i = 1; i <= n_nodes; i++)
            if (isCut[i])
                hasCut = true;

        if (!hasCut) // 真正的双连通图
        {
            return {2, (1LL * n_nodes * (n_nodes - 1)) / 2};
        }
        else // 树
        {
            int leaves = 0;
            for (int i = 1; i <= n_nodes; i++)
            {
                if (G[i].size() == 1)
                    leaves++;
            }
            return {leaves, 1};
        }
    }

    // 统计每个双连通分量中的割点数量
    vector<int> cut_in_bcc(bcc.size(), 0);
    vector<int> non_cut_in_bcc(bcc.size(), 0);

    for (int i = 0; i < bcc.size(); i++)
    {
        for (int node : bcc[i])
        {
            if (isCut[node])
                cut_in_bcc[i]++;
            else
                non_cut_in_bcc[i]++;
        }
    }

    // 识别叶子块(只有一个割点的块)
    int min_exits = 0;
    ll ways = 1;

    for (int i = 0; i < bcc.size(); i++)
    {
        if (cut_in_bcc[i] == 1)
        {
            // 叶子块，必须在这个块里选一个非割点作为出口
            min_exits++;
            ways *= non_cut_in_bcc[i];
        }
    }

    // 如果没有找到叶子块，则至少需要2个救援出口
    if (min_exits == 0)
    {
        // 计算所有可能的选择2个节点的方式
        int total_non_cut = 0;
        for (int i = 1; i <= n_nodes; i++)
            if (!isCut[i])
                total_non_cut++;

        return {2, (1LL * total_non_cut * (total_non_cut - 1)) / 2};
    }

    return {min_exits, ways};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int case_num = 0;
    while (true)
    {
        int edges;
        cin >> edges;
        if (edges == 0)
            break;

        case_num++;

        // 初始化
        for (int i = 0; i < MAXN; i++)
        {
            G[i].clear();
            bct[i].clear();
        }
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(isCut, 0, sizeof(isCut));
        memset(bcc_id, -1, sizeof(bcc_id));
        while (!stk.empty())
            stk.pop();
        bcc.clear();
        timestamp = 0;
        n_nodes = 0;

        // 构建图
        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
            n_nodes = max(n_nodes, max(u, v));
        }

        // 运行Tarjan算法
        for (int i = 1; i <= n_nodes; i++)
        {
            if (!dfn[i])
            {
                tarjan(i, -1);
            }
        }

        // 构建块割树
        buildBlockCutTree();

        // 计算结果
        auto [min_exits, ways] = solve_case();

        cout << "Case " << case_num << ": " << min_exits << " " << ways << endl;
    }

    return 0;
}
