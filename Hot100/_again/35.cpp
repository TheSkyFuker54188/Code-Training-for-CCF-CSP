#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0;
    int r = n - 1;
    while (l <= r) //! 不满足于 l == r，也就是说：找不到后，还得再挪一次
    {
        int mid = (l + r) / 2;
        if (a[mid] < t)
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