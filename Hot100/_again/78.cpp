#include <iostream>
#include <vector>

using namespace std;

int cnt;
int n;
vector<int> a;

vector<int> ans;
void solve(int idx)
{
    if (idx == n)
    {
        cnt++;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << '\n';
        return;
    }

    int num = a[idx];
    solve(idx + 1);

    ans.push_back(a[idx]);
    solve(idx + 1);
    ans.pop_back();
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int x;
    while (cin >> x)
        a.push_back(x);
    n = a.size();
    /* for (int i = 0; i < n; i++)
        cout << a[i] << " "; */
    solve(0);
}