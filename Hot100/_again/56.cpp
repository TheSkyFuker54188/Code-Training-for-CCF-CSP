#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || a[i].first > ans.back().second) //! 先处理简单的判分离push
            ans.push_back({a[i].first, a[i].second});
        else
        {
            ans.back().second = max(ans.back().second, a[i].second);
        }
    }

    for (auto i : ans)
    {
        cout << i.first << " " << i.second << '\n';
    }
}