// 2022-3-A 未初始化警告
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int cnt = 0;
    int n, k;
    cin >> n >> k;
    bool a[n + 1];
    a[0] = true;
    for (int i = 1; i <= n; i++)
        a[i] = false;

    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        if (a[y] == false)
            cnt++;
        a[x]=true;
    }
    cout<<cnt;
}