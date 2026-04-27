// 2020-9-C 点亮数字人生
// 拓扑排序 + 电路模拟
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

enum GateType
{
    G_NOT = 0,
    G_AND,
    G_OR,
    G_XOR,
    G_NAND,
    G_NOR
};

int parseGateType(const string &name)
{
    if (name == "NOT")
        return G_NOT;
    if (name == "AND")
        return G_AND;
    if (name == "OR")
        return G_OR;
    if (name == "XOR")
        return G_XOR;
    if (name == "NAND")
        return G_NAND;
    return G_NOR;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q--)
    {
        int M, N;
        cin >> M >> N;

        vector<int> gateType(N + 1);
        vector<vector<pair<int, int>>> inputs(N + 1); // {0, m}=Im, {1, n}=On
        vector<vector<int>> graph(N + 1);
        vector<int> indeg(N + 1, 0);

        for (int i = 1; i <= N; i++)
        {
            string func;
            int k;
            cin >> func >> k;
            gateType[i] = parseGateType(func);
            inputs[i].reserve(k);

            for (int j = 0; j < k; j++)
            {
                string label;
                cin >> label;
                int idx = stoi(label.substr(1));

                if (label[0] == 'I')
                {
                    inputs[i].push_back({0, idx});
                }
                else
                {
                    inputs[i].push_back({1, idx});
                    graph[idx].push_back(i);
                    indeg[i]++;
                }
            }
        }

        int S;
        cin >> S;

        vector<vector<int>> runInputs(S, vector<int>(M + 1, 0));
        for (int i = 0; i < S; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                cin >> runInputs[i][j];
            }
        }

        vector<vector<int>> queries(S);
        for (int i = 0; i < S; i++)
        {
            int si;
            cin >> si;
            queries[i].resize(si);
            for (int j = 0; j < si; j++)
            {
                cin >> queries[i][j];
            }
        }

        queue<int> q;
        vector<int> deg = indeg;
        for (int i = 1; i <= N; i++)
        {
            if (deg[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        topo.reserve(N);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (int v : graph[u])
            {
                if (--deg[v] == 0)
                {
                    q.push(v);
                }
            }
        }

        if ((int)topo.size() != N)
        {
            cout << "LOOP\n";
            continue;
        }

        vector<int> outVal(N + 1, 0);
        for (int r = 0; r < S; r++)
        {
            for (int u : topo)
            {
                int t = gateType[u];

                auto getInputValue = [&](const pair<int, int> &src) -> int
                {
                    if (src.first == 0)
                    {
                        return runInputs[r][src.second];
                    }
                    return outVal[src.second];
                };

                if (t == G_NOT)
                {
                    outVal[u] = 1 - getInputValue(inputs[u][0]);
                }
                else if (t == G_AND || t == G_NAND)
                {
                    int v = 1;
                    for (const auto &src : inputs[u])
                    {
                        v &= getInputValue(src);
                    }
                    outVal[u] = (t == G_AND ? v : 1 - v);
                }
                else if (t == G_OR || t == G_NOR)
                {
                    int v = 0;
                    for (const auto &src : inputs[u])
                    {
                        v |= getInputValue(src);
                    }
                    outVal[u] = (t == G_OR ? v : 1 - v);
                }
                else
                {
                    int v = 0;
                    for (const auto &src : inputs[u])
                    {
                        v ^= getInputValue(src);
                    }
                    outVal[u] = v;
                }
            }

            int sz = (int)queries[r].size();
            for (int i = 0; i < sz; i++)
            {
                if (i)
                    cout << ' ';
                cout << outVal[queries[r][i]];
            }
            cout << '\n';
        }
    }

    return 0;
}