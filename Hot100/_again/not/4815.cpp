#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    vector<int> pref(n + 1, 0);
    a[0] = 0;
    pref[0] = 0;

    int sum;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i == 0)
            pref[i] = a[i];
        else
            pref[i] = pref[i - 1] + a[i];
    }
    sum = pref[n];

    int l;
    int r;

    int lest = sum;
    for (l = 0; l <= k; l++)
    {
        r = l + n - k;
        int s = pref[r] - pref[l];
        lest = min(lest, s);
    }

    cout << sum - lest;
}