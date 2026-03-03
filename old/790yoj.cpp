#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<pair<int, int>> points(n);
    for (auto& p : points) {
        cin >> p.first >> p.second;
    }
    
    // 对点按照x坐标排序，便于二分查找
    sort(points.begin(), points.end());
    
    int q; cin >> q;
    while (q--) {
        int x0, x1, y0, y1;
        cin >> x0 >> x1 >> y0 >> y1;
        
        // 使用二分查找找出x坐标范围内的点的边界
        auto lower = lower_bound(points.begin(), points.end(), make_pair(x0, -1));
        auto upper = upper_bound(points.begin(), points.end(), make_pair(x1, INT_MAX));
        
        // 只检查x范围内的点的y坐标
        int count = 0;
        for (auto it = lower; it != upper; ++it) {
            if (y0 <= it->second && it->second <= y1) {
                count++;
            }
        }
        
        cout << count << '\n';
    }
    
    return 0;
}
