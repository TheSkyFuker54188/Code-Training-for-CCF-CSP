#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
int n;

bool h(string ss)
{
    if (ss.size() == 0 || ss.size() == 1)
        return true;
    int l = 0;
    int r = ss.size() - 1;
    while (l < r)
    {
        if (ss[l] != ss[r])
            return false;
        l++;
        r--;
    }
    return true;
}

vector<string> ans;
void solve(int idx, int last)
{
    /* for (string i : ans)
        cout << i << " ";
    cout << '\n'; */
    string a = s.substr(last, idx - last);
    /* cout << a << '\n'; */
    if (idx == n)
    {
        if (h(a))
        {
            for (string i : ans)
                cout << i << " ";
            cout << a << '\n';
        }
        return;
    }

    solve(idx + 1, last);
    if (h(a))
    {
        ans.push_back(a);
 /*        for (string i : ans)
            cout << i << " ";
        cout << '\n'; */
        solve(idx + 1, idx);
        ans.pop_back();
    }
    return;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> s;
    n = s.size();
    solve(1, 0);
}