#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canRemove(const vector<int>& points, int m, int mid) {
    int count = 0;
    int last = 0; // 左边界点
    for (int i = 0; i < points.size(); ++i) {
        if (points[i] - last < mid) {
            count++; // 需要删除当前点
        } else {
            last = points[i]; // 更新上一个点的位置
        }
        if (count > m) {
            return false;
        }
    }
    return true;
}

int findMaxMinDistance(int L, int N, int M, vector<int>& points) {
    int left = 0;
    int right = L;
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canRemove(points, M, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int L, N, M;
    cin >> L >> N >> M;
    vector<int> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i];
    }

    int result = findMaxMinDistance(L, N, M, points);
    cout << result << endl;

    return 0;
}