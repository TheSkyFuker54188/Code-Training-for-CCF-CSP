// 2024-09-B 字符串变换
//! 暴力必超时
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<pair<int, string>> ss;
    string s;

    string tmp;
    getline(cin, tmp);
    int tmp_ptr = 0;
    for (int i = 1; i < tmp.length() - 1; i++)
    {
        s[tmp_ptr] = tmp[i];
        tmp_ptr++;
    }
    ss.push_back(make_pair(0, s));

    int n;
    cin >> n;
    cin.ignore();
    vector<pair<char, char>> f(n);
    for (int i = 0; i < n; i++)
    {
        string tmp;
        getline(cin, tmp);
        f[i] = make_pair(tmp[1], tmp[2]);
    }

    int m;
    cin >> m;
    int k[m];
    for (int i = 0; i < m; i++)
    {
        cin >> k[i];
    }
    sort(k, k + m);
    for (int i = 0; i < m; i++)
    {
        int last_idx = ss[ss.size() - 1].first;
        int t = k[i] - last_idx;
        for (int j = 0; j < t; j++)
        {
            int p = 0;
            //
        }
    }
}