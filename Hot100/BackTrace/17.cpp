// 列出映射表，代表每个数字所对应的字母列表
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int n;
string digits;

vector<vector<char>> ans;
vector<char> cur;

unordered_map<char, vector<char>> q =
    {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}} //
};

void solve(int idx)
{
    if (idx == n)
    {
        ans.push_back(cur);
        return;
    }

    vector<char> ch = q[digits[idx]];
    for (char c : ch)
    {
        cur.push_back(c);
        solve(idx + 1);
        cur.pop_back();
    }
}

int main()
{
    cin >> digits;
    n = digits.size();

    solve(0);

    for (auto i : ans)
    {
        int d = i.size();
        for (int j = 0; j < d; j++)
        {
            cout << i[j];
        }
        cout << ' ';
    }
}