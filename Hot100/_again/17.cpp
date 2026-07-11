#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string a;
int n;

unordered_map<char, vector<char>> v = {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}}};

vector<char> ans;
void solve(int idx)
{
    if (idx == n)
    {
        for (int i = 0; i < n; i++)
            cout << ans[i];
        cout << " ";
        return;
    }
    char num = a[idx];
    vector<char> al = v[num];

    for (char c : al)
    {
        ans.push_back(c);
        solve(idx + 1);
        ans.pop_back();
    }
}

int main()
{
    cin >> a;
    n = a.size();
    solve(0);
}