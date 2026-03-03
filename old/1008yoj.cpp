#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 读入数据
    int n;
    cin >> n;
    
    vector<int> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i];
    }
    
    // 排序
    sort(points.begin(), points.end());
    
    // 找出最大间隙
    int maxGap = 0;
    for(int i = 1; i < n; i++) {
        int currentGap = points[i] - points[i-1];
        maxGap = max(maxGap, currentGap);
    }
    
    cout << maxGap << endl;
    
    return 0;
}