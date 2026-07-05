#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    dp[1][1] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    cout << dp[m][n];
}