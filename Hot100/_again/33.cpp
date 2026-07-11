#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int t;
    cin >> t;

    int p = a[n - 1];
    bool first = true;
    if (t <= p)
        first = false;

    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] > p)
        {
            if (first)
            {
                if (a[mid ]< t)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if (!first)
            {
                if (a[mid] < t)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    if (a[l] == t)
        cout << l;
    else
        cout << -1;
}