// 2020-6-B 稀疏向量
// 双指针
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    int n, a, b;
    cin >> n >> a >> b;
    pair<int, long long> u[a];
    pair<int, long long> v[b];

    for (int i = 0; i < a; i++)
    {
        cin >> u[i].first >> u[i].second;
    }
    for (int i = 0; i < b; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    long long ans = 0;

    int i = 0, j = 0;
    while (i < a && j < b)
    {
        if (u[i].first == v[j].first)
        {
            ans += u[i].second * v[j].second;
            i++;
            j++;
        }
        else if (u[i].first < v[j].first)
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    cout << ans;
}