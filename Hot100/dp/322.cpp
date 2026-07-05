#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int ans;
    int t;
    vector<int> a;
    int x;
    while (cin >> x)
    {
        a.push_back(x);
    }
    t = a.back();
    a.pop_back();

    vector<int> dp(t + 1, t+1);
    dp[0] = 0;

    for (int i = 1; i <= t; i++)
    {
        for (auto c : a)
        {
            if (c > i)
                continue;
            dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
    if (dp[t] == t + 1)
        dp[t] = -1;
    cout << dp[t];
}