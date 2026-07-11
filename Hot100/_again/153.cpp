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

    int p = a[n - 1];

    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        int now = a[mid];
        if (now > p)
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << a[l];
}
