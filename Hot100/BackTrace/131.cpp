#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> ans;
vector<string> cur;
string s;
int n;

bool aba(string s)
{
    int left = 0;
    int right = s.size() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
void solve(int last, int idx)
/* 缝隙0  [索引0]  缝隙1  [索引1]  缝隙2  [索引2]  缝隙3
            a               a               b
缝隙 i 正好就在字符 s[i] 的前面*/
{ /*  last = 当前段的起始索引
    idx = 当前考虑的分割点（当前段结束的下一个位置） */
    if (idx == n)
    {
        string end_part = s.substr(last, n - last);
        if (aba(end_part))
        {
            cur.push_back(end_part);
            ans.push_back(cur);
            cur.pop_back();
        }
        return;
    }
    string sub = s.substr(last, idx - last);
    if (aba(sub))
    {
        cur.push_back(sub);
        solve(idx, idx + 1);
        cur.pop_back();
    }

    solve(last, idx + 1);
}
int main()
{
    cin >> s;
    n = s.size();

    solve(0, 1);
    for (auto i : ans)
    {
        for (int j = 0; j < i.size(); j++)
        {
            cout << i[j] << " ";
        }
        cout << '\n';
    }
}