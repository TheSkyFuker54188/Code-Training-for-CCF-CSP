// 2013年12月 第D题
// 算法 + 数据结构）

#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

const int max_length = 1 + 1000;

int T;
// dp[i][j] 表示前 i 位数，组合出状态 j 的方案数
long long dp[max_length][6];
/*
状态 0（仅有2）：目前出现过的数字只有 2。
状态 1（有2, 0）：目前只有 2 和 0。
状态 2（有2, 3）：目前只有 2 和 3。
状态 3（有2, 0, 3）：目前集齐了 2, 0, 3，还差 1。
状态 4（有2, 0, 1）：目前集齐了 2, 0, 1，还差 3。
状态 5（满状态 2, 0, 1, 3）：四种数字全齐了
*/

void init()
{
    dp[1][0] = 1;
    for (int i = 1; i < 1000; i++)
    {
        dp[i + 1][0] = (dp[i][0] * 1) % MOD;
        dp[i + 1][1] = (dp[i][1] * 2 + dp[i][0] * 1) % MOD;
        dp[i + 1][2] = (dp[i][2] * 1 + dp[i][0] * 1) % MOD;
        dp[i + 1][3] = (dp[i][3] * 2 + dp[i][1] * 1 + dp[i][2] * 1) % MOD;
        dp[i + 1][4] = (dp[i][4] * 2 + dp[i][1] * 1) % MOD;
        dp[i + 1][5] = (dp[i][5] * 2 + dp[i][4] * 1 + dp[i][3] * 1) % MOD;
    }
}

int main()
{
    init();

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        cout << dp[n][5] << endl;
    }
    return 0;
}