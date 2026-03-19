// 2017年03月 第A题
// 算法 + 数据结构）

#include <iostream>

using namespace std;

const int MAX = 1000;

int n;
int k;
int a[MAX + 1];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;
    int weight = 0;
    for (int i = 1; i <= n; i++)
    {
        weight += a[i];
        if (weight >= k)
        {
            ans++;
            weight = 0;
        }
        if (i == n && weight != 0)
            ans++;
    }
    cout << ans;
}