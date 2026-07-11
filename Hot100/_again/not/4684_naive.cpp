#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;

void quick(int l, int r)
{
    if (l >= r) // 空区间：l > r
        // 单元素区间：l == r
        return;
    int l0 = l;
    int r0 = r;

    int piv = a[l]; // todo 挖第一个坑
    while (l < r)   //* 当 l == r 时，两个指针重合，坑就在这个重合点，循环结束
    {
        // 1. 从右往左找第一个小于基准的数
        while (l < r)
        {
            if (a[r] < piv)
            {
                a[l] = a[r]; // 填左坑，右边留下新坑
                break;       // 找到就停，准备切换方向
            }
            else
            {
                r--;
            }
        }
        // 2. 从左往右找第一个大于基准的数
        while (l < r)
        {
            if (a[l] > piv)
            {
                a[r] = a[l]; // 填右坑，左边留下新坑
                break;
            }
            else
            {
                l++;
            }
        }
    }
    // 相遇点放入基准
    a[l] = piv;
    quick(l0, l - 1);
    quick(l + 1, r0);
}

int main()
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quick(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}