// 2022-9-B 何以包邮？
// DP / 背包问题
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int a[n];

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >= a[i]; j--)
        {
            if (dp[j - a[i]])
                dp[j] = true;
        }
    }

    for (int i = x; i <= sum; i++)
    {
        if (dp[i])
        {
            cout << i;
            break;
        }
    }
}