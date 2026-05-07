// 2022-3-B 出行计划
//! 带STL仍是暴力解，不可行
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> time(400000 + 1);

    for (int i = 0; i < n; i++)
    {
        int t, c;
        cin >> t >> c;

        for (int j = t; j >= t - c+1; j--)
        {
            if (j < 0)
                break;
            time[j].push_back(i);
        }
    }

    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        // q+k
        /* cout << endl
             << "DEBUG: ";
        for (int j = 0; j < time[q + k].size(); j++)
            cout << time[q + k][j] << " "; */
        cout << time[q + k].size() << endl;
    }
}