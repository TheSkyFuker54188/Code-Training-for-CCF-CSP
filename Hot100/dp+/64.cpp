#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 80000));

    dp[1][0] = 0;
    dp[1][1] = a[1][1];

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                continue;

            dp[i][j] = min(dp[i][j - 1] + a[i][j], dp[i - 1][j] + a[i][j]);
        }
    }
    cout << dp[m][n];
}