// 2023-05-B 矩阵运算
//?
//? 利用结合律改变计算顺序来节省内存
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

    // 用全局 vector，比变长数组更安全（不会爆栈）
    vector<vector<ll>> Q(n, vector<ll>(d));
    vector<vector<ll>> K(n, vector<ll>(d));
    vector<vector<ll>> V(n, vector<ll>(d));
    vector<ll> W(n);

    // 读入 Q
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j)
            cin >> Q[i][j];

    // 读入 K
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j)
            cin >> K[i][j];

    // 读入 V
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < d; ++j)
            cin >> V[i][j];

    // 读入 W
    for (int i = 0; i < n; ++i)
        cin >> W[i];

    // --- 关键优化：改变运算顺序，避免 O(n^2) 内存 ---

    // 第一步：计算 M[t][j] = Σ_k (K[k][t] * V[k][j])
    // M 是 d × d 的小矩阵，内存极小
    vector<vector<ll>> M(d, vector<ll>(d, 0));
    for (int t = 0; t < d; ++t)
    {
        for (int j = 0; j < d; ++j)
        {
            ll sum = 0;
            for (int k = 0; k < n; ++k)
            {
                sum += K[k][t] * V[k][j];
            }
            M[t][j] = sum;
        }
    }

    // 第二步：计算结果矩阵 ans[i][j] = W[i] * Σ_t (Q[i][t] * M[t][j])
    // ans 是 n × d，大小 n*d = 2e5，完全够用
    vector<vector<ll>> ans(n, vector<ll>(d, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < d; ++j)
        {
            ll sum = 0;
            for (int t = 0; t < d; ++t)
            {
                sum += Q[i][t] * M[t][j];
            }
            ans[i][j] = sum * W[i]; // 乘以 W 的第 i 个元素
        }
    }

    // 输出结果
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < d; ++j)
        {
            cout << ans[i][j];
            if (j != d - 1)
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}