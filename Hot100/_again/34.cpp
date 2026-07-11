#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int t;
    cin >> t;

    int s = -1;
    int e = -1;

    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        int p = a[mid];

        if (p < t)
        {
            l = mid + 1;
        }
        else if (p >= t)
        {
            r = mid - 1;
        }
    }
    if (a[l] == t)
        s = l;

    l = 0;
    r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int p = a[mid];

        if (p <= t)
        {
            l = mid + 1;
        }
        else if (p > t)
        {
            r = mid - 1;
        }
    }
    if (a[l-1] == t)
        e = l-1;
    cout << s << " " << e;
}