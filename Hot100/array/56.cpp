//! n≥10^7时，排序才基本行不通，必须想 O(n) 解法
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    vector<vector<int>> interval;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        interval.push_back({l, r});
    }

    sort(interval.begin(), interval.end());

    vector<vector<int>> ans;
    //ans.push_back(interval[0]); 

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() ||
            interval[i][0] > ans.back()[1])
        {
            ans.push_back(interval[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], interval[i][1]);
        }
    }

    for (auto &item : ans)
    {
        cout << item[0] << " " << item[1] << '\n';
    }
}