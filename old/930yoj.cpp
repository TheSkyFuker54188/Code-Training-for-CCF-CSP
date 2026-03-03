#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> stones(n);
    for (int i = 0; i < n; ++i) {
        cin >> stones[i];
    }

    // 处理环形问题，扩展数组为两倍长度
    vector<int> extended(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        extended[i] = stones[i % n];
    }

    // 前缀和数组
    vector<int> prefix(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = prefix[i - 1] + extended[i - 1];
    }

    // DP数组初始化
    vector<vector<int>> dp_min(2 * n, vector<int>(2 * n, INT_MAX));
    vector<vector<int>> dp_max(2 * n, vector<int>(2 * n, INT_MIN));

    for (int i = 0; i < 2 * n; ++i) {
        dp_min[i][i] = 0;
        dp_max[i][i] = 0;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < 2 * n; ++i) {
            int j = i + len - 1;
            int sum_ij = prefix[j + 1] - prefix[i];
            for (int k = i; k < j; ++k) {
                dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] + dp_min[k + 1][j] + sum_ij);
                dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] + dp_max[k + 1][j] + sum_ij);
            }
        }
    }

    int min_score = INT_MAX;
    int max_score = INT_MIN;
    for (int i = 0; i < n; ++i) {
        int j = i + n - 1;
        min_score = min(min_score, dp_min[i][j]);
        max_score = max(max_score, dp_max[i][j]);
    }

    cout << min_score << endl;
    cout << max_score << endl;

    return 0;
}