#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> dims(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> dims[i] >> dims[i + 1];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = 1e18;
            for (int k = i; k < j; ++k) {
                ll cost = dp[i][k] + dp[k + 1][j] + (ll)dims[i] * dims[k + 1] * dims[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}