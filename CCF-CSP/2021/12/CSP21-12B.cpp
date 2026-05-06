// 2021-12-B 序列查询新解
//! 暴力超时
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, N;
    cin >> n >> N;
    int r = N / (n + 1);

    int A[n + 1];
    int f;
    int g;
    int err = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    int idx = n;
    for (int x = N - 1; x >= 0; x--)
    {
        while (A[idx] > x && idx > 0)
        {
            idx--;
        }
        f = idx;
        g = x / r;
        err += abs(f - g);
    }
    cout << err;
}