//? 先排序，然后枚举三个下标中的某一个下标，剩下的两个下标由相向双指针确定
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && a[i] == a[i - 1])//! 对 i 的去重
            continue;
        int t = -a[i];

        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            int sum = a[l] + a[r];
            if (sum > t)
                r--;
            else if (sum < t)
                l++;
            else
            {
                cout << a[i] << " " << a[l] << " " << a[r] << '\n';
                l++;
                r--;
                while (l < r && a[l] == a[l - 1])
                    l++;
                while (l < r && a[r] == a[r + 1])
                    r--;
            }
        }
    }
}