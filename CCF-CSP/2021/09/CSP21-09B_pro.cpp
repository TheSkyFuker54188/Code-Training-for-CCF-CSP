// 2021-9-B 非零段划分
//! 剪枝版的暴力还是不行
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    int A[n];
    int B[n];

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (A[i] > max)
            max = A[i];
        B[i] = A[i];
    }
    int p_max = max;
    // int p = 1;
    sort(B, B + n);

    max = 0;

    for (int k = 0; k < n; k++)
    {
        int a[n];
        int last = 0;
        int cnt = 0;

        int p = B[k];
        for (int i = 0; i < n; i++)
        {
            if (A[i] < p)
                a[i] = 0;
            else
                a[i] = A[i];

            if (last == 0 && a[i] != 0)
                cnt++;
            last = a[i];
        }
        if (cnt > max)
            max = cnt;
    }

    cout << max;
}