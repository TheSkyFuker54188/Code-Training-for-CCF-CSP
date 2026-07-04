/*
1.如果目标值T存在于数组，则找到目标值的下标。
2.如果目标值T不存在于数组，则找到≥T的第一个位置的下标。
化简一下就是：找到数组中≥T 的第一个位置
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l;
}