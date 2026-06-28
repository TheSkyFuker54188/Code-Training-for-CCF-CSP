#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> dp(n);

    int ans = nums[0];
    dp[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (dp[i - 1] > 0)
            dp[i] = dp[i - 1] + nums[i];
        else
            dp[i] = nums[i];

        ans = max(ans, dp[i]);
    }
    cout << ans;
}