#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;
vector<bool> b;
vector<int> ans;

void solve(int idx)
{
    if (idx == n)
    {
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == false)
        {
            ans[idx]=a[i];
            b[i] = true;
            solve(idx + 1);
            b[i] = false;
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int x;
    while (cin >> x)
        a.push_back(x);
    n = a.size();

    b.assign(n, false);
    ans.assign(n, 0);

    sort(a.begin(), a.end());

    solve(0);
}