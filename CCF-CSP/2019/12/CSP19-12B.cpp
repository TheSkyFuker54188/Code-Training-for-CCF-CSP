// 2019-12-B 回收站选址
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;

    sort(points.begin(), points.end());

    int ans[5] = {0};
    for (int i = 0; i < n; i++)
    {
        int x = points[i].first;
        int y = points[i].second;

        bool up = binary_search(points.begin(), points.end(), make_pair(x, y + 1));
        bool down = binary_search(points.begin(), points.end(), make_pair(x, y - 1));
        bool left = binary_search(points.begin(), points.end(), make_pair(x - 1, y));
        bool right = binary_search(points.begin(), points.end(), make_pair(x + 1, y));

        if (up && down && left && right)
        {
            int score = 0;
            if (binary_search(points.begin(), points.end(), make_pair(x + 1, y + 1)))
                score++;
            if (binary_search(points.begin(), points.end(), make_pair(x - 1, y + 1)))
                score++;
            if (binary_search(points.begin(), points.end(), make_pair(x + 1, y - 1)))
                score++;
            if (binary_search(points.begin(), points.end(), make_pair(x - 1, y - 1)))
                score++;

            ans[score]++;
        }
    }
    for (int i = 0; i < 5; i++)
        cout << ans[i] << endl;
}