// 2019-12-B 回收站选址
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 提升 cin/cout 速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].first >> points[i].second;
    }

    // 将坐标排序，方便后续利用二分法快速查找 (O(logN)时间复杂度)
    sort(points.begin(), points.end());
    //? C++ 内部默认的 pair 比较规则是：先比较 first，如果 first 相等，再比较 second
    int ans[5] = {0};

    // 遍历每一个垃圾点，判断能否作为回收站
    for (int i = 0; i < n; ++i)
    {
        int x = points[i].first;
        int y = points[i].second;

        // 检查上下左右是否有垃圾
        bool up = binary_search(points.begin(), points.end(), make_pair(x, y + 1));
        bool down = binary_search(points.begin(), points.end(), make_pair(x, y - 1));
        bool left = binary_search(points.begin(), points.end(), make_pair(x - 1, y));
        bool right = binary_search(points.begin(), points.end(), make_pair(x + 1, y));

        if (up && down && left && right)
        {
            // 计算评分：检查对角线四个位置的垃圾数量
            int score = 0;
            if (binary_search(points.begin(), points.end(), make_pair(x + 1, y + 1)))
                score++;
            if (binary_search(points.begin(), points.end(), make_pair(x + 1, y - 1)))
                score++;
            if (binary_search(points.begin(), points.end(), make_pair(x - 1, y + 1)))
                score++;
            if (binary_search(points.begin(), points.end(), make_pair(x - 1, y - 1)))
                score++;

            ans[score]++;
        }
    }

    // 按格式输出
    for (int i = 0; i < 5; ++i)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}