#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> pre(n, 1);
    vector<int> pos(n, 1);
    pre[0] = 1;
    pos[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] * a[i - 1];
    }
    for (int j = n - 2; j >= 0; j--)
    {
        pos[j] = pos[j + 1] * a[j + 1];
    }

    for (int i = 0; i < n; i++)
    {
        int ans = pre[i] * pos[i];
        cout << ans << " ";
    }
}