#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;

void quick(int l, int r)
{
    if (l >= r)
        return;
    int l0 = l;
    int r0 = r;

    int piv = a[l];//todo 挖第一个坑
    while (l < r)//! 交替填坑
    {
        while (l < r && a[r] >= piv)//todo 从右往左找一个不该在右边的数
            r--;
        a[l] = a[r];
        while (l < r && a[l] <= piv)
            l++;
        a[r] = a[l];
    }
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