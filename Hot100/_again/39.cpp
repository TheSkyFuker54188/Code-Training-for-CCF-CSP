#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int n;
int t;

vector<int> ans;
int sum;

void solve(int idx)
{
    if (sum == t)
    {
        for (int i : ans)
            cout << i << " ";
        cout << '\n';
        return;
    }
    else if (sum > t)
        return;
    else
    {
        if (idx == n)
            return;
        solve(idx + 1);

        sum += a[idx];
        ans.push_back(a[idx]);
        solve(idx);
        sum -= a[idx];
        ans.pop_back();
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> n >> t;

    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    solve(0);
}