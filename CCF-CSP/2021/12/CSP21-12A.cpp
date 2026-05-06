// 2021-12-A 序列查询
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    int n, N;
    cin >> n >> N;

    int A[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    int sum = 0;

    int idx = n;
    for (int x = N-1; x >= 0; x--)
    {
        while (A[idx] > x && idx > 0)
        {
            idx--;
        }
        sum += idx;
    } 
    cout << sum;
}