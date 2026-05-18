// 2023-05-B 矩阵运算
//? 利用结合律改变计算顺序来节省内存
#include <iostream>
#include <cstring>   // 提供 memset 原型
using namespace std;

typedef long long ll;

const int MAX_N = 10000;   // 题目 n 最大 1e4
const int MAX_D = 20;      // d 最大 20

// 大数组放在全局区，避免爆栈
int Q[MAX_N][MAX_D];
int K[MAX_N][MAX_D];
int V[MAX_N][MAX_D];
ll ans[MAX_N][MAX_D];      // 结果矩阵用 long long 防溢出
int W[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

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

    // ====== 关键优化：先算 d×d 的小矩阵 M ======
    // M[t][j] = Σ_k K[k][t] * V[k][j]
    // 这个矩阵只需要 d×d 大小，非常小
    ll M[MAX_D][MAX_D] = {{0}};  // 局部二维数组 d×d 栈上没问题

    for (int t = 0; t < d; ++t) {
        for (int j = 0; j < d; ++j) {
            ll sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += (ll)K[k][t] * V[k][j];
            }
            M[t][j] = sum;
        }
    }

    // ====== 第二步：用 M 和 Q 直接算出最终答案 ======
    // ans[i][j] = W[i] * Σ_t Q[i][t] * M[t][j]
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            ll sum = 0;
            for (int t = 0; t < d; ++t) {
                sum += (ll)Q[i][t] * M[t][j];
            }
            ans[i][j] = sum * W[i];
        }
    }

    // 输出
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            cout << ans[i][j];
            if (j != d - 1) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}