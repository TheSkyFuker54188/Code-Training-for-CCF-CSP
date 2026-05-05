// 2021-9-A 数组推导
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int B[n];
    int A[n];
    // bool a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
        A[i] = -1;
    }

    int last = -1;
    for (int i = 0; i < n; i++)
    {
        if (B[i] != last)
        {
            A[i] = B[i];
        }
        last = B[i];
    }
    int sum_max = 0, sum_min = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] != -1)
        {
            sum_max += A[i];
            sum_min += A[i];
        }
        else
        {
            sum_max += B[i];
            sum_min += 0;
        }
    }
    cout << sum_max << endl
         << sum_min;
}