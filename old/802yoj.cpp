#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int l, r, w;
};

bool compare(const Interval &a, const Interval &b) {
    return a.r < b.r;
}

int findLastNonOverlapping(const vector<Interval> &intervals, int index) {
    int low = 0, high = index - 1;
    int target = intervals[index].l;
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (intervals[mid].r <= target) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Interval> intervals(n);
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].l >> intervals[i].r >> intervals[i].w;
    }

    sort(intervals.begin(), intervals.end(), compare);

    vector<int> dp(n, 0);
    dp[0] = intervals[0].w;

    for (int i = 1; i < n; ++i) {
        int currentWeight = intervals[i].w;
        int j = findLastNonOverlapping(intervals, i);
        if (j != -1) {
            currentWeight += dp[j];
        }
        dp[i] = max(currentWeight, dp[i-1]);
    }

    cout << dp[n-1] << endl;

    return 0;
}