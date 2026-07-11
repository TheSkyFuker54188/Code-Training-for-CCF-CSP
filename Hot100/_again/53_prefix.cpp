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

    int ans = a[0];
    int min_pref = 0;

    int sum = 0;
    for (int x : a)
    {
        sum += x;
        ans = max(ans, sum - min_pref);
        min_pref = min(min_pref, sum);
    }
    cout << ans;
}