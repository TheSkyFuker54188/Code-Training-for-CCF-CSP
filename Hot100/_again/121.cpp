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

    int m = a[0];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        if (x < m)
            m = x;
        ans = max(ans, x - m);
    }
    cout << ans;
}