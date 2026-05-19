// 2024-03-A 词频统计
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    vector<int> artic(m + 1, 0); // 出现在了多少篇文章中
    vector<int> vocab(m + 1, 0); // 在全部文章中总共出现了几次

    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        vector<bool> voc(m + 1, false);
        for (int j = 0; j < l; j++)
        {
            int tmp;
            cin >> tmp;
            voc[tmp] = true;
            vocab[tmp]++;
        }
        //for (int j = 1; j <= m; j++)
        //    cout << j << ": " << voc[j] << "||";
        for (int j = 1; j <= m; j++)
        {
            if (voc[j])
                artic[j]++;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cout << artic[i] << " " << vocab[i] << "\n";
    }
}