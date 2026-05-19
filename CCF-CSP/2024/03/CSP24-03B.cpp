// 2024-03-B 相似度计算
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    map<string, pair<int, int>> voc;
    //    词  ,     <Acnt,Bcnt>

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);

        auto it = voc.find(tmp);
        if (it == voc.end())
        {
            voc.insert({tmp, {1, 0}});
        }
        else
        {
            it->second.first++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        string tmp;
        cin >> tmp;
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);

        auto it = voc.find(tmp);
        if (it == voc.end())
        {
            voc.insert({tmp, {0, 1}});
        }
        else
        {
            it->second.second++;
        }
    }

    int a = 0, b = 0;
    for (auto it = voc.begin(); it != voc.end(); it++)
    {
        if (it->second.first != 0 && it->second.second != 0)
            a++;
    }
    b = voc.size();

    cout << a << "\n"
         << b;
}