#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = n - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] > a[n - 1])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << a[l];
}