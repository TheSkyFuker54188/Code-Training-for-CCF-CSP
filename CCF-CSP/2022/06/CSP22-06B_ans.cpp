// 2022-6-B 寻宝！大冒险！
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    int n, L, S;
    cin >> n >> L >> S;

    vector<pair<int, int>> A;
    // < x , y >
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        A.push_back(make_pair(x, y));
    }

    // 藏宝图 B，存储完整的S*S矩阵即可
    vector<vector<int>> B(S + 1, vector<int>(S + 1));
    int b_cnt = 0; // 记录藏宝图里有几棵树
    for (int i = S; i >= 0; i--)
    {
        for (int j = 0; j <= S; j++)
        {
            cin >> B[i][j];
            if (B[i][j] == 1)
                b_cnt++;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int tx = A[i].first;
        int ty = A[i].second;
        // 边界检查：如果把这棵树作为左下角，是否会越过大地图边界
        if (tx + S > L || ty + S > L)
            continue;

        bool fail = false;
        int tree_in_box = 0; // 统计实际落在这个范围内的树的数量

        for (int j = 0; j < n; j++)
        {
            int dx = A[j].first - tx;
            int dy = A[j].second - ty;

            // 如果树落在藏宝图的范围内
            if (dx >= 0 && dx <= S && dy >= 0 && dy <= S)
            {
                if (B[dx][dy] == 0) // 藏宝图说这个位置没树，但实际上有树 -> 失败
                {
                    fail = true;
                    break;
                }
                tree_in_box++;
            }
        }
        // 如果没有没冲突的树，且树的总数目跟藏宝图中的树的数目相等
        if (!fail && tree_in_box == b_cnt)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}