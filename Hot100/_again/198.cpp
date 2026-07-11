#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int x;
    vector<int> a;
    a.push_back(0);
    while (cin >> x)
        a.push_back(x);

    int n = a.size();
    // int ans = 0;
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = a[1];

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    }
    cout << dp[n-1];
}