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
        cin >> a[i];

    int l = 0;
    int r = n - 1;
    int ans = 0;

    while (l < r)
    {
        int w = r - l;
        int h;
        if (a[l] < a[r])
        {
            h = a[l];
            l++;
        }
        else
        {
            h = a[r];
            r--;
        }
        //cout << h << " " << w;
        ans = max(ans, h * w);
    }
    cout << ans;
}